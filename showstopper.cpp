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
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve(vector<int>&u, vector<int>&l)
{
    if(u.size() == 1 ){
        cout << "Yes";
        return;
    }

    int umax = u.back();
    int lmax = l.back();

    if(umax < u[u.size()-2] || lmax < l[l.size()-2])
    {
        swap(umax, lmax);
    }
    if(umax < u[u.size()-2] || lmax < l[l.size()-2])
    {
        cout<<"No";
        return;
    }

    for(int i = u[u.size()-2] ; i>=0; i)
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    vector<int> u;
    vector<int> l;
    while (t--)
    {
        int sz;
        cin>>sz;
        u.clear();
        l.clear();
        for(int i = 0; i<sz; i++)
        {
            int ele;
            cin>>ele;
            u.push_back(ele);
        }
        for(int i = 0; i<sz; i++)
        {
            int ele;
            cin>>ele;
            l.push_back(ele);
        }
        solve(u, l);
    }
    return 0;
}