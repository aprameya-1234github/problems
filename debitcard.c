#include<stdio.h>
#include<string.h>
int check(int *a,int b);
#define MAX 100
int size(long long int a);
int main()
{
	long long int a;
	int count;
	int c[200];
	char b[MAX];
	char m[MAX]="MasterCard";
	char am[MAX]="American Express";
	char v[MAX]="Visa";
        printf("Enter the type of debit card: ");
	fgets(b,MAX,stdin);
	printf("Enter Card number: ");
	scanf("%lld",&a);
	count=size(a);
	int n=strncmp(b,m,strlen(m));
	int k=strncmp(b,am,strlen(am));
	int l=strncmp(b,v,strlen(v));
	for (int i=(count-1);i>=0;i--)
	{
		c[i]=a%10;
		
		a=a/10;
	}
	if (n==0)
	{
		if (count==16)
		{
			if (c[0]==5&&(c[1]==1||c[1]==2||c[1]==3||c[1]==4||c[1]==5))
			{
				if (check(c,a)==2)
				{
					printf("VALID");
				}
				else
				{
					printf("INVALID");
				}
			}
			else
			{
				printf("INVALID");
			}
		}
		else
		{
			printf("INVALID");
		}
	
	}
	else if (k==0)
	{
		if (count==15)
		{
			if (c[0]==3&&(c[1]==4||c[1]==7))
			{
				if (check(c,a)==2)
				{
					printf("VALID");
				}
				else
				{
					printf("INVALID");
				}
			}
			else
			{
				printf("INVALID");
			}
		}
		else
		{
			printf("INVALID");
		}
	}
	else if (l==0)
	{
		if (count==16||count==13)
		{
			if (c[0]==4)
			{
				if (check(c,a)==2)
				{
					printf("VALID");
				}
				else
				{
					printf("INVALID");
				}
			}
			else
			{
				printf("INVALID");
			}
		}
		else
		{
			printf("INVALID");
		}	
	else
	{
		printf("INVALID");
	}
	
	return 0;
}
int size(long long int a)
{
	int count=0;
	while (a!=0)
	{
		a/=10;
		++count;
	}
	return count;
}
int check(int *a,int c)
{
	int sum1=0,sum2=0;
	int b;
	int count;
	count=size(c);
	for (int i=0;i<count;i++)
	{
		sum1+=a[i];
	}
	for (int j=0;j<count;j+=2)
	{
		sum1+=a[j+1];
	}
	if (((2*sum2)-sum1)%10==0)
	{
		b=2;
	}
	else
	{
		b=1;
	}
	return b;
}
		
		

