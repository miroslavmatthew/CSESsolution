#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
#define setB(a,i) (a |= (1 << i))
#define unsetB(a,i) (a &= (~(1 << i)))
#define queryB(a,i) (a & (1 << i))
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define all(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define INF_INT 2e9
#define INF_LL 2e18
#define MOD 1000000007


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll arr[55];
    arr[0]=0;
    cf(i,1,50){
        arr[i]=arr[i-1]*2+(1<<(i-1));
    }
    ll n;cin>>n;
    int cc =1;
    ll cnt =1;
    while(cnt<<1<=n)
    {
        cnt<<=1; 
        cc++;
    }
    if (n==(cnt<<1)-1)
    {
        cout << arr[cc]<<'\n';
    }
    else{
        ll res = arr[cc-1];
        n-=cnt-1;
        while (n>1)
        {
            cc=1;
            cnt=1;
            while(cnt<<1<=n)
            {
                cnt<<=1; 
                cc++;
            }
            cout<<cnt;
            n-=cnt;
            res+=arr[cc-1]+1*(cnt);
        }
        
        
        cout<<res<<"\n";     
    }
}