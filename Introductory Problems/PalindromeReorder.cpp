#include<cstdio>
#include<string>
using namespace std;

int main(){
    int arr[30]={0};
    char ch;
    int cnt=0;
    int idx=-1;
    char x[1000100];
    char res[1000100];
    scanf("%s\n",x);
    string xa = x;
    int lef = 0;
    int right = xa.length();
    res[right]='\0';
    right--;
    for (int i = 0; i < xa.length(); i++) {
        
            arr[x[i]-'A']+=1;
            if (arr[x[i]-'A']%2!=0)
            {
                cnt++;
            }
            else{
                res[lef]=x[i];
                lef++;
                res[right]=x[i];
                right--;
                cnt--;
                arr[x[i]-'A']=0;
            }
        
    }

    if (cnt>1)
    {
        printf("NO SOLUTION\n");
    }
    else{ 
        if (cnt!=0)
        {
             for (int i = 0; i < 26; i++)
            {
                if (arr[i]%2!=0)
                {
                    idx=i;
                }
                
            }
            for (int i = 0; i < arr[idx]; i++)
            {
                res[lef]='A'+idx;
                lef++;
            }
        }
        printf("%s\n",res);
    }
    
}