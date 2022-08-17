#include <bits/stdc++.h>
using namespace std;

//sort and return
//tc=O(n log n)
//sc=O(1)
int sol1(int arr[], int n, int k)
{
    sort(arr,arr+n);// non-stable, in-place
    return arr[k-1];
}

//min heap
//tc=O(n + k log n) if k=n, then its n log n
//sc=O(1)
int sol2(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq(arr,arr+n);
    for(int i=0;i<k-1;i++)
    {
        pq.pop();
    }
    return pq.top();// top is read-only location,cant be modified maually
}

//max heap
//tc=O(k + (n-k) log k) if k=n/2, then its n log n
//sc=O(1)
int sol3(int arr[], int n, int k)
{
    priority_queue<int> pq (arr,arr+k);
    
    for(int i=k;i<n;i++)
    {
        if(arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

//randomized quick sort based method
//tc=O(n) worst case is O(n^2)
//sc=O(1)
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
int partition(int arr[], int low, int high)
{
    int rand_index=rand() % (high-low+1) + low;
    swap(&arr[high], &arr[rand_index]);

    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);
}

int sol4(int arr[], int low, int high, int k)
{
    if(k<=low || k>high+1)
        return INT_MAX;
    
    int pos=partition(arr,low,high);

    if(pos==k-1)
        return arr[pos];
    if(pos>k-1)
        return sol4(arr,low,pos-1,k);
    return sol4(arr,pos+1,high,k);
    
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int ans1= sol1(arr,n,k);
    int ans2= sol2(arr,n,k);
    int ans3= sol3(arr,n,k);
    int ans4= sol4(arr,0,n-1,k);
    
    cout<<ans1<<"\n"<<ans2<<"\n"<<ans3<<"\n"<<ans4;

    return 0;
}