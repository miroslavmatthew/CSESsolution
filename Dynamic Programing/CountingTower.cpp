#include<cstdio>

int arr[3][1000001];
int main(){
    for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                if (i==0||j==0)
                {
                    arr[i][j]= 0;
                }
                else{
                    arr[i][j]=1;
                    if (i==2&&j==2)
                    {
                        for (int z = 0; z < i; z++)
                    {
                        for (int q = 1; q <= j; q++)
                        {
                            printf("%d %d\n",arr[i-z][j-q],arr[i-(z+1)][q]);
                            arr[i][j]+=arr[i-z][j-q];
                            arr[i][j]+=arr[i-(z+1)][q];
                        }
                    } 
                    }
                    else{
                        for (int z = 0; z < i; z++)
                    {
                        for (int q = 1; q <= j; q++)
                        {
                            
                            arr[i][j]+=arr[i-z][j-q];
                            arr[i][j]+=arr[i-(z+1)][q];
                        }
                    } 
                    }
                    // for (int z = 0; z < i; z++)
                    // {
                    //     for (int q = 1; q <= j; q++)
                    //     {
                            
                    //         arr[i][j]+=arr[i-z][j-q];
                    //         arr[i][j]+=arr[i-(z+1)][q];
                    //     }
                    // }   
                }   
            }
        }
    int cnt ;scanf("%d",&cnt);
    while (cnt--)
    {
        int n;scanf("%d",&n);
        printf("%d\n",arr[2][n]);
    }
}