#include<stdio.h>
int main()
{
	int process[50], size[50], rm[50];
	int memory, blocks, block_size,n,i,j,count=0;

	printf("Enter total memory size: ");
	scanf("%d",&memory);
	printf("Enter number of blocks: ");
	scanf("%d",&blocks);
	block_size = memory / blocks;
	printf("Block size : %d\n",block_size);
	printf("Enter number of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		process[i] = i+1;
		printf("Enter process %d size : ",i+1);
		scanf("%d",&size[i]);
		if(size[i]>memory)
		{
			count= 1;
			break;
		}
		memory	= memory - size[i];
		rm[i] = memory;
	}
	printf("\n Process\tSize\tRemaining Memory\n");
	for(j=0;j<n;j++)
	{
		printf(" P-%d\t\t%d\t\%d\n",process[j],size[j],rm[j]);
	}
	if(count==1)
	{
		printf("insufficient memory for remaining process");
	}
	printf("External fragmentation is : %d",memory);
	return 0;
}
