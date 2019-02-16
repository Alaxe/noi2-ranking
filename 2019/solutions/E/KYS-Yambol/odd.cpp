 #include<iostream>
 using namespace std;

 int main()
 {
     int a,b,i,del,f,ch;
     cin>>a>>b;
     ch=0;
     i=2;
     f=1;
     while ((i>a)||(i<b)){
        while (i>a){
            if(i%f==0)
                del++;
            f++;
        }
    if(del%2!=0)
        ch++;
    i++;
     }
     cout<<ch<<endl;
     return 0;
 }
