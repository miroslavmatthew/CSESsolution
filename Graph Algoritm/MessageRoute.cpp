#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
queue<int> qw;
vector<int> arr[100010];
int isvis[100010]={0};
int n,m;
bool res=false;

void bfs(){
    qw.push(1);
    isvis[1]=1;
    while (!qw.empty())
    {
       if (qw.front()==n)
       {
            res=true;
            break;
       }
       for (int a= 0; a < arr[qw.front()].size(); a++)
        {
            if (isvis[arr[qw.front()][a]]==0)
            {
                qw.push(arr[qw.front()][a]);
                isvis[arr[qw.front()][a]]=qw.front();
            }
        }
       qw.pop();
    }
    
}
void pathprint(int x,int len){
    if (isvis[x]==x)
    {
       printf("%d\n",len+1);
       printf("1");
    }
    else{
        pathprint(isvis[x],len+1);
        printf(" %d",x);
    }
}

int main(){
   scanf("%d %d\n",&n,&m);
    for (int i = 0; i < m; i++)
    {
        int x,y;scanf("%d %d",&x,&y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    bfs();
    if (res)
    {
        pathprint(n,0);
    }
    else{
        printf("IMPOSSIBLE\n");
    }
    
}