#include<bits/stdc++.h>
using namespace std;
string a[100][100];
int main()
{
    long long n,i,num,r,c,sum=0,p1,p2;
    string beg,up,right,k,var1,var2;
    cin >> n;

    for(r=1; r<=n; r++)
    {
        for(c=1; c<=n; c++)
        {
            cin >> a[r][c];
        }
    }


            beg=a[n][1];
            if(beg=="AC" || beg=="AD" || beg=="AH" || beg=="AS") num=1;
            if(beg=="2C" || beg=="2D" || beg=="2H" || beg=="2S") num=2;
            if(beg=="3C" || beg=="3D" || beg=="3H" || beg=="3S") num=3;
            if(beg=="4C" || beg=="4D" || beg=="4H" || beg=="4S") num=4;
            if(beg=="5C" || beg=="5D" || beg=="5H" || beg=="5S") num=5;
            if(beg=="6C" || beg=="6D" || beg=="6H" || beg=="6S") num=6;
            if(beg=="7C" || beg=="7D" || beg=="7H" || beg=="7S") num=7;
            if(beg=="8C" || beg=="8D" || beg=="8H" || beg=="8S") num=8;
            if(beg=="9C" || beg=="9D" || beg=="9H" || beg=="9S") num=9;
            if(beg=="TC" || beg=="TD" || beg=="TH" || beg=="TS") num=10;
            if(beg=="JC" || beg=="JD" || beg=="JH" || beg=="JS") num=11;
            if(beg=="QC" || beg=="QD" || beg=="QH" || beg=="QS") num=12;
            if(beg=="KC" || beg=="KD" || beg=="KH" || beg=="KS") num=13;
            sum+=num;
    cout << beg << " " << num <<endl; ///!!!!!!!!!!!!!!!!!!!!!!

    while(k!=a[1][n])
    {

            if(var1=="AC" || var1=="AD" || var1=="AH" || var1=="AS") num1=1;
            if(var1=="2C" || var1=="2D" || var1=="2H" || var1=="2S") num1=2;
            if(var1=="3C" || var1=="3D" || var1=="3H" || var1=="3S") num1=3;
            if(var1=="4C" || var1=="4D" || var1=="4H" || var1=="4S") num1=4;
            if(var1=="5C" || var1=="5D" || var1=="5H" || var1=="5S") num1=5;
            if(var1=="6C" || var1=="6D" || var1=="6H" || var1=="6S") num1=6;
            if(var1=="7C" || var1=="7D" || var1=="7H" || var1=="7S") num1=7;
            if(var1=="8C" || var1=="8D" || var1=="8H" || var1=="8S") num1=8;
            if(var1=="9C" || var1=="9D" || var1=="9H" || var1=="9S") num1=9;
            if(var1=="TC" || var1=="TD" || var1=="TH" || var1=="TS") num1=10;
            if(var1=="JC" || var1=="JD" || var1=="JH" || var1=="JS") num1=11;
            if(var1=="QC" || var1=="QD" || var1=="QH" || var1=="QS") num1=12;
            if(var1=="KC" || var1=="KD" || var1=="KH" || var1=="KS") num1=13;

            if(var2=="AC" || var2=="AD" || var2=="AH" || var2=="AS") num2=1;
            if(var2=="2C" || var2=="2D" || var2=="2H" || var2=="2S") num2=2;
            if(var2=="3C" || var2=="3D" || var2=="3H" || var2=="3S") num2=3;
            if(var2=="4C" || var2=="4D" || var2=="4H" || var2=="4S") num2=4;
            if(var2=="5C" || var2=="5D" || var2=="5H" || var2=="5S") num2=5;
            if(var2=="6C" || var2=="6D" || var2=="6H" || var2=="6S") num2=6;
            if(var2=="7C" || var2=="7D" || var2=="7H" || var2=="7S") num2=7;
            if(var2=="8C" || var2=="8D" || var2=="8H" || var2=="8S") num2=8;
            if(var2=="9C" || var2=="9D" || var2=="9H" || var2=="9S") num2=9;
            if(var2=="TC" || var2=="TD" || var2=="TH" || var2=="TS") num2=10;
            if(var2=="JC" || var2=="JD" || var2=="JH" || var2=="JS") num2=11;
            if(var2=="QC" || var2=="QD" || var2=="QH" || var2=="QS") num2=12;
            if(var2=="KC" || var2=="KD" || var2=="KH" || var2=="KS") num2=13;



        }
    }


     cout << sum <<endl;
    return 0;
}
