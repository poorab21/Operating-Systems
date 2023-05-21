#include<iostream>
float RR(int i,int processes[][100],int time)
{
	float y=float(processes[i][1]);
	float z=float(processes[i][2]);
	float x=(((time-y)+z)/z);
	return x;
}
bool All_Complete(bool *Complete,int size)
{
	for(int i=0;i<size;i++)
	{
		if(Complete[i]==true && i==size-1)
		{
			return true;
		}
		else if(Complete[i]==false) return false; 
	}
}
int main()
{
	int processes[100][100],size,time=0,position=-1;
	float ResponseTime=-9999,AvgTurnaround=0,AvgWaiting=0;
	bool Complete[100];
	std::cout<<"Enter Number of Processes:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Enter Arrival Time:";
		std::cin>>processes[i][1];
		std::cout<<"Enter Burst Time:";
		std::cin>>processes[i][2];
		Complete[i]=false;
	}
	int i=0;
	while(!All_Complete(Complete,size))
	{
		ResponseTime=-9999;
		position=-1;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && Complete[i]==false && ResponseTime<RR(i,processes,time))
			{
				ResponseTime=RR(i,processes,time);
				position=i;
			}
			else if(ResponseTime==RR(i,processes,time) && processes[i][1]<=time && Complete[i]==false)
			{
				if(processes[position][1]>processes[i][1])
				{
					ResponseTime=RR(i,processes,time);
					position=i;
				}
				else if(processes[position][1]==processes[i][1])
				{
					if(processes[position][0]>processes[i][0])
					{
						ResponseTime=RR(i,processes,time);
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
			Complete[position]=true;
			processes[position][3]=time;
			processes[position][4]=processes[position][3]-processes[position][1];
			processes[position][5]=processes[position][4]-processes[position][2];
			if(processes[position][5]<0)
			{
				processes[position][5]=0;
			}
		}
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
