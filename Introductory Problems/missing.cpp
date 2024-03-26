#include<cstdio>

int main(){
    long long arr[200200]={0};
    arr[1]=1;
    for (int i = 2; i <= 200000; i++)
    {
        arr[i]=arr[i-1]+i;
    }
    
    int n;scanf("%d",&n);
    long long total = 0;
    for (int i = 0; i < n-1; i++)
    {
       int s;scanf("%d",&s);
       total+=s;
    }
    printf("%lld\n",arr[n]-total);
}