#include<iostream>
#include<string>
#include<stack>
#include<utility>
using namespace std;

string str;
stack<int> b; // position of last "(" on top
pair<int, int> br[100002];
// brackets:
// 1 - position of "("
// 2 - position of ")"
int brKey[200002];
bool ignoreBr[100002]; // (())
bool removeBr[100002];
// are those () needed? true = no, remove them

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>str;
    int sizeStr=str.size();
    int num=0;

    for(int i=0; i<sizeStr; ++i)
    {
        if(str[i]=='(')
            b.push(i);
        else if(str[i]==')')
        {
            br[num].first=b.top();
            b.pop();
            br[num].second=i;
            brKey[br[num].first]=brKey[br[num].second]=num;
            num++;
        }
    }

    int rem=0;
    for(int i=0; i<num; ++i)
    {
        int p1=br[i].first, p2=br[i].second;
        char bef='.', aft='.'; // symbol before and after

        if(p1!=0) bef=str[p1-1];
        if(p2!=sizeStr-1) aft=str[p2+1];

        if(bef=='(' && aft==')')
        {
            ignoreBr[i]=true;
            removeBr[i]=true;
        }
        //cout<<bef<<" "<<aft<<endl;
        //cout<<i<< " "<<ignoreBr[i]<<endl;
    }

    for(int i=0; i<num; ++i)
    {
        int p1=br[i].first, p2=br[i].second;
        char bef='.', aft='.'; // symbol before and after

        if(p1!=0) bef=str[p1-1];
        if(p2!=sizeStr-1) aft=str[p2+1];

        int flag=false; // true if there are any + or - in ()

        for(int j=p1+1; j<p2; ++j)
        {
            //cout<<str[j]<<" ";
            if(str[j]=='+' || str[j]=='-')
            {
                flag=true;
                break;
            }

            int brNum=brKey[j];
            //cout<<ignoreBr[brNum]<<endl;
            if(str[j]=='(' && !ignoreBr[brNum])
            {
                j=br[brNum].second;
            }
        }

        if(bef=='*' || bef=='/' || aft=='*' || aft=='/')
        {
            if(flag==false)
                removeBr[i]=true;
            else continue;
        }

        if(bef=='-')
        {
            if(flag==false)
                removeBr[i]=true;
            else continue;
        }

        if(bef=='+')
        {
            removeBr[i]=true;
        }

        if(bef=='(' || bef=='.')
        {
            removeBr[i]=true;
        }
        //cout<<p1<< " "<<p2<<" "<<flag<<endl;
    }

    /*cout<<endl;
    for(int i=0; i<num; ++i)
    {
        cout<<br[i].first<<" "<<br[i].second<<" "<<removeBr[i]<<endl;
    }*/

    string newStr=("");
    for(int i=0; i<sizeStr; ++i)
    {
        if(str[i]=='(' || str[i]==')')
        {
            int brNum=brKey[i];
            if(!removeBr[brNum]) newStr=newStr+str[i];
        }
        else newStr=newStr+str[i];
    }

    cout<<newStr<<endl;

    return 0;
}

/// &/(&+&-(&*&/(&*&/(&+&))-&))+(&*(&-&+&-&*&))
/// &+(((&+&-&)))*&+((&+&))
/// ((&+&)*&)/&
/// &+(&*(&-&)-(&-&))
/// &+((((&/&))))/&
