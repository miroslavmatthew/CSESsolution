#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;
queue<pair<pair<int,int> ,char> > qw;
vector<pair<int,int> > mons;
bool res = false;
bool isvis[1000][1000];
bool isvis2[1000][1000];
int par[1000][1000];
int moved[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
int a1,a2;
int b1,b2;
bool legal (int i,int j){
    if(i>=0&&i<n&&j>=0&&j<m){
        return true;
    }
    return false;
}
char toMove(int i){
    if (i==0)
    {
        return 'D';
    }
    else if (i==1)
    {
        return 'U';
    }
    else if (i==2)
    {
        return 'R';
    }
    else 
    {
        return 'L';
    }
}

void bfs(){
    qw.push(make_pair(make_pair(a1,a2),'A'));
    isvis[a1][a2]=1;
    for (int i = 0; i < mons.size(); i++)
    {
        isvis[mons[i].first][mons[i].second]=1;
        isvis2[mons[i].first][mons[i].second]=1;
        qw.push(make_pair(make_pair(mons[i].first,mons[i].second),'M'));
    }
    
    while (!qw.empty())
    {
        int i=qw.front().first.first;
        int j=qw.front().first.second;
        char typ = qw.front().second;
       if (typ=='A'&&(i==n-1||j==m-1||i==0||j==0)&&!isvis2[i][j])
       {
            res=true;
            b1=i;
            b2=j;
            break;
       }
       for (int a= 0; a < 4; a++)
        {
            if (typ=='A')
            {
                if (!isvis2[i][j])
                {
                     if (legal(i+moved[a][0],j+moved[a][1])&&!isvis[i+moved[a][0]][j+moved[a][1]])
                    {
                        qw.push(make_pair(make_pair(i+moved[a][0],j+moved[a][1]),'A'));
                        isvis[i+moved[a][0]][j+moved[a][1]]=1;
                        par[i+moved[a][0]][j+moved[a][1]]=a;
                    }
                }
            }
            else{
                if (legal(i+moved[a][0],j+moved[a][1])&&!isvis2[i+moved[a][0]][j+moved[a][1]])
                {
                    qw.push(make_pair(make_pair(i+moved[a][0],j+moved[a][1]),'M'));
                    isvis2[i+moved[a][0]][j+moved[a][1]]=1;
                    isvis[i+moved[a][0]][j+moved[a][1]]=1;
                }
            }
            
            
        }
       qw.pop();
    }
    
}

void pathprint(int x,int y,int len){
    if (x==a1&&y==a2)
    {
       printf("%d\n",len);
    }
    else{
        pathprint(x-moved[par[x][y]][0],y-moved[par[x][y]][1],len+1);
        printf("%c",toMove(par[x][y]));
    }
}
int main(){
   scanf("%d %d\n",&n,&m);
    memset(isvis,0,sizeof(bool)*1000000);
    memset(isvis2,0,sizeof(bool)*1000000);
    memset(par,-1,sizeof(int)*1000000);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;scanf("%c\n",&c);
            if (c=='A')
            {
               a1=i;
               a2=j;
            }
            else if (c=='M')
            {
               mons.push_back(make_pair(i,j));
            }
            else if(c!='.'){
                isvis[i][j]=1;
                isvis2[i][j]=1;
            }
            
        }
        
    }
    bfs();
    if (res)
    {
        printf("YES\n");
        pathprint(b1,b2,0);
    }
    else{
        printf("NO\n");
    }
    
}