/* FIXME: Implement! */
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "time_routine.h"

char smallest_character(char str[],char c);

int main(int argc,char *argv[])
{
    if(argc!=2) {
        printf("Please input at least ONE cahracter to check result\n");
        printf("Ex: ./a.out abcd\n");
        return 0;
    }
    struct timespec start, end;
    double cpu_time1;
    char test_str[]="abcdefghijklmnopqrstuvwxyz";
    int check=1;
    unsigned int count=0;
    printf("input character count:%d\n",strlen(argv[1]));
    clock_gettime(CLOCK_REALTIME, &start);
    for(; count<strlen(argv[1]); count++) {
        char result=smallest_character(test_str,(char )argv[1][count]);
        if(result==((int)argv[1][count]+1) ||((argv[1][count])=='z' && result=='a'))
            ;
        else
            check=0;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);
    if(check)
        printf("Correct\n");
    else
        printf("Wrong\n");

    printf("Time: %lf sec.\n",cpu_time1);
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

