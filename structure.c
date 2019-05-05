#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct book{
	char title[100];
	char author[100];
	char publisher[100];
	long int pages;
	long int cost;
};
void modify_attribute(struct book *data);
void insert_record(struct book *data);
void expensive(struct book *data);
int main()
{
	struct book data[100];
	printf("To insert record, press I\n");
	printf("To change attribute, press C\n");
	printf("To see the most expensive book, press M\n");
	printf("To quit, press Q\n");
	getchar;
	char C;
	scanf("%c",&C);
	do
	{
		if (C=='I')
        	{
                	insert_record(data);
        	}
		else if (C=='C')
        	{
                	modify_attribute(data);
        	}
		else if (C=='M')
        	{
                	expensive(data);
        	}
		else if (C=='Q')
		{
			return 0;
		}
		else 
		{
			printf("Wrong input,Enter again\n");
		}

	}
	while(getchar()!='\n');
	return 0;
}
void insert_record(struct book *data)
{
	for (int i=0;i<10;i++)
	{
		printf("Enter book title: ");
		fgets(data[i].title,100,stdin);
		while(getchar()!='\n')
		printf("Enter author's name: ");
		fgets(data[i].author,100,stdin);
		while(getchar()!='\n')
		printf("Enter publisher's name: ");
		fgets(data[i].publisher,100,stdin);
		while(getchar()!='\n')
		printf("Enter number of pages: ");
		scanf("%ld",&data[i].pages);
		printf("Enter cost: ");
		scanf("%ld",&data[i].cost);
	}
}
void modify_attribute(struct book *data)
{
	printf("To change by book name, press B\n");
	printf("To change by author name, press A\n");
	char index;
	scanf("%c",&index);
	if (index=='B');
	{
		char name[100];
		printf("Enter Book name: ");
		fgets(name,100,stdin);
		getchar();
		for (int i=0;i<10;i++)
		{
			if (strcmp(name,data[i].title)==0)
			{
                        	printf("Match found. Reset it\n");
				printf("Enter Book title: ");
				fgets(data[i].title,100,stdin);
				while(getchar()!='\n')
				printf("Enter author's name: ");
				fgets(data[i].author,100,stdin);
				while(getchar()!='\n')
				printf("Enter publisher's name: ");
				fgets(data[i].publisher,100,stdin);
				while(getchar()!='\n')
				printf("Enter number of pages: ");
				scanf("%ld",&data[i].pages);
				printf("Enter cost: ");
				scanf("%ld",&data[i].cost);
			}
		}
	}
	if (index=='A');
        {
                char authornew[100];
                printf("Enter Author's name: ");
                fgets(authornew,100,stdin);
                getchar();
                for (int i=0;i<10;i++)
                {
                        if (strcmp(authornew,data[i].author)==0)
                        {
                                printf("Match found. Reset it\n");
                                printf("Enter Book title: ");
                                fgets(data[i].title,100,stdin);
                                while(getchar()!='\n')
                                printf("Enter author's name: ");
                                fgets(data[i].author,100,stdin);
                                while(getchar()!='\n')
                                printf("Enter publisher's name: ");
                                fgets(data[i].publisher,100,stdin);
                                while(getchar()!='\n')
                                printf("Enter number of pages: ");
                                scanf("%ld",&data[i].pages);
                                printf("Enter cost: ");
                                scanf("%ld",&data[i].cost);
                        }
                }
        }
}
void expensive(struct book *data)
{
	long int max=0;
	for (int i=0;i<10;i++)
	{
		if (max<data[i].cost)
		{
			max=data[i].cost;
		}
	}
	for (int i=0;i<10;i++)
	{
		if (data[i].cost==max)
		{
			printf("Most Expensive book\n");
			puts(data[i].title);
		}
	}
}



			

