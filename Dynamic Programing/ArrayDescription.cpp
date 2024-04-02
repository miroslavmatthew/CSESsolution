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
int arr[100002][102];
int req[100002];

int solve(int i,int j){
    if (arr[i][j]!=-1)
    {
        return arr[i][j];
    }
    else{
        arr[i][j]=0;
        arr[i][j]=(arr[i][j]%MOD+solve(i-1,j-1)%MOD)%MOD;
        arr[i][j]=(arr[i][j]%MOD+solve(i-1,j)%MOD)%MOD;
        arr[i][j]=(arr[i][j]%MOD+solve(i-1,j+1)%MOD)%MOD;
        return arr[i][j];
    }
    
}


int main(){
    int n,m;scanf("%d %d",&n,&m);
    cf(i,1,n)scanf("%d",&req[i]);
    cf(i,0,n+1){
        bool cek = req[i]!=0;
        cf(j,0,m+1){
            if (j==0||i==0||j==m+1||i==n+1)
            {
                arr[i][j]=0;
            }
            else{
                if (cek)
                {
                    if (i==1&&req[i]==j)
                    {
                        arr[i][j]=1;
                    }
                    else if (req[i]!=j){
                        arr[i][j]=0;
                    }
                    else{
                        arr[i][j]=-1;
                    }
                }
                else{
                    if (i==1)
                    {
                        arr[i][j]=1;
                    }
                    else{
                        arr[i][j]=-1;
                    }
                } 
            }
            // printf("%d ",arr[i][j]);
        }
        // printf("\n");
    }
    int res = 0;
    if (req[n]==0)
    {
        cf(i,1,m){
            res=(res%MOD+solve(n,i)%MOD)%MOD;
        }
    }
    else{
        res+=solve(n,req[n]);
    }
    printf("%d\n",res);


}