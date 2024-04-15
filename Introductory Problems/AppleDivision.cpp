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

int arr[21];
int n;
ll rec(int idx,ll l,ll r){
    if (idx==n)
    {
        return abs(l-r);
    }
    else{
        return min(rec(idx+1,l+arr[idx],r),rec(idx+1,l,r+arr[idx]));
    }
}

int main(){
    scanf("%d",&n);
    f(i,0,n){
        scanf("%d",&arr[i]);
    }
    printf("%lld\n",rec(0,0,0));
}