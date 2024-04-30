#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define INF_INT 2e9
#define ll long long
int par[550];
int adj[550][550];
int n;
ll bfs(int start,int end){
    memset(par,-1,sizeof(int)*550);
    int mins = INF_INT;
    queue<int> qw;
    qw.push(start);
    par[start]=start;
    bool iisem = false;
    while (!qw.empty())
    {
        int parent = qw.front();    
        if (parent==end)
        {
            iisem=true;
           break;
        }
        for (int i = 1; i <= n; i++)
        {
            if (adj[parent][i]>0&&par[i]==-1)
            {
                qw.push(i);
                par[i]=parent;
            }
        }
        qw.pop();
    }
    int ed = end;
    int pare = par[ed];
    while (iisem&&pare!=ed)
    {
        if (adj[pare][ed]<mins)
        {
            mins = adj[pare][ed];
        }
        ed = pare;
        pare = par[ed];
    }
    ed = end;
    pare = par[ed];
    while (iisem&&pare!=ed)
    {
        adj[pare][ed]-=mins;
        adj[ed][pare]+=mins;
        ed = pare;
        pare = par[ed];
        
    }
    return mins;
}
ll solve(int start,int end){
    ll sts = bfs(start,end);
    ll res = 0;
    while (sts!=INF_INT)
    {
        // printf("%d\n",sts);
        res+=sts;
        sts=bfs(start,end);
    }
    return res;
    
}
int main(){
    memset(adj,0,sizeof(int)*550*550);
    int q;
    scanf("%d %d",&n,&q);
    while (q--)
   {
        int a,b,wei;
        scanf("%d %d %d",&a,&b,&wei);
        if (a!=n)
        {
             adj[a][b]+=wei;
            adj[b][a]+=wei;
        }
   }        
    printf("%lld\n",solve(1,n));
}