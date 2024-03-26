#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long arr[1000010];
int com[100];
int n;
long long rec(int a){
    if (arr[a]!=-1)
    {
        return arr[a];
    }
    else{
        arr[a]=1000001;
        for (int i =0; i < n; i++)
        {
            if(com[i]<=a){
                arr[a]=min(arr[a],1+rec(a-com[i]));
            }
        }
        return arr[a];
    }
    
}
int main(){
    int res;
    memset(arr,-1,sizeof(long long)*1000010);
    arr[0]=0;
    scanf("%d %d",&n,&res);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&com[i]);
    }
    int ress = rec(res);
    if (ress>=1000001)
    {
        printf("-1\n");
    }
    else{
        printf("%lld\n",rec(res));

    }
}