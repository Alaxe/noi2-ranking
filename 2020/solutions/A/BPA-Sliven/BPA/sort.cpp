#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    int count = 0;



    cout<<count;
    delete[] arr;
}
