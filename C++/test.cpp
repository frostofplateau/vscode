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
        pStr1 += n-1;
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
/*
//下面两个程序是错的
void Getmemory(char* p)
{
    p = (char*)malloc(100);
}
void test()
{
    char *str = NULL;
    GetMemory(str);
    strcpy(str,"Thunder");
    strcat(str+2,"Downloader");
    printf(str);
}*/
//这是正确的形式
//调用一级指针的地址时，要用二级指针调用
void GetMemory(char **p)
{
    *p = (char*)malloc(100);
}
void test()
{
    char *str = NULL;
    GetMemory(&str);
    strcpy(str,"Thunder");
    strcat(str+7,"Downloader");//这里的str+(1~7)和str+（8～）是两个结果
    printf("%s", str);
    free(str);
}

void fun(int *p1, int* p2, int *s)
{
    s = (int*)malloc(sizeof(int));
    *s = *p1 + *p2;
    printf("%d\n", *s);
    free(s);
}

void test_new()
{
    int* a = new int();
    int b = 4;
    a = &b;
    cout << "#########################################" << endl;

    cout << "*a = " << *a << endl;
    cout << "4" << endl;
    //delete a;
    //它说这个指针a没有被分配
    cout << "3" << endl;
    int* p = new int[10];
    cout << "1" << endl;
    for(int i =0; i < 10; i++)
    {
        p[i] = i * 3 +1;
    }
    cout << "2" << endl;
    for(int i = 0; i < 9; i++)
        cout << "p:" << p[i] << " ";
    delete[] p;
    cout << endl;
    cout << "#########################################" << endl;

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

    cout << "\nThe number of 1 in 9999 is:" << count_num_1(9999) << endl;
    system_funname();

    test();
#endif

    int a[2] = {1,2}, b[2] = {2, 3}, *q = a;
    fun(a,b,q);
    printf("%d\n", *q);
    test_new();
    return 0;
}