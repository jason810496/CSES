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

int n,t;
vector<ll> arr;

bool check(ll val){
    ll cnt=0;
    for(ll i : arr){
        cnt += val/i;
        if( cnt >=t ) return true;
    }

    return false;
}

signed main(){
    OAO
    
    cin>>n>>t;
    arr.resize( n );

    for(ll & i : arr ) cin>>i;

    ll l=1 , r=1e18;

    while( l<=r ){
        ll mid = (l+r)/2;
        if( check(mid) ){
            r = mid-1;
        }
        else l=mid+1;
    }

    cout<<l<<'\n';

    return 0;
}