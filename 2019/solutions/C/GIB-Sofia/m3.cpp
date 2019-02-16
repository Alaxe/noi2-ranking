#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    long long S,K,a,b,c,d;
    cin>>S>>K>>a>>b>>c>>d;
    long long sectorVolume = 4*d;
    long int fullSectors = K/sectorVolume;
    long double leftover = K%sectorVolume, results[4];
    results[0]=results[1]=results[2]=results[3]=0;
    int currentSector = (fullSectors%4) + 1;
    if(leftover == 0.0){
        results[0]=results[1]=results[2]=results[3]=d;
    }else{
        if(currentSector == 1){
            if(leftover<=a){
                results[0]=leftover;
            }else if(leftover<=2*c){
                if(leftover<2*a){
                    results[0]=a;
                    results[1]=leftover-a;
                }else{
                    results[0]=results[1]=leftover/2;
                }
            }else if(leftover>2*c && leftover<4*c){
                results[0]=results[1]=c;
                if(leftover-2*c<=b){
                    results[2]=leftover-2*c;
                }else{
                    if(leftover-2*c < 2*b){
                        results[2]=b;
                        results[3]=leftover-2*c-b;
                    }else{
                        results[2]=results[3]=(leftover-2*c)/2;
                    }
                }
            }else{
                results[0]=results[1]=results[2]=results[3]=leftover/4;
            }
        }else if(currentSector == 2){
            if(leftover<=b*2){
                results[0]=leftover;
            }else if(leftover<=b+a){
                results[0]=b;
                results[1]=leftover-b;
            }else if(leftover<b+2*a){
                results[0]=b;
                results[1]=leftover-b;
                results[2]=leftover-b-a;
            }else if(leftover<=b*3){
                results[0]=b;
                results[1]=results[2]=(leftover-b)/2;
            }else if(leftover<=3*c){
                results[0]=results[1]=results[2]=leftover/3;
            }else if(leftover<=c*4){
                results[0]=results[1]=results[2]=c;
                results[3]=leftover-3*c;
            }else{
                results[0]=results[1]=results[2]=results[3]=leftover/4;
            }
        }else if(currentSector == 3){
            if(leftover<b){
                results[0]=leftover;
            }else if(leftover<=2*b){
                results[0]=b;
                results[1]=leftover-b;
            }else if(leftover<=2*c){
                results[0]=results[1]=leftover/2;
            }else if(leftover<=2*c+a){
                results[0]=results[1]=c;
                results[2]=leftover-2*c;
            }else if(leftover<=4*c){
                results[0]=results[1]=c;
                results[2]=results[3]=(leftover-2*c)/2;
            }else{
                results[0]=results[1]=results[2]=results[3]=leftover/4;
            }
        }else if(currentSector == 4){
            if(leftover<=c){
                results[0]=leftover;
            }else if(leftover<=c+a){
                results[0]=c;
                results[1]=leftover-c;
            }else if(leftover<=c+2*b){
                results[0]=c;
                results[1]=results[2]=(leftover-c)/2;
            }else if(leftover<=c+3*b){
                results[0]=c;
                results[1]=results[2]=b;
                results[3]=leftover-c-2*b;
            }
            else if(leftover<=4*c){
                results[0]=c;
                results[1]=results[2]=results[3]=(leftover-c)/3;
            }else{
                results[0]=results[1]=results[2]=results[3]=leftover/4;
            }
        }
    }
    for(int i=0;i<4;i++){
        cout<<fixed<<setprecision(3)<<results[i]<<endl;
    }
    return 0;
}
