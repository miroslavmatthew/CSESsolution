#include<cstdio>
#include<vector>
#include<stack>
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
using namespace std;
int arr[100001]={0};
int par[100001]={0};
stack<int> st;
int n,z;
bool cnt  = 1;
vector<int> adj[100001];
void dfsrec(int x,int cc){
    arr[x]=cc;
    f(i,0,adj[x].size()){        
        if (par[adj[x][i]]!=0&&arr[x]-arr[adj[x][i]]>=1)
        {
            if (cnt)
            {
                st.push(adj[x][i]);
                int cr = x;
                int conter=0;
                while (cr!=adj[x][i])
                {
                    st.push(cr);
                    cr=par[cr];
                    conter++;
                    if (conter>z)
                    {
                        break;
                    }
                    
                }
                st.push(adj[x][i]);
                if (conter>z)
                {
                    st = stack<int>();
                }
                else{
                cnt=0;
                break;
                }
            }
            
        }
        else if (par[adj[x][i]]==0&&cnt)
        {
            par[adj[x][i]]=x;
            dfsrec(adj[x][i],cc+1);
        }
    }
    
}
void dfs(){
    for (int i = 1; i <= n; i++)
    {
        if (arr[i]==0)
        {
            par[i]=i;
            dfsrec(i,1);
        }
    }
    
}
int main(){
    int m;
    scanf("%d %d",&n,&m);
    z=m;
    while (m--)
    {
        int a,b;scanf("%d %d",&a,&b);
        adj[a].push_back(b);
    }
    dfs();
    if (st.size())
    {
       printf("%ld\n",st.size());
        while (!st.empty())
        {
            printf("%d ",st.top());
            st.pop();
        }
    }
    else{
        printf("IMPOSSIBLE\n");
    }
    
    
    
}