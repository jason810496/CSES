#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<array>

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


const int MAX_N = 1e5;
const int INF = 1e9;
const int MOD = 1e9+7;

vi BIT;
vi Val;

int Get(int x){
    return (lower_bound(all(Val),x)-Val.begin())+1;
}

inline int Low(int i){
    return i&-i;
}

void Update(int idx,int val){
    for(int i=idx;i<BIT.size();i+=Low(i)){
        BIT[i]+=val;
    }
}

int Query(int idx){
    int ret = 0;
    for(int i=idx;i;i-=Low(i) ){
        ret += BIT[i];
    } 
    return ret;
}

signed main(){
    OAO
    int n;
    cin>>n;
    vector< array<int , 3 > > Range(n);
    vector< array<int,2> > ans(n);


    for(int i=0,l,r;i<n;i++){
        cin>>l>>r;
        Range[i] = { l ,r, i };
        Val.PB(l);
        Val.PB(r);
    }

    sort( all(Val) );
    Val.resize( unique(all(Val)) - Val.begin() );

    BIT.resize( Val.size()+1 );

    sort( all(Range) , [&](array<int,3> &a,array<int,3> &b){
        return (a[0]==b[0] ? a[1]>b[1]:a[0]<b[0] );
    });


    for(int i=n-1;i>=0;i--){
        int r = Get( Range[i][1] );
        int idx = Range[i][2];

        ans[idx][0] = Query( r );
        Update( r , 1 );
    }

    fill( all(BIT) , 0 );

    for(int i=0;i<n;i++){
        int r = Get( Range[i][1] );
        int idx = Range[i][2];

        ans[idx][1] = i - Query( r-1 );
        Update( r, 1 );
    }

    for(int i=0;i<n;i++){
        cout<<ans[i][0]<<' ';
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<ans[i][1]<<' ';
    }
    cout<<'\n';

    return 0;
}