// A C++ program to demonstrate common Binary Heap Operations
#include<bits/stdc++.h>
using namespace std;
// A class for Min Heap
class MinHeap
{
	vector<int> harr;
public:
    void MinHeapify(int);
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    int extractMin();
    void decreaseKey(int i, int new_val);
    int getMin() { return harr[0]; }
 	void deleteKey(int i);
	void insertKey(int k);
	void print_arr();
	void insert_vector(int,int);
};
void MinHeap::insert_vector(int index,int item)
{
	if(index==harr.size())
	    harr.push_back(item);
	else harr[index]=item;	
}
//void MinHeap::print_arr()
//{
//	for(int index=0;index<harr.size();index++)
//	   cout<<harr[index]<<" ";
//	cout<<endl;
//}
void MinHeap::insertKey(int item)
{
	int i=harr.size();    
	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > item)
	{
		insert_vector(i,harr[parent(i)]);
	    i=parent(i);
	}
	insert_vector(i,item);
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	if(harr[i]<new_val)
	   return;
	insert_vector(i,new_val);
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	   swap(harr[i], harr[parent(i)]);
	   i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
	if (harr.size() <= 0)
		return INT_MAX;
	if (harr.size() == 1)
		return harr[0];
	// Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[harr.size()-1];
	harr.pop_back();
	MinHeapify(0);
	return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < harr.size() && harr[l] < harr[i])
		smallest = l;
	if (r < harr.size() && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}
int kthsmallest(int arr[],int n,int k,MinHeap h)
{
	cout<<"hello"<<endl;
	for(int i=0;i<n;i++)
	   h.insertKey(arr[i]);
	//h.print_arr();
	
	for(int i=0;i<k-1;i++)
	   h.extractMin();
	return h.getMin();
	   
}

// Driver program to test above functions
int main()
{
	MinHeap h;
   int arr[]={2,4,5,1,9,99};
   int n=sizeof(arr)/sizeof(arr[0]);
   
   int k=3;
   
   
   cout<<kthsmallest(arr,n,k,h);
   
}

