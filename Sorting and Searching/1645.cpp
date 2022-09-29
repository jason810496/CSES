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
    int n,x;
    cin>>n;
    
    deque<pii> dq;

    for(int i=0;i<n;i++){
        cin>>x;
        while( dq.size() && dq.back().F >= x ){
            dq.pop_back();
        }

        if( dq.empty() ) cout<<"0 ";
        else cout<<dq.back().S<<' ';

        dq.push_back( {x,i+1} );
        
    }

    return 0;
}