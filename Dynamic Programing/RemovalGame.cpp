#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int bil[5000];
long long arr[5000][5000];

long long rec(int i,int j){
    if (arr[i][j]!=-1)
    {
       return arr[i][j];
    }
    else if (i>j)
    {
        return 0;
    }
    else{
        arr[i][j]=-5000000000001;
        arr[i][j]=max(arr[i][j],(bil[i]-rec(i+1,j)));//ambil awal musuh awal
        arr[i][j]=max(arr[i][j],(bil[j]-rec(i,j-1)));//ambil akhir musuk akhir        
        return arr[i][j];
    }
    
}

int main(){
    scanf("%d",&n);
    long long tot = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&bil[i]);
        tot+=bil[i];
        for (int j = 0; j < n; j++)
        {
           arr[i][j]=-1;
        }
        
    }
    printf("%lld\n",(tot+rec(0,n-1))/2);
}