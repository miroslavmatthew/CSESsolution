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
    vector<pair<int,int> > res;
    while (n--)
    {
        int a,b;scanf("%d %d",&a,&b);
        res.push_back(make_pair(b,a));

    }
    int rs = 1;
    sort(all(res));
    int end = res[0].first;
    f(i,1,res.size()){
        if (res[i].second>=end)
        {
            rs++;
            end = res[i].first;
        }
        
    }
    printf("%d\n",rs);
}