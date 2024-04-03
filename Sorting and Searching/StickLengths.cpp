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
    int n;scanf("%d",&n);
    int arr[200001];
    f(i,0,n){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    ll res = 0;
    if (n%2==0)
    {
        ll temp=0,temp2=0;
        int tt=arr[(n-1)/2],tr=arr[((n-1)/2)+1];
        f(i,0,n){
            temp+=abs(tt-arr[i]);
            temp2+=abs(tr-arr[i]);
        }
        res=max(temp,temp2);
    }
    else{
        ll temp=0,temp2=0;
        int tt=arr[(n-1)/2];
        f(i,0,n){
            temp+=abs(tt-arr[i]);
        }
        res=temp;
    }
    printf("%lld\n",res);
}