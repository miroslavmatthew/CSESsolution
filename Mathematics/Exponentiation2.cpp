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


int modpow(int x,int n,int m){
    if (n==0)
    {
        return 1%m;
    }
    ll u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2==1)
    {
        u=(u*x)%m;
    }
    return u;
}
int main(){
    int n;scanf("%d",&n);
    while (n--)
    {
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        int res = modpow(a,b,MOD);
        printf("%d\n",modpow(res,c,MOD));
    }
    
}