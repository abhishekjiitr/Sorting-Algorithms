// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// quick_sort.cpp

#include "node.h"
using namespace std;
void swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
void printerArray(int* a, int n)
	{
		for ( int i = 0 ; i < n ; i++ )
			cout << a[i] << " ";
		cout << endl;
	}
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

int partition(int* arr, int l, int h)
	{
		int x = arr[h];
		int i = (l-1);
		for ( int j = l ; j <= h-1 ; j++ )
			{
				if ( arr[j] <= x )
					{
						i++;
						swap(&arr[i], &arr[j]);
					}
			}
		swap(&arr[i+1], &arr[h]);
		return (i+1);
	}
void qsort(int* array, int l, int h)
	{
		if ( l < h )
			{
				int p = partition(array, l, h);
				qsort(array, l, p-1);
				qsort(array, p+1, h);
			}
	}
void quick_sort(int* array, int n)
	{
		cout << "QUICK SORT" << endl;
		clock_t cloc1 = clock();

		qsort(array, 0, n-1);


		clock_t cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
		//printArray(array, n);
	}


node* getPtr(node* head, int index)
	{
		for ( int i = 0 ; i < index ; i++ )
			{
				head = head -> next;
			}
		return head;
	}

int getElement(node* head, int index)
	{
		for ( int i = 0 ; i < index ; i++ )
			{
				head = head -> next;
			}
		return head -> data;
	}
int swap(node* head, int i, int j)
	{
		node* pi = getPtr(head, i);
		node* pj = getPtr(head, j);
		int temp = pi -> data;
		pi -> data = pj -> data;
		pj -> data = temp;
	}
int partition(node* head, int l, int h)
	{
		int x = getElement(head, h);
		int i = (l-1);
		for ( int j = l ; j <= h-1 ; j++ )
			{
				if ( getElement(head, j) <= x )
					{
						i++;
						swap(head, i, j);
					}
			}
		swap(head,i+1, h);
		return (i+1);
	}
void qsort(node* head, int l, int h)
	{
		if ( l < h )
			{
				int p = partition(head, l, h);
				qsort(head, l, p-1);
				qsort(head, p+1, h);
			}
	}
void quick_sort(node* head, int n)
	{
		cout << "QUICK SORT" << endl;
		clock_t cloc1 = clock();

		head = head -> next;
		qsort(head, 0, n-1);

		clock_t cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on Linked List: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
	}

