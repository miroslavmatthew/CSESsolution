#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int> > arr[100000];
long long sortpath[100000];
priority_queue<pair<long long,int> , vector<pair<long long,int> >, greater<pair<long long,int> > > pq;
int n,m;
void djik(int a){
    pq.push(make_pair(0,0));
    int b = a;
    while (!pq.empty())
    {
        long long dis  = pq.top().first;
        int par  = pq.top().second;
        pq.pop();
        if (sortpath[par]==-1)
        {
            sortpath[par]=dis;b--;
            if (b==0)
            {
                break;
            }
            for (int i = 0; i < arr[par].size(); i++)
            {
                long long res = arr[par][i].second+dis;
                pq.push(make_pair(res,arr[par][i].first)); 
            }
        }
    }
}


int main(){
    scanf("%d %d",&n,&m);
    memset(sortpath,-1,sizeof(long long)*100000);
    while (m--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        arr[a-1].push_back(make_pair(b-1,c));
    }
    djik(n);
    for (int i = 0; i <n; i++)
    {
        printf("%lld ",sortpath[i]);
    }
    
}