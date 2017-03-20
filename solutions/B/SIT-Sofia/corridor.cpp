#include<iostream>
#include<vector>
using namespace std;

int masiv[100000000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

int dulj,shir,n,x,y,predx,predy;
long long sum=0,a=0,br=0;
cin>>dulj>>shir;
cin>>n;

for(int i=0;i<n;i++){
    cin>>x>>y;
    if(i==0){
        predx=x;
        predy=y;

        masiv[y]=x;

    }else{
    if(x==predx){
        if(y>predy ){
            for(int j=0;j<y-predy;j++){

                masiv[j+predy]=max(x, masiv[j+predy]);

            }
        }else{
        for(int j=0;j<predy-y;j++){

                masiv[j+y]=max(x, masiv[j+y]);

            }

        }
    }else{
    if(x>predx){

        masiv[y]=max(x,masiv[y]);

    }else{

        //masiv[y]=max(predx,masiv[y]);
    }
    }
    predx=x;
    predy=y;
    }
/*for(int j=0;j<shir;j++){
    cout<<masiv[j]<<" ";
}
cout<<"\n";*/
}
   //sum+=dulj*br;



for(int i=0;i<shir;i++){

    sum+=(dulj-masiv[i]);
}
cout<<sum<<"\n";

return 0;
}
/*
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
/*
5 5
9
0 1
2 1
2 2
1 2
1 3
3 3
4 3
4 4
5 4
*/
