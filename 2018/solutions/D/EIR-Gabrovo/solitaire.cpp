#include <iostream>
using namespace std;
int a[106][106], maxt[106][106], n;
void read()
{
    string in;
    char c;
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>in;
            if (in[0]=='A'){
                a[i][j]=1;
                continue;
            }
            if (in[0]=='T'){
                a[i][j]=10;
                continue;
            }
            if (in[0]=='J'){
                a[i][j]=11;
                continue;
            }
            if (in[0]=='Q'){
                a[i][j]=12;
                continue;
            }
            if (in[0]=='K'){
                a[i][j]=13;
                continue;
            }
            c=in[0];
            a[i][j]=(int)c-48;
        }
    }
}
void neshto()
{
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            maxt[i][j]=a[i][j];
        }
    }
    for (int i=1; i<n; i++){
        maxt[n-1][i]=maxt[n-1][i]+maxt[n-1][i-1];
    }
    for (int i=n-2; i>=0; i--){
        maxt[i][0]=maxt[i][0]+maxt[i+1][0];
    }
    for (int i=n-2; i>=0; i--){
        for (int j=1; j<n; j++){
            maxt[i][j]=maxt[i][j]+max(maxt[i+1][j], maxt[i][j-1]);
        }
    }
}
int main()
{
    read();
    neshto();
    /*for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<maxt[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------"<<endl;*/
    cout<<maxt[0][n-1]<<endl;

    return 0;
}
/**
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
--------------------
5
8S AD 3C AC 7S
8C 4H QD QS 4T
5D 9H KC 7H AC
TC QC AS 2D KD
AC 2D 3D 5T KS
*/
