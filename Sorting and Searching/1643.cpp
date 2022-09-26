#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

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
    vi arr(n);
    for(int & i : arr ) cin>>i;

    ll cur=0 , ans = arr[0] ,x;
    for(int & i : arr ){
        x=i;
        cur = max( cur+x , x );
        ans = max( ans ,cur );
    }

    cout<<ans<<"\n";
    return 0;
}