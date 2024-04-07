#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define setB(a,i) (a |= (1 << i))
#define unsetB(a,i) (a &= (~(1 << i)))
#define queryB(a,i) (a & (1 << i))
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define all(x) x.begin(), x.end()
#define ll long long
#define INF_INT 2e9
#define INF_LL 2e18
#define MOD 1000000007
int main(){
    int n;scanf("%d",&n);
    while (n--)
    {
        int a;scanf("%d",&a);
        int cnt = 0;
        bool r = false;
        for (int i = 1; i*i <= a; i++)
        {
            if (a%i==0)
            {
                cnt++;
            }
            if (i*i==a)
            {
               r=true;
            }
            
        }
        if (r)
        {
            printf("%d\n",(cnt*2)-1);
        }
        else{
            printf("%d\n",(cnt*2));
        }
    }
    
}