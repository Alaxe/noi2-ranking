#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string s, s1;
    cin >> s;
    s1=s;
    char otg1[s.size()];
    int br=0;


    do
    {
        char mins=s[0];
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]<mins)
                mins=s[i];
        }
        br++;
        if (mins=='a')
            break;
        for (int j=0; j<s.size(); j++)
        {
            char ch;
            if (s[j]==mins)
            {
                if (br==1)
                    ch='A';
                if (br==2)
                    ch='B';
                if (br==3)
                    ch='C';
                if (br==4)
                    ch='D';
                if (br==5)
                    ch='E';
                if (br==6)
                    ch='F';
                if (br==7)
                    ch='G';
                if (br==8)
                    ch='H';
                if (br==9)
                    ch='I';
                if (br==10)
                    ch='J';
                if (br==11)
                    ch='K';
                if (br==12)
                    ch='L';
                if (br==13)
                    ch='M';
                if (br==14)
                    ch='N';
                if (br==15)
                    ch='O';
                if (br==16)
                    ch='P';
                if (br==17)
                    ch='Q';
                if (br==18)
                    ch='R';
                if (br==19)
                    ch='S';
                if (br==20)
                    ch='T';
                if (br==21)
                    ch='U';
                if (br==22)
                    ch='V';
                if (br==23)
                    ch='W';
                if (br==24)
                    ch='X';
                if (br==25)
                    ch='Y';
                if (br==26)
                    ch='Z';
                otg1[j]=ch;
                s[j]='a';
            }
        }
    }
    while (br!=s.size());


    for (int i=0; i<s.size(); i++)
    {
        cout << otg1[i];
    }
    cout << endl;


    char otg2[s1.size()];
    int br2=0;
    do
    {
        char maxs=s1[0];
        for (int i=0; i<s1.size(); i++)
        {
            if (s1[i]>maxs)
                maxs=s1[i];
        }
        br2++;
        if (maxs=='0')
            break;
        for (int j=0; j<s1.size(); j++)
        {
            char ch;
            if (s1[j]==maxs)
            {
                if (br2==1)
                    ch='Z';
                if (br2==2)
                    ch='Y';
                if (br2==3)
                    ch='X';
                if (br2==4)
                    ch='W';
                if (br2==5)
                    ch='V';
                if (br2==6)
                    ch='U';
                if (br2==7)
                    ch='T';
                if (br2==8)
                    ch='S';
                if (br2==9)
                    ch='R';
                if (br2==10)
                    ch='Q';
                if (br2==11)
                    ch='P';
                if (br2==12)
                    ch='O';
                if (br2==13)
                    ch='N';
                if (br2==14)
                    ch='M';
                if (br2==15)
                    ch='L';
                if (br2==16)
                    ch='K';
                if (br2==17)
                    ch='J';
                if (br2==18)
                    ch='I';
                if (br2==19)
                    ch='H';
                if (br2==20)
                    ch='G';
                if (br2==21)
                    ch='F';
                if (br2==22)
                    ch='E';
                if (br2==23)
                    ch='D';
                if (br2==24)
                    ch='C';
                if (br2==25)
                    ch='B';
                if (br2==26)
                    ch='A';
                otg2[j]=ch;
                s1[j]='0';
            }
        }
    }
    while (br2!=s1.size());

    for (int i=0; i<s.size(); i++)
    {
        cout << otg2[i];
    }
    return 0;
}
