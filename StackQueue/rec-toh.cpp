#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 0)
    
        return;

    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

// Driver code
int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
