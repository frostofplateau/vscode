#include <stdio.h>
#include<iostream>
#include<string>
using namespace std;
void AlphabetCounting(char a[], int n)
{
        int count[26]={0}, i, kind = 0;
        for(i=0;i < n; i++)
            ++count[a[i]-65];
        for(i=0;i<26;i++)
        {
            if(++kind > 1)
                putchar(';');
            printf("%c=%d",'A'+i,count[i]);
        }
}

void fun_unsigned_char()
{
    /*
    0 <= i <= 255
    */
    unsigned char i = 7;
    int j = 0;
    for(;i>0;i-=3)
        ++j;
    printf("%d\n",j);
}

void* memmove(void* str1,const void* str2,size_t n)
{
    char* pStr1 = (char*)str1;
    char* pStr2 = (char*)str2;
    if(pStr1 < pStr2){
        for(size_t i = 0;i!=n; ++i)
        {
            *(pStr1++) = *(pStr2++);
        }
    }
    else{
        pStr1+= n-1;
        pStr2 += n-1;
        for(size_t i = 0; i != n; ++i){
            *(pStr1--) = *(pStr2--);
        }
    }
    return pStr1;
}

int count_num_1(int x)
{
    int count = 0;
    while(x)
    {
        count++;
        x = x&(x-1);
    }
    return count;
}

void system_funname()
{
    int printf = 10;
    //系统函数名是可以当作自定义标示符
    cout << "测试系统函数名当作自定义标示符" << printf << endl;
}


int main()
{
#if 0
    int a = 1;
    int *p = &a;
    int b = *p++;//*p,p=p+1
    printf("%d",b);
    printf("\nasd\n");


    char a[] = "SDKLJHSUDGSDAJSLDJAHSDZZZZZZZZZZZZZZZZU";
    int n = sizeof(a)/sizeof(a[0]);
    AlphabetCounting(a,n);
    std::cout << std::endl;

    fun_unsigned_char();

    char* str1 = "asdfadfs";
    char* str2 = "asfdasdf";
    int n = strlen(str1);
    char* s = (char*)memmove(str1,str2,n);
 #endif

    cout << "\nThe number of 1 in 9999 is:" << count_num_1(9999) << endl;
    system_funname();

    return 0;
}