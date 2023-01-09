//divide conquer and combine

#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void merge(int arr[], int s, int m , int e){
    int left[m-s+1];
    int right[e-m];
    for(int i =0 ; i<m-s+1; i++){
        left[i] = arr[s+i];
    }

    for(int i = 0 ; i<e-m ; i++){
        right[i] = arr[i+m+1];
    }

    int i =0 , j =0;
    int id = s;
    while(i<m-s+1 and j<e-m){
        if(left[i]<right[j]){
            arr[id] = left[i];i++;
        }
        else{
            arr[id] = right[j];j++;
        }
        id++;
    }
    while(i<m-s+1){
        arr[id] = left[i];
        i++;
        id++;
    }
    while(j<e-m){
        arr[id] = right[j];
        j++;
        id++;
    }
}
void mergesort(int arr[], int s, int e){
    if(s>=e)//one or zero element
    {
        return;
    }
    int m = (s+e)/2;
    mergesort(arr,s,m);
    mergesort(arr,m+1,e);

    merge(arr,s,m,e);
}
void solve(){
    int i , n;
    cout<<"Enter numbr of elements"<<endl;
    cin>>n;
    int *arr = new int[n];
    for(i = 0; i<n; i++){
        //cin>>arr[i];
        arr[i] = rand()%201 -100;
    }
    
    clock_t start = clock();
    mergesort(arr,0,n-1);
    cout.precision(12);
    cout<<"Time taken by program :" <<fixed<<float(clock()-start)/CLOCKS_PER_SEC << endl;

    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    fast_cin();
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}