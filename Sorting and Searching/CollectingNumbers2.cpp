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
    int arr[200002];
    int arr2[200002];
    int n,q;scanf("%d %d",&n,&q);
    arr[0]=0;
    arr[200001]=200001;
    int cnt=1;
    cf (i,1,n)
    {
        int a;scanf("%d",&a);
        arr[a]=i;
        arr2[i]=a;
    }
    cf(i,2,n){
        if (arr[i]<arr[i-1])
        {
            cnt++;
        }
    }
    while (q--)
    {
        bool idx = false;
        int cc = 0;
        int s,e;scanf("%d %d",&s,&e);
        bool res1 = false;
        bool res2 = false;
        if (arr[arr2[s]+1]>arr[arr2[s]])
        {
           res2=true;
        }
        if (arr[arr2[s]-1]<arr[arr2[s]])
        {
           res1=true;
        }
        bool res3 = false;
        bool res4 = false;
        if (arr[arr2[e]+1]>arr[arr2[e]])
        {
           res4=true;
        }
        if (arr[arr2[e]-1]<arr[arr2[e]])
        {
           res3=true;
        }

        int temp  = arr2[s];
        arr2[s]=arr2[e];
        arr2[e]=temp;
        arr[arr2[s]]=s;
        arr[arr2[e]]=e;
        bool rs1 = false;
        bool rs2 = false;
        if (arr[arr2[s]+1]>arr[arr2[s]])
        {
           rs2=true;
        }
        if (arr[arr2[s]-1]<arr[arr2[s]])
        {
           rs1=true;
        }
        bool rs3 = false;
        bool rs4 = false;
        if (arr[arr2[e]+1]>arr[arr2[e]])
        {
           rs4=true;
        }
        if (arr[arr2[e]-1]<arr[arr2[e]])
        {
           rs3=true;
        }
        if (res1!=rs1)
        {
            if (rs1)
            {
                idx=true;
            }
            
        }
        else{
            cc++;
        }
        if (res2!=rs2)
        {
            if (rs2)
            {
                idx=true;
            }
            
        } else{
            cc++;
        }
        if (res3!=rs3)
        {
            if (rs3)
            {
                idx=true;
            }
            
        } else{
            cc++;
        }
        if (res4!=rs4)
        {
            if (rs4)
            {
                idx=true;
            }
            
        } else{
            cc++;
        }
        if (cc!=4)
        {
             if (idx)
        {
            cnt--;
        }
        else{
            cnt++;
        }
        }
        printf("%d\n",cnt);
    }
    
    
}