#include<cstdio>
#include<algorithm>
using namespace std;
int resp;
int cross(long long x2,long long y2,long long x3,long long y3){
     long long res = (x2*y3)-(y2*x3);
       if (res>0)
       {
        return 3;
       }
       else if (res==0)
       {
        if (x2!=0&&x3>=min(x2,(long long)0)&&x3<=max(x2,(long long)0))
        {
            resp=true;
        }else if(x2==0&&y3>=min(y2,(long long)0)&&y3<=max(y2,(long long)0)){
            resp=true;
        }
        return 5;
       }
       
       else{
        return -3;
       }
}

int main(){
    int n;scanf("%d",&n);
    while (n--)
    {
        resp=false;
       long long x1,y1,x2,y2,x3,y3,x4,y4;
       scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        int first = cross(x2-x1,y2-y1,x3-x1,y3-y1)+cross(x2-x1,y2-y1,x4-x1,y4-y1);
        int sec = cross(x4-x3,y4-y3,x1-x3,y1-y3)+cross(x4-x3,y4-y3,x2-x3,y2-y3);
        if (resp||(first==0&&sec==0))
        {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        
    }
    
}