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
char arr[50];
bool adj[9][9];
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int rs = 0;
bool valid(int i,int j,int n){
    if (i>=1&&i<=7&&j>=1&&j<=7)
    {
        if (i==7&&j==1&&n!=48)
        {
            return false;
        }
        
        return true;
    }
    else{
        return false;
    }
}
void res(int n,int i,int j){
        // printf("%d %d\n",i,j);
    if (n==48)
    {
        if (i==7&&j==1)
        {
            rs++;
        }
        
    }
    else{
        if (arr[n]=='L')
        {
            if (valid(i,j-1,n+1)&&!adj[i][j-1])
            {
                adj[i][j-1]=true;
                res(n+1,i,j-1);
                adj[i][j-1]=false;
            }
        }
        else if (arr[n]=='R')
        {
            if (valid(i,j+1,n+1)&&!adj[i][j+1])
            {
                adj[i][j+1]=true;
                res(n+1,i,j+1);
                adj[i][j+1]=false;
            }
        }
        else if (arr[n]=='U')
        {
            if (valid(i-1,j,n+1)&&!adj[i-1][j])
            {
                adj[i-1][j]=true;
                res(n+1,i-1,j);
                adj[i-1][j]=false;
            }
        }
        else if (arr[n]=='D')
        {
            if (valid(i+1,j,n+1)&&!adj[i+1][j])
            {
                adj[i+1][j]=true;
                res(n+1,i+1,j);
                adj[i+1][j]=false;
            }
        }
        else{
            f(x,0,4){
                if (valid(i+moves[x][0],j+moves[x][1],n+1)&&!adj[i+moves[x][0]][j+moves[x][1]])
                {
                   adj[i+moves[x][0]][j+moves[x][1]]=true;
                    res(n+1,i+moves[x][0],j+moves[x][1]);
                    adj[i+moves[x][0]][j+moves[x][1]]=false;

                }
            }
        }
    }
    
}
int main(){
    scanf("%s\n",arr);
    cf(i,0,8){
        cf(j,0,8){
            adj[i][j]=false; 
        }
    }
    adj[1][1]=true;
    res(0,1,1);
    printf("%d\n",rs);
}