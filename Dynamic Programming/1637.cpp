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

vi dp;

vi GetD(int cur){
    vi r;
    while( cur ){
        r.push_back( cur % 10 );
        cur /= 10;
    }
    return r;
}
int DFS(int cur){
    if( dp[cur] !=INF ) return dp[cur];
    if( cur < 0 ) return INF;
    vi D = GetD( cur );

    for(int & d :  D){
        if( d == 0 ) continue;
        dp[ cur ] = min( dp[cur] , DFS(cur-d) +1 );
    }

    return dp[cur];
}
signed main(){
    OAO
    int n;
    cin>>n;

    dp.resize(n+1,INF);
    dp[0] = 0;

    cout<<DFS(n)<<'\n';
    return 0;
}