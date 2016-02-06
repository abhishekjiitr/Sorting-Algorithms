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
void counting_sort(int* array, int n)
	{
		cout << "COUNTING SORT" << endl;
		clock_t cloc1 = clock();

		int* counts = new int[n];
		//printer(counts, n);
		for ( int i = 0 ; i < n ; i++ )
			{
				counts[array[i]]++;
			}
		for ( int i = 1 ; i < n ; i++ )
			{
				counts[i] += counts[i-1];
			}

		int index = 0;
		for ( int i = 0 ; i < n ; i++ )
			{
				while ( index < counts[i] )
					{
						array[index] = i;
						index++;
					}
			}

		clock_t cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
		//printArray(array, n);
	}
void counting_sort(node* head, int n)
	{
		cout << "COUNTING SORT" << endl;
		clock_t cloc1 = clock();

		head = head -> next;
		int min, temp;
		node *i=head, *j, *index;
		while ( i != NULL && i -> next != NULL )
			{
				j = i -> next;
				min = i -> data;
				index = i;
				while ( j != NULL )
					{
						if ( j -> data < min )
							{
								index = j;
								min = j -> data;
							}
						j = j -> next;
					}
				temp = i -> data;
				i -> data = index -> data;
				index -> data = temp;
				i = i -> next;
			}

		clock_t cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on Linked List: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
	}
