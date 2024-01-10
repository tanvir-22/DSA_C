#include <stdio.h>
int left(int i)
{
    return i * 2;
}
int right(int i)
{
    return (2 * i) + 1;
}

void max_heapify(int heap[], int heap_size, int i)
{
    int l, r, largest, temp;
    l = left(i);
    r = right(i);
    if (l <= heap_size && heap[l] > heap[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        max_heapify(heap, heap_size, largest);
    }
}
void build_max_heap(int heap[], int heap_size)
{
    int i;
    for (i = heap_size; i >= 1; i--)
    {
        max_heapify(heap, heap_size, i);
    }
}
void print_heap(int heap[], int heap_size)
{
    int i;
    for (i = 1; i <= heap_size; i++)
    {
        printf("%d->", heap[i]);
    }
}
int main()
{
    int heap_size = 5;
    int heap[] = {0, 3, 6, 5, 1, 4};
    print_heap(heap, heap_size);
    printf("\n\n");
    build_max_heap(heap, heap_size);
    print_heap(heap, heap_size);
    return 0;
}