#include <bits/stdc++.h>
using namespace std;

class Heap // max-heap
{
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    void siftDown(int index)
    {
        int larger = index;
        int l = left(index);
        int r = right(index);

        if (l < heap.size() && heap[l] > heap[larger])
            larger = l;
        if (r < heap.size() && heap[r] > heap[larger])
            larger = r;
        if (larger != index)
        {
            swap(heap[larger], heap[index]);
            siftDown(larger);
        }
    }

    void siftUp(int index)
    {
        while (index != 0 && heap[index] > heap[parent(index)])
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

public:
    // constructor
    Heap()
    {
    }
    Heap(vector<int> &arr)
    {
        for (auto &ele : arr)
            heap.push_back(ele);

        for (int i = (heap.size() - 2) / 2; i >= 0; i--)
            siftDown(i);
    }

    int size() { return heap.size(); }
    bool empty() { return heap.empty(); }

    // push
    void push(int val)
    {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    // pop
    void pop()
    {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        if (heap.empty())
            return;
        siftDown(0);
    }

    // top
    int top() { return (heap.empty()) ? INT_MIN : heap.front(); }
};

int main()
{
    // Heap heap_obj({10, 30, 20, 5, 1});
    Heap heap_obj;
    heap_obj.push(10);
    heap_obj.push(30);
    heap_obj.push(20);
    heap_obj.push(5);
    heap_obj.push(1);

    cout << "\nheap_obj.size() : " << heap_obj.size();
    cout << "\nheap_obj.top() : " << heap_obj.top();

    heap_obj.pop();
    cout << "\nheap_obj.pop() : " << heap_obj.top();
    heap_obj.pop();
    cout << "\nheap_obj.pop() : " << heap_obj.top();
    heap_obj.pop();
    cout << "\nheap_obj.pop() : " << heap_obj.top();
    heap_obj.pop();
    cout << "\nheap_obj.pop() : " << heap_obj.top();
    heap_obj.pop();
    cout << "\nheap_obj.pop() : " << heap_obj.top();
    heap_obj.pop();
    cout << "\nheap_obj.pop() : " << heap_obj.top();
}
