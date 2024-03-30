#include<cstdio>

int rec(int n){
    if (n==0)
    {
        return 1;
    }
    return (2%1000000007*rec(n-1)%1000000007)%1000000007;

}


int main(){
    int n;scanf("%d",&n);
    printf("%d\n",rec(n));
}