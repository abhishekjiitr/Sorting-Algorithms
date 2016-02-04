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
int main()
	{
		int N, random;
		struct* head, *ptr;
		cout << "Enter N:" << endl;
		//cin >> N;
		N = 10;
		int array[N];
		head = ptr;
		ptr = new node();
		for ( int i = 0 ; i < N ; i++ )
			{
				random = rand() % 1000000000;
				array[i] = random;
			}
		printArray(array, N);
	}
