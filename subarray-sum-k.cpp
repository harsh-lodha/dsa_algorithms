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
#include <apiset.h> 
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
 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> s ;
        s.insert(make_pair(0,1));
        int count = 0;
        int pre_sum = 0;
        for(int i = 0; i< nums.size() ; i++)
        {
            pre_sum += nums[i];
            if(nums[i] == k)
            {
                count++;
            }
            if(s.find(pre_sum - k) != s.end())
            {
                count += s[pre_sum - k];
                s[pre_sum-k]++;
            }
            else{
                s.insert({pre_sum , 1});
            }
        }
        return count;
    }
};

int main(){
    fast_cin();
    ll t;
    t=1;
    int k = 2;
    while(t--){
        subarraySum();
    }
    return 0;
}