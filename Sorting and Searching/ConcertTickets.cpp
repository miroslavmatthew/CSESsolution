#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define all(x) x.begin(), x.end()
#define ll long long
#define INF_INT 2e9
#define INF_LL 2e18
int main(){
    int n,m;scanf("%d %d",&n,&m);
    multiset<int> arr;
    while (n--)
    {
        int a;scanf("%d",&a);
        arr.insert(a);
    }
    while (m--)
    {
        int b;scanf("%d",&b);
        auto z=arr.upper_bound(b);
        if (z==arr.begin())
        {
            printf("-1\n");
        }
        else{
            printf("%d\n",*(--z));
            arr.erase(z);
        }
        
    }
    
}