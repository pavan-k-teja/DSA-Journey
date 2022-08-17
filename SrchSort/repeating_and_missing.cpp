// Q: https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//M: (time, space)
//M1: Sort and parse. If the consecutive elements are same => repeated, also can check if missing an element (n log n, 1)
//M2: Create a temp arr which contains the count of each index, parse again to check repeating and missing (2n, n)

/*M3
since all elements are positive and each has its corresponding index,make arr[element-1] negative, if an
element repeates, then the arr[ele-1] changes from neg to pos
parse again. if an element is positive then it is not touched in 1st iter => that index is missing.
(2n, 1) but modifies the array
*/
int *findTwoElement(int arr[], int n)
{
    // code here
    static int ans[2] = {-1, -1};

    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;
        arr[index] *= -1;

        if (arr[index] > 0)
        {
            ans[0] = index + 1;
            arr[index] *= -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            ans[1] = i;
        else
            arr[i] *= -1;
    }

    return ans;
}

/* M4:
An XOR solution is there but its difficult
xor all elements in arr
xor all numbers from 1 to n
seperate the arr into two cases
xor again to get 1 number from each case
check which is rep and which is missing
*/
int computeXOR(int n) // from 1 to n
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;

    return 0;
}

pair<int, int> rep_and_missing2(const vector<int> &nums)
{
    int orig_xor = computeXOR(nums.size());
    int arr_xor = 0;
    for (int i : nums)
        arr_xor ^= i;
    arr_xor ^= orig_xor;                    //arr_xor==R^M

    int set_bit = 1;

    while(arr_xor & 1 == 0)
    {
        arr_xor >>=1;
        set_bit <<=1;
    } // rightmost set bit

    int case1 = 0, case2 = 0;

    for (int i=1;i<=nums.size();i++)
    {
        if (i & set_bit == 1)
            case1 ^= i;
        else
            case2 ^= i;
    }

    for (int i : nums)
    {
        if (i & set_bit == 1)
            case1 ^= i;
        else
            case2 ^= i;
    }

    int M, R;
    for (int i : nums)
    {
        if (case1 == i)
        {
            R = case1;
            M = case2;
            break;
        }
        else if (case2 == i)
        {
            R = case2;
            M = case1;
            break;
        }
    }

    return {M, R};
}

/* M5:
Sum - Original = R - M
Sum of squares = R^2 - M^2 = Sum*(R + M)
2eq, 2 unknowns
*/
pair<int, int> rep_and_missing3(const vector<int> &nums)
{
    ll len = nums.size();
    ll Sum_N = (len * (len + 1)) / 2;
    ll Sum_NSq = (len * (len + 1) * (2 * len + 1)) / 6;
    ll missingNumber = 0, repeating = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        Sum_N -= (ll)nums[i];
        Sum_NSq -= (ll)nums[i] * (ll)nums[i];
    }

    missingNumber = (Sum_N + Sum_NSq / Sum_N) / 2;
    repeating = missingNumber - Sum_N;
    pair<int, int> ans;
    ans.first = repeating;
    ans.second = missingNumber;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::vector<int> v = {4, 3, 6, 2, 1, 6, 7};

    pair<int, int> ans = rep_and_missing2(v);
    cout << " The missing element is " << ans.first << " and the repeating"
         << " number is " << ans.second;

    return 0;
}