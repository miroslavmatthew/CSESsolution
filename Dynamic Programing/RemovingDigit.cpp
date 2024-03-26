#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[1000001];
int dfs(int n){
    if (arr[n]!=-1)
    {
      return arr[n];
    }
    else{
        int x = n;
        arr[n]= 1000010;
        while (x>0)
        {
           arr[n]=min(arr[n],1+dfs(n-(x%10)));
            x/=10;
        }
        return arr[n];
        
    }
    
}

int main(){
    int n;scanf("%d",&n);
    memset(arr,-1,sizeof(int)*1000001);
    for (int i = 1; i <= 9; i++)
    {
        arr[i]=1;
    }
    printf("%d\n",dfs(n));
}