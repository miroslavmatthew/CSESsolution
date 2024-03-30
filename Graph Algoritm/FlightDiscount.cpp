#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int> > arr[200000];
long long sortpath[200000];
priority_queue<pair<long long,int> , vector<pair<long long,int> >, greater<pair<long long,int> > > pq;
int n,m;
void djik(){
    pq.push(make_pair(0,0));
    while (!pq.empty())
    {
        long long dis  = pq.top().first;
        int par  = pq.top().second;
        pq.pop();
        if (sortpath[par]==-1)
        {
            sortpath[par]=dis;
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
    memset(sortpath,-1,sizeof(long long)*200000);
    while (m--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        arr[a-1].push_back(make_pair(b-1,c));
        arr[a-1+n].push_back(make_pair(b-1+n,c));
        arr[a-1].push_back(make_pair(b-1+n,c/2));
    }
    djik();
    printf("%lld\n",sortpath[n-1+n]);
    
    
}