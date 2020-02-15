#include<iostream>
using namespace std;
int main ()
{
    long long x,n;
    cin >> n >> x;
    if (n<6)
    {

        if (x==0 && n==1) cout << "1" <<endl;
        else if (x==0 && n==2) cout << "1" <<endl;
        else if (x==0 && n==3) cout << "2" <<endl;
        else if (x==0 && n==4) cout << "2" <<endl;
        else if (x==0 && n==5) cout << "0" <<endl;

        else if (x==1 && n==1) cout << "0" <<endl;
        else if (x==1 && n==2) cout << "2" <<endl;
        else if (x==1 && n==3) cout << "1" <<endl;
        else if (x==1 && n==4) cout << "0" <<endl;
        else if (x==1 && n==5) cout << "2" <<endl;

        else if (x==2 && n==1) cout << "2" <<endl;
        else if (x==2 && n==2) cout << "0" <<endl;
        else if (x==2 && n==3) cout << "0" <<endl;
        else if (x==2 && n==4) cout << "1" <<endl;
        else if (x==2 && n==5) cout << "1" <<endl;
    }

    else if (n<=6 && n%6!=0)
    {
        n=n%6;
        if (x==0 && n==1) cout << "1" <<endl;
        else if (x==0 && n==2) cout << "1" <<endl;
        else if (x==0 && n==3) cout << "2" <<endl;
        else if (x==0 && n==4) cout << "2" <<endl;
        else if (x==0 && n==5) cout << "0" <<endl;

        else if (x==1 && n==1) cout << "0" <<endl;
        else if (x==1 && n==2) cout << "2" <<endl;
        else if (x==1 && n==3) cout << "1" <<endl;
        else if (x==1 && n==4) cout << "0" <<endl;
        else if (x==1 && n==5) cout << "2" <<endl;

        else if (x==2 && n==1) cout << "2" <<endl;
        else if (x==2 && n==2) cout << "0" <<endl;
        else if (x==2 && n==3) cout << "0" <<endl;
        else if (x==2 && n==4) cout << "1" <<endl;
        else if (x==2 && n==5) cout << "1" <<endl;
        else if (x==2 && n==5) cout << "1" <<endl;
    }

    else if (n<=6 && n%6==0) cout << x <<endl;

    return 0;
}
