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


signed main(){
    OAO
    int n,k,total=0;
    cin>>n>>k;

    vi wt(n) , val(n) , dp(k+1);
    for(int & i : wt ) cin>>i;
    for(int & i : val) cin>>i;

    for(int i=0;i<n;i++){
        for(int w=k;w>=wt[i];w--){
            if( w-wt[i] >=0 ){
                dp[w] = max( dp[w] , dp[w-wt[i]]+val[i] );
            }
        }
    }

    cout<<dp[k]<<'\n';
    return 0;
}