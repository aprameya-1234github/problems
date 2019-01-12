#include<stdio.h>
#include<string.h>
int check(int *num_array,long long int credit_number);
#define MAX 100
int size(long long int credit_number);
int main()
{
	long long int credit_number;
	int count;
	int num_array[200];
	char card_name[MAX];
	char master[MAX]="MasterCard";
	char amex[MAX]="American Express";
	char visa[MAX]="Visa";
        printf("Enter the type of debit card: ");
	fgets(card_name,MAX,stdin);
	printf("Enter Card number: ");
	scanf("%lld",&credit_number);
	count=size(credit_number);
	int n=strncmp(card_name,master,strlen(m));
	int k=strncmp(card_name,amex,strlen(am));
	int l=strncmp(card_name,visa,strlen(v));
	for (int i=(count-1);i>=0;i--)
	{
		num_array[i]=credit_number%10;
		
		credit_number=credit_number/10;
	}
	if (n==0)
	{
		if (count==16)
		{
			if (num_array[0]==5&&(num_array[1]==1||num_array[1]==2||num_array[1]==3||num_array[1]==4||num_array[1]==5))
			{
				if (check(num_array,credit_number)==2)
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
			if (num_array[0]==3&&(num_array[1]==4||num_array[1]==7))
			{
				if (check(num_array,credit_number)==2)
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
			if (num_array[0]==4)
			{
				if (check(num_array,credit_number)==2)
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
int check(int *a,long long int c)
{
	int sum1=0,sum2=0;
	int b;
	int count;
	count=size(c);
	for (int j=0;j<count;j+=2)
	{
		sum1+=a[j];
		sum2+=a[j+1];
	}
	if (((2*sum2)+sum1)%10==0)
	{
		b=2;
	}
	else
	{
		b=1;
	}
	return b;
}
		
		

