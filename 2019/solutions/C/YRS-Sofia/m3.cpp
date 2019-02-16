#include <iostream>
#include <iomanip>
using namespace std;
long long sectors, water;
long long a, b, c, d;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> sectors >> water;
    cin >> a >> b >> c >> d;
    cout << fixed;
    cout << setprecision(3);
    long long sectorlit = 4 * d;
    if(water % sectorlit == 0 || water > sectors * sectorlit){
        cout << double(d) << ' ' << double(d) << ' ' << double(d) << ' ' << double(d) << '\n';
        return 0;
    }
    long long sectornum = water / sectorlit;
    long long waterost = water % sectorlit;
    sectornum %= 4;
    long long first, second, third;
    switch(sectornum)
    {
    case 0:
        first = a;
        second = c * 2;
        third = c * 2 + b;
        if(waterost <= first){
            cout << double(waterost) << ' ' << 0.0 << ' ' << 0.0 << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= second){
            cout << double(waterost) / 2 << ' ' << double(waterost) / 2 << ' ' << 0.0 << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= third){
            cout << double(c) << ' ' << double(c) << ' ' << double(waterost - 2 * c) << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= sectorlit){
            cout << double(c) << ' ' << double(c) << ' ' << double(b) << ' ' << double(waterost - third) << '\n';
            return 0;
        }
        break;
    case 1:
        first = b;
        second = b + a;
        third = 3 * c;
        if(waterost <= first){
            cout << double(waterost) << ' ' << 0.0 << ' ' << 0.0 << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= second){
            cout << double(b) << ' ' << double(waterost - b) << ' ' << 0.0 << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= third){
           cout << double(b) << ' ' << double(waterost - b) / 2 << ' ' << double(waterost - b) / 2 << ' ' << 0.0 << '\n';
           return 0;
        }
        else if(waterost <= sectorlit){
            cout << double(c) << ' ' << double(c) << ' ' << double(c) << ' ' << double(waterost - third) << '\n';
            return 0;
        }
        break;
    case 2:
        first = b;
        second = 2 * c;
        third = 2 * c + a;
        if(waterost <= first){
            cout << double(waterost) << ' ' << 0.0 << ' ' << 0.0 << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= second){
            cout << double(b) << ' ' << double(waterost - b) << ' ' << 0.0 << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= third){
            cout << double(c) / 2 << ' ' << double(c) / 2 << ' ' << double(waterost - second) << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= sectorlit){
            cout << double(c) / 2 << ' ' << double(c) / 2 << ' ' << double(waterost - second) / 2 << ' ' << double(waterost - second) / 2 << '\n';
            return 0;
        }
        break;
    case 3:
        first = c;
        second = c + a;
        third = c + 2 * b;
        if(waterost <= first){
            cout << double(waterost) << ' ' << 0.0 << ' ' << 0.0 << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= second){
            cout << double(c) << ' ' << double(waterost - c) << ' ' << 0.0 << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= third){
            cout << double(c) << ' ' << double(waterost - c) / 2 << ' ' << double(waterost - c) / 2 << ' ' << 0.0 << '\n';
            return 0;
        }
        else if(waterost <= sectorlit){
            cout << double(c) << ' ' << double(b) << ' ' << double(b) << ' ' << double(waterost - third) << '\n';
            return 0;
        }
        break;
    }
    cout << double(waterost) / 4 << ' ' << double(waterost) / 4 << ' ' << double(waterost) / 4 << ' ' << double(waterost) / 4 << '\n';
    return 0;
}
