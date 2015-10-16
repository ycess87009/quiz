/* FIXME: Implement! */

int maxSubArray(int A[],int n);

int main()
{
    return 0;
}

int maxSubArray(int A[],int n)
{
    if(n==0)return 0;
    int temp_max[2],max=A[0],count=0;
    //find the first postive integer
    for(; count<n; count++) {
        if(A[count]<1)continue;

    }
}

