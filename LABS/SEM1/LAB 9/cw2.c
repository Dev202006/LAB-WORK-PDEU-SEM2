#include<stdio.h>

void convert(char *s,int size)
{
    for (int i = 0; i < size; i++)
    {
        if (s[i] <= 'Z' && s[i] >= 'A')
            s[i] = s[i] + 32;
        else if (s[i] <='z' && s[i]>= 'a')
            s[i] = s[i] -32;

    }
}
    int main()
    {
        char str[] = "PdeuADMIN";
        convert(str,sizeof(str));
        printf("%s\n",str);
    }

