#include<stdio.h>
int main()
{
        int a[50],i=0,j,k,temp;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{	
		scanf("%d",&a[i]);
	}
	for(i=0;i<k-1;)
	{
		for(j=0;j<k-1-i;j++)
		{		
			temp=a[j];
			if(a[j]>a[j+1])
			{
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		i++;
	}
        printf("sorted list is\n");
	for(i=0;i<k;i++)
	{
		printf("%ld",a[i]);
		printf("\n");
	}
	return 0;
}
