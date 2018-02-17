#include <iostream>
using namespace std;
int main(){
long long N,L;
cin>>N>>L;
long long pechati[L-1],a=0,numbers[N-1];
for(long k=0;k<L;k++){
    cin>>pechati[k];
}
for(long h=0;h<10;h++){
    for(long f=0;f<10;f++){
        if(L==1){
            if(f!=pechati[0] && h!=pechati[0]){
              numbers[a]=h*10+f;
              a++;
            }
            if(f==pechati[0] && h==pechati[0]){
                numbers[a]=(h+1)*10+(f+1);
                a++;
            }
            if(f==pechati[0] && h!=pechati[0]){
                numbers[a]=h*10+f+1;
                a++;
            }
            if(f!=pechati[0] && h==pechati[0]){
                numbers[a]=(h+1)*10+f+1;
                a++;
            }
        }
        if(L==2){
          if((f!=pechati[0] && h!=pechati[0] ) && (f!=pechati[1] && h!=pechati[1])){
              numbers[a]=h*10+f;
              a++;
            }
            if(f==pechati[0] && h==pechati[0]){
                numbers[a]=(h+1)*10+(f+1);
                a++;
            }
            if(f==pechati[1] && h==pechati[1]){
                numbers[a]=(h+1)*10+(f+1);
                a++;
            }
            if(f==pechati[0] && h!=pechati[0]){
                numbers[a]=h*10+f+1;
                a++;
            }
                        if(f==pechati[1] && h!=pechati[1]){
                numbers[a]=h*10+f+1;
                a++;
            }
            if(f!=pechati[0] && h==pechati[0]){
                numbers[a]=(h+1)*10+f+1;
                a++;
            }  if(f!=pechati[1] && h==pechati[1]){
                numbers[a]=(h+1)*10+f+1;
                a++;
            }
        }
        if(L==3){
          if((f!=pechati[0] && h!=pechati[0]) && (f!=pechati[1] && h!=pechati[1]) && (f!=pechati[2] && h!=pechati[2])){
              numbers[a]=h*10+f;
              a++;
            }
            if(f==pechati[0] && h==pechati[0]){
                numbers[a]=(h+1)*10+(f+1);
                a++;
            }
            if(f==pechati[1] && h==pechati[1]){
                numbers[a]=(h+1)*10+(f+1);
                a++;
            }
            if(f==pechati[2] && h==pechati[2]){
                numbers[a]=(h+1)*10+(f+1);
                a++;
            }
            if(f==pechati[0] && h!=pechati[0]){
                numbers[a]=h*10+f+1;
                a++;
            }
                if(f==pechati[1] && h!=pechati[1]){
                numbers[a]=h*10+f+1;
                a++;
            }
             if(f==pechati[2] && h!=pechati[2]){
                numbers[a]=h*10+f+1;
                a++;
            }
            if(f!=pechati[0] && h==pechati[0]){
                numbers[a]=(h+1)*10+f+1;
                a++;
            }
             if(f!=pechati[1] && h==pechati[1]){
                numbers[a]=(h+1)*10+f+1;
                a++;
            }
            if(f!=pechati[2] && h==pechati[2]){
                numbers[a]=(h+1)*10+f+1;
                a++;
            }
        }
    }
}
cout<<numbers[N-1];
return 0;
}
