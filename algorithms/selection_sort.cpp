using namespace std;
void selection_sort(int array[], int n)
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
		cout << "Time taken on array: " << diff <<" seconds";
		//printArray(array, n);
	}
void selection_sort(node* head)
	{
		node* ptr, *ptr2, *index, *temp;
		ptr = ptr -> next;
		while ( ptr -> next != NULL && ptr -> next -> next != NULL )
			{	
				ptr2 = ptr -> next; // initially supposed as minimum element
				index = ptr;
				int min = ptr -> data
				while ( ptr2 != NULL && ptr2 -> next != NULL )
					{
						if ( min > ptr2 -> data )
							{
								index = ptr2;
								min = ptr2 -> data; 
							}
						// SWAP index and ptr
							
						ptr2 = ptr2 -> next;
					}
				
			}
	}