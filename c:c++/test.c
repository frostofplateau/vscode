#include <stdio.h>


void AlphabetCounting(char a[], int n)
{
        int count[26]={0}, i, kind = 0;
        for(i=0;i < n; i++)
            ++count[a[i]-65];
        for(i=0;i<26;i++)
        {
            if(++kind > 1)
                putchar(';');
            printf("%C=%d",'A'+i,count[i]);
        }
}


int main()
{
#if 0
    int a = 1;
    int *p = &a;
    int b = *p++;//*p,p=p+1
    printf("%d",b);
    printf("\nasd\n");
#endif

    char a[] = "SDKLJHSUDGSDAJSLDJAHSDU";
    int n = sizeof(a)/sizeof(a[0]);
    AlphabetCounting(a,n);
    

    return 0;
}