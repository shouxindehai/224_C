```c
#include<stdio.h>
int main()
{
    int ip=0xc0a80164;
    unsigned char *ip1=(unsigned char*)(&ip);
    printf("%u.%u.%u.%u",*ip1,*(ip1+1),*(ip1+2),*(ip1+3));
    return 0;
}
```

