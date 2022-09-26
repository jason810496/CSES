#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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

	int n, ans=0 ;
	cin>>n;

	vector< pii > Lines(n);
	
	for( pii &i: Lines ) cin>>i.F>>i.S;

	sort( all( Lines ) );

	priority_queue< int , vector<int> , greater<int> > pq;

	for( int i=0 ; i<n ;i++ ){
		while( pq.size() && pq.top() < Lines[i].F ) pq.pop() ;
		pq.push( Lines[i].S );
		ans = max( ans , (int)pq.size() );
	}

	cout<<ans<<"\n";

    return 0;
}






