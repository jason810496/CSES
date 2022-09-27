#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>

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
    int k , n;
    cin>>k>>n;
    
    set<int> Pos{ 0 , k };
    multiset<int> Gaps{ k };

    for(int i=0,x;i<n;i++){
        cin>>x;

        auto it = Pos.upper_bound( x );

        int r=*it;
        int l=*(--it);
        
        Gaps.erase( Gaps.find(r-l) );
        Gaps.insert(x-l);
        Gaps.insert(r-x);

        Pos.insert( x );
        auto ans = Gaps.end();
        ans--;
        cout<<*ans<<" ";        
    }

    return 0;
}