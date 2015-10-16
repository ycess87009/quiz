/* FIXME: Implement! */
#include<stdio.h>

int main()
{
    return 0;
}

int maxSubArray(int A[],int n)
{
    if(n==0)return 0;
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
