#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

class Printsubsequence{
    private:
        void recursive(int arr[], int index, int temp[])
        {
            if(index == arr_size)
            {
                print(arr, temp);
                return;
            }
            temp[index] = 1;
            recursive(arr, index+1, temp);

            temp[index] = 0;

            recursive(arr,index+1, temp);
        }
    public:
        int arr_size;
        void print_subsequence(int arr[])
        {
            int *temp = new int[arr_size];
            int index = 0;
            recursive(arr, index, temp);
        }
        void print(int arr[], int temp[])
        {
            for (int i = 0; i < 3; i++)
            {
                if(temp[i])
                    cout << arr[i] ;
            }
            cout<<endl;
        }
};

int main()
{
    int arr[] = {1,2,3};
    Printsubsequence p;
    p.arr_size = sizeof(arr)/sizeof(int);
    p.print_subsequence(arr);
    return 0;
}
