#include <bits/stdc++.h>
using namespace std;

int dati18   [12]={1,4,4,7,2,5,7,3,6,1,4,6};
int dati19   [12]={2,5,5,1,3,6,1,4,7,2,5,7};
int dati20   [12]={1,3,4,7,2,5,7,3,6,1,4,6};
int brdmnorm [12]={31,28,31,30,31,30,31,31,30,31,30,31};
int brdmvis  [12]={31,29,31,30,31,30,31,31,30,31,30,31};

int main ()
{

    int day,month,year,brd;
    char c;
    cin >> day >> c >> month >> c >> year >> brd;

    int dos;
    if (year==2018)dos=dati18[month-1];
    else if (year==2019)dos=dati19[month-1];
    else dos=dati20[month-1];

    for (int i=0;i<day;i++)
    {
        if (dos<7)dos++;
        else dos=1;
    }


    for (;brd>0;day++)
    {
        if ((year!=2020 and day>brdmnorm [month-1]) or (year==2020 and day>brdmvis [month-1]))
        {
            day=1;
            month++;
        }

        if (month>12)
        {
            month=1;
            year ++;
        }

        if (dos<6)brd--;

        if (dos<7)dos++;
        else dos=1;
    }

    if (day<10)cout<< 0;
    cout << day <<".";
    if (month<10)cout<< 0;
    cout << month <<"."<< year <<endl;

    return 0;
}
