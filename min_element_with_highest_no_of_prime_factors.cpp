#include<bits/stdc++.h>
using namespace std;

#define prime 0

int number[1000001]={0};// 0 if prime , 1 if not prime
vector<int> primes;
void sieve()
{
   for(int i = 2; i<= 1000; i++)
   {
      if(number[i] == prime)
      {
        primes.push_back(i);
         for(int j = i*2 ; j<=1000000; j+=i)
         {
            number[j] = !prime ;
         }
      }
   }
}
int count_primefactors(int n )
{
   int count = 0;
   for(auto i : primes)
   {
      if(i>n) break;
      if(n%i == 0)
      {
         count++;
      }
   }
   return count;
}
long long solve (int x, int n, vector<int> a) {
   // Type your code here
   sieve();
   int count_of_prime_factors[n];

   for(int i = 0; i<n; i++)
   {
      count_of_prime_factors[i] = count_primefactors(a[i]);
      cout<<a[i]<<"---"<<count_of_prime_factors[i]<<endl;
   }
   unordered_map<int,int>m;
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
    int ans = 1e9;
    pq.push({count_of_prime_factors[0],0});
    for(int i = 1; i<n; i++)
    {
        if(i >= x)
        {
            //pop top element and find index , ans
            while(!pq.empty() && (i- pq.top().second) > x)
            {
                pq.pop();
            }
            
            cout<<a[pq.top().second]<<endl;
            ans = min(ans, a[pq.top().second]);
        }
        while(!pq.empty() && i-pq.top().second >= x)
        {
            pq.pop();
        }
        pq.push({count_of_prime_factors[i],i});
    }
     if(n-pq.top().second<= x)
        {
            //pop top element and find index , ans
            cout<<a[pq.top().second]<<endl;
            ans = min(ans, a[pq.top().second]);
            pq.pop();
        }
    return ans;


}

   int main()
   {
    int x , n;
    cin>>x;//interval
    cin>>n;//number of elements in array
    vector<int>a(n);
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }

    int ans = solve(x,n,a);
    cout<<ans<<endl;
    return 0;
   }