//欧拉筛打素数表
#include <stdio.h>
int primes(int n);
//这是一个用来筛素数的函数
int prime[999999]={0};
//储存数组
int p[999999]={0};
//间接演算素数 假设全部是素数
int main()
{
    int number,i,size;
    //number为范围，size是素数个数；
    scanf("%d",&number);
    size=primes(number);
    for(i=0;i<size;i++)
    {
        printf("%d\n",prime[i]);
    }
    return 0;
}
int primes(int n)
{
    int top=0,i,j;
    //top为prime数组中素数的个数
    for(i=2;i<n;i++)
    {
        if(!p[i])
            prime[top++]=i;
        //精髓思想
        for(j=0;j<top&&i*prime[j]<=n;j++)
        {
            p[i*prime[j]]=1;
            //逻辑：当前的值和前面出现过的素数的乘积为合数
            if(i%prime[j]==0)
                break;
            //逻辑：如果i是已经出现的素数的倍数了，那么i*prime[j+1]一定会被prime[j]筛掉

        }
    }
    return top;
}
