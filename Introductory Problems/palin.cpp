#include<cstdio>
#include<string>
using namespace std;

int main(){
    int arr[30]={0};
    char ch;
    int cnt=0;
    int idx=-1;
    char x[1000100];
    string a="";
    string b="";
    scanf("%s\n",x);
    for (int i = 0; i <= 1000100; i++) {
        if (x[i]=='\0')
        {
            break;
        }
        else{
            arr[x[i]-'A']+=1;
            if (arr[x[i]-'A']%2!=0)
            {
                cnt++;
            }
            else{
                a+=x[i];
                b=x[i]+b;
                cnt--;
                arr[x[i]-'A']=0;
            }
        }
    }

    if (cnt>1)
    {
        printf("NO SOLUTION\n");
    }
    else{ 
        string mid = "";
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
                mid+=('A'+idx);
            }
        }
        a+=mid+b;
        printf("%s\n",a.c_str());
    }
    
}