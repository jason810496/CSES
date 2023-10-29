// ACCEPTED

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
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef vector< pair<int,int> > vpii;


const int MAX_N = 1e5;
const int INF = 1e9;
const int MOD = 1e9+7;


signed main(){
    OAO
    int n,m;
    cin>>n>>m;

    ll mod = 1e9+7;

    vvl dp(n+1,vl(m+1));
    vi arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    // for(int i=1;i<=m;i++){
    //     dp[1][i] = 1;
    // }

    if( arr[1] == 0 ){
        for(int i=1;i<=m;i++){
            dp[1][i] = 1;
        }
    }
    else{
        dp[1][ arr[1] ] = 1;
    }

    
    for(int i=2;i<=n;i++){
        if( arr[i] == 0 ){

            for(int j=1;j<=m;j++){
                // if( dp[i-1][j] == 0 ) continue;

                int l=j-1;
                int r=j+1;
                if( l<=1 ) l=1;
                if( r>=m ) r=m;

                // for(int j=1;j<=m;j++){
                for(int k=l;k<=r;k++){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
                // }
            }

            
        }
        else{
            int l = arr[i]-1;
            int r = arr[i]+1;

            if( l<=1 ) l=1;
            if( r>=m ) r=m;

            // for(int j=1;j<=m;j++){
            for(int k=l;k<=r;k++){
                dp[i][arr[i]] += dp[i-1][k];
                dp[i][arr[i]] %= mod;
            }
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j] << ' ';
    //     }
    //     cout<<"\n";
    // }

    // cout<<"=============================\n";
    // cout<<"0 ";
    // for(int i=1;i<=n;i++){
    //     cout<<arr[i]<<' ';
    // }
    // cout<<'\n';
    // cout<<"=============================\n";
    // for(int j=0;j<=m;j++){
    //     for(int i=0;i<=n;i++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<"\n";
    // }


    ll ans=0;
    for(int i=1;i<=m;i++){
        ans = (ans + dp[n][i] ) % mod;
    }

    cout<<ans<<"\n";

    return 0;
}