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
    int arr2[200001];
    f(i,0,n){
        scanf("%d",&arr[i]);
        scanf("%d",&arr2[i]);
    }
    sort(arr,arr+n);
    sort(arr2,arr2+n);
    int l=0,r=0;
    int cnt = 0;
    int res = 0;
    while (l!=n)
    {
        if (arr[l]<arr2[r])
        {
            cnt++;
            l++;
            res = max(res,cnt);
        }
        else{
            r++;
            cnt--;
            res = max(res,cnt);
        }
        
    }
    printf("%d\n",res);
}