#include<iostream>
using namespace std;

int n;
int a[10000];

int main()
{
    int c = 1;
    int B;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    for(;;c++)
    {
        bool f = 1;
        B = c * c;
        for(int i = 0;i < n;i++)
        {
            if(B % a[i]){f = 0;break;}
        }
        if(f)break;
    }
    cout << c << endl;
}

