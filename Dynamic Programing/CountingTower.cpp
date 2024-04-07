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

ll arr[1000001][2];
int main(){
    arr[1][0]=1;
    arr[1][1]=1;
    f(i,1,1000000){
        arr[i][0]%=MOD;
        arr[i][1]%=MOD;
        arr[i+1][0]+=2*arr[i][0];
        arr[i+1][0]+=arr[i][1];
        arr[i+1][1]+=arr[i][0];
        arr[i+1][1]+=4*arr[i][1];
    }
    int n;scanf("%d",&n);
    while (n--)
    {
        int a;scanf("%d",&a);
        printf("%lld\n",(arr[a][0]%MOD+arr[a][1]%MOD)%MOD);
    }
    
}