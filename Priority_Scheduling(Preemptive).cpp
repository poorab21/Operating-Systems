#include<iostream>
int LargestPriority(int processes[][100],int size)
{
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(processes[i][3]>j)
		{
			j=processes[i][3];
		}
	}
	return j+1;
}
int main()
{
	int processes[100][100],size,count=0,largest_priority,position=0;
	int time=0,burst[100],smallest;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		std::cout<<"Enter Priority:";
		std::cin>>processes[i][3];
		burst[i]=processes[i][2];
	}
	smallest=processes[0][1];
	for(int i=1;i<size;i++)
	{
		if(smallest>processes[i][1])
		{
			smallest=processes[i][1];
		}
	}
	time=smallest;
	while(count != size)
	{
		int largest_priority=LargestPriority(processes,size);
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && processes[i][2]>0 && processes[i][3]<largest_priority)
			{
				largest_priority=processes[i][3];
				position=i;
			}
		}
		time++;
		processes[position][2]--;
		if(processes[position][2]==0)
		{
			processes[position][4]=time;
			processes[position][5]=processes[position][4]-processes[position][1];
			processes[position][6]=processes[position][5]-burst[position];
			if(processes[position][6]<0)
			{
				processes[position][6]=0;
			}
			count++;
		}
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Priority"<<"\t"<<"Completion Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time\n";
	for(int i=0;i<size;i++)
	{
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<burst[i]<<"\t\t"<<processes[i][3]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t"<<processes[i][6]<<"\n";
	}
}
