// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// insertion_sort.cpp

using namespace std;
#include "node.h"
void insertion_sort(int* array, int n)
	{

		cout << "INSERTION SORT\n";
		int cloc1 = clock();
		int x, j;
		for ( int i = 0 ; i < n ; i++ )
			{
				x = array[i];
				j = i-1;
				while(j >= 0 && array[j]>x)
				{
					array[j+1] = array[j];
					j--;
				}
				array[j+1] = x;
			}
		int cloc2 = clock();
		int diff = cloc2 - cloc1;
	cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
		//printArray(array,n);
	}
void insertion_sort(node* head, int n)
	{
		cout << "INSERTION SORT\n";
		int cloc1 = clock();
		int x;
		node *i=head, *j;
		while ( i !=NULL )
			{
				x = i -> data;
				j = i -> prev;
				while ( j!=NULL && j ->data >x)
					{
						j ->next ->data =j ->data;
						j = j -> prev;
					}
				if(j!=NULL) j ->next ->data =x;
				i =i ->next;
			//printLinkedList(head);
			}
		int cloc2 = clock();
		int diff = cloc2 - cloc1;
	cout << "Time taken on linked list: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
	}
