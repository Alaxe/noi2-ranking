#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    long long b,d,m,y,obshto=0;
    cin>>a>>b;
    if(a[1]=='/')
    {
        d=a[0]-'0';
        if(a[3]=='/')
        {
            m=a[2]-'0';
        }
        else
        {
            m=(a[2]-'0')*10+a[3]-'0';
        }
    }
    else
    {
        d=(a[0]-'0')*10+a[1]-'0';
        if(a[4]=='/')
        {
            m=a[3]-'0';
        }
        else
        {
            m=(a[3]-'0')*10+a[4]-'0';
        }
    }

    y=2000+a[a.size()-1]-'0'+(a[a.size()-2]-'0')*10;
    int v=0;
    for(int c=1; c<m; c++)
    {
        //d++;
        if(c==4 or c==6 or c==9 or c==11)
        {
            obshto=obshto+30;
        }
        if(c==2)
        {
            if(y%4==0 or (y%100!=0 or y%400==0))
            {
                obshto=obshto+29;
            }
            else
            {
                obshto=obshto+28;
            }
        }
        if(c==1 or c==3 or c==5 or c==7 or c==8 or c==10)
        {
            obshto=obshto+31;
        }
        if(c==12)
        {
            obshto=obshto+31;
        }

    }
   // obshto=obshto+d;
    //cout<<obshto<<" "<<m<<" "<<d<<endl;
    d=d+b+(b-1)/5*2;
    //cout<<d<<endl;
    if(y==2019){
        if(obshto%7+d%7==5){
            d++;
        }
        if(obshto%7+d%7==6){
            d++;
        }
    }
    if(y==2020){
        if(obshto%7+d%7==4){
            d++;
        }
        if(obshto%7+d%7==5){
            d++;
        }
    }
    if(y==2021){
        if(obshto%7+d%7==2){
            d++;
        }
        if(obshto%7+d%7==3){
            d++;
        }
    }
    //cout<<obshto;
   // cout<<d;
    while(true)
    {

        //d++;
        if(m==0){
            if(d<=31){
                break;
            }
            d=d-31;
            m++;

        }
        if(m==4 or m==6 or m==9 or m==11)
        {
            if(d<=30){
                break;
            }
            d=d-30;

            m++;
        }

        if(m==2)
        {
            if(y%4==0 or (y%100!=0 or y%400==0))
            {
                if(d<=29){
                break;
            }
                d=d-29;

            m++;
            }
            else
            {
                if(d<=28){
                break;
            }
                d=d-28;

            m++;
            }
        }
        if(m==1 or m==3 or m==5 or m==7 or m==8 or m==10)
        {
            if(d<=31){
                break;
            }
            d=d-31;

            m++;
        }
        if(m==12)
        {
            if(d<=31){
                break;
            }
            m=1;
            y=y+1;
            d=d-31;

        }
    }
    bool vl=true;
   // cout<<obshto;
    /*while(v<=b)
    {

        obshto++;
        cout<<obshto<<endl;
    }*/
    //cout<<obshto<<endl;
    if(d<10){
        cout<<"0"<<d<<".";
    }else{
        cout<<d<<".";
    }
    if(m<10){
        cout<<"0"<<m<<".";
    }else{
        cout<<m<<".";
    }
    cout<<y<<endl;
    return 0;
}
