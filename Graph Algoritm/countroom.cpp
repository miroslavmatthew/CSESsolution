#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;
vector<pair <int,int> > vc;
bool isvis[1000][1000];
int moved[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
bool legal (int i,int j){
    if(i>=0&&i<n&&j>=0&&j<m){
        return true;
    }
    return false;
}
void dfsrec(int i,int j){
    isvis[i][j]=1;
    for (int a= 0; a < 4; a++)
    {
        if (legal(i+moved[a][0],j+moved[a][1])&&!isvis[i+moved[a][0]][j+moved[a][1]])
        {
            dfsrec(i+moved[a][0],j+moved[a][1]);
        }
    }
    
}

int dfs(){
    int res=0;
    for (int i = 0; i < vc.size(); i++)
    {
        if (!isvis[vc[i].first][vc[i].second])
        {
            res++;
            dfsrec(vc[i].first,vc[i].second);
        }
    }
    return res;
}
int main(){
   scanf("%d %d\n",&n,&m);
   char arr[1000][1000];
    memset(isvis,0,sizeof(bool)*1000000);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;scanf("%c\n",&c);
            if (c=='.')
            {
                vc.push_back(make_pair(i,j));
            }
            else{
                isvis[i][j]=1;
            }
            
        }
        
    }
    printf("%d\n",dfs());
}