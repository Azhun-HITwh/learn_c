//
//  main.c
//  structure
//
//  Created by Azhun Zhu on 2021/11/3.
//

#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define LEN sizeof(struct student)

struct student
{
    long num;
    float score;
    struct student *next;
};

struct student *create()
{
    struct student *p1, *p2, *head;
    int n =0;
    
    head = NULL;
    
    p1 = p2 = (struct student *) malloc(LEN);
    
    printf("please input num and score.\n");
    scanf("%d %f", &p1->num, &p2->score);
    
    while (p1->num != 0)
    {
        n++;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct student *) malloc(LEN);
        printf("please input num and score.\n");
        scanf("%d %f", &p1->num, &p1->score);
    }
    p2->next = NULL;
    return head;
}

// 打印链表
void printlist(struct student *head)
{
    struct student *p;
    p = head;
    if(head != NULL)
    {
        do
        {
            printf("num=%d score=%f\n", p->num, p->score);
            p = p->next;
        }while(p != NULL);
    }
}

void main()
{
    struct student *head;
    head = create();
    printlist(head);
}

//删除节点
struct student *delNode(struct student *head, int num)
{
    printf("delNode.\n");
    struct student *p1, *p2;
    if(head == NULL)
    {
        printf("The List is NULL.\n");
    }
    else
    {
        p1 = head;
        while(p1->next != NULL && p1->num != num)
        {
            p2 = p1;
            p1 = p1->next;
        }
        if(p1->num == num)
        {
            if(p1 == head)
                head = p1->next;
            else
                p2->next = p1->next;
        }
        else
            printf("Can not find list num.\n");
    }
    return head;
}

//更新节点
struct student *update(struct student *head, int index, int num, float score)
{
    printf("update.\n");
    struct student *p;
    if(head == NULL)
    {
        printf("The List is NULL.\n");
    }
    else
    {
        p = head;
        while(p->next != NULL && p->num != index)
        {
            p = p->next;
        }
        if(p->num == index)
        {
            p->num = num;
            p->score = score;
        }
        else
            printf("Can not find list index.\n");
    }
    return head;
}

//增加节点
struct student *add(struct student *head, int index, int num, float score)
{
    printf("add.\n");
    struct student *p1, *p2, *p3;
    if(head == NULL)
    {
        printf("The List is NULL.\n");
    }
    else
    {
        p1 = p2 = head;
        while(p1->next != NULL && p1->num != index)
        {
            p1 = p1->next;
            p2 = p1;
        }
        if(p1->num == index)
        {
            p3 = (struct student *)malloc(LEN);
            p3->num = num;
            p3->score = score;

            if(p2->next == NULL)
            {
                p2->next = p3;
                p3->next = NULL;
            }
            else
            {
                p3->next = p2->next;
                p2->next = p3;
            }
        }
        else
            printf("Can not find list index.\n");
    }
    return head;
}
