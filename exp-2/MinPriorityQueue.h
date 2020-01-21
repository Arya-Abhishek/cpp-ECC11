# include <vector>
using namespace std;

class minPriorityQueue
{
private:
	vector <int> pq;
	int childIndex;

public:

	minPriorityQueue()
	{

	}

    // Returns Number of Elements present in the priority queue
	int getSize()
	{ 
		return pq.size();
	}

	bool isEmpty()
	{
		return (pq.size()==0);
	}

	int getMin()
	{
		if (isEmpty())
		{
			return 0; // Signifying that the pq is empty;
		}

		return pq[0];
	}

	void insert(int element)
	{
		if (pq.size()==0)
		{
			pq.push_back(element);
			return;
		}

      pq.push_back(element);  // to staisfy cbt property
      int childIndex=pq.size()-1;
      int parentIndex=(childIndex-1)/2;
      int parentElement=pq[parentIndex];
      int childElement=pq[childIndex];
      
      // upheapify
      while  (parentElement > childElement)
      {
      	int temp=pq[parentIndex];
      	pq[parentIndex]=element;
      	pq[childIndex]=temp;

      	childIndex=parentIndex;
      	parentIndex=(childIndex-1)/2;

      	parentElement=pq[parentIndex];
      	childElement=pq[childIndex];

      	if (childIndex==0)
      	{
      		break;
      	}
      }
  }

  int removeMin()
  {
  	if(pq.size()==0)
  	{
  		return -1;
  	}

  	int elementToBeRemoved=pq[0];
  	int childIndex=pq.size()-1;

	// Swap of first Element and last element
  	int temp=pq[childIndex];
  	pq[childIndex]=pq[0];
  	pq[0]=temp;

	//deletion of last Element
  	int data=pq[childIndex];
  	pq.pop_back();

  	int parentIndex=0;
  	int lci=2*parentIndex+1;
  	int rci=2*parentIndex+2;

  	while (lci < pq.size())
  	{

  		if (lci > pq.size()-1 && rci>pq.size()-1)
  		{
  			break;
  		}

  		else if (lci>pq.size()-1)
  		{
  			if (pq[parentIndex] > pq[rci])
  			{
              int temp=pq[parentIndex];
              pq[parentIndex]=pq[rci];
              pq[rci]=temp;

              parentIndex=rci;
  			}

  			else
  			{
  				break;
  			}

  		}

  		else if (rci>pq.size()-1)
  		{
          if (pq[parentIndex] > pq[lci])
          {
            int temp=pq[parentIndex];
            pq[parentIndex]=pq[lci];
            pq[lci]=temp;

            parentIndex=lci;
          }

          else
          {
          	break;
          }
  		}

  		else
  		{
  			int minElement;
  			int minChildIndex;

  			if (pq[lci] < pq[rci])
  			{
  				minElement=pq[lci];
  				minChildIndex=lci;
  			}

  			else
  			{
  				minElement=pq[rci];
  				minChildIndex=rci;
  			}

  			if (minElement > pq[parentIndex])
  			{
  				break;
  			}

  			int temp=pq[parentIndex];
  			pq[parentIndex]=pq[minChildIndex];
  			pq[minChildIndex]=temp;

  			parentIndex=minChildIndex;
  		}

  		lci=2*parentIndex+1;
  		rci=2*parentIndex+2;
  	}

  	return data;  
  }


};