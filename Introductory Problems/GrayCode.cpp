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
char arr[17];
int n;
void rec(int a,bool res){
    if (a==n)
    {
        arr[a]='\0';
        printf("%s\n",arr);
    }
    else{
        if (res)
        {
            arr[a]='0';
            rec(a+1,true);
            arr[a]='1';
            rec(a+1,false);
        }
        else{
            arr[a]='1';
            rec(a+1,true);
            arr[a]='0';
            rec(a+1,false);
        }
    }
    
}

int main(){
    scanf("%d",&n);
    rec(0,true);
}