#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second 
#define PB push_back 
#define all(x) x.begin(),x.end()

typedef pair<int,int> pii;
typedef vector<int> vi;



const int MAX_N = 1e5;
const int INF = 1e9;
const int MOD = 1e9+7;


signed main(){
    OAO 
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    vi arr(n) , house(m);
    for(int &i: arr) cin>>i;
    for(int &i: house) cin>>i;
    sort( all(arr) );
    sort( all(house) );

    int i=0 , j=0 ,diff ;
    while( i<n && j<m ){
        diff = abs( arr[i] - house[j] );
        if( diff <= k ){
            ans++;
            i++ , j++;
        }
        else{
            if( arr[i]-k > house[j] ) j++;
            else i++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}