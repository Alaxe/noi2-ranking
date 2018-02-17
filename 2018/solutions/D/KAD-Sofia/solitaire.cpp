#include<iostream>
using namespace std;
int f(char t){
    if(t=='A'){
        return 1;
    }else if(t=='2'){
        return 2;
    }else if(t=='3'){
        return 3;
    }else if(t=='4'){
        return 4;
    }else if(t=='5'){
        return 5;
    }else if(t=='6'){
        return 6;
    }else if(t=='7'){
        return 7;
    }else if(t=='8'){
        return 8;
    }else if(t=='9'){
        return 9;
    }else if(t=='T'){
        return 10;
    }else if(t=='J'){
        return 11;
    }else if(t=='Q'){
        return 12;
    }else if(t=='K'){
        return 13;
    }
}
int main(){
    int n;
    cin>>n;
    char a[3];
    int i,ch[n][n],i2;
    for(i=0;i<n;i++){
        for(i2=0;i2<n;i2++){
            cin>>a;
            ch[i][i2]=f(a[0]);
        }
    }
    if(n==1){
        cout<<ch[0][0]<<endl;
        return 0;
    }
    long long sbor,naigolqmo=0,i3,i4;
    i2=0;
    for(i=n-1;i>=1;i--){
        if(i!=n-1){
            if(ch[i+1][i2]>=ch[i][i2-1]){
                ch[i][i2]+=ch[i+1][i2];
            }else{
                ch[i][i2]+=ch[i][i2-1];
            }
            for(i3=i2+1;i3<n;i3++){
                if(ch[i][i3-1]>=ch[i+1][i3]){
                    ch[i][i3]+=ch[i][i3-1];
                }else{
                    ch[i][i3]+=ch[i+1][i3];
                }
            }
            for(i4=i-1;i4>=0;i4--){
                if(ch[i4+1][i2]>=ch[i4][i2-1]){
                    ch[i4][i2]+=ch[i4+1][i2];
                }else{
                    ch[i4][i2]+=ch[i4][i2-1];
                }
            }
        }else if(i==n-1){
            for(i3=i2+1;i3<n;i3++){
                ch[i][i3]+=ch[i][i3-1];
            }
            for(i4=i-1;i4>=0;i4--){
                ch[i4][i2]+=ch[i4+1][i2];
            }
        }
        i2++;
    }
    if(ch[0][n-2]>=ch[1][n-1]){
        ch[0][n-1]+=ch[0][n-2];
    }else{
        ch[0][n-1]+=ch[1][n-1];
    }
    cout<<ch[0][n-1]<<endl;
return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
