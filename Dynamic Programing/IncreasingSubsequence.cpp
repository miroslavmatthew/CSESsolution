#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> res;
int arr[200001];
int num[200001];
int n;
int mz=1;
// void lis(int z){
//     for (int i = 0; i < z; i++)
//     {
//        for (int j = 0; j < i; j++)
//        {
//         if (num[j]<num[i])
//         {
//             arr[i]=max(arr[i],1+arr[j]);
//         }
//         mz=max(mz,arr[i]);
//        }
//     }
    
// }

int lisBin(){

    for (int i = 0; i < n; i++)
    {
        vector<int>::iterator idx = lower_bound(res.begin(),res.end(),num[i]);
       if (idx==res.end())
       {
            res.push_back(num[i]);
       }
       else{
            res[idx-res.begin()]=num[i];
       }
    }
    return res.size();
}

int main(){

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        arr[i]=1;
        scanf("%d",&num[i]);
    }
    // lis(n);
    printf("%d\n",lisBin());
}