#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    while (n--)
    {
        int a,b;scanf("%d %d",&a,&b);
        long long mak = max(a,b);
        long long sel = a-b;
        long long mar = (mak*mak)-(mak-1);
        if (sel>0)
        {
            if (mak%2==0)
            {
               printf("%lld\n",mar+sel);
            }
            else{
                printf("%lld\n",mar-sel);
            }
        }
        else{
            if (mak%2==0)
            {
               printf("%lld\n",mar-sel*-1);
            }
            else{
                printf("%lld\n",mar+sel*-1);
            }
        }
        
    }
    
}