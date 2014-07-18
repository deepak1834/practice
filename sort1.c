#include<stdio.h>
int main()
{
	int a[50],n,i,j,temp,min;
	printf("enter the number of elements u want to insert\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
        scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		for(j=i+1;j<n;j++)
		{
			if(min>a[j])
			{
				temp=a[i];	
				min=a[j];
				a[i]=min;
				a[j]=temp;
			}
			else
			min=min;
		}
	}
	printf("sorted list is\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	return 0;
}
