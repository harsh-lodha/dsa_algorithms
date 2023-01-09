/**
 * @file COUNT_INV.cpp
 * @author Harsh Lodha (harsh-lodha.github.io)
 * @brief 
 * A[1 : n] be an array of n distinct numbers. If i < j and A[i] > A[j],
 * then the pair (i, j) is called an inversion of A.
 * Give an algorithm that determines the number of inversions in any permutation
 * on n elements in Θ(n lg n) worst-case time. (Hint: Modify merge sort.)
 * pg 81 TMC
 * @version 0.1
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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

void Count(int arr[] , int s,int m, int e, int *res){
    int left[m-s+1];
    int right[e-m];
    int counter = 0;
    for(int i =s ; i<=m ; i++){
        left[counter] = arr[i];counter++;
    }
    counter = 0;
    for(int i = m+1 ; i<=e ; i++){
        right[counter] = arr[i]; counter++;
    }

    int id = s;
    int i = 0;
    int j = 0;

    i=s;
    j = e;
    if(arr[m]<arr[m+1]) return;
    while(i<=m  && j>m){
        if(arr[i] > arr[j]){
            *res = *res + j-m;
            i++;
            j=e;
        }
        else{
            j--;
            if(j==m){
                j=e;
                i++;
            }
        }
    }
    cout<<s<<"\t"<<m<<"\t"<<e<<"\t"<<*res<<endl;
    
    i =0;
    j=0;
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
void CountInv(int arr[], int s , int e, int *res){
    if(s==e){
        return ;
    }
    int m = (s+e)/2;
    CountInv(arr, s, m, res);
    CountInv(arr, m+1, e, res);
    Count(arr, s, m , e, res);
    return;
}
void solve(){
    int i , n;
    cout<<"Enter numbr of elements"<<endl;
    cin>>n;
    int *arr = new int[n];
    for(i = 0; i<n; i++){
        cin>>arr[i];
    }
    // clock_t start = clock();
    int *res;
    *res = 0;
    CountInv(arr, 0 , n-1 , res);
    // cout.precision(12);
    // cout<<"Time taken by program :" << fixed << float(clock()-start)/CLOCKS_PER_SEC << endl;
    cout<<"Total number of inversions : "<< *res <<"\n"<<res<< endl;
}
int main(){
    fast_cin();
    ll t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}