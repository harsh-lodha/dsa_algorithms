/**
 * @file Selection sort
 * @author Harsh Lodha
 * @brief https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/practice-problems/algorithm/old-keypad-in-a-foreign-land-24/
 * @version 0.1
 * @date 2022-10-20
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
 

void solve(){

}
int main(){
    fast_cin();

    int n;
    cin>>n;
    int *freq = new int[n];
    
    for(int i = 0; i<n; i++){
        cin>>freq[i];
    }

    int k;
    cin>>k;
    int *key = new int[k];


    int sumk = 0;
    for (int i = 0; i < k; i++)
    {
        cin>>key[i];/* code */
        sumk+=key[i];
    }
    
    if(sumk<n)
    {
        cout<<-1;
        return 0;
    }

    int maxidx ;
    int mul_factor = 1;
    int sum =0;
    int keyidx = 0;

    for(int i = 0 ; i<n ; i++)
    {
        maxidx = i;

        for(int j = i+1; j<n ; j++)
        {
            if(freq[maxidx] < freq[j])
            {
                maxidx = j;
            }
        }
        int tmp = freq[i];
        freq[i]= freq[maxidx] ;
        freq[maxidx] = tmp;

        if(keyidx >= k)
        {
            keyidx = 0;
            mul_factor++;
        }
        while (key[keyidx] <= 0 && keyidx < k)
        {
            keyidx++;
        }
        if (key[keyidx] > 0 && keyidx < k)
        {
            sum += freq[i] * mul_factor;
            key[keyidx]--;
            keyidx++;
        }
    }
    
    cout << sum ;
    return 0;
}