#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int n;
int coin[1000];
vector<int> res;
int arr[100010];
int memo[105][100010];
void rec(int z , int q){
    // printf("%d %d\n",z,q);
    if (z==n)
    {
        if (arr[q]==-1)
        {
           arr[q]=1;
            res.push_back(q);
        }
    }
    else{
        if(memo[z][q] == -1){
            memo[z][q] = 1;
            rec(z+1,q+coin[z]);
            rec(z+1,q);
        }
    }
}

int main(){
    memset(arr,-1,sizeof(int)*100010);
    scanf("%d",&n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&coin[i]);
       total += coin[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= total; j++){
            memo[i][j] = -1;
        }
    }
    rec(0,0);
    sort(res.begin(),res.end());
    printf("%lu\n",res.size()-1);
    for (int i = 1; i < res.size(); i++)
    {
        printf("%d ",res[i]);
    }
    printf("\n");
}