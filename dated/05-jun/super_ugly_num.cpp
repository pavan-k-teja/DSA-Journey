#include <bits/stdc++.h>
using namespace std;

// try this again
int superUgly(int n, int primes[], int k)
{
    vector<int> nextMultiple(primes, primes + k);
    int multiple_Of[k];
    memset(multiple_Of, 0, sizeof(multiple_Of));

    set<int> ugly;
    ugly.insert(1);

    while (ugly.size() != n)
    {
        int next_ugly_no = *min_element(nextMultiple.begin(), nextMultiple.end());
        ugly.insert(next_ugly_no);
        for (int j = 0; j < k; j++)
        {
            if (next_ugly_no == nextMultiple[j])
            {
                multiple_Of[j]++;
                set<int>::iterator it = ugly.begin();
                for (int i = 1; i <= multiple_Of[j]; i++)
                    it++;

                nextMultiple[j] = primes[j] * (*it);
                break;
            }
        }
    }
    set<int>::iterator it = ugly.end();
    it--;
    return *it;
}
int main()
{
    int primes[] = {2, 5};
    int k = sizeof(primes) / sizeof(primes[0]);
    int n = 5;
    cout << superUgly(n, primes, k);
    return 0;
}
