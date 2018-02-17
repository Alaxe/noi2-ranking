#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char dog, cat, mouse, pig, lol;
    long long datef, datee, datei, months[12], timef, timee, timei, timerf, draft = 0, timere, timeri, now, timeit, dateit, meet=0, mod1, mod2, mod3, answer;
    cin >> datef >> dog >> timef >> datee >> cat >> timee >> datei >> pig >> timei >> dateit >> lol >> timeit;
    switch(timef)
    {
    case 1:
        timerf = datef;
        break;
    case 2:
        timerf = datef + 31;
        break;
    case 3:
        timerf = datef + 59;
        break;
    case 4:
        timerf = datef + 90;
        break;
    case 5:
        timerf = datef + 120;
        break;
    case 6:
        timerf = datef + 151;
        break;
    case 7:
        timerf = datef + 181;
        break;
    case 8:
        timerf = datef + 212;
        break;
    case 9:
        timerf = datef + 243;
        break;
    case 10:
        timerf = datef + 273;
        break;
    case 11:
        timerf = datef + 304;
        break;
    case 12:
        timerf = datef + 334;
        break;
    }
    switch(timee)
    {
    case 1:
        timere = datee;
        break;
    case 2:
        timere = datee + 31;
        break;
    case 3:
        timere = datee + 59;
        break;
    case 4:
        timere = datee + 90;
        break;
    case 5:
        timere = datee + 120;
        break;
    case 6:
        timere = datee + 151;
        break;
    case 7:
        timere = datee + 181;
        break;
    case 8:
        timere = datee + 212;
        break;
    case 9:
        timere = datee + 243;
        break;
    case 10:
        timere = datee + 273;
        break;
    case 11:
        timere = datee + 304;
        break;
    case 12:
        timere = datee + 334;
        break;
    }
    switch(timei)
    {
    case 1:
        timeri = datei;
        break;
    case 2:
        timeri = datei + 31;
        break;
    case 3:
        timeri = datei + 59;
        break;
    case 4:
        timeri = datei + 90;
        break;
    case 5:
        timeri = datei + 120;
        break;
    case 6:
        timeri = datei + 151;
        break;
    case 7:
        timeri = datei + 181;
        break;
    case 8:
        timeri = datei + 212;
        break;
    case 9:
        timeri = datei + 243;
        break;
    case 10:
        timeri = datei + 273;
        break;
    case 11:
        timeri = datei + 304;
        break;
    case 12:
        timeri = datei + 334;
        break;
    }
    switch(timeit)
    {
    case 1:
        now = dateit;
        break;
    case 2:
        now = dateit + 31;
        break;
    case 3:
        now = dateit + 59;
        break;
    case 4:
        now = dateit + 90;
        break;
    case 5:
        now = dateit + 120;
        break;
    case 6:
        now = dateit + 151;
        break;
    case 7:
        now = dateit + 181;
        break;
    case 8:
        now = dateit + 212;
        break;
    case 9:
        now = dateit + 243;
        break;
    case 10:
        now = dateit + 273;
        break;
    case 11:
        now = dateit + 304;
        break;
    case 12:
        now = dateit + 334;
        break;
    }
    ///cout << timerf << " " << timere << " " << timeri << " " << now;
    mod1 = timerf % 23;
    mod2 = timere % 28;
    mod3 = timeri % 33;
    if((meet % 23) - mod1 == 0 and (meet % 28) - mod2 == 0 and (meet % 33) - mod3 == 0)
    {
        answer = 21252;
    }
    while ((meet % 23) - mod1 != 0 or (meet % 28) - mod2 != 0 or (meet % 33) - mod3 != 0)
    {
        meet++;
    }
    answer = meet - now;
    if(timerf == timere and timere == timeri)
    {
        cout << 21252 << endl;
    }
    else
    {
        cout << answer << endl;
    }
    return 0;
}
