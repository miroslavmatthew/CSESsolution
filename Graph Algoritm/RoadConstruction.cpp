#include<stdio.h>
#include<utility>
#include<vector>
#include<math.h>
#include<algorithm>
#include<cstring>

using namespace std;
typedef pair<int, int> ii;

class DisjointSets{
	public:
	int N;
	int *rank, *parent;

	DisjointSets(int N){
		this->N = N;
		rank = new int[N];
		parent = new int[N];
		for(int i=0; i<N; i++){
			parent[i] = i;
			rank[i] = 0;
		}
	}

	~DisjointSets(){
		delete[] rank;
		delete[] parent;
	}

	int find(int x){
		while(x != parent[x])
			x = parent[x];

		return x;
	}

	void unionSet(int x, int y){
		if(rank[x]<rank[y])
			parent[x] = y;
		else if(rank[x]>rank[y])
			parent[y] = x;
		else{
			parent[x] = y;
			rank[y]++;
		}
	}
};
int arr[100001];
int main(){
    int n,m;scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        arr[i]=1;
    }
    
    DisjointSets sets(n);
    int maxi = 1;
    int set = n;
    while (m--)
    {
        int a,b;scanf("%d %d",&a,&b);

        int ab=sets.find(a-1);
        int bc = sets.find(b-1);
        if (ab!=bc)
        {
            sets.unionSet(ab,bc);
            set--;
            arr[bc]+=arr[ab];
            arr[ab]=arr[bc];
            maxi = max(maxi,arr[bc]);
            
        }
        printf("%d %d\n",set,maxi);
        
    }
    
}