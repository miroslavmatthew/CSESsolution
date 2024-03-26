#include<cstdio>
#include<cstring>
using namespace std;
long long arr[1000010]={0};
long long com[100];
int n;
long long rec(int a){
    if (arr[a]!=-1)
    {
        return arr[a]%1000000007;
    }
    else{
        for (int i =0; i < n; i++)
        {
            if (com[i]<=a)
            {
                arr[a]+=rec(a-com[i])%1000000007;   
            }
           
        }
        arr[a]+=1;
        return arr[a]%1000000007;
    }
    
}
int main(){
    memset(arr,-1,sizeof(long long)*1000010);
    arr[0]=1;
    long long res;

    scanf("%d %lld",&n,&res);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&com[i]);
    }
    printf("%lld\n",rec(res));

    
}