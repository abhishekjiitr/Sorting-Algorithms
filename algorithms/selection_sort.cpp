using namespace std;
void selection_sort(int array[], int n)
	{
		int cloc1 = clock();

		int min, index, temp;
		for ( int i = 0 ; i < n - 1 ; i++ )
			{
				min = array[i];

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
		cout << "Time taken: " << diff <<" seconds";
		//printArray(array, n);
	}