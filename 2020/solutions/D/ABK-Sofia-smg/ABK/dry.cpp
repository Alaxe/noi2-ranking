#include<bits/stdc++.h>
long long masiv[110],otg[105];
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long br,raz,sh;
cin>>br>>raz>>sh;
for(long long i=1;i<=br;i++){
    cin>>masiv[i];
}
long long h=1,h2,h3;
while(h<=br ){
    if(masiv[h]<masiv[h+1]){
            otg[h]=masiv[h];


    }
    if(masiv[h]>=masiv[h+1]){
            h2=h;
            while(masiv[h2]>=masiv[h2+1] && h2<=br){
                h2++;
            }
            h2++;

            while(h<h2){
                otg[h]=masiv[h2];
                h++;
            }


    }

     h++;

}
 h=br;

while(h>=1 ){
    if(masiv[h]<masiv[h-1]){
            otg[h]=max(masiv[h],otg[h]);
    }
    if(masiv[h]>=masiv[h-1]){
            h2=h;
            while(masiv[h]>=masiv[h2] && h2>=1){
                h2--;
            }
            h2--;
        if(h2<1){
        h=h2;
            }
                h3=h;
            while(h>h2){
                otg[h]=max(otg[h],masiv[h3]);
                h--;
            }


    }

     h--;
}
long long sum=0;
for(long long i=1;i<br;i++){

   sum+=(otg[i]*raz*sh);
}
cout<<sum<<endl;


return 0;
}
