#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 1000

typedef struct heap
{
	int size;
	int data[MAX_HEAP_SIZE];
} heap;

int get_parent_index(heap *my_heap, int index)
{
	return index/2;
}

int get_left_index(heap *my_heap, int index)
{
	return 2 * index;
}

int get_right_index(heap *my_heap, int index)
{
	return 2 * index + 1;
}

void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void max_heapify(heap *my_heap, int index)
{
	int largest;
	int left_index = get_left_index(my_heap,index);
	int right_index = get_right_index(my_heap,index);
	if(left_index <= heap->size && heap->data[left_index] > heap->data[index]){
		largest = left_index;
	} else{
		largest = index;
	}
	if(right_index <= heap->size && heap->data[right_index] > heap->data[largest]){
		largest = right_index;
	}
	if(heap->data[index] != heap->data[largest]){
		swap(&heap->data[index],&heap->data[largest]);
		max_heapify(heap,largest);
	}
}

int main() {

	heap * heap = NULL;



	return 0;
}