/* FIXME: Implement! */
#define NULL 0


int main()
{
    
    return 0;
}

char smallest_character(char str[],char c){
    if(str==NULL)return '\0';
    if(c==NULL)return '\0';
    int count=0;
    while(str[count]!='\0'){
        if((int) str[count]>(int) c)return str[count];
        count++;
    }
    return str[0];
}

