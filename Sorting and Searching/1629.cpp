#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

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
    int n , l ,r;
    cin>>n;
    vpii arr(n);
    for(int i=0;i<n;i++){
        cin>>l>>r;
        arr[i] = {r,l};
    }

    sort( all(arr) );

    int cur=0 , ans=0;
    for(int i=0 ;i<n;i++){
        if(  arr[i].S >= cur ){
            cur = arr[i].F;
            ans++;
        }
    }

    cout<<ans<<"\n";
    return 0;
}