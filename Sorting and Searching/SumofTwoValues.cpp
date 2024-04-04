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
    vector<pair<int,int> > vii;
    int n,m;scanf("%d %d",&n,&m);
    cf(i,1,n){
        int a;scanf("%d",&a);
        vii.push_back(make_pair(a,i));
    }
    sort(all(vii));
    int l =0,r=n-1;
    bool res = false;
    while (l!=r)
    {
        if (vii[l].first+vii[r].first==m)
        {
            printf("%d %d\n",vii[l].second,vii[r].second);
            res=true;
            break;
        }
        else if (vii[l].first+vii[r].first>m)
        {
            r--;
        }
        else{
            l++;
        }
        
    }
    if (!res)
    {
        printf("IMPOSSIBLE\n");
    }
    
}