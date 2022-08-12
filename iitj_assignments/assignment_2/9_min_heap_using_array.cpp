// A C++ program to demonstrate common Binary Heap Operations
#include<bits/stdc++.h>
#define N 100001
using namespace std;

// A class for Min Heap
class MinHeap
{
	int harr[N];
	int count;
public:
	 MinHeap()
	 {
		count=0;
	 }
    void MinHeapify(int);
		//parent node index
    int parent(int i) { return (i-1)/2; }
		//left child node index
    int left(int i) { return (2*i + 1); }
		//right child node index
    int right(int i) { return (2*i + 2); }
    int extractMin();
    void decreaseKey(int i, int new_val);
    int getMin() { return harr[0]; }
 	  void deleteKey(int i);
	  void insertKey(int k);
	  void print_arr();
};

void MinHeap::print_arr()
{
	for(int index=0;index<=count;index++)
	   cout<<harr[index]<<" ";
	cout<<endl;
}
void MinHeap::insertKey(int item)
{
	int i=count;
	if(i==N)
	  {
			cout<<"Overflow"<<endl;
			return;
		}
	// fixing the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > item)
	{
		harr[i]=harr[parent(i)];
	  i=parent(i);
	}
	harr[i]=item;
	count++;
}

// Decreases value of key at index i to new_val
void MinHeap::decreaseKey(int i, int new_val)
{
	if(harr[i]<new_val)
	   return;
	harr[i]=new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	   swap(harr[i], harr[parent(i)]);
	   i = parent(i);
	}
}

//remove minimum element from min heap
int MinHeap::extractMin()
{
	if ( count<= 0)
		return INT_MAX;
	if (count == 1)
		return harr[0];
	// Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[count-1];
	count--;
	MinHeapify(0);
	return root;
}


// deletes key at index i
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// heapify a subtree with the root at given index
//when subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < count && harr[l] < harr[i])
		smallest = l;
	if (r < count && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}
//main function
int main()
{
	MinHeap h;
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " "<<endl;
	cout << h.getMin() << " "<<endl;
	h.decreaseKey(2, 1);
	h.print_arr();
	cout << h.getMin()<<endl;
	return 0;
}
