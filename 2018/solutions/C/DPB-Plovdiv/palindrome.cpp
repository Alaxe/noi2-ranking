#include<iostream>
#include<string>
using namespace std;

string number;
unsigned size;
string half;

void add1(string &str,int size=::size)
{
   if(size==0)
       str="1"+str,::size=size+1;
   else if(str[size-1]=='9')
   {
      str[size-1]='0';
      add1(str,size-1);
   }
   else
       str[size-1]++;
}
void getHalf()
{
     const int s=size/2;
     half="";
     for(int i=0;i<s;i++)
         half+=number[i];
     if(size%2!=0)half+=number[s];
     for(int i=s-1;i>=0;i--)
         half+=number[i];
}
int main()
{
    cin>>number;
    size=number.size();
    getHalf();
    if(half<number)
    {
        string n1="";
        for(int i=0;i<size/2;i++)
            n1+=number[i];
        add1(n1,size/2);
        for(int i=0;i<size/2;i++)
            number[i]=n1[i];
        getHalf();
    }
    cout<<half<<endl;
    system("pause");
    return 0;
}

