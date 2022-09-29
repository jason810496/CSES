#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

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

    vpii arr(n);
    for(int i=0,x;i<n;i++){
        cin>>x;
        arr[i] = { x, i };
    }
    sort( all( arr ) );

    bool flag = true;
    for(int i=1;i<n-1 && flag ;i++){
        int l=0,r=n-1;
        while(l<i&&i<r){
            int sum = arr[l].F+arr[i].F+arr[r].F;
            if( sum == k ){
                cout<<arr[l].S+1<<' '<<arr[i].S+1<<' '<<arr[r].S+1<<"\n";
                flag = false;
                break;
            }
            else if(sum > k) r--;
            else l++;
        }
    }

    if( flag ) cout<<"IMPOSSIBLE\n";

    return 0;
}