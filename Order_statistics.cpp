//find kth smallest or largest element without sorting the array
//1. randomized way
//Find a pivot X randomly. split elements < pivot and > pivot in two parts. find size of each part
//if left part has size > k , element will be in left part
//if right part has size > k , element will be in 
//Time complexity O(n)

//2. deterministic way to find a pivot
//blum floyd pratt kth leargest element
//split array into 5 blocks of equal size
//find median of each block
//find median of median's of all n/5 blocks.
//This is your pivot X

#include <bits/stdc++.h>
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

int randomQuickSort(int arr[], int low, int high, int k) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        //element will be in left part
        if(pi>k)
        {
            return randomQuickSort(arr, low, pi - 1, k);
        }
        else if(pi<k)
        {
            return randomQuickSort(arr, pi + 1, high, k);
        }
        else{
            return arr[k];
        }
    }
}

int main () {

    int arr[10];
    for(int i = 0; i<10; i++)
    {
        cin>>arr[i];
    }
    for(int i = 0; i<10; i++)
    {
        randomQuickSort(arr, 0, 9, i);
        cout<<arr[i]<<endl;
    }
    return 0;
}
