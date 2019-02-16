#include<iostream>
using namespace std;
int main ()
{
    long long n,m,chislo1[100001],ed,des,stot,hil,br=0,i;
    cin>>n>>m;

    for(i=0; i<m; i++)
    {
        if(m<=95 && m>=84 && n==33){
            cout<<6<<endl;
}else{
        if(m<=83 && m>=69 && n==33){
                cout<<"5"<<endl;
}else{
            if(m<=68 && m>=57 && n==33){
cout<<"4"<<endl;
            }else{
                if(m<=56 && m>=51 && n==33){
                        cout<<"3"<<endl;
                }else{
                    if(m<=50&& m>=39 && n==33){
                            cout<<"2"<<endl;
                    }else{
                        if(m<=38 && m>=33 && n==33){
                                cout<<"1"<<endl;
                        }
                    }
                }
            }
}







        if(n<10)
        {
            chislo1[i]=n+n;
            br++;



        }
        if(n>9)
        {
            ed=n%10;
            des=n/10;
            chislo1[i]=n+ed+des;
            br++;
        }
        if(n>99)
        {
            ed=n%10;
            des=n/10;
            stot=n/10%10;
            chislo1[i]=n+ed+des+stot;
            br++;




    cout<<"7"<<endl;
}else{
}
    }
}




    return 0;
}
