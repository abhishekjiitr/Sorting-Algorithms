// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// Main.cpp - Top Level File.

#include <bits/stdc++.h>
//#include "algorithms/selection_sort.cpp"
//#include "algorithms/counting_sort.cpp"
//#include "algorithms/shell_sort.cpp"
//#include "algorithms/quick_sort.cpp"
//#include "algorithms/bucket_sort.cpp"
//#include "algorithms/bubble_sort.cpp"
//#include "algorithms/insertion_sort.cpp"
//#include "algorithms/radix_sort.cpp"
#include "algorithms/merge_sort.cpp"
//#include "algorithms/heap_sort.cpp"
using namespace std;
void printArray(int* a, int n)
	{
		for ( int i = 0 ; i < n ; i++ )
			cout << a[i] << " ";
		cout << endl;
	}
void printLinkedList(node* ptr)
	{
		if ( ptr == NULL )
			return;
		ptr = ptr -> next;
		while ( ptr != NULL )
			{
				cout << ptr -> data << " ";
				ptr = ptr -> next;
			}
		cout << endl;
	}
int main()
	{
	
		//srand((int)time(0));
		int N;
		int random;
		node *head, *ptr;
		cout << "Enter N:" << endl;
		N = 10;
		cin >> N;
		int* array = new int[N];
		head = new node();
		head -> data = -1;
		head -> prev = NULL;
		ptr = head;
		for ( int i = 0 ; i < N ; i++ )
			{
				ptr -> next = new node();
				ptr -> next -> prev = ptr;
				random = (rand() % N);
				array[i] = random;
				ptr -> next -> data = random;
				ptr -> next-> next = NULL;
				ptr = ptr -> next;
			}

		printArray(array, N);
		//printLinkedList(head);
		cout << endl;
		//bucket_sort(head, N);
		//bubble_sort(head, N);
		merge_sort(array, N);
		//heap_sort(head, N);
		cout << endl;
		printArray(array, N);
		//bucket_sort(head, N);
		//printLinkedList(head);
		cout << endl;
	}
