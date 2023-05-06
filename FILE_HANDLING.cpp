#include <bits/stdc++.h>
using namespace std;

#ifndef quick_sort
#define quick_sort
/*code*/
#define ln "\n"
#endif // quick_sort

int main () {
    
    ifstream fin("input.txt");
    ofstream fout("output.txt", ofstream::app); //to append line
    string line;

    if(fin.is_open())
    {
        while(getline(fin, line))
        {
            fout<<line<<ln;
        }
        fin.close();
        fout.close();
    }
    system("pause");
    return 0;
}