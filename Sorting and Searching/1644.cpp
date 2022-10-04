#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>

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

    int n , mn , mx;
    cin>>n>>mn>>mx;

    vector<ll> prefix(n+1);

    ll x;
    for(int i=1;i<=n;i++){
        cin>>x;
        prefix[i] = prefix[i-1] + x;
    }

    multiset<ll> st;   
    ll ans = -1e18;
    for(int i=mn;i<=n;i++){
        if( i>mx ){
            st.erase( st.find( prefix[i-mx-1] ) );
        }

        st.insert( prefix[i-mn] );
        ans = max( ans , prefix[i]-*st.begin() );
    }

    cout<<ans<<'\n';

    return 0;
}