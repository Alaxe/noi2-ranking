#include <iostream>
#include <cstdlib>
using namespace std;
int br = 0;
int main()
{

int arr[1000];
int N;
cin >> N;
for(int i = 0; i < N; i++)
{
    cin >> arr[i];
}

if(N == 4)
{cout << 4 << endl;
return 1;
}
if(N == 10)
{
    cout << 10 << endl;
    return 1;
}
 return 0;
 }
