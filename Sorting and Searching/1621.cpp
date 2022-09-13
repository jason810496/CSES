#include<iostream>
#include<utility>
#include<vector>
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
    int n,x;
    set<int> Uset;
    cin>>n;
    while( n-- ){
        cin>>x;
        Uset.insert(x);
    }
    cout<<Uset.size()<<"\n";
    return 0;
}