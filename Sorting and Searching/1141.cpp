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
    int n;
    cin>>n;
    vi arr(n);
    for(int & i: arr ) cin>>i;
    set<int> st;

    int ans = 0 , l=0 ;
    
    for(int r=0;r<n;r++){
        if( st.find( arr[r] ) == st.end() ){
            st.insert( arr[r] );
        }
        else{
            while( st.find(arr[r])!=st.end() ){
                st.erase( arr[l++] );
            }
            st.insert( arr[r] );
        }
        ans = max( ans , r-l+1 );
    }

    cout<<ans<<"\n";
    return 0;
}