#include <iostream>
#include <math.h>

using namespace std;




int find (int n)
{
    int nums=0;
    while (n>0)
    {
        n=n/10;
        nums++;
    }
    return nums;
}

int len (char* array)
{  int i=0;
    
    for (; i<10001; i++)
    {
        if(array[i]==NULL) {break;}
    }
    
    return i;
}

int main()
{
long long m;
int n;
char arr[10001];
cin>>arr;
cin>>n>>m;

//cout<<find(n);
long long sum=0;
int length = len(arr);
for (int i=0; i<length; i++)
{
    if (arr[i]%n==0) {sum++;}
}
sum=(sum+1)%m;
cout<<sum;
return 0;
}