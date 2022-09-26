#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>

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

signed main(){
    OAO
    int n;
    cin>>n;
    
    vi arr( n );
    for(int & i : arr ) cin>>i;
    sort( all(arr) );

    
    if( arr[0] > 1 ){
        cout<<"1\n";
    }
    else{
        int Idx=0;
        ll sum = 0 ;

        bool flag = true;
        for(;Idx<n;Idx++){
            if( sum+1 < arr[Idx] ){
                flag = false;
                cout<<sum+1<<"\n";
                break;
            }
            sum+=arr[Idx];
        }

        if( flag ){
            cout<<sum+1<<"\n";
        }
        
    }

    
    return 0;
}