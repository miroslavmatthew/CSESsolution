#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
#define setB(a,i) (a |= (1 << i))
#define unsetB(a,i) (a &= (~(1 << i)))
#define queryB(a,i) (a & (1 << i))
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define all(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define INF_INT 2e9
#define INF_LL 2e18
#define MOD 1000000007


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int,int> > vii;
    vector<ll> arr;
    int n;
    ll m;cin>>n>>m;
    cf(i,1,n){
        ll a;cin>>a;
        vii.push_back(make_pair(a,i));
        arr.push_back(a);
    }
    sort(all(vii));
    sort(all(arr));
    bool res = true;
    int l =0,r=n-1;
    while (l+1<r)
    {
        if (arr[l]+arr[r]>=m)
        {
            r--;
            l=0;
        }
        else{
            ll target = m-arr[l]-arr[r];
            vector<ll>::iterator ptr=arr.begin()+l+1; 
            vector<ll>::iterator ptr2=arr.begin()+r; 
            int lb = lower_bound(ptr,ptr2,target)-arr.begin();
            int ub = upper_bound(ptr,ptr2,target)-arr.begin();
            if (ub==lb)
            {
                l++;
            }
            else{
                res=false;
                cout<<vii[l].second<<" "<<vii[lb].second<<" "<<vii[r].second<<"\n";
                break;
            }
        }
    }
    if (res)
    {
        cout<<"IMPOSSIBLE\n";
    }
    
    
}
