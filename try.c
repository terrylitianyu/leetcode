#include <stdio.h>

int main(void) {
    int n;
    int A[1000];
    int i;
    int last_n = 0;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for(i=n-2;i>=0;i--)
    {
        if(A[i]>=A[i+1])
        {
            last_n=i;
            break;
        }
    }

    for (i = 0; i <= last_n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
