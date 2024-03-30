#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
stack<int> st;
int isVisit[100001]={0};
int isVisit2[100001]={0};

int n,m;
bool can=true;
vector<int> adj[100001];
void dfsrec(int z){
   isVisit[z]=1;
   for (int i = 0; i < adj[z].size(); i++)
   {
        if (isVisit[adj[z][i]]&&!isVisit2[adj[z][i]])
        {
            can=false;
        }
        else if (!isVisit[adj[z][i]])
        {
            dfsrec(adj[z][i]);
        }
   }
    st.push(z);
   isVisit2[z]=1;
}

void dfsa(){
    for (int i = 1; i <= n; i++)
    {
        if (!isVisit[i])
        {
           dfsrec(i);
        }
        
    }
    
}
int main(){
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        int a,b;scanf("%d %d",&a,&b);
        adj[a].push_back(b);
    }
    dfsa();
    if (can)
    {
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