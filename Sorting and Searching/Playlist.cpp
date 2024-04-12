#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
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
    map<int,int> mp;
    int n;scanf("%d",&n);
    int cnt =1;
    ll maxs = 0;
    cf(i,1,n)
    {
        int a;scanf("%d",&a);
        if(mp.find(a)==mp.end()){
            maxs = max(maxs,i-cnt+1);
            mp[a]=i;
        }
        else{
            maxs = max(maxs,(i-1)-cnt+1);
            cnt=max(mp[a]+1,cnt);
            mp[a]=i;
        }
    }
    printf("%lld\n",maxs);
    
}