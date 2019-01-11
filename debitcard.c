#include<stdio.h>
#include<string.h>
int size(long long int a);
int main()
{
	long long int a;
	int count;
	int c[200];
	char b[100];
	char m[1000]="MasterCard";
        printf("Enter the type of debit card: ");
	fgets(b,100,stdin);
	printf("Enter Card number: ");
	scanf("%lld",&a);
	count=size(a);
	for (int i=0;i<=count;i++)
	{
		c[i]=a%10;
		a=a/10;
	}
	if (strcmp(b,m)==0)
	{
		if (count==16)
		{
			if (c[0]==5&&(c[1]==1||c[1]==2||c[1]==3||c[1]==4)
			    {
				    printf("VALID");
			    }
			 else
			    printf("INVALID");
			    }
	        else
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

		
		

