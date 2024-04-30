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
    int arrz[200001];
    vector<pair<int,int> > arr;
    vector<pair<int,int> > arr2;
    priority_queue<int, vector<int>, greater<int> > pq;
    f(i,0,n){
        pq.push(i+1);
        int s;scanf("%d",&s);
        arr.push_back(make_pair(s,i));

        int z;
        scanf("%d",&z);
        arr2.push_back(make_pair(z,i));
    }
    sort(all(arr));
    sort(all(arr2));
    int l=0,r=0;
    int cnt = 0;
    int res = 0;
    while (l!=n)
    {
        if (arr[l].first<=arr2[r].first)
        {
            arrz[arr[l].second]=pq.top();
            cnt++;
            l++;
            res = max(res,cnt);
            pq.pop();
        }
        else{
            pq.push(arrz[arr2[r].second]);
            r++;
            cnt--;
            res = max(res,cnt);
        }
        
    }
    printf("%d\n",res);
    f(i,0,n){
        printf("%d ",arrz[i]);
    }
    printf("\n");
}