#include<cstdio>
#include<algorithm>
using namespace std;
int arr[550][550];

int dfs(int i,int j){
    if (arr[i][j]!=-1)
    {
        return arr[i][j];
    }
    else{
        arr[i][j]=250000;
       for (int q = 1; q <= i/2; q++)
       {
           arr[i][j]=min(arr[i][j],1+dfs(q,j)+dfs(i-q,j));
       }
       for (int q = 1; q <= j/2; q++)
       {
           arr[i][j]=min(arr[i][j],1+dfs(i,q)+dfs(i,j-q));
       }
        return arr[i][j];
    }
}
int main(){
    for (int i = 1; i <= 500; i++)
    {
       for (int j= 1; j <= 500; j++)
        {
            if (i==j)
            {
                arr[i][j]=0;

            }
            else if (i==1)
            {
               arr[i][j]=j-1;
            }
            else if (j==1)
            {
               arr[i][j]=i-1;
            }
            else{
                arr[i][j]=-1;
            }
            
        }
    }
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",dfs(a,b));
}