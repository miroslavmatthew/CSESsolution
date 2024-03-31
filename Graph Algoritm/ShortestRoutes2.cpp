#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define ll long long
#define INF_INT 2e9
#define INF_LL 2e18
int main(){
    int n,m,q;scanf("%d %d %d",&n,&m,&q);
    ll arr[505][505];
    cf(i,1,n){
        cf(j,1,n){
            arr[i][j]=INF_LL;
            if (i==j)
            {
               arr[i][j]=0;
            }
            
        }
    }
    while (m--)
    {
        int a,b;
        ll c;scanf("%d %d %lld",&a,&b,&c);
        arr[a][b]=min(arr[a][b],c);
        arr[b][a]=min(arr[b][a],c);
    }
    cf(k,1,n)cf(i,1,n)cf(j,1,n)arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
    while (q--)
    {
        int x,y;scanf("%d %d",&x,&y);
        if (arr[x][y]==INF_LL)
        {
            printf("-1\n");
        }
        else printf("%lld\n",arr[x][y]);
    }
    
}
