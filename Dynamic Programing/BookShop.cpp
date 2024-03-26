#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[100010];
int page[1001];
int price[1001];


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    memset(arr,0,sizeof(int)*100010);
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&price[i]);
    }
     for (int i = 0; i < n; i++)
    {
       scanf("%d",&page[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m-price[i]; j >=0; j--)
        {
            arr[j+price[i]]=max(arr[j+price[i]],page[i]+arr[j]);
        }
        
    }
    
    printf("%d\n",arr[m]);
}