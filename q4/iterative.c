/* FIXME: Implement! */
#include<stdio.h>
#include<stdlib.h>
#include"time_routine.h"


int maxSubArray(int A[],int n);

int main()
{
    //setup Random number seed
    srand((unsigned)time(NULL));
    unsigned int arraysize=rand()%200;
    /*
     *generate A[]
     * */
    struct timespec start, end;
    double cpu_time;
    int count=0;
    int *A=malloc(arraysize*sizeof(int));
    for(; count<arraysize; count++) {
        int pos_nege=rand()%2;
        int number=rand()%100;
        if(pos_nege)
            number=-number;
        A[count]=number;
    }
    /*
       for(count=0;count<arraysize;count++)
       {
       printf("%d,",A[count]);
       }
       printf("\n");
       */
    clock_gettime(CLOCK_REALTIME, &start);
    int k=maxSubArray(A,arraysize);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    printf("Size: %d ,Result: %d ,Time:%lf sec\n",arraysize,k,cpu_time);
    return 0;
}

int maxSubArray(int A[],int n)
{
    if(n==0||A==NULL)return 0;
    int temp_max[2],max=A[0],count=0;
    for(; count<n; count++) {
        if(A[count]<1)continue;     //find the first postive integer
        //temp_max[0]:max contiguous sum
        //temp_max[1]:contiguous sum
        temp_max[0]=temp_max[1]=A[count];
        while(count<(n-1) && (temp_max[1]+A[count+1])>0) {  //if the contiguous sum is negetive,abort this
            temp_max[1]+=A[count+1];
            if(temp_max[1]>temp_max[0]) {
                temp_max[0]=temp_max[1];
            }
            count++;
        }
        if(temp_max[0]>max)//determine max
            max=temp_max[0];
    }
    return max;
}
