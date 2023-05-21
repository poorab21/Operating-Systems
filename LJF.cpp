#include<iostream>
int main()
{
	int processes[100][100],size,largest=-1,position=-1,sub[100],time=0,breaker=0;
	float AvgTurnaround=0,AvgWaiting=0;
	bool Complete[100];
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	if(size==0) return 0;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		sub[i]=processes[i][2];
	}
	while(1)
	{
		int largest=-1;
		position=-1;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1] <= time && sub[i] != -1 && largest<processes[i][2])
			{
				largest=processes[i][2];
				position=i;
			}
			else if(processes[i][2]==processes[position][2] && processes[position][1]<=time && processes[i][1]<=time && sub[i] != -1 && sub[position] != -1)
			{
				if(processes[i][1]<processes[position][1])
				{
					largest=processes[i][2];
					position=i;
				}
				else if(processes[i][1]==processes[position][1])
				{
					if(processes[i][0]<processes[position][0])
					{
						largest=processes[i][2];
						position=i;
					}
				}
			}
		}
		if(position==-1)
		{
			time++;
		}
		else
		{
			time+=processes[position][2];
			processes[position][3]=time;
			processes[position][4]=processes[position][3]-processes[position][1];
			processes[position][5]=processes[position][4]-processes[position][2];
			if(processes[position][5]<0)
			{
				processes[position][5]=0;
			}
			Complete[position]=true;
			std::cout<<processes[position][0]<<"->"<<processes[position][2]<<"->"<<time<<"\n";
			sub[position]=-1;
		}
		for(int i=0;i<size;i++)
		{
			if(Complete[i]==true && i==size-1)
			{
				breaker=1;
			}
			else if(Complete[i]==false) break;
		}
		if(breaker==1) break;
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time"<<"\t"<<"Completion Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][4];
		AvgWaiting+=processes[i][5];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t"<<processes[i][3]<<"\n";
	}
	std::cout<<"Average Turnaround time = "<<AvgTurnaround/size<<std::endl;
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size;
}
