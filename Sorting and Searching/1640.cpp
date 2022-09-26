#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>

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

    int n , k;
    cin>>n>>k;

    vi arr(n);
    map<int,int> MP;
    
    for(int &i: arr) cin>>i;

    bool flag = false;
    for(int i=0;i<n;i++ ){
        int target = k-arr[i];
        if( MP.find(target)!=MP.end() ){
            cout<<MP[ target ]+1<<" "<<i+1<<"\n";
            flag = true;
            break;
        }
        MP[ arr[i] ]=i;
    }
    if( !flag ) cout<<"IMPOSSIBLE\n";
    return 0;
}