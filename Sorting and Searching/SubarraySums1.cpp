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
    int n,m;cin>>n>>m;
    vi arr;
    arr.push_back(0);
    cf(i,1,n){
        int a;cin>>a;
        arr.push_back(arr[i-1]+a);
    }
    int start = 1;
    int end = 1;
    int cnt =0;
    while (start<=n&&end<=n)
    {
        if (arr[end]-arr[start-1]<m)
        {
            end++;
        }
        else{
            if (arr[end]-arr[start-1]==m)
            {
                cnt++;
            }
           
            start++;
            
        }
    }
    cout<<cnt<<"\n";
}