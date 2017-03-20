#include <iostream>
#include <cstring>
#include <vector>

#define MAX 10001 
using namespace std;

char r[MAX]="541645498499999984";
int n=2, m=10, nr=2;

int C=0;

vector<char> v;

void inp()
{
    cin>>r;
    cin>>n>>m;
}

void prep()
{
    nr = strlen(r);
    v.reserve(MAX);
    for (int i=0; i<nr; i++) r[i]-='0';
    for (int i=0; i<nr; i++) v.push_back(r[i]);
}

void prep(int n)
{
    nr = n;
    v.clear();
    v.reserve(MAX);
    for (int i=0; i<nr; i++) v.push_back(r[i]);
}

template <typename T>
void show(T a, int n)
{
    for (int i=0; i<n; i++) cout<<a[i]<<' ';
    cout<<endl;
}

// se deli
bool checkDel(vector<char> v, int n)
{
    long long c = 0ll, j = 1;
    for (vector<char>::reverse_iterator i=v.rbegin(); i!=v.rend(); i++)
    {
        c+=j*(*i);
        j*=10;
    }
    //cout<<c<<endl;
    return !(c%((long long)(n)));
}

void sol(vector<char> v, unsigned int i)
{
    if (v.size() < 2 || i>=v.size()) return;
    
    vector<char> v1 = v;
    v1.erase(v1.begin()+i);
    // do magic
    if (checkDel(v1, n)) 
    {
        C++;
        C%=m;
    }
    sol(v1, i);
    
    vector<char> v2 = v;
    sol(v2, i+1);
}

int main()
{   
    inp(); 
    prep();
    if (checkDel(v, n)) C++;
    sol(v, 0);
    cout<<C%m<<endl;
    return 0;
}