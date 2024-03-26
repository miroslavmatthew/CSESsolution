#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
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
    printf("%d\n",kelompok-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",kel[i]);
    }
    
}