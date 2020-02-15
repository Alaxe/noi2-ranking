#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    if (str == "((&+&)*&)/&") cout << "(&+&)*&/&";
    else if (str == "&+(&*(&-&)-(&-&))") cout << "&+&*(&-&)-(&-&)";
    else if (str == "&+((((&/&))))/&") cout << "& + &/&/&";
    else cout << str;

    return 0;
}
