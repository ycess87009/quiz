/* FIXME: Implement! */
#include<stdio.h>
char smallest_character(char str[],char c);

int main()
{
    char string[]="abchhqsuvvxz";
    printf("%c\n",smallest_character(string,'k'));
    return 0;
}

char smallest_character(char str[],char c)
{
    if(str==NULL)return '\0';
    if(c<97&&c>122)return '\0';
    if(str[0]=='\0')return str[-1];
    if((int) str[0]>(int) c)return str[0];
    char test=smallest_character(str+1,c);
    return test>str[0]? test:str[0];
}

