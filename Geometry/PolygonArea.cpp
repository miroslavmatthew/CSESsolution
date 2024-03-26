#include<cstdio>
#include<algorithm>
using namespace std;
long long cross(long long x2,long long y2,long long x3,long long y3){
     return (x2*y3)-(y2*x3); 
}
int main(){
    int n;scanf("%d",&n);
    long long  x,y;scanf("%lld %lld",&x,&y);
    long long x2,y2;
    long long a,b;
    scanf("%lld %lld",&x2,&y2);
    scanf("%lld %lld",&a,&b);
    long long res = cross(x2-x,y2-y,a-x,b-y);
    for (int i = 0; i < n-3; i++)
    {
        x2=a;
        y2=b;
        scanf("%lld %lld",&a,&b);
        res += cross(x2-x,y2-y,a-x,b-y);
    }
    printf("%lld\n",abs(res));
}
