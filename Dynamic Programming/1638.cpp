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
typedef vector< vector<int> > vvi;
typedef vector< pair<int,int> > vpii;


const int MAX_N = 1e5;
const int INF = 1e9;
const int MOD = 1e9+7;


int solve(vvi &dp , int I ,int J ){
    if( I<=0 || J<=0 ) return 0;
    if( dp[I][J] == -2 ){
        return dp[I][J] = 0;
    }
    if( dp[I][J]!=-1 ) return dp[I][J];

    int res = ( solve(dp,I-1,J) % MOD + solve(dp,I,J-1) % MOD ) % MOD;

    return dp[I][J] = res ;
}
signed main(){
    OAO
    int n;
    cin>>n;

    vvi dp(n+1 ,vi(n+1,-1) );

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if( c == '*' ) dp[i][j] = -2;
        }
    }

    if( dp[1][1] == -2 || dp[n][n] == -2 ){
        cout<<"0\n";
        return 0;
    }

    dp[1][1] = 1;
    cout<<solve(dp,n,n)<<'\n';
    return 0;
}