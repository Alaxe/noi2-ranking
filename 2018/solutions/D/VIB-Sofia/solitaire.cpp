#include<iostream>
using namespace std;
int main(){
    long long n=100;
    cin>>n;
    char tablica[n][2*n];
    long long maxtochki[n][n],tochki[n][n],putishta[1000];
    for(int a=0;a<n;a++){
        for(int b=0;b<2*n;b++){
            cin>>tablica[a][b];
        }
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<2*n;b=b+2){
            if(tablica[a][b]<='9' and tablica[a][b]>='0'){
                tochki[a][b/2]=tablica[a][b]-'0';
            }
            else if(tablica[a][b]=='A'){
                tochki[a][b/2]=1;
            }
            else if(tablica[a][b]=='J'){
                tochki[a][b/2]=11;
            }
            else if(tablica[a][b]=='Q'){
                tochki[a][b/2]=12;
            }
            else if(tablica[a][b]=='K'){
                tochki[a][b/2]=13;
            }
            else if(tablica[a][b]=='T'){
                tochki[a][b/2]=10;
            }
        }
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            maxtochki[a][b]=0;
        }
    }
    for(int a=n-1;a>=0;a--){
        for(int b=0;b<n;b++){
                if(a==n-1 and b==0){
                    maxtochki[a][b]=tochki[a][b];
                }
                else if(a==n-1){
                    maxtochki[a][b]=tochki[a][b]+maxtochki[a][b-1];
                }
                else if(b==0){
                    maxtochki[a][b]=tochki[a][b]+maxtochki[a+1][b];
                }
                else if(a!=n-1 and b!=0){
                    if(maxtochki[a+1][b]>maxtochki[a][b-1]){
                        maxtochki[a][b]=tochki[a][b]+maxtochki[a+1][b];
                    }
                    else{
                        maxtochki[a][b]=tochki[a][b]+maxtochki[a][b-1];
                    }
                }
        }
    }
    cout<<endl<<maxtochki[0][n-1];
return 0;
}
