#include <iostream>
#include <queue>
using namespace std;

/*priority_queue functions:
    empty
    size
    top
    push
    emplace
    pop
    swap
*/

//  O(k + (n-k)*Logk)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    //************************
    priority_queue<int> pq(a, a+k); //maxheap O(k)

    for (int i = k; i < n; i++) // O((n-k)(log k))
    {
        if (a[i] < pq.top())
        {
            pq.pop();
            pq.push(a[i]);
        }
    }

    cout << pq.top();   

    return 0;
}