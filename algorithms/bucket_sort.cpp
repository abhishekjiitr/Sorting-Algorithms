// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// bucket_sort.cpp

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
void bucket_sort(double* array, int n)
	{
		cout << "BUCKET SORT" << endl;
		clock_t cloc1 = clock();
		
		vector<double> b[n];

		for ( int i = 0 ; i < n ; i++ )
			{
				int bucket = n * array[i];
				b[bucket].push_back(array[i]);
			}

		for ( int i = 0 ; i < n ; i++ )
			{
				sort(b[i].begin(), b[i].end());
			}
			int index = 0;
		for ( int i = 0 ; i < n ; i++ )
			{
				for ( int j = 0 ; j < b[i].size() ; j++ )
					{
						array[index] = b[i][j];
						index++;
					}
			}

		clock_t cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
		//printArray(array, n);
	}
void insert(node* head, double data)
	{
		if ( head == NULL )
			{
				head = new node();
				head -> data = data;
				return;
			}
		cout << "DATA "<<data << endl;
		node* prev = head;
		while ( head != NULL )
			{
				cout << "NOT NULL"<<endl;
				prev = head;
				head = head -> next;
			}
		cout << prev -> data << endl;
		prev -> next = new node();
		prev -> next -> data = data;
		prev ->  next -> next = NULL;
		cout << prev -> next ->data << endl;

	}
void selection_sort(node *a)
{
	if ( a == NULL || a -> next == NULL )
		return;
	int n = 0;
	node* temp = a;
	while ( temp != NULL )
		{
			n++;
			temp = temp -> next;
		}
	int index;
	node*head = a;
	for(int i=0;i<n;i++)
	{
		node* current = a;
		double min = a->data;
		node* mini = a;
					
		for(int j=i ; j<n ; j++ )
		{
			if(a->data<=min)
			{
				min=a->data;
				index=j;
				mini=a;
			}
			a=a->next;
		}
		double temp=current->data;
		current->data=min;
		mini->data=temp;
		
		current=current->next;
		a=current;
	}
}

void bucket_sort(node* head, int n)
	{

		head = head -> next;
		cout << "BUCKET SORT" << endl;
		clock_t cloc1 = clock();

		node* HEAD = head;
		node** bucket = new node*[n];
		for ( int i = 0 ; i < n ; i++ )
			{
				bucket[i] = NULL;
			}
		while ( head != NULL )
			{
				double data = head -> data;
				//cout << "inserting "<<data << " in "<<(int)(n*data)<<endl;
				//insert((bucket[(int)(n*data)]), data);
				node* temp = bucket[(int)(n*data)];
				while ( temp!= NULL && temp -> next != NULL)
					{
						temp = temp -> next;
					}
				if ( temp == NULL )
					{
						bucket[(int)(n*data)] = new node();
						bucket[(int)(n*data)] -> data = data; 
					}
				else
					{
						temp -> next = new node();
						temp -> next -> data = data;
					}

				head = head -> next;
			}		
		for( int i = 0 ; i < n ; i++ )
			{
				head = bucket[i];
				selection_sort(bucket[i]);

				//cout << i << endl;
				while ( head != NULL )
					{
						//cout << head -> data << " ";
						HEAD -> data = head -> data;
						HEAD = HEAD -> next;
						head = head -> next;
					}
				//cout << endl;
			} 
		clock_t cloc2 = clock();
		int diff = cloc2 - cloc1;
		cout << "Time taken on Linked List: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
	}
