#include <bits/stdc++.h>
using namespace std;

class kStacks
{
	int *arr;
	int *stackTop;
	int *next;

	int n, k;
	int freeSpot;

public:
	kStacks(int k, int n);

	bool isFull() { return (freeSpot == -1); }

	bool isEmpty(int sn) { return (stackTop[sn] == -1); }

	void push(int item, int sn);

	int pop(int sn);

	int peek(int sn);
};

kStacks::kStacks(int k1, int n1)
{

	k = k1, n = n1;
	arr = new int[n];
	stackTop = new int[k];
	next = new int[n];

	for (int i = 0; i < k; i++)
		stackTop[i] = -1;

	freeSpot = 0;
	for (int i = 0; i < n - 1; i++)
		next[i] = i + 1;
	next[n - 1] = -1;
}

void kStacks::push(int item, int sn)
{
	// if full, there is no space to push
	if (isFull())
	{
		cout << "\nStack is full. Push failed\n";
		return;
	}

	// find index in arr where we can store our item
	int idx = freeSpot;

	// insert in arr
	arr[idx] = item;

	// update freeSpot bcuz curr not free now
	freeSpot = next[idx];

	// update next
	next[idx] = stackTop[sn];
	
	// update top
	stackTop[sn] = idx;

}

int kStacks::pop(int sn)
{
	// if empty, there is nothing to pop
	if (isEmpty(sn))
	{
		cout << "\nStack is empty. Pop failed\n";
		return INT_MAX;
	}

	int idx = stackTop[sn];

	stackTop[sn] = next[idx];

	next[idx] = freeSpot;
	freeSpot = idx;

	return arr[idx];
}

int kStacks::peek(int sn)
{
	// if empty, there is nothing to pop
	if (isEmpty(sn))
	{
		cout << "\nStack Underflow\n";
		return INT_MAX;
	}

	return arr[stackTop[sn]];
}
int main()
{

	int k = 3, n = 10;
	kStacks ks(k, n);

	ks.push(15, 2);
	ks.push(45, 2);

	ks.push(17, 1);
	ks.push(49, 1);
	ks.push(39, 1);

	ks.push(11, 0);
	ks.push(9, 0);
	ks.push(7, 0);

	cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

	return 0;
}
