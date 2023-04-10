#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

void q_sort(vector<int>& arr, int l, int r)
{
    if(r-l <= 1)
    {
        return;
    }
    int x = arr[l+random()%(r-l)]; //pivot
    int m = l;
    for(int i = l ; i<=r-1; i++)
    {
        if(arr[i]<x)
        {
            int temp = arr[i];
            arr[i] = arr[m];
            arr[m] = temp;
            m++;
        }
    }
    q_sort(arr,l,m);
    q_sort(arr,m,r);
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

    q_sort(arr, 0, n);
    for(int i = 0; i<arr.size(); i++)
    {
        cout<<endl<<arr[i];
    }
    return 0;
}