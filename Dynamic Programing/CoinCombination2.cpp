#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1000010];
int coin[101];
int n,b;


int main(){
    scanf("%d %d",&n,&b);
    arr[0]=1;
    for (int i = 1; i <=b; i++)
    {
        arr[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&coin[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j <=b; j++)
        {
            arr[j]=(arr[j]%1000000007+arr[j-coin[i]]%1000000007)%1000000007;
        }
        
    }
    
    printf("%d\n",arr[b]);

}