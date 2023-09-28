#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<WinBase.h>
#define LEN sizeof(struct student)
#define stu struct student       


stu/*结构体的成员*/
{
 int num;
 char name[30];
 char yuan_xi[30];
 char C[30];
 char math[30];
 char english[30];
 char clas[30];
 int score1;
 int score2;
 int score3;//上为数据域
    stu* next;//指针域
};

stu* creat()//创建表
{
    stu* head, * p1, * p2;
    int i = 0;
    head = NULL;
    p1 = p2 = (stu*)malloc(LEN);
    printf("\n\n                               学生信息的录入\n ");
    printf("请输入学生学号：");
    scanf_s("%d", &p1->num,30);
    printf("*********************\n");


    printf("请输入学生姓名：");
    scanf_s("%s", &p1->name,20);
    printf("*********************\n");

    printf("请输入学生所在学院：");
    scanf_s("%s", &p1->yuan_xi,30);
    printf("*********************\n");

    printf("请输入学生班级：");
    scanf_s("%s", &p1->clas,30);
    printf("*********************\n");

    printf("请输入学生C语言：");
    scanf_s("%s", &p1->C,30);
    printf("*********************\n");

    printf("请输入学生C语言成绩：");
    scanf_s("%d", &p1->score1);
    printf("*********************\n");

    printf("请输入学生高数：");
    scanf_s("%s", &p1->math,30);
    printf("*********************\n");

    printf("请输入学生高数成绩：");
    scanf_s("%d", &p1->score2);
    printf("*********************\n");

    printf("请输入学生英语：");
    scanf_s("%s", &p1->english,30);
    printf("*********************\n");

    printf("请输入学生英语成绩：");
    scanf_s("%d", &p1->score3);
    printf("*********************\n");

   



    while (p1->num != 0)
    {
        i = 1 + i;
        if (i == 1)
        {
            head = p1;
        }
        else
        {
            p2->next = p1; 
        }

        p2 = p1;

        printf("各项为0结束\n");
        p1 = (stu*)malloc(LEN);
        
        printf("请输入学生学号：");
        scanf_s("%d", &p1->num,30);
        printf("*********************\n");
 
        printf("请输入学生姓名：");
        scanf_s("%s", &p1->name,30);                                                                                                                                                                                                                                                                                           
        printf("*********************\n");

        printf("请输入学生所在所在学院：");
        scanf_s("%s", &p1->yuan_xi,30);
        printf("*********************\n");

        printf("请输入学生班级：");
        scanf_s("%s", &p1->clas,30);
        printf("*********************\n");

        printf("请输入学生C语言：");
        scanf_s("%s", &p1->C,30);
        printf("*********************\n");

        printf("请输入学生C语言成绩：");
        scanf_s("%d", &p1->score1);
        printf("*********************\n");

        printf("请输入学生高数：");
        scanf_s("%s", &p1->math, 20);
        printf("*********************\n");

        printf("请输入学生高数成绩：");
        scanf_s("%d", &p1->score2);
        printf("*********************\n");

        printf("请输入学生英语：");
        scanf_s("%s", &p1->english,30);
        printf("*********************\n");

        printf("请输入学生英语成绩：");
        scanf_s("%d", &p1->score3);
        printf("*********************\n");


    }
    p2->next = NULL;
    return head;
}

void cun(stu* head)/*录入信息的存取*/
{
    stu* p;
    FILE* fp;

    p = head;

    fp = fopen("e:\\数据存储.txt", "ab+");//保存路径

    do
    {
        fwrite(p, LEN, 1, fp);

        p = p->next;

    } while (p != NULL);

    fclose(fp);
}

void save(stu* head)/*保存修改后的数据*/
{
    stu* p;
    FILE* fp;

    p = head;

    fp = fopen("e:\\数据存储.txt", "wb");  /*建一个数据存储.txt的文件。*/

    do
    {
        fwrite(p, LEN, 1, fp);

        p = p->next;

    } while (p != NULL);

    fclose(fp);
}

stu* du()/*读出文件中的数据*/
{
    stu* head, * p4, * p5;

    int i = 0;
    head = NULL;
    p4 = p5 = (stu*)malloc(LEN);

    FILE* fp;

    fp = fopen("e:\\数据存储.txt", "r+");
    if (fp == 0)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    while (fread(p4, LEN, 1, fp) == 1)//用于读出文件中的数据的循环体      
    {
        i = i + 1;

        if (i == 1)
        {
            head = p4;
        }
        else
        {
            p5->next = p4;
        }
        p5 = p4;

        p4 = (stu*)malloc(LEN);
    }
    p5->next = NULL;

    fclose(fp);

    return (head);
}

void print()/*输出函数*/
{
    stu* p;
    p = du();

    printf("\n\n                                学生成绩表\n\n ");
    printf("   ┌──┬──┬──┬──┬───┬──┬───┬──┬───┬──┐\n");
    printf("   │学号│姓名│所在学院│班级│C语言 │成绩│高数 │成绩│英语 │成绩│\n");
    printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");

    while (p != 0)
    {
        printf("   │%d  │%s  │%s  │%s  │%s    │%d  │%s    │%d  │%s    │%d  │\n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
        p = p->next;
        if (p == 0)
            printf("   └──┴──┴──┴──┴───┴──┴───┴──┴───┴──┘\n");
        else
            printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");
    }
}

void change()/*这个函数用于修改文件中的数据*/
{
    char mi[30];

    print();/*先读出再修改*/

    stu* p, * head;

    head = du();

    p = head;

    printf("请输入你要修改的学生的姓名:");

    scanf_s("%s", mi,30);//接受输入的姓名

    while (p != 0)

    {
        if (strcmp(mi, p->name) == 0)
        {
            printf("\n\n                          学生信息的显示\n ");
            printf("  ┌──┬──┬──┬──┬───┬──┬───┬──┬───┬──┐\n");
            printf("   │学号│姓名│所在学院│班级│C语言 │成绩│高数 │成绩│英语 │成绩│\n");
            printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");

            printf("   %d  %s  %s  %s  %s  %d  %s  %d  %s  %d  ", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);

            printf("\n");

            printf("    ┌──────────────────────────────────┐\n");
            printf("    │  1. 修改学号信息                  6. 修改C语言成绩                 │\n");
            printf("    ├──────────────────────────────────┤\n");
            printf("    │  2. 修改姓名信息                  7. 修改高数                      │\n");

            printf("    ├──────────────────────────────────┤\n");

            printf("    │  3. 修改所在学院信息                  8. 修改数学成绩              │\n");
            printf("    ├──────────────────────────────────┤\n");
            printf("    │  4. 修改班级信息                  9. 修改英语                      │\n");
            printf("    ├──────────────────────────────────┤\n");
            printf("    │  5. 修改C语言                    10. 修改英语成绩                  │\n");
            printf("    └──────────────────────────────────┘\n");
            printf("\n              请输入需要修改的内容：");
            printf("\n请输入：");

            int n;

            scanf_s("%d", &n);

            switch (n)  //菜单选择你要修改的内容

            {

            case 1:/*修改学号信息*/
                printf("请输入修改后的学号：\n");

                scanf_s("%d", &p->num);

                break;

            case 2:

                printf("请输入修改后的姓名：\n");

                scanf_s("%s", p->name,30);

                break;

            case 3:
                printf("请输入修改后的系别：\n");

                scanf_s("%s", p->yuan_xi,30);

                break;
            case 4:
                printf("请输入修改后的班级：\n");

                scanf_s("%s", p->clas,30);

                break;

            case 5:
                printf("请输入修改后的C语言：\n");

                scanf_s("%s", p->C,30);

                break;
            case 6:
                printf("请输入修改后的C语言成绩：\n");

                scanf_s("%d", &p->score1);

                break;

            case 7:
                printf("请输入修改后的高数：\n");

                scanf_s("%s", p->math,30);

                break;
            case 8:
                printf("请输入修改后的高数成绩：\n");

                scanf_s("%d", &p->score2);

                break;

            case 9:
                printf("请输入修改后的英语：\n");

                scanf_s("%s", p->english,30);

                break;

            case 10:

                printf("请输入修改后的英语成绩：\n");

                scanf_s("%d", &p->score3);

                break;

            case 11:

                exit(0);

                break;
            }

            save(head);

            break;

        }

        p = p->next;

        if (p == 0)
            printf("\n没有此学生!\n");
    }

}
int deleteStu()//删除方法
{
    print();//输出所有学生信息
    stu* head,*q,*p;

    head =p= du();
    int deldata = 0;
    int u = 0;//判断数
    if (head == NULL)
    {
        printf("该表为空");
    }

    printf("请输入你要删除的学号:\n");
    scanf_s("%d", &deldata);
    
    while (p != 0)
    {
        if (p->num == deldata)
        {
            u = 1;
            if (p == head)
            {
                head = p->next;
            }
            else
            {
                head->next = p->next;
            }


            printf("     %d  %s  %s  %s  %s  %d  %s  %d  %s  %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
        }
        
        p = p->next;
    }
    if (u == 0)
    {
        printf("没有此学生\n");
    }
    save(head);
        return 0;
}


void snum()/*学号查询*/
{
    stu* p;
    
    int num=0;
    int u = 0;//判断数
    

    printf("请输入你要查找的学号:\n");
    scanf_s("%d", &num);
    p = du();
    printf("\n\n                       查询学生信息结果显示\n ");
    printf("  ┌──┬──┬──┬──┬───┬──┬───┬──┬───┬──┐\n");
    printf("   │学号│姓名│所在学院│班级│C语言 │成绩│高数 │成绩│英语 │成绩│\n");
    printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");

    while (p != 0)
    {
        if (p->num== num)
        {
            u = 1;
            printf("     %d  %s  %s  %s  %s  %d  %s  %d  %s  %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
        }
        p = p->next;
    }
    if (u == 0)
    {
        printf("没有此学生\n");
    }
}


void  search() //查询函数
{
    int i;
    printf(" \n\n\n\n\n");
    printf("    ┌──────────────────────────────────┐\n");
    printf("    │  1. 按学生的姓名查询                                               │\n");
    printf("    ├──────────────────────────────────┤\n");
    printf("    │  2. 按学生的班级查询                                               │\n");
    printf("    ├──────────────────────────────────┤\n");

    printf("    │  3. 按所在学院查询                                                 │\n");
    printf("    │  4.按学生学号查询                                                  │\n");
    printf("    └──────────────────────────────────┘\n");
    printf("\n                           请选择：");
}

void name()/*姓名查询*/
{
    stu* p;
    char name[30];
    int u = 0;//判断数

    printf("请输入你要查找的名字\n");
    scanf_s("%s", name,30);
    p = du();
    printf("\n\n                       查询学生信息结果显示\n ");
    printf("  ┌──┬──┬──┬──┬───┬──┬───┬──┬───┬──┐\n");
    printf("   │学号│姓名│所在学院│班级│C语言 │成绩│高数 │成绩│英语 │成绩│\n");
    printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");

    while (p != 0)
    {
        if (strcmp(p->name, name) == 0)
        {
            u = 1;
            printf("     %d  %s  %s  %s  %s  %d  %s  %d  %s  %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
        }
        p = p->next;
    }
    if (u == 0)
    {
        printf("没有此学生\n");
    }
}

void ban()/*班级查询*/
{
    stu* p;
    char ban[30];
    int u = 0;

    printf("请输入你要查找的班级：\n");
    scanf_s("%s", ban,30);
    p = du();

    printf("\n\n                        查询学生信息结果为\n ");
    printf("  ┌──┬──┬──┬──┬───┬──┬───┬──┬───┬──┐\n");
    printf("   │学号│姓名│所在学院│班级│C语言 │成绩│高数 │成绩│英语 │成绩│\n");
    printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");

    while (p != 0)
    {
        if (strcmp(p->clas, ban) == 0)
        {
            u = 1;
            printf("     %d  %s  %s  %s  %s  %d  %s  %d  %s  %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
        }
        p = p->next;
    }
    if (u == 0)
    {
        printf("没有此学生\n");
    }

}

void xi()/*系别查询*/
{
    stu* p;
    char xi[30];
    int u = 0;

    printf("\n请输入你要查找的系别：\n");
    scanf_s("%s", xi,30);
    p = du();
    printf("\n\n                        查询学生信息结果显示\n ");
    printf("  ┌──┬──┬──┬──┬───┬──┬───┬──┬───┬──┐\n");
    printf("   │学号│姓名│所在学院│班级│C语言 │成绩│高数 │成绩│英语 │成绩│\n");
    printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");

    while (p != 0)
    {
        if (strcmp(p->yuan_xi, xi) == 0)
        {
            u = 1;
            printf("     %d  %s  %s  %s  %s  %d  %s  %d  %s  %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
        }
        p = p->next;
    }
    if (u == 0)
    {
        printf("没有此学生\n");
    }
}

void  xian()/*排序菜单*/
{
    int i;
    printf(" \n\n\n\n\n");
    printf("    ┌──────────────────────────────────┐\n");
    printf("    │  1. 按学生的C语言进行排序                                          │\n");
    printf("    ├──────────────────────────────────┤\n");
    printf("    │  2. 按学生的高数进行排序                                           │\n");
    printf("    ├──────────────────────────────────┤\n");
    printf("    │  3. 按学生的英语进行排序                                           │\n");
    printf("    ├──────────────────────────────────┤\n");
    printf("    │  4. 返回上一层                                                     │\n");
    printf("    └──────────────────────────────────┘\n");
    printf("\n                           请选择：");
}

void sort_chin() //按c语言成绩排序
{
    stu* p, * tail, * head;  //定义中间变量
    int score1;
    p = (stu*)malloc(LEN);
    head = du();
    printf("\n\n                      按学生语文C语言成绩排序\n ");
    printf("   ┌──┬──┬──┬──┬───┬──┬───┬──┬───┬──┐\n");
    printf("   │学号│姓名│所在学院│班级│C语言 │成绩│高数 │成绩│英语 │成绩│\n");
    printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");

    while (head->next != NULL) //选择法排序
    {
        tail = NULL;
        p = head;
        score1 = p->score1;  //将链表中第一个成绩赋给score1

        while (p != NULL)
        {
            if ((p->score1) > score1)//比较
            score1 = p->score1;
            tail = p;
            p = p->next;
        }
        tail = NULL;
        p = head;
        while (p->next != NULL)
        {
            if (p->score1 == score1)
            {
                printf("    %d   %s   %s   %s   %s   %d   %s   %d   %s   %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);

                if (p == head)
                    head = head->next;
                else
                    tail->next = p->next;
            }
            tail = p;
            p = p->next;
        }
        if (p->score1 == score1)//分数相同时不比较
        {
            printf("    %d   %s   %s   %s   %s   %d   %s   %d   %s   %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);

            tail->next = NULL;
        }
    }
    p = head; //将链表赋给结构体指针
    printf("    %d   %s   %s   %s   %s   %d   %s   %d   %s   %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3); printf("   %d  %s  %s  %s  %s  %d  %s  %d  %s  %d  ", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
}

void sort_math() //按高数成绩排序
{
    stu* p, * tail, * head;  
    int score2;
    p = (stu*)malloc(LEN);
    head = du();
    printf("\n\n                      按学生高数成绩排序\n ");
    printf("   ┌──┬──┬──┬──┬───┬──┬───┬──┬───┬──┐\n");
    printf("   │学号│姓名│所在学院│班级│C语言 │成绩│高数 │成绩│英语 │成绩│\n");
    printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");

    while (head->next != NULL) /*利用选择法排序*/
    {
        tail = NULL;
        p = head;
        score2 = p->score2;  /*将链表中第一个成绩赋给score2*/
        while (p != NULL)
        {
            if ((p->score2) > score2)/*比较*/
                score2 = p->score2;
            tail = p;
            p = p->next;
        }
        tail = NULL;
        p = head;
        while (p->next != NULL)
        {
            if (p->score2 == score2)
            {
                printf("    %d   %s   %s   %s   %s   %d   %s   %d   %s   %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3); printf("   %d  %s  %s  %s  %s  %d  %s  %d  %s  %d  ", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);

                if (p == head)
                    head = head->next;
                else
                    tail->next = p->next;
            }
            tail = p;
            p = p->next;
        }
        if (p->score2 == score2) //分数相同时无需比较
        {
            printf("    %d   %s   %s   %s   %s   %d   %s   %d   %s   %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3); printf("   %d  %s  %s  %s  %s  %d  %s  %d  %s  %d  ", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);

            tail->next = NULL;
        }
    }
    p = head; //将链表赋给结构体指针
    printf("     %d   %s   %s   %s   %s   %d   %s   %d   %s   %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
}

void sort_eng()//按英语成绩排序
{
    stu* p, * tail, * head;  //定义中间变量
    int score3;
    p = (stu*)malloc(LEN);
    head = du();
    printf("\n\n                      按学生英语成绩排序\n ");
    printf("   ┌──┬──┬──┬──┬───┬──┬───┬──┬───┬──┐\n");
    printf("   │学号│姓名│所在学院│班级│C语言 │成绩│高数 │成绩│英语 │成绩│\n");
    printf("   ├──┼──┼──┼──┼───┼──┼───┼──┼───┼──┤\n");

    while (head->next != NULL) //选择法排序
    {
        tail = NULL;
        p = head;
        score3 = p->score3;//将链表中第一个成绩赋给score3
        while (p != NULL)
        {
            if ((p->score3) > score3)
                score3 = p->score3;
            tail = p;
            p = p->next;
        }
        tail = NULL;
        p = head;
        while (p->next != NULL)
        {
            if (p->score3 == score3)
            {
                printf("    %d   %s   %s   %s   %s   %d   %s   %d   %s   %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);

                if (p == head)
                    head = head->next;
                else
                    tail->next = p->next;
            }
            tail = p;
            p = p->next;
        }
        if (p->score3 == score3) /*分数相同时无需比较*/
        {
            printf("    %d   %s   %s   %s   %s   %d   %s   %d   %s   %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
            tail->next = NULL;
        }
    }
    p = head;  /*将链表赋给结构体指针*/
    printf("    %d   %s   %s   %s   %s   %d   %s   %d   %s   %d  \n", p->num, p->name, p->yuan_xi, p->clas, p->C, p->score1, p->math, p->score2, p->english, p->score3);
}

void math()
{
    int b, sum = 0, c;
    float i = 0, j = 0, g = 0, ave;
    float m, n;
    stu* p;
    p = du();

    char  ba[30];
    printf(" \n\n\n\n\n");
    printf("                                对C语言成绩分析\n");
    printf("    ┌──────────────────────────────────┐\n");
    printf("    │  1. 系别成绩分析                                                   │\n");
    printf("    ├──────────────────────────────────┤\n");
    printf("    │  2. 班级成绩分析                                                   │\n");

    printf("    ├──────────────────────────────────┤\n");

    printf("    │  0. 返回上一层                                                     │\n");

    printf("    └──────────────────────────────────┘\n");
    printf("\n                           请选择：");
    scanf_s("%d", &c);
    if (c == 1)
    {
        printf("请输入系别名称:\n");
        scanf_s("%s", ba,30);
    }
    else if (c == 2)
    {
        printf("请输入班级名称:\n");
        scanf_s("%s", ba,30);
    }
    else
    {
        exit(0);
    }
    while (p != 0)
    {
        if (c == 2)
        {
            if (strcmp(p->clas, ba) == 0)
            {
                i = i + 1;
                b = p->score2;
                sum = sum + b;
                if (b >= 60)
                {
                    j = j + 1;
                    if (b >= 90)
                    {
                        g = g + 1;
                    }
                }
            }
        }
        if (c == 1)
        {
            if (strcmp(p->yuan_xi, ba) == 0)
            {
                i = i + 1;
                b = p->score2;
                sum = sum + b;
                if (b >= 60)
                {
                    j = j + 1;
                    if (b >= 90)
                    {
                        g = g + 1;
                    }
                }

            }
        }
        b = 0;
        p = p->next;
    }
    m = j / i;
    n = g / i;
    ave = sum / i;
    printf("及格率%.2f   优秀率%.2f    平均值%.2f\n", m, n, ave);
}

void chin()/*对高数成绩分析*/
{
    int b, sum = 0, c, o;
    float i = 0, j = 0, g = 0;
    float m, n, ave;
    stu* p;
    p = du();

    char  ba[30];
    printf(" \n\n\n\n\n");
    printf("                                对高数成绩分析\n");
    printf("    ┌──────────────────────────────────┐\n");
    printf("    │  1. 按系别进行查看                                                   │\n");
    printf("    ├──────────────────────────────────┤\n");
    printf("    │  2. 按班级进行查看                                                   │\n");

    printf("    └──────────────────────────────────┘\n");
    printf("\n                           请选择、、、：");
    scanf_s("%d", &c);
    if (c == 1)
    {
        printf("请输入系别名称:\n");
        scanf_s("%s", ba,30);
    }
    else if (c == 2)
    {
        printf("请输入班级名称:\n");
        scanf_s("%s", ba,30);
    }
    else
    {
        printf("输入错误");
        system("PAUSE");
        system("cls");
    }
    while (p != 0)
    {
        if (c == 2)
        {
            if (strcmp(p->clas, ba) == 0)
            {
                i = i + 1;
                b = p->score1;
                sum = sum + b;
                if (b >= 60)
                {
                    j = j + 1;
                    if (b >= 90)
                    {
                        g = g + 1;
                    }
                }
            }
        }
        else
        {
            if (strcmp(p->yuan_xi, ba) == 0)
            {
                i = i + 1;
                b = p->score2;
                sum = sum + b;
                if (b >= 60)
                {
                    j = j + 1;
                    if (b >= 90)
                    {
                        g = g + 1;
                    }
                }
            }
        }
        b = 0;
        p = p->next;
    }
    m = j / i;
    n = g / i;
    ave = sum / i;
    printf("及格率%.2f   优秀率%.2f   平均值%.2f\n", m, n, ave);
}

void eng()/*对英语成绩分析*/
{
    int b, sum = 0, c;
    float i = 0, j = 0, g = 0;
    float m, n, ave;
    stu* p;
    p = du();

    char  ba[20];
    printf(" \n\n\n\n\n");
    printf("                                对英语成绩分析\n");
    printf("    ┌──────────────────────────────────┐\n");
    printf("    │  1. 按系别进行查看                                                   │\n");
    printf("    ├──────────────────────────────────┤\n");
    printf("    │  2. 按班级进行查看                                                   │\n");

    printf("    └──────────────────────────────────┘\n");
    printf("\n                           请选择、、、：");
    scanf_s("%d", &c);
    if (c == 1)
    {
        printf("请输入系别名称:\n");
        scanf_s("%s", ba,30);
    }
    else if (c == 2)
    {
        printf("\n请输入班级名称:\n");
        scanf_s("%s", ba,30);
    }
    else
    {
        printf("输入错误");
        system("PAUSE");
        system("cls");
    }
    while (p != 0)
    {
        if (c == 2)
        {
            if (strcmp(p->clas, ba) == 0)
            {
                i = i + 1;
                b = p->score3;
                sum = sum + b;
                if (b >= 60)
                {
                    j = j + 1;
                    if (b >= 90)
                    {
                        g = g + 1;
                    }
                }
            }
        }
        else
        {
            if (strcmp(p->yuan_xi, ba) == 0)
            {
                i = i + 1;
                b = p->score2;
                sum = sum + b;
                if (b >= 60)
                {
                    j = j + 1;
                    if (b >= 90)
                    {
                        g = g + 1;
                    }
                }

            }
        }
        b = 0;
        p = p->next;
    }
    m = j / i;
    n = g / i;
    ave = sum / i;
    printf("及格率%.2f   优秀率%.2f     平均值%.2f\n", m, n, ave);
}

void zui()/*分析个人成绩**/
{
    int max, min, sum, a, b, ave, c, i = 0, g = 0;
    sum = 0; a = 0; b = 0;
    char  name[30];
    stu* p;
    p = du();

    printf("\n\n                             分析个人成绩\n");
    printf("\n         请输入学生的名字:\n");
    scanf_s("%s", name,30);
    while (p != 0)
    {
        if (strcmp(p->name, name) == 0)
        {
            g = 1;
            sum = p->score1 + p->score2 + p->score3;
            a = p->score1;
            b = p->score2;
            c = p->score3;
        }
        p = p->next;
    }
    ave = sum / 3;
    if (a >= b)
    {
        if (b >= c)
        {
            max = a;
            min = c;
            printf("max:%d  min:%d  ave:%d\n", max, min, ave);
        }
        else
        {
            if (a >= c)
            {
                max = a;
                min = b;
                printf("max:%d  min:%d  ave:%d\n", max, min, ave);
            }
            else
            {
                max = c;
                min = b;
                printf("max:%d  min:%d  ave:%d\n", max, min, ave);
            }
        }
    }
    else
    {
        ave = sum / 3;
        if (a >= c)
        {
            max = b;
            min = c;
            printf("max:%d  min:%d,ave:%d\n", max, min, ave);
        }
        else
        {
            if (b >= c)
            {
                max = b;
                min = a;
                printf("max:%d  min:%d  ave:%d\n", max, min, ave);
            }
            else
            {
                max = c;
                min = a;
                printf("max:%d  min:%d  ave:%d\n", max, min, ave);
            }
        }
    }
}


void welcome()//欢迎动画
{
    int count = 0;//计数器
    printf("\n");
    printf("加载中，请耐心等待。。。。。\n");
    for (int i = 0; i < 120; i++)
    {
            Sleep(5);
            printf("*");
            
    }

    for (int n = 0; n < 5; n++)
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
        printf("\n");

    }
  
    printf("                欢迎你！User！\n         如需加速请联系开发者");
    for (int m = 0; m < 4; m++)
    {
        printf("\n");
    }

    for (int j = 0; j < 120; j++)
    {
        Sleep(5);
        printf("*");

    }
    printf("加载成功！欢迎进入系统\n");

}


void enter()//密码函数
{
    char name[30];
    int password=0;
    int count = 0;
    printf("    ┌────────────────────────────────────────────────────────────────────┐\n");
    printf("    │                                                                    │\n");
    printf("     |                 欢迎使用成绩分析管理系统-V1.0                      |\n");
    printf("    │                         管理员你好                                 │\n");

    printf("    ├────────────────────────────────────────────────────────────────────┤\n");

    printf("    │                                                                    │\n");
    printf("    ├────────────────────────────────────────────────────────────────────┤\n");
    printf("    │                                                                    │\n");
    printf("    |                    如遇问题请联系开发者zhouger                     ┤\n");
    printf("    │                                                                    │\n");
    printf("    └────────────────────────────────────────────────────────────────────┘\n");


                                            
    printf("输入你的密码：");
    scanf_s("%d", &password);
    int key =1234;
    while (password != key)
    {
        
        printf("\n");
        if (password != key)
        {
            printf("密码错误，请重新输入：");
            scanf_s("%d", &password);
            count++;
            printf("您输入的密码错误为%d次\n", count);
            printf("注意：输入错误密码超过五次系统将会强制推出！");
            printf("\n");
            if (count == 4)
            {
                exit(0);
            }
        }
       
        
        
    }
    printf("密码正确！欢迎使用本系统！\n");
    welcome();
    
}


int main() 
{
    int i;
    enter();
    system("PAUSE");
    system("cls");
    printf("\n\n");
    while (1)
    {
        printf("\n");
        printf("    ┌──────────────────────────────────┐\n");
        printf("    │  1. 学生信息的录入                                                 │\n");
        printf("    ├──────────────────────────────────┤\n");
        printf("    │  2. 学生信息的修改                                                 │\n");
        printf("    ├──────────────────────────────────┤\n");

        printf("    │  3. 对学生的成绩进行分析(所在学院和班级的单科平均成绩、及格率和优秀率) │\n");
        printf("    ├──────────────────────────────────┤\n");
        printf("    │  4. 对个人成绩进行分析（各科的最高分和最低分）                     │\n");
        printf("    ├──────────────────────────────────┤\n");
        printf("    │  5. 对学生考试成绩进行排名                                         │\n");
        printf("    ├──────────────────────────────────┤\n");

        printf("    │  6. 显示成绩表                                                     │\n");

        printf("    ├──────────────────────────────────┤\n");
        printf("    │  7. 学生成绩的查找                                                 │\n");
        printf("    ├──────────────────────────────────┤\n");
        printf("        9.删除学生信息                                                      \n");
        printf("    ├──────────────────────────────────┤\n");
        printf("    │  8. 退出程序                                                       │\n");
        printf("    └──────────────────────────────────┘\n");
        int n;
        stu* head;
        printf("                                  请选择:");
        scanf_s("%d", &n);
        switch (n)
        {
        case 1:/*学生信息的录入*/
        {
            system("PAUSE");
            system("cls");
            head = creat();/*创建函数*/
            cun(head);/*保存函数*/
        }; break;

        case 2:/*学生信息的修改*/
        {
            system("PAUSE");
            system("cls");
            change();/*修改*/
        }; break;

        case 3:/*即求单科平均成绩、及格率和优秀率*/
        {
            system("PAUSE");
            system("cls");
            int h;
            printf("    ┌──────────────────────────────────┐\n");
            printf("    │  1. 对C语言进行成绩分析                                            │\n");
            printf("    ├──────────────────────────────────┤\n");
            printf("    │  2. 对高数进行成绩分析                                            │\n");
            printf("    ├──────────────────────────────────┤\n");

            printf("    │  3. 对英语进行成绩分析                                            │\n");
            printf("    └──────────────────────────────────┘\n");
            printf("\n                           请选择、、、：");

            scanf_s("%d", &h);

            switch (h)
            {
            case 1:/*按C语言进行成绩分析*/
            {
                system("PAUSE");
                system("cls");
                chin();
            }; break;

            case 2:/*按高数进行成绩分析*/
            {
                system("PAUSE");
                system("cls");
                math();
            }; break;

            case 3:/*按英语进行成绩分析*/
            {
                system("PAUSE");
                system("cls");
                eng();

            }; break;
            default:
            {
                system("PAUSE");
                system("cls");
                printf("\n           你的输入有误、、、");
            }; break;
            }
        }; break;

        case 4:/*对个人成绩进行分析（各科的最高分和最低分）*/
        {
            system("PAUSE");
            system("cls");
            zui();/* 最值*/

        }; break;

        case 5: /*对学生考试成绩进行排名*/
        {
            system("PAUSE");
            system("cls");
            xian();
            int y;
            scanf_s("%d", &y);
            switch (y)
            {
            case 1:
            {
                system("PAUSE");
                system("cls");

                sort_chin();/*按语文成绩排序*/
            }; break;

            case 2:
            {
                system("PAUSE");
                system("cls");
                sort_math();/*按数学成绩排序*/
            }; break;

            case 3:
            {
                system("PAUSE");
                system("cls");
                sort_eng();/*按英语成绩排序*/
            }; break;

            case 4:
            {
               
            }; break;

            default:
            {
                printf("输入错误:\n");
            }; break;
            }
        }; break;

        case 6:/*显示成绩表*/
        {
            system("PAUSE");/*用于输出*/
            system("cls");
            print();

        }; break;

        case 7: /*学生成绩的查找*/
        {
            system("PAUSE");
            system("cls");
            search();
            int a;
            scanf_s("%d", &a);
            switch (a)
            {
            case 1:/*按学生的姓名查询*/
            {
                system("PAUSE");
                system("cls");
                name();
            }; break;

            case 2:/*按学生的班级查询*/
            {
                system("PAUSE");
                system("cls");
                ban();
            }; break;

            case 3:/*按所在学院查询*/
            {
                system("PAUSE");
                system("cls");
                xi();
            }; break;
            case 4:/*按学生学号查询查询*/
            {
                system("PAUSE");
                system("cls");
                snum();
            }; break;

            default:
            {
                printf("输入错误:\n");
            }; break;
            }
        }; break;

        case 8:/*退出程序*/
        {
            exit(0);
        }; break;

        case 9://删除学生
        {
           
            system("PAUSE");
            system("cls");
            deleteStu();
            

        }; break;

        default:
        {
            printf("输入错误:\n");
        }; break;

        }
        system("PAUSE");
        system("cls");
    }
    return 0;
}