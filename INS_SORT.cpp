//simple sorting of deck of cards

#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;
using namespace std::chrono;

int main(){
    int i , n;
    cout<<"Enter numbr of elements";
    cin>>n;
    int *arr = new int[n];
    for(i = 0; i<n; i++){
        cin>>arr[i];
    }
    clock_t start = clock();
    for(i=1;i<n;i++){
        int key = arr[i];
        int j;
        for(j = i-1; j>=0 && key<arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
    for(i = 0; i<n; i++){
       cout<<arr[i]<<"\t";
    }
    cout.precision(12);
    cout<<fixed<<float(clock()-start)/CLOCKS_PER_SEC << endl;
    return 0;
}