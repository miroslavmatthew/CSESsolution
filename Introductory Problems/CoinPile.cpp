#include<cstdio>
bool binarySearch (int i ,int j , int res,int target){
    if (i>j)
    {
        return false;
    }
    else{
        int mid = (i+j)/2;
        if (res-3*mid == target)
        {
           return true;
        }
        else{
            if (res-3*mid > target)
            {
                return binarySearch(mid+1,j,res,target);
            }
            else{
                return binarySearch(i,mid-1,res,target);
            }
        }
    }

}

bool rec(int a,int b){
    if (a>b)
    {
        if (a>b*2)
        {
            return false;
        }
        else{
            int res = b*2;
            return binarySearch(0,res/3,res,a);
        }
    }
    else{
        if (b>a*2)
        {
            return false;
        }
        else{
            int res = a*2;
            return binarySearch(0,res/3,res,b);
        }
    }
}

int main(){
    int n;scanf("%d",&n);
    while (n--)
    {
        int a,b;scanf("%d %d",&a,&b);
        if (rec(a,b))
        {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        
    }
    

}