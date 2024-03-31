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
#define ll long long
#define INF_INT 2e9
#define INF_LL 2e18
int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    int arr[200001];
    int rm[200001];
    f(i,0,n)scanf("%d",&arr[i]);
    f(i,0,m)scanf("%d",&rm[i]);
    sort(arr,arr+n);
    sort(rm,rm+m);
    int cnt=0;
    int i = 0, j = 0;
	while (i < n && j < m) {
		if (abs(arr[i] - rm[j]) <= q) {
			i++;
            j++;
            cnt++;
		} else {
			if (arr[i] - rm[j] > q) {
				j++;
			}
			else {
				i++;
			}
		}
	}
    printf("%d\n",cnt);
}