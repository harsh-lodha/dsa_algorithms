#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

int randomPartition(int arr[], int low, int high) {
    int n = high - low + 1;
    int pivot = rand() % n;
    int temp = arr[low + pivot];
    arr[low + pivot] = arr[high];
    arr[high] = temp;
    return partition(arr, low, high);
}

void randomQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        randomQuickSort(arr, low, pi - 1);
        randomQuickSort(arr, pi + 1, high);
    }
}
void q_sort(vector<int>& arr, int l, int r)
{
    if(r <= l)
    {
        return;
    }
    int pivot = l+random()%(r-l);
    int x = arr[pivot]; //pivot
    swap(arr[r],arr[pivot]);//swap rightmost element with pivot to avoid misplacement of pivot.
    int m = l;
    for(int i = l ; i<=r; i++)
    {
        if(arr[i]<x)
        {
            int temp = arr[i];
            arr[i] = arr[m];
            arr[m] = temp;
            m++;
        }
    }
    swap(arr[r],arr[m]);
    q_sort(arr,l,m);
    q_sort(arr,m+1,r);
    return;
}
int main () {
    vector<int> arr;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    q_sort(arr, 0, n-1);
    for(int i = 0; i<arr.size(); i++)
    {
        cout<<endl<<arr[i];
    }
    return 0;
}