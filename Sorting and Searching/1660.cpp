#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<deque>

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
    int n,k;
    cin>>n>>k;

    vi arr(n);
    for(int & i : arr ) cin>>i;

    ll cur=0;
    int l=0 , ans=0 ;
    for(int r=0;r<n;r++){
        cur+=arr[r];
        while( cur > k && l<r) cur-=arr[l++];

        if( cur == k ) ans++;
    }

    cout<<ans<<'\n';

    return 0;
}