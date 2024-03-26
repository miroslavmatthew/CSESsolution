#include<cstdio>

int arr[1001][1001];
int rec(int i,int j){
    if (arr[i][j]!=-1)
    {
        return arr[i][j];
    }
    else{
        return arr[i][j]=(rec(i,j-1)%1000000007+rec(i-1,j)%1000000007)%1000000007;
    }

}


int main(){
    int n;scanf("%d\n",&n);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i==0||j==0)
            {
                arr[i][j]=0;
            }
            else{
                char x;scanf("%c\n",&x);
                if (x=='*')
                   {
                    arr[i][j]=0;
                    }
                    else{
                        if (i==1&j==1)
                        {
                            arr[i][j]=1;
                        }
                        else{
                            arr[i][j]=-1;
                        }
                    }
                
            } 
            
        }
    }
    printf("%d\n",rec(n,n));
}