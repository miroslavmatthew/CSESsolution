#include<cstdio>
#include <cstring>
#include<algorithm>
using namespace std;
int dp[5005][5005]={0};
char initsial[5005];
char sek[5005];
char sek2[5005];

int rec(int i,int j){
    if(dp[i][j]!=100000){
        return dp[i][j];
    }
    else if(i==0&&j==0) {
        return 0;
    }
    else{
        if (initsial[i-1]==sek[j-1])
        {
            dp[i][j]=0+rec(i-1,j-1);
        }
        else{
            dp[i][j]=min(1+rec(i-1,j-1),dp[i][j]);
            dp[i][j]=min(1+rec(i-1,j),dp[i][j]);
            dp[i][j]=min(1+rec(i,j-1),dp[i][j]);
        }
        return dp[i][j];
    }
    
}
int main(){
  
        fgets(initsial,5005,stdin);
       fgets(sek,5005,stdin);
       int a,b;
       
        b=strlen(sek)-1;
      
        a=strlen(initsial)-1;
       
       for (int i = 0; i < 5005; i++)
       {
        for (int j = 0; j < 5005; j++)
        {
            if (i==0)
            {
                dp[i][j]=j;
            }
            else if (j==0)
            {
                dp[i][j]=i;
            }
            else{
                dp[i][j]=100000;
            }
        }
       }
    //    printf("%d %da",a,b);
        printf("%d\n",rec(a,b));
    
    
}