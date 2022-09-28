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
    int n;
    cin>>n;

    vpii arr(n);
    for(int i=0,a,d;i<n;i++){
        cin>>a>>d;
        arr[i] = { a, d };
    }

    // sort( all(arr) , [&](pii &a , pii &b){
    //     return a.S == b.S ? a.F<b.F : a.S<b.S ;
    // });

    sort( all( arr) );

    ll cur=0 , ans=0;
    for(int i=0;i<n;i++){
        cur+= arr[i].F;
        ans+= (ll)arr[i].S - cur;
    }

    cout<<ans<<'\n';
    return 0;
}