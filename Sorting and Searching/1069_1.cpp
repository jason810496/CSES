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
	vi val;
	vector< pii > arr(n);

	for( auto & i : arr ) {
		cin>>i.F>>i.S;
		val.PB( i.F );
		val.PB( i.S );
	}

	sort( all(val) );
	val.resize( unique( all(val) )- val.begin() );

	vi Cnt( val.size() + 3 );

	for(auto & i: arr ) {
		i.F = lower_bound( all(val) , i.F)  - val.begin() + 1;
		i.S = lower_bound( all(val) , i.S) - val.begin() + 1;

		Cnt[i.F]++;
		Cnt[i.S+1]--;
	}

	int cur=0 , ans=0;

	for( int i=1;i<=val.size();i++){
		cur+=Cnt[i];
		ans = max( cur , ans );
	}

	cout<<ans<<"\n";
	

    return 0;
}






