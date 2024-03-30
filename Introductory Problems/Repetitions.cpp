#include<cstdio>

int main(){
    char fr;
    scanf("%c",&fr);
    char ch;
    int max=1;
    int cnt =1;
    while (scanf("%c",&ch)>0)
    {
        if (ch!=fr)
        {
           fr=ch;
           if (cnt>max)
           {
            max=cnt;
           }
           cnt=1;
           
        }
        else{
            cnt++;
        }
    }
    printf("%d",max);
}