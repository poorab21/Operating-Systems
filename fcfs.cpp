#include<iostream>
bool Completion(bool *Completed,int size)
{
	for(int i=0;i<size;i++)
	{
		if(Completed[i]==true && i==size-1) return true;
		else if(Completed[i]==false) return false;
	}
}
int First_Arrival(int processes[][100],int size)
{
	int largest=0;
	for(int i=0;i<size;i++)
	{
		if(largest<processes[i][1])
		{
			largest=processes[i][1];
		}
	}
	return largest+1;
}
int main()
{
	int processes[100][100],size,time=0;
	bool Completed[100];
	float AvgTurnaround=0,AvgWaiting=0;
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Length:";
		std::cin>>processes[i][2];
		Completed[i]=false;
	}
	while(!Completion(Completed,size))
	{
		int FCFS=First_Arrival(processes,size);
		int position=-1;
		for(int i=0;i<size;i++)
		{
			if(FCFS>processes[i][1] && Completed[i]==false && processes[i][1]<=time)
			{
				position=i;
				FCFS=processes[i][1];
			}
			else if(FCFS==processes[i][1] && Completed[i]==false && processes[i][1]<=time)
			{
				if(processes[i][0]<processes[position][0])
				{
					position=i;
					FCFS=processes[i][1];
				}
			}
		}
		if(position==-1) time++;
		else
		{
			Completed[position]=true;
			time+=processes[position][2];
			processes[position][3]=time;
			processes[position][4]=processes[position][3]-processes[position][1];
			processes[position][5]=processes[position][4]-processes[position][2];
			if(processes[position][5]<0)
			{
				processes[position][5]=0;
			}
		}
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Completion Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time"<<std::endl;
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][4];
		AvgWaiting+=processes[i][5];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][3]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<std::endl;
	}
	std::cout<<"Average Turnaround Time = "<<AvgTurnaround/size<<std::endl;
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size<<std::endl;
}
