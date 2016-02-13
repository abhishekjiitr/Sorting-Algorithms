// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// selection_sort.cpp

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
void selection_sort(int* array, int n)
	{
		cout << "SELECTION SORT" << endl;
		clock_t cloc1 = clock();

		int min, index, temp;
		for ( int i = 0 ; i < n - 1 ; i++ )
			{
				min = array[i];
				index = i;
				for ( int j = i+1 ; j < n ; j++)
					{
						if ( array[j] < min )
							{
								index = j;
								min = array[j];
							}
					}
				temp = array[i];
				array[i] = min;
				array[index] = temp;
			}
		clock_t cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
		//printArray(array, n);
	}
// void selection_sort(node* head, int n)
// 	{
// 		cout << "COUNTING SORT" << endl;
// 		clock_t cloc1 = clock();

// 		int* count = new int[n];
// 		head = head -> next;
	
// 		node *ptr=head;
// 		while ( ptr != NULL  )
// 			{
// 				count[ptr->data]++;
// 			}
// 		for ( int i = 1 ; i < n ; i++ )
// 			{
// 				count[i] += count[i-1]; 
// 			}
// 		int index = 0;
// 		ptr = head;
// 		for ( int i =  0 ; i < n ; i++ )
// 			{
// 				while (  index < count[i] )
// 					{
// 						ptr -> data = i;
// 						index++;
// 					}
// 			}

// 		clock_t cloc2 = clock();
// 		int diff = cloc2 - cloc1;
// 		cout << "Time taken on nodeed List: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
// 	}

void selection_sort(node *a ,int n)
{

	cout << "SELECTION SORT" << endl;
	clock_t cloc1 = clock();	
	int index;
	node*head=a;
	for(int i=0;i<n;i++)
	{
		node*current=a;
		int min=a->data;
		node*mini=a;
					
		for(int j=i;j<n;j++)
		{
			if(a->data<=min)
			{
				min=a->data;
				index=j;
				mini=a;
			}
			a=a->next;
		}
		int temp=current->data;
		current->data=min;
		mini->data=temp;
		
		current=current->next;
		a=current;
	}
	clock_t cloc2 = clock();
	int diff = cloc2 - cloc1;
	cout << "Time taken on linked list: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
}
