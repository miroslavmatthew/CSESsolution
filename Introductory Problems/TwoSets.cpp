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
    ll tot = 0;
    cf(i,1,n){
        tot+=i;
    }
    if (tot%2==0)
    {
        ll a = tot/2;
        vector<int> satu;
        vector<int> dua;
        rf(i,n+1,1){
            if (a>=i)
            {
                a-=i;
                satu.push_back(i);
            }
            else{
                dua.push_back(i);
            }
            
        }
        printf("YES\n");
        printf("%lu\n",satu.size());
        f(i,0,satu.size()){
            printf("%d ",satu[i]);
        }
        printf("\n");
        printf("%lu\n",dua.size());
        f(i,0,dua.size()){
            printf("%d ",dua[i]);
        }
        printf("\n");
    }
    else{
        printf("NO\n");
    }
    
}