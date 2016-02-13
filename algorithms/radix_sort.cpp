// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// radix_sort.cpp

using namespace std;
#include "math.h"
#include "node.h"
void radix_sort( int* a,int n)
{
    cout << "RADIX SORT\n";
    clock_t cloc1 = clock();
	int i, m = a[0], exp = 1;
    int b[n];
    for (i = 1; i < n; i++) {
        b[i]=0;
    	if (a[i] > m) {
    		m = a[i];
    	}
    }
    while ((m / exp) > 0)
    {
    	int bucket[10]={0,0,0,0,0,0,0,0,0,0};
        for (i = 0; i < n; i++) {
        	bucket[a[i] / exp % 10]++;
        }
        for (i = 1; i < 10; i++) {
        	bucket[i] += bucket[i - 1];
        }
        for (i = n - 1; i >= 0; i--) {
        	b[--bucket[a[i] / exp % 10]] = a[i];
        }
        for (i = 0; i < n; i++) {
            a[i] = b[i];	
        }
        exp *= 10;        
    }
    clock_t cloc2 = clock();
    int diff = cloc2 - cloc1;
    cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;

}

node* rsort(node *list, int rounds){
    int n = 1;
    node *next, *temp,**bucket;
    bucket = (node**)malloc(sizeof(node)*10);
    for(int j = 0; j < rounds ;j++)
    {        
        while(list->next!= NULL)
        {    
                next                  = list->next;            
                list->next            = bucket[(list->data/n)%10];
                bucket[(list->data/n)%10]  = list;
                list                  = list->next;
                list                  = next;
        }
        for(int i = 0; i < 10; i++)
        {        
            while(bucket[i]!=NULL)
            {
                temp            = bucket[i]->next;
                bucket[i]->next = list;
                list            = bucket[i];
                bucket[i]       = bucket[i]->next;
                bucket[i]       = temp;
            }
        }
        n *=10;
    }
    return list;
}
void radix_sort(node* head, int n)
{

    cout << "RADIX SORT\n";
    int m=0;
    for (node *i = head; !i->next; i=i->next) {
        if ( log10(i -> data)> m) {
            m = i -> data;
        }
    }
    clock_t cloc1 = clock();
    head=rsort(head,m);
    clock_t cloc2 = clock();
    int diff = cloc2 - cloc1;
    cout << "Time taken on linked list: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
}