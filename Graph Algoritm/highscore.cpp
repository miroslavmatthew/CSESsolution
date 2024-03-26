#include <cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long star[2525];
long long cpy[2525];
vector<int> arr[2525];
int isV [2525]={0};
bool res [2525]={0};

int x, y;
bool cek = false;
bool dfs(int n,bool x){
    isV[n]=true;
        for (int i = 0; i < arr[n].size(); i++)
        {
            if (!isV[arr[n][i]])
            {
                if (x)
                {
                    res[arr[n][i]]=true;
                    return dfs(arr[n][i],true);
                }
               if (cpy[arr[n][i]]!=star[arr[n][i]])
               {
                res[arr[n][i]]=true;
                    return dfs(arr[n][i],true);
               }
               else{
                res[arr[n][i]]=false;
                return dfs(arr[n][i],false);
               }
            }
        } 
    
}

int main()
{
        
        scanf("%d %d", &x, &y);
        
        for (int j = 1; j < x; j++)
        {
            star[j] = 0;
        }
        star[1]=0;
        bool isvis[2525];
        
        
        star[0] = 0;
        int a[y];
        int b[y];
        int weight[y];
        for (int j = 0; j < y; j++)
        {
            scanf("%d %d %d", &a[j], &b[j], &weight[j]);
            weight[j]*=-1;
            arr[a[j]].push_back(b[j]);
        }
        for (int z = 0; z < x; z++)
        {
            for (int j = 0; j < y; j++)
            {
                if (!isvis[b[j]])
                {
                    isvis[b[j]]=1;
                    star[b[j]]=star[a[j]]+weight[j];
                }
                else{
                    if (star[a[j]] + weight[j] < star[b[j]])
                    {
                        star[b[j]] = star[a[j]] + weight[j];
                    }
                }
                
            }
        }
        for (int i = 1; i <= x; i++)
        {
            cpy[i]=star[i];
        }
        long long maxi = star[x];
        for (int j = 0; j < y; j++)
        {
            if (star[a[j]] + weight[j] < star[b[j]])
            {
                star[b[j]] = star[a[j]] + weight[j];
            }
        }
        if (res[x])
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n",maxi*-1);
        }
    
}