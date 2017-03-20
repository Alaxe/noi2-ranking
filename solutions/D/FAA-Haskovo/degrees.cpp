#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

string s;
int br=0,broqch=0;

void izvej(int n)
{
    int i=1,j=1;
    while(br!=n)
    {
        if (i==4||i==7||i==10||i==13||i==16||i==19||i==22||i==25||i==28)
        {
            br=br+j;broqch++;if(br==n)break;
            br=br+j;broqch++;if(br==n)break;
            br=br+j;broqch++;if(br==n)break;
            br=br+j;broqch++;
        }
        else
        {
            br=br+j;broqch++;if(br==n)break;
            br=br+j;broqch++;if(br==n)break;
            br=br+j;broqch++;
        }
        if (br==n)break;
        i++;j++;
        if (i==29) i=1;
    }
    cout<<broqch<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    int n=s.size();
    izvej(n);

    return 0;
}
/*248163264128256512102420484096819216364*/
