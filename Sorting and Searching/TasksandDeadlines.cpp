#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define setB(a,i) (a |= (1 << i))
#define unsetB(a,i) (a &= (~(1 << i)))
#define queryB(a,i) (a & (1 << i))
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define all(x) x.begin(), x.end()
#define ll long long
#define INF_INT 2e9
#define INF_LL 2e18
#define MOD 1000000007
int main(){
    vector<pair<int,int> > arr;
    int n;scanf("%d",&n);
    f(i,0,n)
    {
        int a,b;scanf("%d %d",&a,&b);
        arr.push_back(make_pair(a,b));
    }
    sort(all(arr));
    ll init = 0;
    ll res = 0;
    f(i,0,n){
        init+=arr[i].first;
        res+=arr[i].second-init;
    }
    printf("%lld\n",res);
}