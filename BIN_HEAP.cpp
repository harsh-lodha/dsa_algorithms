#include <bits/stdc++.h>
using namespace std;

#ifndef hari/*define*/
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#endif // /*define*/

int* insert(int x, int& sz, int* abc)
{
    if(sz%10 == 0){
        if(sz == 0)
        {
            abc = new int[10];
        }
        else
        {
            int* newArr = new int[sz+10];
            copy(abc, abc+sz, newArr);
            delete[] abc;
            abc = newArr;
        }
    }
    abc[sz] = x;
    sz++;
    int i = sz-1;
    while(i>0 && abc[i] < abc[(i-1)/2])
    {
        swap(abc[i] , abc[(i-1)/2]);
        i = (i-1)/2;
    }
    return abc;
}

int remove_min(int& sz, int abc[])
{
    if(sz<=0)
    {
       cerr<<"size zero"<<endl;
       return -1;
    }

    swap(abc[0], abc[sz-1]);
    sz--;
    int i = 0;

    while(2*i+1 < sz){
        int j = 2*i+1;
        if(2*i+2 < sz && abc[2*i+2]<abc[j]){
            j = 2*i+2;
        }
        if(abc[j] >= abc[i])
            break;
        swap(abc[i], abc[j]);
        i = j;
    }
    return abc[sz];
}

int main () {
    //fast insertion O(1) and slow removal O(n) , or
    // slow insertion O(n) and first removal O(1)

    //bin heap both operations in O(log n)
    // each node is greater or equal to parent node

    //create a array
    int* arr = new int[10];
    int sz = 0;

    //insert element at last position. increment sz
    arr = insert(5, sz, arr);

    arr = insert(4, sz, arr);
    
    arr = insert(411, sz, arr);

    arr = insert(11, sz, arr);

    cout<<remove_min(sz, arr)<<endl;

    arr = insert(7, sz, arr);

    arr = insert(-1, sz, arr);
    
    cout<<remove_min(sz, arr)<<endl;

    arr = insert(100, sz, arr);

    cout<<remove_min(sz, arr)<<endl;

    cout<<remove_min(sz, arr)<<endl;

    cout<<remove_min(sz, arr)<<endl;

    cout<<remove_min(sz, arr)<<endl;

    cout<<remove_min(sz, arr)<<endl;

    cout<<remove_min(sz, arr)<<endl;


    //sorting
    int sz = 0;
    int *ar;
    for(int i = 0; i<=20;i++)
    {
        int x;
        cin>>x;
        ar = insert(x, sz, ar);
    }

    for(int i = 0; i<=20; i++)
    {
        cout<<remove_min(sz, ar)<<endl;
    }
    return 0;
}