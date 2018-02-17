#include <iostream>
#include <cstring>
using namespace std;
string m;
int base;

string solve()
{
    for(int r0 = 1; r0<base;r0++){
        string a;
        a.resize(m.size());

        int carry = 0;

        int i = m.size() - 1;
        int ri = r0;
        int mi;
        int ai;
        while(i >= 0){
            if(m[i] >= '0' && m[i] <= '9')
                mi = m[i] - '0';
            else
                mi = m[i] - 'A' + 10;

            if(ri < mi){
                ri += base;
                carry = 1;
            }

            ai = ri-mi;
            if(ai < 10) a[i] = ai + '0';
            else a[i] = (ai-10) + 'A';

            ri = ai - carry;
            carry = 0;
            i--;
        }
        if(r0 == ai){
            return a;
        }

    }
    return "0";
}

int main(){
    cin>>base;

    cin>>m;
    cout<<solve()<<endl;
    cin>>m;
    cout<<solve()<<endl;
    cin>>m;
    cout<<solve()<<endl;
    cin>>m;
    cout<<solve()<<endl;
}
