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
		int cloc1 = clock();

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
		int cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on array: " << diff <<" seconds" <<endl;
		//printArray(array, n);
	}
void selection_sort(node* head)
	{
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
	}
