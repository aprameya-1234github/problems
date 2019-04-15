#include<stdio.h>//author: Sayantan Chakrabarty,Department of Computer Science & Technology(2018-2022 batch),IIEST Shibpur
#include<stdlib.h>
#include<string.h>
typedef struct student
{
    char fname[20];
    char surname[20];
    int roll;
    struct student *next;
}stud;
stud *addSNode(stud *start,stud s)
{
    stud *t;
    t=(stud*)malloc(sizeof(stud));
    strcpy(t->fname,s.fname);
    strcpy(t->surname,s.surname);
    t->roll=s.roll;
    t->next=start;
    start=t;
    return(start);
}
void printLL(stud *start,FILE *ft)
{
    stud *itr;
    for(itr=start;itr!=NULL;itr=itr->next)
    {
        fprintf(ft,"%10s %10s %10d\n",itr->fname,itr->surname,itr->roll);
    }
}
stud *appendSNode(stud *start,stud s)
{
    stud *fnode,*tmp;
    for(tmp=start;tmp->next!=NULL;)
        tmp=tmp->next;
    fnode=(stud*)malloc(sizeof(stud));
    strcpy(fnode->fname,s.fname);
    strcpy(fnode->surname,s.surname);
    fnode->roll=s.roll;
    fnode->next=NULL;
    tmp->next=fnode;
    return(start);
}
stud *deleteNthSNode(stud *start,int n)
{
    stud *prenode,*todelete;
    todelete=start;

    int i;
    if(n==1)
    {
        //delete 1st node.
        todelete=start;
        start=start->next;
        free(todelete);
        return(start);
    }
    else{
    for(i=1;i<=n-1;i++)
    {
        prenode=todelete;
        todelete=todelete->next;
        if(todelete==NULL)
            return(start);
    }
    prenode->next=todelete->next;
    free(todelete);
    return(start);}
}
stud *deleteSNode(stud *start,int r)
{
    int f=1;
    stud *prenode,*todelete;
    todelete=start;
    if(start->roll==r)
    {
        start=start->next;
        free(todelete);
        return(start);
    }
    else{
    while(todelete->roll!=r)
    {
        prenode=todelete;
        todelete=todelete->next;
        if(todelete==NULL)
            return(start);
    }
    prenode->next=todelete->next;
    free(todelete);
    return(start);}
}
stud *reverseSList(stud *start)
{
    stud *curr,*next,*prev;
    curr=start;
    next=NULL;
    prev=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
    return(start);
}
stud *duplicateSList(stud *start)
{
    stud *dup,*fnode;
    dup=NULL;


    while(start!=NULL)
    {
        fnode=(stud*)malloc(sizeof(stud));
        strcpy(fnode->fname,start->fname);
        strcpy(fnode->surname,start->surname);
        fnode->roll=start->roll;
        fnode->next=dup;
        dup=fnode;
        start=start->next;

    }
    dup=reverseSList(dup);
    return(dup);
}
stud *truncateNtSList(stud *start,int n)
{
    stud *prenode,*todelete;
    todelete=start;
    int i;
    for(i=1;i<=n;i++)
    {
        prenode=todelete;
        todelete=todelete->next;
    }
    prenode->next=NULL;
    while(todelete!=NULL)
    {
        prenode=todelete;
        todelete=todelete->next;
        free(prenode);
    }
    return(start);
}
void main()
{
    stud s,*start,*dup;
    int n,r;
    start=NULL;
    FILE *fs;
    fs=fopen("myf5.txt","r");
    if(fs==NULL)
    {
        printf("cannot open source file\n");
        exit(0);
    }
    while(fscanf(fs,"%s%s%d",s.fname,s.surname,&s.roll)!=EOF)
    {
        start=addSNode(start,s);
    }
    fclose(fs);
    int op;
    char ch,tch;
    printf("1.append\n2.delete n th node\n3.delete specified roll field\n4.duplicate\n5.reverse\n6.truncate\n7.print\n");

    do
    {
        printf("enter your choice: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            do
            {
                printf("enter the first name,surname and roll: ");
                scanf("%s%s%d",s.fname,s.surname,&s.roll);
                start=appendSNode(start,s);
                getchar();
                printf("append another record(y/n)? ");
                ch=getchar();
            }while(ch=='y');

            break;
        case 2:
            do
            {
                printf("enter the node to be deleted: ");
                scanf("%d",&n);
                start=deleteNthSNode(start,n);
                getchar();
                printf("delete another node(y/n)? ");
                ch=getchar();
            }while(ch=='y');

            break;
        case 3:
            do
            {
                printf("enter the roll no to be deleted: ");
                scanf("%d",&r);
                start=deleteSNode(start,r);
                getchar();
                printf("delete another node(y/n)? ");

                ch=getchar();
            }while(ch=='y');

            break;
        case 4:
            dup=duplicateSList(start);
            printf("duplicate linked list is\n");
            printLL(dup,stdout);
            break;
        case 5:
            start=reverseSList(start);
            break;
        case 6:
            printf("enter the value of n: ");
            scanf("%d",&n);
            start=truncateNtSList(start,n);
            break;
        case 7:
            printLL(start,stdout);

        }
        getchar();
        printf("want to do another operation(y/n)? ");
        tch=getchar();
    }while(tch=='y');

}
