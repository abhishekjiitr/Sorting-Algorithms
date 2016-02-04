// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// Main.cpp - Top Level File.

#include <bits/stdc++.h>
using namespace std;

struct node
	{
		int data;
		node* link;
	};
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
		ptr = ptr -> link;
		while ( ptr != NULL )
			{
				cout << ptr -> data << " ";
				ptr = ptr -> link;
			}
		cout << endl;
	}
int main()
	{
		int N, random;
		node *head, *ptr;
		cout << "Enter N:" << endl;
		//cin >> N;
		N = 10;
		int array[N];
		head = new node();
		head -> data = -1;
		ptr = head;
		for ( int i = 0 ; i < N ; i++ )
			{
				ptr -> link = new node();
				random = rand() % 1000000000;
				array[i] = random;
				ptr -> link -> data = random;
				ptr -> link-> link = NULL;
				ptr = ptr -> link;
			}
		printArray(array, N);
		printLinkedList(head);
	}
