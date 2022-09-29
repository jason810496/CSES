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
    int n;
    cin>>n;
    vi RemainCnt(n);
    ll remain=0;

    RemainCnt[ remain ]=1;

    for(int i=0,x;i<n;i++){
        cin>>x;
        remain += x;

        RemainCnt[ (remain%n+n)%n ]++;
    }

    ll ans=0;

    for(ll i : RemainCnt ){
        ans += i*(i-1)/2;
    }

    cout<<ans<<'\n';

    // cur  = n*k + prefix
    // prefix =  cur - n*k ;
    return 0;
}

/*

pre(i) - pre(j) = n*k

( pre(i) - pre(j) )%n = (n*k)%n = 0

pre(i)%n == pre(j)%n

*/