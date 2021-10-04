#include <stdio.h>

int main()
{
    char str1[30],str2[30];
    int i,j=0,len=0;
    printf("entre the 1st string\n");
    scanf(" %s",str1);
    printf("entre the 2nd string\n");
    scanf(" %s",str2);
    for(i=0;str1[i]!='\0' && str2[i]!='\0' && str1[i] == str2[i];i++)
    {
        printf("%c",str1[i]);
        len++;
    }
    if(str1[i]=='\0')
    {
        while(str2[i]!='\0')
        {
            printf("%c",str2[i]);
            i++;len++;
        }
    }
     else if(str2[i]=='\0')
    {
        while(str1[i]!='\0')
        {
            printf("%c",str1[i]);
            i++;len++;
        }
    }
    else if(str1[i] != str2[i])
    {
        j=i;
        while(str1[i]!='\0')
        {
            printf("%c",str1[i]);
            i++;len++;
        }
         while(str2[j]!='\0')
        {
            printf("%c",str2[j]);
            j++;len++;
        }
    }
    printf("\n%d",len);


}

