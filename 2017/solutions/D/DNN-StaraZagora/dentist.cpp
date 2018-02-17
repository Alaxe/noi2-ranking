#include <iostream>
#include <algorithm>
using namespace std;

struct Client
{
    int arrive, time; 
};

Client a[100000000];

int main()
{
	a[0].arrive = 0;
    a[0].time = 30;
    a[1].arrive = 720;
    a[1].time = 10;
    a[2].arrive = 715;
    a[2].time = 20;
    a[3].arrive = 714;
    a[3].time = 25;
//cout<<a[0].arrive<<a[0].time<<endl;
    for (int i=0; i<4; i++)
    {
        for (int j=i; j<4; j++)
        {
            if (a[j].arrive<a[i].arrive) a[i].arrive=a[j].arrive;
        }
    }
    cout<<a[0].arrive<<a[1].arrive<<a[2].arrive<<a[3].arrive<<endl;
	return 0;
}