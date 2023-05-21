#include<iostream>
int main()
{
	int processes[100][100],size,position,time=0;
	int largest_priority=0,breaker=0,value;
	float Avg_turnaround=0,Avg_waitingTime=0;
	bool allow[10];
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Process "<<i+1<<std::endl;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Length:";
		std::cin>>processes[i][2];
		std::cout<<"Enter Priority:";
		std::cin>>processes[i][3];
	}
	for(int i=0;i<size;i++)
	{
		allow[i]=false;
	}
	for(int i=0;i<size;i++)
	{
		if(processes[i][3]>largest_priority)
		{
			value=processes[i][3];
			largest_priority=processes[i][3];
		}
	}
	value+=1;
	while(1)
	{
		largest_priority=value;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && allow[i]==false && processes[i][3]<largest_priority)
			{
				largest_priority=processes[i][3];
				position=i;
			}
		}
		time+=processes[position][2];
		allow[position]=true;
		std::cout<<processes[position][0]<<"->"<<processes[position][1]<<"->"<<processes[position][2]<<"->"<<time<<"\n";
		for(int i=0;i<size;i++)
		{
			if(allow[i]==true && i==size-1) breaker=1;
			else if(allow[i]==false) break;
		}
		processes[position][4]=time;
		processes[position][5]=processes[position][4]-processes[position][1];
		processes[position][6]=processes[position][5]-processes[position][2];
		if(breaker==1) break;
	}
	std::cout<<"Process ID | Arrival Time | Burst Time | Priority | Completion Time | Turnaround Time | Waiting Time\n";
	for(int i=0;i<size;i++)
	{
		Avg_turnaround+=processes[i][5];
		Avg_waitingTime+=processes[i][6];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][3]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t"<<processes[i][6]<<"\n";
	}
	std::cout<<"Average Turnaround Time = "<<Avg_turnaround/size<<std::endl;
	std::cout<<"Average Waiting Time = "<<Avg_waitingTime/size;
}
