//Task: strip_comb
//Author: Kinka Kirilova-Lupanova

#include <iostream>
#include <vector>
using namespace std;

int n, k; 
long long fact(int n)
{long long p=1;
 for (int i=1;i<=n;i++) p=p*i;
 return p;
}
int main()
{cin >> n >> k; 
 cout << fact(n-1)/(fact(k-1)*fact(n-k))<<endl; 
}
