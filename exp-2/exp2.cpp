# include <iostream>
# include "MinPriorityQueue.h"
# include <sys/time.h>
#include "space.h"
using namespace std;


long getTimeInMicroSeconds()
{
	struct timeval start;
	gettimeofday(&start,NULL);
	return start.tv_sec*1000000+start.tv_usec;
}


void selectionSort(int * arr,int n)
{
	for (int i=0;i<n;i++)
	{
		int min=arr[i];
		int pos=i;
		for (int j=i+1;j<n;j++)
		{
			if (arr[j]<min)
			{
				min=arr[j];
				pos=j;
			}
		}

		// swap the ith element with the min
		int temp=arr[i];
		arr[i]=min;
		arr[pos]=temp;

		cout<<"After"<<i+1<<"th pass array is:";

		for (int k=0;k<n;k++)
		{
			cout<<arr[k]<<" ";
		}

		cout<<endl;
	}
}

void insertionSort(int * arr,int n)
{
	for (int i=1;i<n;i++)
	{
		int find=arr[i];
		int times=i-1;
		while (times>=0 && arr[times]>find)
		{
			arr[times+1]=arr[times];
			times--;
		}

		arr[times+1]=find;

		cout<<"After"<<i-1<<"th pass array is:";

		for (int k=0;k<n;k++)
		{
			cout<<arr[k]<<" ";
		}

		cout<<endl;
	}
}

void bubleSort(int * arr,int n)
{
	for (int i=0;i<n;i++)
	{

		for (int j=i+1;j<n-i;j++)
		{
			if (arr[j-1] > arr[j])
			{
				// swap them
				int temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}

			else
			{
				break;
			}
		}

		cout<<"After"<<i<<"th pass array is:";

		for (int k=0;k<n;k++)
		{
			cout<<arr[k]<<" ";
		}

		cout<<endl;
	}
}

void mergeSortHelper(int * arr,int si,int ei,int & count)
{
	// Base Case
	if (si>=ei)
	{
		return;
	}
	
	int mid=(si+ei)/2;
	count++;
	
	// Induction Hypothesis
	mergeSortHelper(arr,si,mid,count);
	mergeSortHelper(arr,mid+1,ei,count);

	// Merge Two Sorted Arrays
	int * finalArr=new int [ei-si+1];
	int firstArraySi=si;
	int secondArraySi=mid+1;
	int k=0;

	while (firstArraySi<=mid && secondArraySi<=ei)
	{
		if (arr[firstArraySi] < arr[secondArraySi])
		{
			finalArr[k]=arr[firstArraySi];
			firstArraySi++;
		}

		else
		{
			finalArr[k]=arr[secondArraySi];
			secondArraySi++;
		}

		k++;
	}

	while (firstArraySi<=mid)
	{
		finalArr[k]=arr[firstArraySi];
		firstArraySi++;
		k++;
	}

	while (secondArraySi<=ei)
	{
		finalArr[k]=arr[secondArraySi];
		secondArraySi++;
		k++;
	}

	k=0;

	for (int i=si;i<=ei;i++)
	{
		arr[i]=finalArr[k];
		k++;
	}

	delete [] finalArr;
}

void mergeSort(int * arr,int n,int & count)
{
	mergeSortHelper(arr,0,n-1,count);
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int findPartitionIndex(int * arr,int si,int ei)
{
	int count=0;
	for (int i=si;i<=ei;i++)
	{
		if (arr[i] < arr[si])
		{
			count++;
		}
	}

	// putting the element at si in the correct postiton
	int elementOfParition=arr[si];
	int indexOfPartition=si+count;

	int temp=arr[si];
	arr[si]=arr[si+count];
	arr[si+count]=temp;

	// placing all the elements greater than the si 
	int i=si;
	int j=ei;

	while (i<=si+count && j>=si+count)
	{
		if (arr[i]<elementOfParition && arr[j]>elementOfParition)
		{
			i++;
			j--;
		}

		else if(arr[i]<elementOfParition)
		{
			i++;
		} 

		else if (arr[j]>=elementOfParition)
		{
			j--;
		}

		else
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			
			i++;
			j--;
		}
	}

	return si+count;
}

void quickSortHelper(int * arr,int si,int ei,int & count)
{
	// Base Case
	if (si>=ei)
	{
		return;
	}

	count++;

    // Our Calculation
	int indexOfPartition=findPartitionIndex(arr,si,ei);
	
	// Inuction Hypothesis
	quickSortHelper(arr,si,indexOfPartition-1,count);
	quickSortHelper(arr,indexOfPartition+1,ei,count);
}

void quickSort(int * arr,int n,int & count)
{
	quickSortHelper(arr,0,n-1,count);

	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

	cout <<endl;
}

void heapSort(int * arr,int n)
{
  minPriorityQueue minPQ;
  for (int i=0;i<n;i++)
  {
  	minPQ.insert(arr[i]);
  }

  while(!minPQ.isEmpty())
  {
    cout<<minPQ.removeMin()<<" ";
  }

  cout<<endl;
}

int main()
{
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	int * arr=new int [n];
	long startTime;
	long endTime;

	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int choice=0;
	cout<<"LIST OF ALGORITHMS:"<<endl;
	cout<<"1: SELECTION SORT"<<endl;
	cout<<"2: INSERTION SORT"<<endl;
	cout<<"3: BUBBLE SORT"<<endl;
	cout<<"4: MERGE SORT"<<endl;
	cout<<"5: QUICK SORT"<<endl;
	cout<<"6: HEAP SORT"<<endl;

	cout<<"Enter your choice:"<<endl;
	cin>>choice;
	int count=0;
	float spaceComplexity=4*(n+2)+3*8;

	switch (choice)
	{
		case 1:startTime=getTimeInMicroSeconds();
		selectionSort(arr,n);
		endTime=getTimeInMicroSeconds();
		cout<<"Time taken for execution is:"<<endTime-startTime<<"seconds"<<endl;
		cout<<"Space Taken by the program is:"<<(1.0)*spaceComplexity/n<<"bytes"<<endl;
		break;

		case 2:startTime=getTimeInMicroSeconds();
		insertionSort(arr,n);
		endTime=getTimeInMicroSeconds();
		cout<<"Time taken for execution is:"<<endTime-startTime<<"seconds"<<endl;
		cout<<"Space Taken by the program is:"<<(1.0)*spaceComplexity/n<<"bytes"<<endl;
		break;

		case 3:startTime=getTimeInMicroSeconds();
		bubleSort(arr,n);
		endTime=getTimeInMicroSeconds();
		cout<<"Time taken for execution is:"<<endTime-startTime<<"seconds"<<endl;
		cout<<"Space Taken by the program is:"<<(1.0)*spaceComplexity/n<<"bytes"<<endl;
		break;

		case 4:startTime=getTimeInMicroSeconds();
		mergeSort(arr,n,count);
		endTime=getTimeInMicroSeconds();
		cout<<"Time taken for execution is:"<<endTime-startTime<<"seconds"<<endl;
		cout<<"Space Taken by the program is:"<<(1.0)*(count +spaceComplexity)/n<<"bytes"<<endl;
		break;

		case 5:startTime=getTimeInMicroSeconds();
		quickSort(arr,n,count);
		endTime=getTimeInMicroSeconds();
		cout<<"Time taken for execution is:"<<endTime-startTime<<"seconds"<<endl;
		cout<<"Space Taken by the program is:"<<(1.0)*(count+spaceComplexity)/n<<"bytes"<<endl;
		break;

		case 6:startTime=getTimeInMicroSeconds();
		heapSort(arr,n);
		endTime=getTimeInMicroSeconds();
		cout<<"Time taken for execution is:"<<endTime-startTime<<"seconds"<<endl;
		cout<<"Space Taken by the program is:"<<(1.0)*spaceComplexity/n<<"bytes"<<endl;
		break;
	}

	return 0;
}