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
    ll k;
    cin>>n>>k;

    map<ll,ll> MP;
    vi arr(n);
    for(int & i : arr ) cin>>i;

    ll sum=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if( sum == k ) ans++;
        
        ans+= MP[ sum-k ];
        MP[ sum ]++;
    }

    cout<<ans<<'\n';
    return 0;
}