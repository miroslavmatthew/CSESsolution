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

void solve(int n,int a,int b,int c){
    if (n>0)
    {
        solve(n-1,a,c,b);
        printf("%d %d\n",a,c);
        solve(n-1,b,a,c);
    }
    
}

int main(){
    int n;scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    solve(n,1,2,3);
}