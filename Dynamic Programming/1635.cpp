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
    int n , k ;
    cin>>n>>k;

    vi coin(n);
    for(int & c : coin ) cin>>c;

    vi dp(k+1 ,0 );
    dp[0] = 1;
    for(int i=1;i<=k;i++){
        for(int & c : coin ){
            if( i-c >=0 ){
                dp[i]+= dp[i-c];
            }
        }
    }
    
    cout<<dp[k]<<'\n';
    return 0;
}