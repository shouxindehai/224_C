//问题来自：洛谷P1093
//本题包含结构数组的声明和排序
//排序逻辑 类似高考，语文相同则按照学号
#include<stdio.h>

typedef struct student
{
    int id;
    int chi;
    int math;
    int eng;
    int sum;
}Student;

void creatlist(Student stu[],int num);
void sortlist(Student stu[],int num);

int main()
{
    int number;
    scanf("%d",&number);
    Student stu[number];
    creatlist(stu,number);
    sortlist(stu,number);
    for(int i=0;i<5;i++)
    {
        printf("%d %d\n",stu[i].id,stu[i].sum);
    }
}

void creatlist(Student stu[],int num)
{
    for(int i=0;i<num;i++)
    {
        stu[i].id=i+1;
        scanf("%d",&(stu[i].chi));
        scanf("%d",&(stu[i].math));
        scanf("%d",&(stu[i].eng));
        stu[i].sum=stu[i].chi+stu[i].math+stu[i].eng;
    }
}
void sortlist(Student stu[],int num)
{
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(stu[j].sum>stu[i].sum)
            {
                Student temp=stu[j];
                stu[j]=stu[i];
                stu[i]=temp;
            }else if(stu[j].sum==stu[i].sum)
            {
                if(stu[j].chi>stu[i].chi)
                {
                    Student temp=stu[j];
                    stu[j]=stu[i];
                    stu[i]=temp;
                }else if(stu[j].chi==stu[i].chi)
                {
                    if(stu[j].id<stu[i].id)
                    {
                        Student temp=stu[j];
                        stu[j]=stu[i];
                        stu[i]=temp;
                    }
                }
            }
        }
    }
}