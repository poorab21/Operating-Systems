#include<iostream>
bool All_Finished(bool *finished,int size)
{
	for(int i=0;i<size;i++)
	{
		if(finished[i]==false) return false;
	}
	return true;
}
bool NotSafe(int need[][100],int size,int *available,bool *finished)
{
	for(int i=0;i<size;i++)
	{
		if(need[i][0]<=available[0] && need[i][1]<=available[1] && need[i][2]<=available[2] && finished[i]==false)
		{
			return false;
		}
		else if(All_Finished(finished,size))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int processes[100][100],size,A,B,C,available[3],need[100][100];
	int safeProcesses[100],count=0;
	bool finished[100];
	std::cout<<"Enter Total Amount of Resource A:";
	std::cin>>A;
	std::cout<<"Enter Total Amount of Resource B:";
	std::cin>>B;
	std::cout<<"Enter Total Amount of Resource C:";
	std::cin>>C;
	std::cout<<"Enter Total Number of Processes:";
	std::cin>>size;
	available[0]=A;
	available[1]=B;
	available[2]=C;
	for(int i=0;i<size;i++)
	{
		processes[i][0]=i+1;
		std::cout<<"Process "<<i+1<<std::endl;
		std::cout<<"Enter A (Allocation):";
		std::cin>>processes[i][1];
		std::cout<<"Enter B (Allocation):";
		std::cin>>processes[i][2];
		std::cout<<"Enter C (Allocation):";
		std::cin>>processes[i][3];
		std::cout<<"Enter A (Max):";
		std::cin>>processes[i][4];
		std::cout<<"Enter B (Max):";
		std::cin>>processes[i][5];
		std::cout<<"Enter C (Max):";
		std::cin>>processes[i][6];
		available[0]-=processes[i][1];
		available[1]-=processes[i][2];
		available[2]-=processes[i][3];
	}
	for(int i=0;i<size;i++)
	{
		need[i][0]=processes[i][4]-processes[i][1];
		need[i][1]=processes[i][5]-processes[i][2];
		need[i][2]=processes[i][6]-processes[i][3];
	}
	int i=0;
	while(!All_Finished(finished,size) && !NotSafe(need,size,available,finished))
	{
		if(need[i][0]<=available[0] && need[i][1]<=available[1] && need[i][2]<=available[2] && finished[i]==false)
		{
			for(int j=0;j<3;j++)
			{
				need[i][j]=0;
			}
			for(int j=0;j<3;j++)
			{
				available[j]+=processes[i][j+1];
			}
			finished[i]=true;
			safeProcesses[count]=i+1;
			count++;
		}
		i=(i+1)%size;
	}
	if(NotSafe(need,size,available,finished))
	{
		std::cout<<"System is not in Safe State"<<std::endl;
	}
	else
	{
		std::cout<<"System is in Safe State"<<std::endl;
		std::cout<<"<";
		for(int i=0;i<count;i++)
		{
			if(i==count-1)
			{
				std::cout<<"P"<<safeProcesses[i]<<">"<<std::endl;
			}
			else
			{
				std::cout<<"P"<<safeProcesses[i]<<",";
			}
		}
	}
}
