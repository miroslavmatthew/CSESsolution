#include<cstdio>
long long arr[1000010]={0};
long long rec(int n){
    if (arr[n]!=0)
    {
        return arr[n]%1000000007;
    }
    else{
        for (int i =1; i <= 6; i++)
        {
            if (i>n)
            {
                break;
            }
            else{
                arr[n]+=rec(n-i)%1000000007;
            }
        }
        return arr[n]%1000000007;
    }
    
}
int main(){
    arr[0]=1;
    arr[1]=1;
    int a;
    scanf("%d",&a);
    printf("%lld\n",rec(a));
}