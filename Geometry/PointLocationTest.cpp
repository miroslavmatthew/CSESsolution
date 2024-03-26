#include<cstdio>

int main(){
    int n;scanf("%d",&n);
    while (n--)
    {
       long long x1,y1,x2,y2,x3,y3;
       scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3);
        x2-=x1;
        y2-=y1;
        x3-=x1;
        y3-=y1; 
       long long res = (x2*y3)-(y2*x3);
       if (res>0)
       {
        printf("LEFT\n");
       }
       else if (res==0)
       {
        printf("TOUCH\n");
       }
       else{
        printf("RIGHT\n");
       }
       
    }
    
}