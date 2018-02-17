#include <iostream>
using namespace std;
int main()
{
	int d1,d2,d3,m1,m2,m3,d,m,od1,od2,od3,od;
	char s;
	cin>>d1>>s>>m1>>d2>>s>>m2>>d3>>s>>m3>>d>>s>>m;
	if(m1==1) od1=d1;
	else if(m1==2) od1=31+d1;
	else if(m1==3) od1=31+28+d1;
	else if(m1==4) od1=31+28+31+d1;
	else if(m1==5) od1=31+28+31+30+d1;
	else if(m1==6) od1=31+28+31+30+31+d1;
	else if(m1==7) od1=31+28+31+30+31+30+d1;
	else if(m1==8) od1=31+28+31+30+31+30+31+d1;
	else if(m1==9) od1=31+28+31+30+31+30+31+31+d1;
	else if(m1==10) od1=31+28+31+30+31+30+31+31+30+d1;
	else if(m1==11) od1=31+28+31+30+31+30+31+31+30+31+d1;
	else if(m1==12) od1=31+28+31+30+31+30+31+31+30+31+30+d1;
	if(m2==1) od2=d2;
	else if(m2==2) od2=31+d2;
	else if(m2==3) od2=31+28+d2;
	else if(m2==4) od2=31+28+31+d2;
	else if(m2==5) od2=31+28+31+30+d2;
	else if(m2==6) od2=31+28+31+30+31+d2;
	else if(m2==7) od2=31+28+31+30+31+30+d2;
	else if(m2==8) od2=31+28+31+30+31+30+31+d2;
	else if(m2==9) od2=31+28+31+30+31+30+31+31+d2;
	else if(m2==10) od2=31+28+31+30+31+30+31+31+30+d2;
	else if(m2==11) od2=31+28+31+30+31+30+31+31+30+31+d2;
	else if(m2==12) od2=31+28+31+30+31+30+31+31+30+31+30+d2;
	if(m3==1) od3=d3;
	else if(m3==2) od3=31+d3;
	else if(m3==3) od3=31+28+d3;
	else if(m3==4) od3=31+28+31+d3;
	else if(m3==5) od3=31+28+31+30+d3;
	else if(m3==6) od3=31+28+31+30+31+d3;
	else if(m3==7) od3=31+28+31+30+31+30+d3;
	else if(m3==8) od3=31+28+31+30+31+30+31+d3;
	else if(m3==9) od3=31+28+31+30+31+30+31+31+d3;
	else if(m3==10) od3=31+28+31+30+31+30+31+31+30+d3;
	else if(m3==11) od3=31+28+31+30+31+30+31+31+30+31+d3;
	else if(m3==12) od3=31+28+31+30+31+30+31+31+30+31+30+d3;
	if(m==1) od=d;
	else if(m==2) od=31+d;
	else if(m==3) od=31+28+d;
	else if(m==4) od=31+28+31+d;
	else if(m==5) od=31+28+31+30+d;
	else if(m==6) od=31+28+31+30+31+d;
	else if(m==7) od=31+28+31+30+31+30+d;
	else if(m==8) od=31+28+31+30+31+30+31+d;
	else if(m==9) od=31+28+31+30+31+30+31+31+d;
	else if(m==10) od=31+28+31+30+31+30+31+31+30+d;
	else if(m==11) od=31+28+31+30+31+30+31+31+30+31+d;
	else if(m==12) od=31+28+31+30+31+30+31+31+30+31+30+d;
	od1=od1%23;
	od2=od2%28;
	od3=od3%33;
    for(;;)
    {
        if(od1==od2 && od1==od3) break;
        else
        {
            if(od2>=od1 && od3>=od1) od1=od1+23;
            else if(od1>=od2 && od3>=od2) od2=od2+28;
            else od3=od3+33;
        }
    }
    if(od1>od) cout<<od1-od;
    else cout<<od1+21252-od;
    cout<<endl;
	return 0;
}

