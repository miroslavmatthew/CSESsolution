#include<cstdio>

int main(){
    int n;scanf("%d",&n);
    if (n==1)
    {
        printf("1\n");
    }
    else if(n<4){
        printf("NO SOLUTION\n");
    }
    else{
        printf("2");
         for (int i = 4; i <=n; i+=2)
        {
            printf(" %d",i);
        }
        for (int i = 1; i <=n; i+=2)
        {
            printf(" %d",i);
        }
        printf("\n");
    }
}