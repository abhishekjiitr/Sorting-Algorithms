// GroupID-8 (14114002_14114068) - Abhishek Jaisingh & Tarun Kumar
// Date: February 4, 2016
// heap_sort.cpp

using namespace std;
#include "node.h"

void max_heapify(int* a, int n, int i)
{
    int left =  (i + 1) * 2 - 1;
    int right = (i + 1) * 2;
    int largest = i;
    if (left < n && a[left] > a[largest])
    largest = left;
    if (right < n && a[right] > a[largest])
    largest = right;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        max_heapify(a, n, largest);
    }
}

void build_max_heap(int* a, int n) {
  for (int i = n / 2; i >= 0; i--) {
    max_heapify(a, n, i);
  }
}

void heap_sort(int* a, int n) {
    cout << "HEAP SORT" << endl;
clock_t cloc1 = clock();
  build_max_heap(a, n);
  int heap_n = n;
  for (int i = n-1; i > 0; i--) {
    swap(a[0], a[i]);
    heap_n--;
    max_heapify(a, heap_n, 0);
  }
    clock_t cloc2 = clock();
        int diff = cloc2 - cloc1;
        cout << "Time taken on array: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
}

struct treenode {
    int data;
    treenode* left;
    treenode* right;
};

void swap(treenode* &a,treenode* &b)
{
    a->data=a->data^b->data;
    b->data=a->data^b->data;
    a->data=a->data^b->data;
}


void heapify(treenode* & root){
    if(root == NULL || root->left == NULL){
        return;
    }

    if(root->left != NULL && root->right != NULL){
        if((root->data > root->left->data) && (root->left->data <= root->right->data)){
            swap(root,root->left);
            heapify(root->left);
        }
    

    else if(root->data > root->right->data && root->right->data <= root->left->data)
        {
            swap(root,root->right);
            heapify(root->right);
        }
    }

    else if((root->right == NULL) && (root->left != NULL))
    {
        if(root->left->data < root->data)
        {
            swap(root,root->left);
            heapify(root->left);
        }
    }
}


void buildheap(treenode* &root)
{

    if(root == NULL)
    return;

    buildheap(root->left);
    buildheap(root->right);
    heapify(root);

}


void heap_sort(treenode * root,node* head,int n){
    node* temp = head;
    for(int i=0;i<n;i++)
    {
        temp->data = root->data;
        root->data =  999999999;
        heapify(root);
        temp = temp->next;
    }
}


void heap_sort(node* &head,int n){
      //cout << "HEAP SORT" << endl;
clock_t cloc1 = clock();
 int temp1[n];
 node* t1=head;
    treenode* root = new treenode;
    node* temp = head;
    root->data = head->data;
    root->right = NULL;
    root->left = NULL;
    temp = temp->next;
    queue<treenode*>q;
    q.push(root);
    treenode* t = q.front();
    for(int i=1;i<n;i++){

        if(i%2 == 1)
        {
        treenode* t2=new treenode;
        t2->data = temp->data;
        t2->left = NULL;
        t2->right = NULL;
        (t)->left = t2;
        q.push(t2);
        temp = temp->next;
        }

        else
        {

        treenode* t2 = new treenode;
        t2->data = temp->data;
        t2->left = NULL;
        t2->right = NULL;
        (t)->right = t2;
        q.push(t2);
        q.pop();
        temp = temp->next;
        if(!q.empty())
        {
            (t) = q.front();
        }
        }
        temp1[i-1]=t1->data;
        t1=t1->next;
    }
    buildheap(root);
    heap_sort(temp1,n);
    t1=head;
    for(int i=1;i<n;i++) {
        t1->data=temp1[i-1];
        t1=t1->next;
    }
        clock_t cloc2 = clock();
        int diff = cloc2 - cloc1;
        cout << "Time taken on linked_list: " << (double)diff/(double)CLOCKS_PER_SEC * 1000  <<" milli seconds" <<endl;
}