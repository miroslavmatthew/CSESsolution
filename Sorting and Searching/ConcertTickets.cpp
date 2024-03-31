#include<cstdio>
#include<algorithm>
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
    int n,m;scanf("%d %d",&n,&m);
    vector<int> arr;
    while (n--)
    {
        int a;scanf("%d",&a);
        arr.push_back(a*-1);
    }
    sort(all(arr));
    while (m--)
    {
        int b;scanf("%d",&b);
        vector<int>::iterator z = lower_bound(all(arr),b*-1);
        if (z==arr.end())
        {
            printf("-1\n");
        }
        else{
            printf("%d\n",-1*arr[z-arr.begin()]);
            arr[z-arr.begin()]=arr[z-arr.begin()+1];
        }
        
    }
    
}