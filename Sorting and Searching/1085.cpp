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
typedef vector< vector<int> > vvi;
typedef vector< pair<int,int> > vpii;


const int MAX_N = 2e5+5;
const int INF = 1e9;
const int MOD = 1e9+7;

int n,k;
int arr[MAX_N];
int mx=0;

bool check(unsigned ll mid){
    if(mx>mid) return 0;

    int cnt=0;
    unsigned ll cur=0;
    for(int i=0;i<n;i++){
        if( cur+arr[i] > mid ){
            cnt++;
            cur = 0;
        }
        cur+=arr[i];
        if( cnt>k ) return 0;
    }
    cnt+=(cur<=mid);

    // cout<<"cur : "<<cnt<<"\n";

    return (cnt<=k);
}

signed main(){
    OAO
    cin>>n>>k;

    unsigned ll l=1,r=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        r+=arr[i];
        mx=max(mx,arr[i]);
    }

    while(l<=r){
        unsigned ll mid = l+(r-l)/2;
        if( check(mid) ){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        // cout<<l<<" "<<mid<<" "<<r<<"\n";
    }

    cout<<l<<'\n';

    return 0;
}