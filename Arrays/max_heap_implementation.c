#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

typedef struct heap
{
	int max_size;
	int heap_size;
	int *arr;
}heap;

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

heap* create_heap(int size)
{
	heap *h=(heap*) malloc (sizeof(heap));
	h->heap_size=0;
	h->max_size=size;
	h->arr=(int*) malloc (size*sizeof(int));

	return h;
}

int parent_index(int index)
{
	return (index-1)/2;
}
int left_index(int index) 
{
	return (2*index + 1);
} 
int right_index(int index)
{
	return (2*index + 2); 
}
int peek_max(heap *h)
{
	if(h->heap_size==0) return INT_MIN;
	return h->arr[0];
}

void print_heaparray(heap *h)
{
	for(int i=0;i<h->heap_size;i++)
	{
		printf("%d ", h->arr[i]);
	}
	printf("\n");
}

int search_key(int key,heap *h)
{
	for(int i=0;i<h->heap_size;i++)
	{
		if(key==h->arr[i])
			return i;
	}
	return -1;
}
void insertKey(int key,heap *h)
{
	if(h->heap_size==h->max_size)
	{
		printf("cant add anymore\n");
		return;
	}
	h->heap_size++;
	int index=h->heap_size-1;
	h->arr[index]=key;

	while(index!=0 && h->arr[index]>h->arr[parent_index(index)])
	{
		swap(&h->arr[index], &h->arr[parent_index(index)]);
		index=parent_index(index);
	}

	printf("key insertion successful\n");
}

void heapify(int index,heap *h)
{
	int larger=index;
	int l=left_index(index);
	int r=right_index(index);
	
	if(l<h->heap_size && h->arr[l]>h->arr[larger])
		larger=l;
	if(r<h->heap_size && h->arr[r]>h->arr[larger])
		larger=r;
	if(larger!=index)
	{
		swap(&h->arr[larger], &h->arr[index]);
		heapify(larger, h);
	}
}

void pop_max(heap *h)
{
	if(h->heap_size==0) return;
	h->arr[0]=h->arr[h->heap_size-1];
	h->heap_size--;

	if(h->heap_size>0)
		heapify(0,h);
}

void decrease_key(int index, int new_val, heap* h)
{
	h->arr[index]=new_val;
	heapify(index, h);
}
void increase_key(int index, int new_val, heap* h)
{
	h->arr[index]=new_val;
	while(index!=0 && h->arr[index]>h->arr[parent_index(index)])
	{
		swap(&h->arr[index], &h->arr[parent_index(index)]);
		index=parent_index(index);
	}
}
void replace_key(int old, int new, heap *h)
{
	int index=search_key(old, h);
	if(old>new)
		decrease_key(index, new, h);
	if(old<new)
		increase_key(index, new, h);
}
void delete_node(int key, heap *h)
{
	int index=search_key(key, h);
	h->arr[index]=h->arr[h->heap_size];
	h->heap_size--;
	heapify(index, h);
}

heap* buildHeap(int *arr,int size)
{
	heap *h=create_heap(size);
	h->heap_size=size;
	h->arr=arr;

	int last_internal_node_index=(size<4? 0 : (size-2)/2);

	for(int i=last_internal_node_index;i>=0;i--)
	{
		heapify(i,h);
	}
	return h;
}

int main()
{
	/* 
      list of functions
	  	struct heap
		swap int
		create_heap // new object of struct heap and initialization
		parent,left,right
		peek_max
		print_heaparray
		search_key (BFS approach)
        insert_key // bottom top heapify
		heapify // top bottom default
		pop_max
		decrease,increase_key // used with below func. 
		replace_key
		delete_node
		buildHeap// from array
    */

   	int arr[]={0,1,2,3,4,5,6};
	heap* h=buildHeap(arr, 7);
	print_heaparray(h);
	return 0;
}