#include<iostream>
using namespace std;

 int sum = 0;
int obhoj(int left, int right)
{
   if(left == 0 || right == 0){sum++; return 1; }

           obhoj(left - 1, right);
           obhoj(left, right - 1);

}

int leftspace;
int rightspace;

int main()
{
    int n, k;
   cin>>n;
   cin>>k;

    if(k == 1 || k == n) cout<<1<<endl;
    else
    {
        leftspace = k - 1; rightspace = n - k;
        obhoj(leftspace, rightspace);
        cout<<sum<<endl;
    }
}
