#include<stdio.h>
main()
{
    int a[10],i;
    for (i = 0;i<=9;i++)
    {
        printf("Enter the number:");
        scanf("%d",&a[i]);
    }
    quick(a,0,9);
    for (i =0 ;i<=9;i++)
    {
        printf("%d\n",a[i]);
    }
}
void quick(int a[],int low,int upper)
{
    int r;
    if (low<upper)
    {
        r = partition(a,low,upper);
        quick(a,low,r-1);
        quick(a,r+1,upper);
    }
}
int partition(int a[],int low,int upper)
{
    int ele,p,q,temp;
    ele = a[low];
    p = low + 1;
    q = upper;
    while(p <= q)
    {
        while(a[p]<ele)
        {
            p++;
        }
        while(a[q]>ele)
        {
            q--;
        }
        if (p<q)//Initially, p moves right and stops at 7 (which is greater than 5), and q moves left and stops at 2 (which is less than 5).
//Since p < q, swapping 7 and 2 makes sense, because 7 belongs on the right and 2 belongs on the left:[3, 7, 4, 9, 1, 5, 6, 2, 8]
        {
            temp = a[p];
            a[p] = a[q];
            a[q] = temp;
        }
    }
    temp = a[low];
    a[low] = a[q];
    a[q] = temp;
    return q;
}
