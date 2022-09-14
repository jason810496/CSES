#include<iostream>
#include<vector>
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
    int n , x;
    cin>>n>>x;
    vi P(n);
    for(int &i:P) cin>>i;
    
    sort( all(P) );

    int L=0 , R=n-1 , ans = 0 ;

    while( L<=R ){
        if( P[L] + P[R] <= x ){
            L++ , R--;
            ans++;
        }
        else{
            R--;
            ans++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}