#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second 
#define PB push_back 
#define all(x) x.begin(),x.end()
#define ll long long 

typedef pair<int,int> pii;
typedef vector<int> vi;



const int MAX_N = 1e5;
const int INF = 1e9;
const int MOD = 1e9+7;


signed main(){
    OAO 

	int n,  l ,r ;
	cin>>n;
	vector< pii > arr(n);

	for( auto & i : arr ) {
		cin>>l>>r;
		arr.PB( {l,1} );
		arr.PB( {r,-1} );
	}

	sort( all(arr) );

	int cur=0,ans=0;

	for(auto & i: arr ) {
		cur+= i.S;
		ans = max( ans , cur );
	}

	cout<<ans<<"\n";
	

    return 0;
}






