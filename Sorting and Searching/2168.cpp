#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<map>
#include<array>
#include<string.h>

#define ll long long
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second 
#define PB push_back 
#define all(x) x.begin(),x.end()
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vpii;


const int MAX_N = 2e5+5;
const int INF = 2e5;
const int MOD = 1e9+7;

typedef array<int,3> range;
vi unique_val;

vi BIT;

inline int Low(int x){
    return x&-x;
}

inline int GetPos(int i){
    return (lower_bound(all(unique_val) ,i ) - unique_val.begin()) + 1;
}

void Update(int idx,int val){
    for(int i=idx;i<BIT.size();i+=Low(i) ){
        BIT[i]+=val;
    }
}

int Query(int idx){
    int ret=0;
    for(int i=idx;i;i-=Low(i) ){
        ret+=BIT[i];
    }
    return ret;
}

signed main(){
    OAO
    int n;
    cin>>n;
    vector< range > arr(n);
    vector< array<int,2> > ans(n);

    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        arr[i] = { a,b,i};
        
        unique_val.PB( a );
        unique_val.PB( b );
    }

    sort( all(unique_val) );
    unique_val.resize( unique(all(unique_val)) - unique_val.begin() );

    BIT.resize( unique_val.size()+1 ); 

    sort( all(arr) , [&](range &a,range &b){
        return a[0]==b[0] ? a[1]>b[1]:a[0]<b[0] ;
    });

    for(int i=n-1;i>=0;i--){
        int r = GetPos( arr[i][1] );
        int idx = arr[i][2];

        ans[idx][0] = Query( r );
        Update( r , 1 );
    }

    fill( all(BIT) , 0 );

    for(int i=0;i<n;i++){
        int r = GetPos( arr[i][1] );
        int idx = arr[i][2];

        ans[idx][1] = i - Query( r-1 );
        Update( r, 1);
    }

    for(int i=0;i<n;i++){
        cout<<(ans[i][0] ? 1:0)<<' ';
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<(ans[i][1] ? 1:0)<<' ';
    }
    cout<<'\n';

    return 0;
}