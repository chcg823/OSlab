#include<stdio.h>

int i,j,N,process[10],arrival_time[10],exec_time[10],priority[10],service_time[10],waiting_time[10],turn_around[10],ft[10];
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void main()
{
	int total_wt = 0, total_ta = 0;
	float avg_wt = 0, avg_ta = 0;
	printf("Enter number of processes: ");
	scanf("%d",&N);

	printf("\nPriority Scheduling......\n");

	for(i=0; i<N; i++)
	{
		printf("\nEnter process number: ");
		scanf("%d",&process[i]);
		printf("Enter arrival time: ");
		scanf("%d",&arrival_time[i]);
		printf("Enter execution time: ");
		scanf("%d",&exec_time[i]);
		printf("Enter priority: ");
		scanf("%d",&priority[i]);
	}

	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(priority[i]<priority[j])
			{
				swap(&priority[i],&priority[j]);
				swap(&process[i],&process[j]);
				swap(&arrival_time[i],&arrival_time[j]);
				swap(&exec_time[i],&exec_time[j]);
			}
		}
	}

	for(i=0;i<N; i++)
	{
		if(i==0)
		{
			service_time[i] = arrival_time[i];
		}
		else
		{
			service_time[i] = ft[i-1];	
		}
		waiting_time[i] = service_time[i] - arrival_time[i];
		ft[i] = service_time[i] + exec_time[i];
		turn_around[i] = ft[i] - arrival_time[i];
		
		total_wt += waiting_time[i];
		total_ta += turn_around[i];
	}
	avg_wt = (float)total_wt/N;
	avg_ta = (float)total_ta/N;

	printf("\nProcess\tArrivalTime\tExecutionTime\tPriority\tWaitingTime\tTurnAroundTime");
	for(i=0; i<N; i++)
	{
		printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i],arrival_time[i],exec_time[i],priority[i],waiting_time[i],turn_around[i]);
	}
	printf("\n\nAverage Waiting Time: %f",avg_wt);
	printf("\nAverage Turn Around Time: %f\n\n",avg_ta);
}
