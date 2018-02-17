#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;
int power(int number, int powerTo)
{
    long result=1;
    for(int i=0;i<powerTo;i++)
    {
        result*=number;
    }
    return result;
}
int rot(unsigned long long a)
{
    unsigned long long b=a;
    int br=0;
    while(b>=10)
    {
        b=b/10;
        br++;
    }
    int first = b;
    a=a-b*power(10,br);
    return a*10 + b;
}
int digitNumber(unsigned long long a)
{
    int br=0;
    while(a)
    {
        a=a/10;
        br++;
    }
    return br;
}
int solution(unsigned long long a)
{
    unsigned long long copyOfA = a;
    /// a = 216
    int length = digitNumber(a); /// =3
    int digits[length];
    for(int i=length;i>0;i--)
    {
        digits[i-1] = a%10;
        a/=10;
    } /// 2,1,6
    int d1 = 1, d2 = d1+digits[0], dLast = (11-digits[length-1])%10; ///1 , 3, 5
    for(int i=d1*power(10,length-1) + d2*power(10,length-2) + dLast;i<power(10,length);i+=10)  ///
    {
       // cout<<rot(i)<<"-"<<i<<"="<<rot(i)-i<<endl;
        if(i==1372)
        {
           // system("pause");
        }
        if(rot(i)-i==copyOfA)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int b;
    cin>>b;
    b=10;
    unsigned long long M[4];

    for(int i=0;i<4;i++)
    {
        cin>>M[i];
    }

    for(int i=0;i<4;i++)
    {
        //cout<<endl<<rot(M[i])<<" "<<digitNumber(M[i]);
    }
    /*
    M[0]=216;
    M[1]=1318;
    M[2]=2349;
    M[3]=44444;
    */
    for(int i=0;i<4;i++)
    {
     cout<<solution(M[i])<<endl;
     //system("pause");
    }


}
