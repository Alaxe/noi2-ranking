#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

struct fff{
long long number, day;
};



  priority_queue < pair < long long, long long > > q;
  long long n,k,FIRST,MUL,ADD,MOD,a;
  long long sum,day,number;
  fff current;

int main(){

    cin>>n>>k;
    cin>>FIRST>>MUL>>ADD>>MOD;

    a=FIRST;
    sum+=FIRST;

    current.day=1;
    current.number=FIRST;


    for(int i=2;i<=n;i++){
        a=(a*MUL+ADD)%MOD; /// day=i; number=a;

        if(a>=current.number){
            current.number=a;
            current.day=i;
        }
        else
        if(a<current.number){
            q.push(make_pair(a,i));
        }

        if(current.day+k<=i){
            current.day=0;
            current.number=0;

            if(q.empty()){
                current.day=i;
                current.number=a;
                a=-1;
            }
            else
            {
                for(;!q.empty();){

                    number=q.top().first;
                    day=q.top().second;
                    q.pop();

                    if(day+k>i){
                        current.day=day;
                        current.number=number;
                        break;
                    }
                }

                if(a>=current.number){
                    q.push(make_pair(current.number,day));
                    current.number=a;
                    current.day=i;
                }
                else{
                    q.push(make_pair(a,i));
                }

            }
        }

        sum+=current.number;

    }


cout<<sum<<endl;
return 0;
}
/*
7 3
5 3 2 23

133742 666
20 3 17 1000000007

3000000 625
3 17 525 16234


*/
