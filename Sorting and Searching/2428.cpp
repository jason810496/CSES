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
    int n , k ;
    cin>>n>>k;
    
    vi arr(n);
    for(int & i : arr ) cin>>i;

    int l=0,r=0;
    ll ans=0;
    map<int,int> MP;
    while( r<n ){
        MP[ arr[r] ]++;

        while( MP.size() > k ){
            MP[ arr[l] ]--;
            if( MP[arr[l] ] == 0 ){ 
                MP.erase( MP.find( arr[l] ) );
            }
            l++;
        }

        ans+= r-l+1;
        r++;
    }

    cout<<ans<<'\n';
    return 0;
}