// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// Main.cpp - Top Level File.

#include <bits/stdc++.h>
#include "algorithms/selection_sort.cpp"

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

		int N, random;
		node *head, *ptr;
		//cout << "Enter N:" << endl;
		//cin >> N;
		N = 10;
		int* array = new int[N];
		head = new node();
		head -> data = -1;
		ptr = head;

		for ( int i = 0 ; i < N ; i++ )
			{
				ptr -> next = new node();
				random = rand() % 10;
				array[i] = random;
				ptr -> next -> data = random;
				ptr -> next-> next = NULL;
				ptr = ptr -> next;
			}

		//printArray(array, N);
		//printLinkedList(head);
		//selection_sort(array, N);
		printLinkedList(head);
		selection_sort(head);
		printLinkedList(head);
		//printArray(array, N);
	}
