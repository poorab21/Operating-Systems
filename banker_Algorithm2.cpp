#include<iostream>
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
	while(count<size)
	{
		bool found=false;
		for(int i=0;i<size;i++)
		{
			if(finished[i]==false)
			{
				int j;
				for(j=0;j<3;j++)
				{
					if(need[i][j]>available[j]) break;
				}
				if(j==3)
				{
					for(int k=0;k<3;k++)
					{
						available[k]+=processes[i][k+1];
					}
					finished[i]=true;
					found=true;
					safeProcesses[count]=i+1;
					count++;
				}
			}
		}
		if(found==false)
		{
			std::cout<<"System is not in Safe State"<<std::endl;
			break;
		}
		else if(count==size)
		{
			std::cout<<"System is in Safe State"<<std::endl;
			for(int i=0;i<size;i++)
			{
				std::cout<<"P"<<safeProcesses[i]<<" ";
			}
			break;
		}
	}
}
