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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //************************
    //First make the array into heap: O(n)
    //Extract min k times: O(k.log n)
    
    priority_queue<int, vector<int>, greater<int>> pq(a, a + n); // minheap
    for (int i = 0; i < k - 1; i++)
        pq.pop();

    cout << pq.top();

    return 0;
}