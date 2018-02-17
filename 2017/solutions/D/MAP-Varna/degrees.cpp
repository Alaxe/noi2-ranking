#include<iostream>
using namespace std;
int main ()
{
    int n=0,s=2,br=0,s2=2,br2=0,k;/**n-stepenta na 2 ; s-proverka */
    string a; /** chislata ot 2 do 2 na n-ta - a*/
    cin>>a; /** vuvejdame a */
    //cout<<endl;
    k=a.size();
    //cout<<"GOLEMINATA NA NIZA E "<<a.size()<<endl;
    while(br2<k)
    {
        while(s2!=0)
        {
            s2=s2/10;
            br++;
        }
        //cout<<br<<endl;
        br2=br2+br;
        s=s*2;
        s2=s;
        n++;
        br=0;
        //cout<<n<<endl;
    }
    cout<<n<<endl;/** tursenoto chislo n */
    return 0;
}
