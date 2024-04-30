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
    int n;
    ll m;scanf("%d %lld",&n,&m);
    cf(i,1,n){
        int a;scanf("%d",&a);
        vii.push_back(make_pair(a,i));
    }
    sort(all(vii));
    int l =0,mid=1,r=n-1;
    bool res = false;
    int cnt = 0;
    while (l<mid&&mid<r)
    {
        if (vii[l].first+vii[mid].first+vii[r].first==m)
        {
            printf("%d %d %d\n",vii[l].second,vii[mid].second,vii[r].second);
            res=true;
            break;
        }
        else if (vii[l].first+vii[mid].first+vii[r].first>m)
        {
            if (mid==l+1)
            {
                r--;
                cnt=0;
            }
            else{
                if (cnt!=1)
                {
                    cnt=2;
                    mid--;
                }
                else{
                    break;
                }
                
            }
        }
        else{
            if (mid==r-1)
            {
                l++;
                cnt=0;
            }
            else{
                if (cnt!=2)
                {
                    cnt=1;
                    mid++;
                }
                else{
                    break;
                }
            }
        }
        
    }
    if (!res)
    {
        printf("IMPOSSIBLE\n");
    }
    
}