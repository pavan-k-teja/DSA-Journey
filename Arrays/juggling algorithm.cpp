#include <bits/stdc++.h>
using namespace std;

void reverseArr(int arr[], int start, int end)
{
    while(start<end)
    {
        swap(arr[start], arr[end]);
        start++;end--;
    }
}
void leftrotate2(int arr[], int n, int d)
{
    if(d<=0) return;
    reverseArr(arr,0,d-1);
    reverseArr(arr,d,n-1);
    reverseArr(arr,0,n-1);
}
void leftrotate(int arr[], int n, int d)
{
    if(d>=n || d<=0) return;

    int g=__gcd(n,d);
    for(int i=0;i<g;i++)
    {
        int j=i;
        int temp=arr[i];
        while(1)
        {
            int k=(j+d)%n;
            if(k==i)
                break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j]=temp;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    return 0;
}