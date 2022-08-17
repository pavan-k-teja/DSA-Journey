#include <iostream>

void merge(int arr[], int l_idx, int mid_idx, int r_idx)
{
    int l_size = mid_idx - l_idx + 1;
    int r_size = r_idx - mid_idx;

    int l_arr[l_size], r_arr[r_size];

    for (int i = 0; i < l_size; i++)
        l_arr[i] = arr[l_idx + i];
    for (int j = 0; j < r_size; j++)
        r_arr[j] = arr[mid_idx + 1 + j];

    l_idx = 0;       //idx for l_arr
    r_idx = 0;       //idx for r_arr
    int arr_idx = 0; //idx for arr

    while (r_idx < r_size && l_idx < l_size)
    {
        if (l_arr[l_idx] <= r_arr[r_idx])
        {
            arr[arr_idx] = l_arr[l_idx];
            l_idx++;
        }
        else
        {
            arr[arr_idx] = r_arr[r_idx];
            r_idx++;
        }
        arr_idx++;
    }
    while (l_idx < l_size)
    {
        arr[arr_idx] = l_arr[l_idx];
        l_idx++;
        arr_idx++;
    }
    while (r_idx < r_size)
    {
        arr[arr_idx] = r_arr[r_idx];
        r_idx++;
        arr_idx++;
    }
}

void mergeSort(int arr[], int l_idx, int r_idx)
{
    int mid_idx = l_idx + (r_idx - l_idx) / 2;

    mergeSort(arr, l_idx, mid_idx);
    mergeSort(arr, mid_idx + 1, r_idx);

    merge(arr, l_idx, mid_idx, r_idx);
}

int main()
{

    return 0;
}