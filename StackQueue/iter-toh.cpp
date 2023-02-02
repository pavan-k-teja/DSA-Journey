#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void moveDisk(int a, int b, vector<stack<int>> &stacks)
{
	if (stacks[b].empty() || (!stacks[a].empty() && stacks[a].top() < stacks[b].top()))
	{
		cout << "Move disk " << stacks[a].top() << " from rod " << char(a + 'A') << " to rod " << char(b + 'A') << "\n";
		stacks[b].push(stacks[a].top());
		stacks[a].pop();
	}
	else
		moveDisk(b, a, stacks);
}

void towerOfHanoi(int n)
{
	cout << "Tower of Hanoi for " << n << " disks:\n";
	
	vector<stack<int>> stacks(3);
	int src = 0, aux = 1, dest = 2;
	for (int i = n; i > 0; i--)
		stacks[src].push(i);

	int totalMoves = (1 << n) - 1;
	if (n % 2 == 0)
		swap(aux, dest);

	for (int i = 1; i <= totalMoves; i++)
	{
		if (i % 3 == 0)
			moveDisk(aux, dest, stacks);
		else if (i % 3 == 1)
			moveDisk(src, dest, stacks);
		else
			moveDisk(src, aux, stacks);
	}
}

int main()
{
	int n = 3; // number of disks
	towerOfHanoi(3);
	cout << "\n";
	towerOfHanoi(4);
	return 0;
}