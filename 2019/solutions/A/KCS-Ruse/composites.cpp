#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int j,x,z,l,key,br=0,otg=0;
unsigned long long y,i,n;
int p[] = {9,25,49,121,169,289,361,529,841,961,1369,1681,1849,2209,2809,3481,3721,4489,5041,5329,6241,6889,7921,9409,10201,10609,11449,11881,12769,16129,17161,18769,19321,22201,22801,24649,26569,27889,29929,32041,32761,36481,37249,38809,39601,44521,49729,51529,52441,54289,57121,58081,63001,66049,69169,72361,73441,76729,78961,80089,85849,94249,96721,97969,100489,109561,113569,120409,121801,124609,128881,134689,139129,143641,146689,151321,157609,160801,167281,175561,177241,185761,187489,192721,196249,201601,208849,212521,214369,218089,229441,237169,241081,249001,253009,259081,271441,273529,292681,299209,310249,316969,323761,326041,332929,344569,351649,358801,361201,368449,375769,380689,383161,398161,410881,413449,418609,426409,434281,436921,452929,458329,466489,477481,491401,502681,516961,528529,537289,546121,552049,564001,573049,579121,591361,597529,619369,635209,654481,657721,674041,677329,683929,687241,703921,727609,734449,737881,744769,769129,776161,779689};
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("test.txt","r",stdin);
    cin>>n;
    if(n%2==1) i=n+1;
    else i=n;
    while(otg==0)
    {
        for(j=0;j<150;j++)
        {
            key=0;
            y=p[j]+i;
            z=sqrt(y);
            for(l=2;l<=z;l++)
            {
                if(y%l==0) {key=1;break;}
            }
            if(key==0) break;
        }
        if(key==1) {cout<<i<<endl;otg=1;}
        i+=2;
    }
    return 0;
}