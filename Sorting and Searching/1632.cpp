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

    int n,k;
    cin>>n>>k;

    vpii arr(n);
    for(auto & i : arr ){
        cin>>i.F>>i.S;
    }
    sort( all( arr ) , [&](pii &a,pii &b){return (a.S==b.S ? a.F < b.F: a.S < b.S ); } );

    multiset<int> st;

    while(k--){
        st.insert(0);
    }

    ll ans=0;
    for(auto & i : arr){
        auto it = st.upper_bound(i.F);
        if( it == st.begin() ) continue;

        st.erase( --it );
        st.insert( i.S );
        ans++;
    }

    cout<<ans<<"\n";
    
    return 0;
}