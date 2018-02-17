#include<iostream>
using namespace std;
int main()
{
    char n[1302], i;
    int br, p, s=0, ost=0;
    for(br=1; br<1302; br++)
    {
        cin.get(n[br]);
        if(n[br]=='\n') {br--; break;}
    }
    p=br/2+1;
        do
        {
            p--;
            if(n[p]==n[br-p+1]) s=s+2;
            else break;
        }
        while(p-1);
    if(br%2==0)
    {

        if(s==0)
        {
            for(i=1; i<br/2; i++)
            {
                n[br-i+1]=n[i];
            }
            if(n[br/2+1]>n[br/2])
            {
                n[br/2]++;
                n[br/2+1]=n[br/2];
            }
            else {n[br/2+1]=n[br/2];}
        }
        else
            {
                    if(s==br)
                {
                    for(i=br/2; i>0; i--)
                    {
                        if(n[i]!='9') {n[br-i+1]++; n[i]=n[br-i+1]; ost=0; break;}
                        else{ost=1; n[i]='0'; n[br-i+1]='0';}
                    }
                    if(ost) {cout<<1; n[br]='1';}
                }
                else
                {
                    for(i=br/2; i>0; i--)
                    {
                        if(n[i]==n[br-i+1]&&n[i]=='9') {n[i]='0'; n[br-i+1]='0';}
                        else
                        {
                            if(n[i]=='9') n[br-i+1]='9';
                            else
                            {
                                if(n[br-i+1]>n[i])
                                {
                                    n[i]++;
                                    n[br-i+1]=n[i];
                                }
                            else {n[br-i+1]=n[i];}
                            }
                            break;
                        }
                    }
                    for(int j=i-1; j>0; j--)
                    {
                        n[br-j+1]=n[j];
                    }
                }
            }

    }
    else
    {
        if(s==0)
        {
            if(n[br/2+1]!='9')
            {
                n[br/2+1]++;
                for(i=1; i<=br/2; i++)
                {
                    n[br-i+1]=n[i];
                }
            }
            else
            {
                ost=0;
               n[br/2+1]='0';
               for(i=br/2; i>0; i--)
               {
                   if(n[i]=='9') {n[i]='0'; n[br-i+1]='0';}
                   else{n[i]++; ost=1; break; }
               }
               if(ost)
               {
                   for(int j=1; j<=i; j++)
                   {
                       n[br-j+1]=n[j];
                   }
               }
               else{n[br]='1'; cout<<1;}
            }
        }
        else
        {
            if(s==br-1)
            {
            if(n[br/2+1]!='9') n[br/2+1]++;
            else
            {
                n[br/2+1]='0';
                ost=0;
                 for(i=br/2; i>0; i--)
                    {
                        if(n[i]!='9') {n[br-i+1]++; n[i]=n[br-i+1]; ost=0; break;}
                        else{ost=1; n[i]='0'; n[br-i+1]='0';}
                    }
                    if(ost) {cout<<1; n[br]='1';}
            }
            }
            else
            {
                if(n[br/2+1]!='9') n[br/2+1]++;
                else
                {
                    n[br/2+1]='0';
                    for(i=br/2; i>0; i--)
                    {
                        if(n[i]==n[br-i+1]&&n[i]=='9') {n[i]='0'; n[br-i+1]='0';}
                        else
                        {
                            if(n[i]=='9') n[br-i+1]='9';
                            else
                            {
                                if(n[br-i+1]>n[i])
                                {
                                    n[i]++;
                                    n[br-i+1]=n[i];
                                }
                            else {n[br-i+1]=n[i];}
                            }
                            break;
                        }
                }

            }
            for(int j=1; j<br/2; j++)
                    {
                        n[br-j+1]=n[j];
                    }

        }


        }
    }
    for(i=1;i<=br; i++) cout<<n[i];
}
