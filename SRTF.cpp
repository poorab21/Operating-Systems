#include<iostream>
bool All_Completed(bool *Complete,int size)
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
int Largest_Burst(int processes[][100],int size)
{
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(j<processes[i][2])
		{
			j=processes[i][2];
		}
	}
	return j+1;
}
int main()
{
	int processes[100][100],size,position=-1,sub[100],largest,time=0;
	bool Complete[100];
	float AvgTurnaround=0,AvgWaiting=0;
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
		Complete[i]=false;
		sub[i]=processes[i][2];
	}
	int n=Largest_Burst(processes,size);
	while(!All_Completed(Complete,size))
	{
		position=-1,largest=n;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && Complete[i]==false && sub[i]<largest)
			{
				largest=sub[i];
				position=i;
			}
			else if(processes[i][1]<=time && Complete[i]==false && sub[i]==largest)
			{
				if(processes[i][1]<processes[position][1])
				{
					largest=sub[i];
					position=i;
				}
				else if(processes[i][1]==processes[position][1])
				{
					if(processes[i][0]<processes[position][0])
					{
						largest=sub[i];
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
			time++;
			sub[position]-=1;
			if(sub[position]==0)
			{
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
