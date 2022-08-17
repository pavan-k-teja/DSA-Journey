#include <iostream>
#include <limits.h>
using namespace std;

// int minJumps_first(int arr[],int n){
//     if(n==0 || n==1)
//         return 0;
//     int memo[n];
//     for(int i=0;i<n;i++)
//         memo[i] = INT_MAX;
//     memo[0] = 0;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n && j<i+1+arr[i];j++){
//             memo[j] = min(memo[j],1+memo[i]);
//         }
//     }
//     return memo[n-1];
// }

int minJumps_BestMethod(int arr[], int n)
{
    if (n == 0 || n == 1)
        return 0;
    int detectZero = false;
    if (arr[0] == 0)
        return -1;
    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 1;
    for (int i = 1; i < n - 1; i++)
    {
        steps--;
        maxReach = max(maxReach, arr[i] + i);
        if (steps == 0)
        {
            jumps++;
            steps = maxReach - i;
            if (steps <= 0)
                return -1;
        }
    }
    return jumps;
}

int main()
{
    int arr[] = {2, 1, 0, 3};
    // cout << minJumps_first(arr,11)<<endl;
    cout << minJumps_BestMethod(arr, 4) << endl;
}