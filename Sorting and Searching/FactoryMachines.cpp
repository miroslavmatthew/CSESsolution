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
vector<int> arr;
int n,k;
bool valid(ll x){
    ll cnt = 0;
    f(i,0,n){
        cnt+=x/arr[i];
    }
    if (cnt>=k)
    {
        return true;
    }
    else{
        return false;
    }
}
int main(){

    scanf("%d %d",&n,&k);
    ll z = INF_INT;
    f(i,0,n){
        ll a;scanf("%lld",&a);
        arr.push_back(a);
        z=min(z,a);
    }
    z*=k;
    ll x = -1;
    for (ll b = z; b >= 1; b /= 2) {
        while (!valid(x+b)) x += b; 
    }
    ll k = x+1;
    printf("%lld\n",k);
}