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
	int n=strncmp(b,m,strlen(m));
	for (int i=0;i<=count;i++)
	{
		c[i]=a%10;
		a=a/10;
	}
	if (n==0)
	{
		if (count==16)
		{
			if (c[15]==5&&(c[14]==1||c[14]==2||c[14]==3||c[14]==4)
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

		
		

