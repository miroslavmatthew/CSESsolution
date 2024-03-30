#include<cstdio>
#include<vector>
using namespace std;
int arr[100001]={0};
int n;
vector<int> adj[100001];
vector<int > vi;
int cnt = 0;
void dfsrec(int j){
    for (int i = 0; i < adj[j].size(); i++)
    {
        if (arr[adj[j][i]]==0)
        {
            arr[adj[j][i]]=cnt;
            dfsrec(adj[j][i]);
        }
        
    }
    
}

void dfs(){
    for (int i = 1; i <=n; i++)
    {
        if (arr[i]==0)
        {
            vi.push_back(i);
            cnt++;
            arr[i]=cnt;
            dfsrec(i);
        }
        
    }
    printf("%d\n",cnt-1);
    for (int i = 0; i < vi.size()-1; i++)
    {
        printf("%d %d\n",vi[i],vi[i+1]);
    }
    
}


int main(){
    scanf("%d",&n);
    int e;scanf("%d",&e);
    while (e--)
    {
        int a,b;scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    
   
    
    
}