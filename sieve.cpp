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
 
int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    //method - 1

    int result = 0;
    vector<char> block(S);
    fill(block.begin(), block.end(), true);
    for( int p : primes)
    {
        int st_idx  = p*p;
        int j = st_idx ;
        for(; j<S ; j+=p)
        {
            block[j] = false;
        }
    }
    for(int i = 2 ; i<S && i<=n; i++)
    {
        if(block[i])
        {
            result++;
        }
    }

    for(int k = 1 ; k*S <= n ; k++)
    {
        fill(block.begin(), block.end(), true);
        int start = k*S;
        for(int p: primes)
        {   
            int start_idx = ((start+p-1)/p)*p;
            int j = max(start_idx , p*p) ;
            for(; j < start+S ; j+=p)
            {
                block[j-start] = false;
            }
        }
        for(int i=0 ; i<S && i+start <=n; i++)
        {
            if(block[i])
            {
                result++;
            }
        }
    }
    return result;


    // method - 2
    // int result = 0;
    // vector<char> block(S);
    // for (int k = 0; k * S <= n; k++) {
    //     fill(block.begin(), block.end(), true);
    //     int start = k * S;
    //     for (int p : primes) {
    //         int start_idx = (start + p - 1) / p;
    //         int j = max(start_idx, p) * p - start;
    //         for (; j < S; j += p)
    //             block[j] = false;
    //     }
    //     if (k == 0)
    //         block[0] = block[1] = false;
    //     for (int i = 0; i < S && start + i <= n; i++) {
    //         if (block[i])
    //         {
    //             if(k==0)
    //             {
    //                 cout<<i<<endl;
    //             }
    //             else{
    //                 cout<<start+i<<endl;
    //             }
    //             result++;
    //         }
    //     }
    // }
    // return result;
}
void sieve()
{
    int n;
    cin >> n;
    vector<bool> is_prime(n+1 , true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2 ; i <= n ; i++)
    {
        if(is_prime[i] && (ll) i * i <= n )
        {
            for(int j = i*i ; j <= n ; j+=i)
            {
                is_prime[j] = false;
            }
        }
    }

    for(int i = 0 ; i <= n ; i++)
    {
        if(is_prime[i])
        {
            cout<< i << endl;
        }
    }
}
int main(){
    fast_cin();
    ll t;
    t = 1;
    cout<<(8 ^ 1) << endl;
    while(t--){
        cout << count_primes(100)<<endl;
    }
    return 0;
    
}