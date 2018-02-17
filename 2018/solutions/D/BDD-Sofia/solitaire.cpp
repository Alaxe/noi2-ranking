#include<iostream>
using namespace std;
int main (){
    long long n;
    cin>>n;
    long long pole[n][n],x,y,sbor=0,k=9;
    char a,b;
    for(x=0;x<n;x++){
        for(y=0;y<n;y++){
            cin>>a>>b;
            if(a=='T'){ pole[x][y]=10;}else{
            if(a=='J'){ pole[x][y]=11;}else{
            if(a=='K'){ pole[x][y]=13;}else{
            if(a=='A'){ pole[x][y]=1;}else{
            if(a=='Q'){ pole[x][y]=12;}else{
                pole[x][y]=a-'0';
            }
            }
            }
            }
            }
        }
    }
    for(x=0;x<n;x++){
        for(y=0;y<n;y++){
                cout<<pole[x][y]<<" ";
        }
        cout<<"\n";
    }
    sbor=sbor+pole[n-1][0];
    cout<<sbor;
    y=0;
    for(x=n-1;x!=0 && y!=n-1;sbor=sbor+pole[x][y]){
        if(pole[x][y+1]>pole[x-1][y]){
            y=y+1;
        }else{
            if(pole[x][y+1]<pole[x-1][y]){
                x=x-1;
            }else{
                if(pole[x][y+1]==pole[x-1][y] && pole[x][y+2]>pole[x-2][y]){
                    y=y+1;
                }else{
                    x=x-1;
                }
            }
        }
          if(x==2 && y==n-1){
            sbor=sbor+pole[1][n-1];
        }
        cout<<x<<" "<<y<<"\n";
    }
    sbor=sbor+pole[0][n-1];
    cout<<sbor;
return 0;
}

