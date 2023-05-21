#include<iostream>
#include"Processing_Algorithms.cpp"
int main()
{
	int choice;
	std::cout<<"\t\t ______________________________________"<<std::endl;
	std::cout<<"\t\t|       Scheduling Processes           |"<<std::endl;
	std::cout<<"\t\t|______________________________________|"<<std::endl;
	std::cout<<"\t\t| 1.Highest Response Ratio Next(HRRN)  |"<<std::endl;
	std::cout<<"\t\t| 2.Longest Job First(LJF)             |"<<std::endl;
	std::cout<<"\t\t| 3.Longest Remaining Time First(LRTF) |"<<std::endl;
	std::cout<<"\t\t| 4.Multi-Level Feedback Queue(MLFQ)   |"<<std::endl;
	std::cout<<"\t\t| 5.Multi-Level Queue Scheduling(MLQ)  |"<<std::endl;
	std::cout<<"\t\t| 6.Preemptive Priority Scheduling     |"<<std::endl;
	std::cout<<"\t\t| 7.Shortest Remaining Time First(SRTF)|"<<std::endl;
	std::cout<<"\t\t|______________________________________|"<<std::endl;
	std::cout<<"\t\t| Which Process Scheduling Algorithm   |"<<std::endl;
	std::cout<<"\t\t| To Execute?                          |"<<std::endl;
	std::cout<<"\t\t|______________________________________|"<<std::endl;
	std::cout<<"\n\t\t Choose:";
	std::cin>>choice;
	if(choice==1)
	{
		HRRN();
	}
	else if(choice==2)
	{
		LJF();
	}
	else if(choice==3)
	{
		LRTF();
	}
	else if(choice==4)
	{
		MLFQ();
	}
	else if(choice==5)
	{
		MLQ();
	}
	else if(choice==6)
	{
		Priority();
	}
	else if(choice==7)
	{
		SRTF();
	}
}
