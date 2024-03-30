#include<cstdio>
#include<cstdlib>
int main(){

    int n;scanf("%d",&n);
    long long total  =0;
    int a;
    scanf("%d",&a);
    for (int i = 1; i < n; i++)
    {
        int b;scanf("%d",&b);
        if (b<a)
        {
           total+=abs(a-b);
        }
        else{
            a=b;
        }
    }
    printf("%lld\n",total);
}