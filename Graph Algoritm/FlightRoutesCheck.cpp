#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define ll long long
#define INF_INT 2e9
#define INF_LL 2e18
int n;
int kelompok = 1;
vector<int> adj[100000];
vector<int> adj2[100000];
int kel[100000]={0};
bool isvisit[100000]={0};
stack<int> stk;
void dfsrec(int x){
    isvisit[x]=true;
    for (int i = 0; i < adj[x].size(); i++)
    {
        if (!isvisit[adj[x][i]])
        {
            dfsrec(adj[x][i]);
        }
    }
    stk.push(x);
}
void dfs(){
    for (int i = 0; i < n; i++)
    {
        if (!isvisit[i])
        {
           dfsrec(i);
        }
    }
}

void sccrec(int x,int kelompok){
    kel[x]=kelompok;
    for (int i = 0; i < adj2[x].size(); i++)
    {
        if (kel[adj2[x][i]]==0)
        {
            sccrec(adj2[x][i],kelompok);
        }
    }
}
void scc(){
    while (!stk.empty())
    {
        if (kel[stk.top()]==0)
        {
            sccrec(stk.top(),kelompok);
            kelompok++;
        }
        stk.pop();
    }
}

int main(){
    int m;
    bool ty=0;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a-1].push_back(b-1);
        adj2[b-1].push_back(a-1);

    }    
    dfs();
    scc();
    if (kelompok-1!=1)
    {
        printf("NO\n");
        for (int i = 0; i < n; i++)
        {
            f(j,0,adj[i].size()){
                if (kel[i]!=kel[adj[i][j]])
                {
                    printf("%d %d\n",adj[i][j]+1,i+1);
                    ty=1;
                    break;
                }
                
            }
            if(ty){
                break;
            }
        }
        if (!ty)
        {
            f(i,1,n){
                if (kel[0]!=kel[i])
                {
                    printf("%d %d\n",1,i+1);
                    break;
                }
                
            }
        }
        
    }
    else{
        printf("YES\n");
    }
    
    
}