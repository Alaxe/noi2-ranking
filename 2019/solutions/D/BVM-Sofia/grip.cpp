#include <iostream>
#include <iomanip>
using namespace std;
bool d[32][13][4];
int days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
bool vis(int y){
    if(y == 2)return 1;
    return 0;
}
int power(int a, int b)
{
    if(b == 0)return 1;
    if(b % 2 == 1)return a*power(a,b-1);
    int ans = power(a,b/2);
    return ans*ans;
}
int tolong(string& s)
{
    int a = 0;
    for(int i = s.size()-1 , j = 0 ; i >= 0 ; --i, ++j)
    {
        a += (s[i]-'0')*power(10,j);
    }
    return a;
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int brnul = 0, bred = 4;
    bool koe = 1;
    for(int y = 1 ; y <= 3 ; ++y)
    {
        for(int m = 1 ; m <= 12 ; ++m)
        {
            for(int day = 1 ; day <= days[m] ; ++day)
            {
                if(m == 2 && day == 29 && !vis(y)){
                    continue;
                }
                if(!koe){
                    d[day][m][y] = 0;
                    --brnul;
                }
                if(koe)
                {
                    d[day][m][y] = 1;
                    --bred;
                }
                if(koe && bred == 0)
                {
                    koe = 0;
                    brnul = 2;
                }
                if(!koe && brnul == 0)
                {
                    koe = 1;
                    bred = 5;
                }
            }
        }
    }
    string s1,s2,s3,s4;
    getline(cin, s1, '/');
    getline(cin, s2, '/');
    getline(cin, s3, ' ');
    getline(cin, s4, '\n');
    int den = tolong(s1), mesec = tolong(s2), godina = tolong(s3), dni = tolong(s4);
    godina -= 2018;
    while(dni >= 0)
    {
        if(!vis(godina) && den == 29 && mesec == 2)
        {
            den = 1;
            mesec = 3;
        }
        if(den > days[mesec])
        {
            den = 1;
            ++mesec;
        }
        if(mesec > 12)
        {
            mesec = 1;
            ++godina;
        }
        dni -= int(d[den][mesec][godina]);
        if(dni >= 0)++den;
    }
    godina += 2018;
    if(den < 10)cout << 0;
    cout << den << '.';
    if(mesec < 10)cout << 0;
    cout << mesec << '.';
    cout << godina << '\n';
    return 0;
}
