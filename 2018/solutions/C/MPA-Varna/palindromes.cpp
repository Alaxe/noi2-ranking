#include<iostream>
#include<string>
using namespace std;
string input;
int ar[1301];
int main()
{

    cin>>input;
    int size = input.size();
    bool oddSize = false;
    for(int i = 0; i<size/2; ++i)
    {

        ar[i] = input[i]-'0';
        ar[size-i-1] = input[i]-'0';

    }


    if(input.size()%2!=0)
    {
        ar[input.size()/2] = input [input.size()/2]-'0';
        oddSize = true;
    }



    if(!oddSize)
    {
        for(int i = 0; i<size/2; ++i)
        {

            if(ar[i]<input[size-i-1]-'0')
            {

                if(ar[size/2]<=input[size/2]-'0'&&ar[size-size/2]<=input[size-size/2]-'0')
                {
                    ar[size/2-1]++;
                    ar[size-size/2]++;
                }
                else break;


            }
            if(ar[i]>input[size-i-1]-'0') break;



        }
    }
    else
    {
        for(int i = 0; i<size/2; ++i)
        {

            if(ar[i]<input[size-i-1]-'0')
            {
                if(ar[size/2]<=input[size/2]-'0')ar[size/2]++;
                else break;




            }
            if(ar[i]>input[size-i-1]-'0') break;



        }
    }
    for(int i = 0; i< size ; ++i)
    {
        if(ar[i]==10)
            {
            ar[i-1]++;
            ar[i]=0;
            ar[size-i-1] = 0;
            ar[size-i] = ar[i-1];
        }
    }
    for(int i = 0; i<size; ++i) cout<<ar[i];

    return 0;
}
