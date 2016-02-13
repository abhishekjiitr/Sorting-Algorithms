// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// shell_sort.cpp

#include "node.h"
using namespace std;
void printer(node* ptr)
	{
		int i = 0;
		if ( ptr == NULL )
			return;
		while ( ptr != NULL )
			{
				if ( i > 10 )
					break;
				cout << ptr -> data << " ";
				ptr = ptr -> next;
				i++;
			}
		cout << endl;
	}
/* Function to sort an array using insertion sort*/
void insertion_sort(int* arr, int n, int gap)
{
   int i, key, j;
   for ( int x = 0 ; x < gap ; x++ )
   {
	   for (i = x+gap; i < n; i += gap)
	   {
	       key = arr[i];
	       j = i-gap;
	 
	       /* Move elements of arr[0..i-1], that are
	          greater than key, to one position ahead
	          of their current position */
	       while (j >= 0 && arr[j] > key)
	       {
	           arr[j+gap] = arr[j];
	           j = j-gap;
	       }
	       arr[j+gap] = key;
	   }
	}
}
void shell_sort(int* array, int n)
	{
		cout << "SHELL SORT" << endl;
		clock_t cloc1 = clock();
		int gap = n / 2;
		for ( ; gap > 0 ; gap /= 2 )
			insertion_sort(array, n, gap);	

		clock_t cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
		//printArray(array, n);
	}
node* incrementPtr(node* ptr, int x)
	{
		for ( int i = 0 ; i < x ; i++ )
			{
				if ( ptr == NULL )
					break;
				ptr = ptr -> next;
			}
		return ptr;
	}
// node* decrementPtr(node* ptr, int x)
// 	{
// 		for ( int i = 0 ; i < x ; i++ )
// 			{
// 				if ( ptr == NULL )
// 					break;
// 				ptr = ptr -> prev;
// 			}
// 		return ptr;
// 	}

int decrementPtr(node* &a,int gap)
{
	for(int i=0;i<gap;i++)
	{
		a=a->prev;
	}
	return a->data;
}

void shell_sort(node * ptr,int n)       
{
	cout << "SHELL SORT" << endl;
	clock_t cloc1 = clock();
	ptr = ptr -> next;
	ptr -> prev = NULL;
	int h=1;
	node* head = ptr;
	while(h>=1)
	{
	
	for(int k=0;k<h;k++){
		ptr=ptr->next;
	}
					
		for(int i=h;i<n;i++)
		{
			node*current=ptr;
			node*back =ptr;
			int value=current->data;
			int index=-1;
			
			
		for(int j=i-h;j>=0;j-=h)
		{
			back=ptr;
			
			if((decrementPtr(back,h))>value)
			{
				index=j;
				for(int k=0;k<h;k++)
				ptr=ptr->prev;	
			}
			else
			break;
		}
		
		if(index >= 0)
		{
			int temp=value;
			node*ptr=current;
			for(int j=i;j>index;j-=h)
			{	
				ptr->data = decrementPtr(ptr,h);
			}
			ptr->data=temp;
		}
		current=current->next;
		ptr=current;
		
	}
	ptr=head;
	h=h/3;
	}
	clock_t cloc2 = clock();
	int diff = cloc2 - cloc1;
	cout << "Time taken on Linked List: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
}
