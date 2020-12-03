```c
#include<stdio.h>

void bfs(char origin[],char ans[],int judge,int flag[]);

int main()
{
    char origin[4]={"ABC"};
    char ans[4];
    int flag[4]={0};

    bfs(origin,ans,0,flag);
    
    return 0;
}

void bfs(char origin[],char ans[],int judge,int flag[])
{
    //截止条件
    if(judge==3) 
    {
        ans[3]='\0';
        printf("%s\n",ans);
        return;
    }
    //候选人
    for(int i=0;i<3;i++)
    {
        //筛选条件
        if(!flag[i])
        {
            ans[judge]=origin[i];
            flag[i]=1;
            bfs(origin,ans,judge+1,flag);
            flag[i]=0;
        }
    }
}

```

