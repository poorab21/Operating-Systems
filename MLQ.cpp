#include<iostream>
bool All_Completed(bool *Complete,int size)
{
	for(int i=0;i<size;i++)
	{
		if(Complete[i]==true && i==size-1) return true;
		else if(Complete[i]==false) return false;
	}
}
int main()
{
	int processes[100][100],size,sub[100],queue=0,position=-1,time=0;
	bool Complete[100];
	float AvgTurnaround=0,AvgWaiting=0;
	std::cout<<"\t\t|Queue 1 Processing Schedule = FCFS|"<<std::endl;
	std::cout<<"\t\t|Queue 2 Processing Schedule = SJF |"<<std::endl;
	std::cout<<"\t\t|__________________________________|"<<std::endl;
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
		std::cout<<"Enter Queue Number:";
		std::cin>>processes[i][3];
		sub[i]=processes[i][2];
		Complete[i]=false;
	}
	while(!All_Completed(Complete,size))
	{
		queue=3,position=-1;
		for(int i=0;i<size;i++)
		{
			if(processes[i][1]<=time && Complete[i]==false && processes[i][3]<queue)
			{
				queue=processes[i][3];
				position=i;
			}
			else if(processes[i][1]<=time && Complete[i]==false && processes[i][3]==queue)
			{
				if(queue==1)
				{
					if(processes[i][1]<processes[position][1])
					{
						position=i;
					}
					else if(processes[i][1]==processes[position][1])
					{
						if(processes[i][0]<processes[position][0])
						{
							position=i;
						}
					}
				}
				else if(queue==2)
				{
					if(sub[i]<sub[position])
					{
						position=i;
					}
					else if(sub[i]==sub[position])
					{
						if(processes[i][1]<processes[position][1])
						{
							position=i;
						}
						else if(processes[i][1]==processes[position][1])
						{
							if(processes[i][0]<processes[position][0])
							{
								position=i;
							}
						}
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
			std::cout<<processes[position][0]<<"->"<<processes[position][1]<<"->"<<processes[position][2]<<"->"<<time<<"\n";
			if(sub[position]==0)
			{
				Complete[position]=true;
				processes[position][4]=time;
				processes[position][5]=processes[position][4]-processes[position][1];
				processes[position][6]=processes[position][5]-processes[position][2];
				if(processes[position][6]<0)
				{
					processes[position][6]=0;
				}
			}
		}
	}
	std::cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Completion Time"<<"\t"<<"Turnaround Time"<<"\t"<<"Waiting Time\n";
	for(int i=0;i<size;i++)
	{
		AvgTurnaround+=processes[i][5];
		AvgWaiting+=processes[i][6];
		std::cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<processes[i][4]<<"\t\t"<<processes[i][5]<<"\t\t"<<processes[i][6]<<"\n";
	}
	std::cout<<"Average Turnaround Time = "<<AvgTurnaround/size<<"\n";
	std::cout<<"Average Waiting Time = "<<AvgWaiting/size;
}
