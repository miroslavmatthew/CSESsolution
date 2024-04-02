#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define all(x) x.begin(), x.end()
#define ll long long
#define INF_INT 2e9
#define INF_LL 2e18
int main(){
    int n;scanf("%d",&n);
    int res = 0;
    int cnt = 1;
    while (n>=pow(5,cnt))
    {
        cnt++;
    }
    f(i,1,cnt){
        res+=n/(pow(5,i));
    }
    printf("%d\n",res);
}