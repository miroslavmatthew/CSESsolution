#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define all(x) x.begin(), x.end()
#define ll long long
#define INF_INT 2e9
#define INF_LL 2e18
int main(){
    int n,m;scanf("%d %d",&n,&m);
    multiset<int> arr;
    int ar[200001];
    int cnt = 0;
    f(i,0,n)
    {
        int a;scanf("%d",&a);
        arr.insert(a);
        ar[i]=a;
    }
    f(i,0,n){
        auto z=arr.lower_bound(ar[i]);
        arr.erase(z);
        z=arr.upper_bound(m-ar[i]);
        if (z==arr.begin())
        {
            cnt++;
        }
        else{
            cnt++;
            --z;
            arr.erase(z);
        }
    }
    printf("%d\n",cnt);
    
}