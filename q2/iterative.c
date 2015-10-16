/* FIXME: Implement! */
#include<stdio.h>


int main()
{
    return 0;
}

/*
 *  parameters   :  a sorted character array , the search character
 *  return value :  The smallest character that is strictly larger than the search character
 */
char smallest_character(char str[],char c)
{
    if(str==NULL)return '\0';     //check if str is NULL
    if(c<97 && c>122)return '\0'; //check if c is valid
    int count=0;
    while(str[count]!='\0') {   //if it's not the end of str[]
        if((int) str[count]>(int) c)return str[count];
        count++;
    }
    return str[0];
}

