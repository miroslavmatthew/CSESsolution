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
    int arr[200001];
    int n;scanf("%d",&n);
    int cnt=1;
    cf (i,1,n)
    {
        int a;scanf("%d",&a);
        arr[a]=i;
    }
    cf(i,2,n){
        if (arr[i]<arr[i-1])
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
    
}