#include<stdio.h>
#include<string.h>
//program to split a string about '@'
int main()
{
    char str[]="devchauhan@gmail.com";
    char str2[100],str3[100];
    int m,x,y;
    int *p_str = str;
    int *p_str2 = str2;
    int *p_str3 = str3;

    x=strlen(str);

    for(int i=0;i<=x;i++)
    {
        if(str[i]=='@')
        {
            y=i;
            break;
        }
    }
    printf("the position of @is %d \n",y);

    for(int i=0;i<y;i++)
    {
        *(str2+i)=*(str+i);
    }
    m=x-y;
    for(int i=0;i<=m;i++)
    {
        *(str3+i)=*(str+ i+y+1);
    }
    printf("%s \n",str2);
    printf("%s \n",str3);
    return 0;
}
