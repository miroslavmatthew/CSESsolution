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
#define ll long long
#define INF_INT 2e9
#define INF_LL 2e18
int main(){
    int n;
    scanf("%d",&n);
    set<int> st;
    while (n--)
    {
        int a;scanf("%d",&a);
        st.insert(a);
        
    }
    printf("%lu\n",st.size());
}