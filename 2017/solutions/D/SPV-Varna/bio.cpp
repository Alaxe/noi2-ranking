#include<iostream>
using namespace std;

int main(){

int d1, d2, d3;
int m1, m2, m3;
int d, m;
char c;

cin>>d1>>c>>m1>>d2>>c>>m2>>d3>>c>>m3>>d>>c>>m;

int n1, n2, n3, n;
switch(m1){
    case 1:
        n1=d1;
        break;
    case 2:
        n1=d1+31;
        break;
    case 3:
        n1=d1+59;
        break;
    case 4:
        n1=d1+90;
        break;
    case 5:
        n1=d1+120;
        break;
    case 6:
        n1=d1+151;
        break;
    case 7:
        n1=d1+181;
        break;
    case 8:
       n1=d1+212;
        break;
    case 9:
       n1=d1+243;
        break;
    case 10:
       n1=d1+273;
        break;
    case 11:
      n1=d1+304;
        break;
    case 12:
        n1=d1+334;
        break;
}

switch(m2){
    case 1:
        n2=d2;
        break;
    case 2:
        n2=d2+31;
        break;
    case 3:
        n2=d2+59;
        break;
    case 4:
        n2=d2+90;
        break;
    case 5:
        n2=d2+120;
        break;
    case 6:
        n2=d2+151;
        break;
    case 7:
        n2=d2+181;
        break;
    case 8:
       n2=d2+212;
        break;
    case 9:
       n2=d2+243;
        break;
    case 10:
       n2=d2+273;
        break;
    case 11:
      n2=d2+304;
        break;
    case 12:
        n2=d2+334;
        break;
}

switch(m3){
    case 1:
        n3=d3;
        break;
    case 2:
        n3=d3+31;
        break;
    case 3:
        n3=d3+59;
        break;
    case 4:
        n3=d3+90;
        break;
    case 5:
        n3=d3+120;
        break;
    case 6:
        n3=d3+151;
        break;
    case 7:
        n3=d3+181;
        break;
    case 8:
       n3=d3+212;
        break;
    case 9:
       n3=d3+243;
        break;
    case 10:
       n3=d3+273;
        break;
    case 11:
      n3=d3+304;
        break;
    case 12:
        n3=d3+334;
        break;
}

switch(m){
    case 1:
        n=d;
        break;
    case 2:
        n=d+31;
        break;
    case 3:
        n=d+59;
        break;
    case 4:
        n=d+90;
        break;
    case 5:
        n=d+120;
        break;
    case 6:
        n=d+151;
        break;
    case 7:
        n=d+181;
        break;
    case 8:
       n=d+212;
        break;
    case 9:
       n=d+243;
        break;
    case 10:
       n=d+273;
        break;
    case 11:
      n=d+304;
        break;
    case 12:
        n=d+334;
        break;
}

///23/7 29/10 23/7 10/2; 1 1 1 1 1 1 2 1
//cout<<n<<endl;
//cout<<d1<<" "<<m1<<" "<<d2<<" "<<m2<<" "<<d3<<" "<<m3<<" "<<d<<" "<<m;
//cout<<n1%23<<" "<<n2%28<<n3%33<<endl;
if(n1 == n2 == n3) {cout<<21252-n+1<<endl; return 0;}
//if(d1==23 && m1==7){ cout<<10789<<endl; return 0;}

while(n1!=n2!=n3){
n1+=23;
n2+=28;
n3+=33;
}

cout<<n1;
}
