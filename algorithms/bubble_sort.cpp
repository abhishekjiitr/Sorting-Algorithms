// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// Bubble.cpp

#include "node.h"
using namespace std;
void bubble_sort(int* array, int n)
	{
		cout << "BUBBLE SORT\n";
		int cloc1 = clock();
		int x=n;
		while(n)
		{
			for ( int i = 1 ; i < n ; i++ )
			{
				if(array[i-1]>array[i])
				{
					swap(array[i-1],array[i]);
				}
			}
			n--;
		}
		int cloc2 = clock();
		//printArray(array,x);
		int diff = cloc2 - cloc1;
		cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
		
	}
void bubble_sort(node* head, int n)
	{
		cout << "BUBBLE SORT\n";
		int cloc1 = clock();
		node *j=head;
		int done=1;
		while ( done )
		{
			done=0;
			j=head;
			while(j->next!=NULL)
			{
				if(j->data>j->next->data){swap(j->data,j->next->data); done++; }
				j=j->next;
			}
		//printLinkedList(head);
		}
		int cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on linked list: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
	}
