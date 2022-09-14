#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second 
#define PB push_back 
#define all(x) x.begin(),x.end()
#define ll long long 

// typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAX_N = 1e5;
const int INF = 1e9;
const int MOD = 1e9+7;


signed main(){
    OAO 
    int n,m;
    cin>>n>>m;
    multiset<int> st;
    for(int i=0,x;i<n;i++){
        cin>>x;
        st.insert( x );
    }

    for(int i=0,x;i<m;i++){
        cin>>x;
        if( st.empty() ){
            cout<<"-1\n";
            continue;
        }
        auto it = st.lower_bound( x );
        if( it==st.end() ) it--;
        while( *it > x && it!=st.begin() ) it--;
        
        if( *it<=x ){
            cout<<*it<<"\n";
            st.erase( it );
        }
        else cout<<"-1\n";
    }

    return 0;
}