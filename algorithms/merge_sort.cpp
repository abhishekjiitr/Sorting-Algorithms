// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// merge_sort.cpp

using namespace std;
#include "node.h"
void merge(int* array,int l,int mid,int r)
{
	int i,j,k;
	int n1 = mid - l + 1;
    int n2 =  r - mid;
    int a1[n1], a2[n2];
    for(i = 0; i < n1; i++) a1[i] = array[l + i];
    for(j = 0; j < n2; j++) a2[j] = array[mid + 1+ j];
    i=0,j=0;
    for(k=l;i<n1 && j<n2;k++)
    {
		if(a1[i]<= a2[j])
		{
			array[k] = a1[i];
			i++;
		}
		else
		{
			array[k] = a2[j];
			j++;
		}
    }
    while(i<n1)
    {
    	array[k] = a1[i];
    	i++;
    	k++;
    }
    while(j<n2)
    {
    	array[k] = a2[j];
    	j++;
    	k++;
    }	
}
void merge_sort(int* array,int l,int r)
{
	if(r>l)
	{
		int mid = (l+r)/2;
		merge_sort(array,l,mid);
		merge_sort(array,mid+1,r);
		merge(array,l,mid,r);
	}
}
void merge_sort(int* array, int n)
	{
        cout << "MERGE SORT\n";
		clock_t cloc1 = clock();
		merge_sort(array,0,n);
        clock_t cloc2 = clock();
        int diff = cloc2 - cloc1;
        cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
	}

