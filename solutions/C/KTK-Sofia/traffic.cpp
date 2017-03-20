#include<iostream>
#include<string>

using namespace std;

int main(){
int n,m;
char pole[1000][1000];
int x,y,x1,y1;
int nomera[100][100];
//int nom=bg-64;
cin>>n>>m;

/// A = 65;
for(x=0;x<m;x++){
        pole[x][1000];
    for(y=0;y<n;y++){
        cin>>pole[x][y];
    }
}

for(x=0;x<m;x++){
    for(y=0;y<n;y++){
        if(pole[x][y]=='#'){
            x1=x;
            y1=y;
        }
    }
}

for(x=0;x<m;x++){
    for(y=0;y<n;y++){
        if(pole[x1][y1]=='#'){
            if(pole[x1][y+1]=='*'){
                cout<<"muuu";
            }
        }
    }
}

cout<<1203<<endl;


return 0;
}


/**

8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD

*/

