#include <cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define INF_LL 2e18
long long star[2525];
long long cpy[2525];
vector<int> arr[2525];
int isV [2525]={0};
bool res [2525]={0};
bool fir=1;
int x, y;
bool cek = false;
void dfsrec(int n,bool r){
    for(int i =0;i<arr[n].size();i++){
        if(star[n]!=cpy[n]){
            if(fir){
                fir=0;
                memset(isV,0,sizeof(int)*2525);
            }
            res[n]=1;
            if(!isV[arr[n][i]]){
            isV[arr[n][i]]=1;
            dfsrec(arr[n][i],1);
            }
            res[arr[n][i]]=1;
        }
        else{
            if(!isV[arr[n][i]]){
                isV[arr[n][i]]=1;
                dfsrec(arr[n][i],r);
            }
            else if(r==1){

            }
            res[arr[n][i]]|=r;
        }
    }
}
void dfs(){
    isV[1]=1;
    dfsrec(1,0);
}

int main()
{
        scanf("%d %d", &x, &y);
        for (int j = 1; j <= x; j++)
        {
            star[j] = INF_LL;
        }
        star[1]=0;
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
                star[b[j]]=min(star[b[j]],weight[j]+star[a[j]]);
            }
        }
        for (int i = 1; i <= x; i++)
        {
            cpy[i]=star[i];
        }
        long long maxi = star[x];
        for (int j = 0; j < y; j++)
        {
            star[b[j]]=min(star[b[j]],weight[j]+star[a[j]]);
        }
        dfs();
        if (res[x])
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n",maxi*-1);
        }
    
}