#include<iostream>
bool IsEmpty(int *arr,int frame_size)
{
	for(int i=0;i<frame_size;i++)
	{
		if(arr[i]==-1) return true;
	}
	return false;
}
bool Exists(int num,int *arr,int frame_size)
{
	for(int i=0;i<frame_size;i++)
	{
		if(num==arr[i]) return true;
	}
	return false;
}
int main()
{
	std::string page_reference_string;
	int frame_size,j=0,*stack,*arr,page_fault=0;
	std::cout<<"Enter Page Reference String:";
	std::cin>>page_reference_string;
	std::cout<<"Enter Frame Size:";
	std::cin>>frame_size;
	stack=new int[frame_size];
	arr=new int[frame_size];
	for(int i=0;i<frame_size;i++)
	{
		arr[i]=-1;
	}
	std::cout<<"Page Reference | Frames"<<std::endl;
	for(int i=0;i<page_reference_string.length();i++)
	{
		if(IsEmpty(arr,frame_size) && !Exists(page_reference_string[i]-48,arr,frame_size))
		{
			arr[j]=page_reference_string[i]-48;
			stack[j]=page_reference_string[i]-48;
			j++;
			page_fault++;
		}
		else if(IsEmpty(arr,frame_size) && Exists((page_reference_string[i])-48,arr,frame_size))
		{
			for(int k=0;k<frame_size;k++)
			{
				if(stack[k]==(page_reference_string[i])-48)
				{
					for(int l=k;l<frame_size-1;l++)
					{
						stack[l]=stack[l+1];
					}
					stack[frame_size-1]=(page_reference_string[i])-48;
					break;
				}
			}
		}
		else if(!IsEmpty(arr,frame_size))
		{
			if(Exists((page_reference_string[i]-48),arr,frame_size))
			{
				for(int k=0;k<frame_size;k++)
				{
					if(stack[k]==(page_reference_string[i])-48)
					{
						for(int l=k;l<frame_size-1;l++)
						{
							stack[l]=stack[l+1];
						}
						stack[frame_size-1]=(page_reference_string[i])-48;
						break;
					}
				}
			}
			else
			{
				for(int k=0;k<frame_size;k++)
				{
					if(arr[k]==stack[0])
					{
						arr[k]=page_reference_string[i]-48;
					}
				}
				for(int k=0;k<frame_size-1;k++)
				{
					stack[k]=stack[k+1];
				}
				stack[frame_size-1]=page_reference_string[i]-48;
				page_fault++;
			}
		}
		std::cout<<page_reference_string[i]<<"\t\t";
		for(int k=0;k<frame_size;k++)
		{
			std::cout<<arr[k]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Page Faults = "<<page_fault<<std::endl;
}
