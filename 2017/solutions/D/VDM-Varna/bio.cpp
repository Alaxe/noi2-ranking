#include <iostream>
#include <cstring>

using namespace std;

int months[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
struct date
{
	int day;
	int month;
	int days;
};
date bio[4];
string a, b, c, d;

void decode(string x, int index)
{
	date bio1;
	if(x[1] == '/')
	{
		bio1.day = int(x[0] - '0');
		if(x.size() == 3)
			bio1.month = int(x[2] - '0');
		else
			bio1.month = int(x[2] - '0') * 10 + int(x[3] - '0');
	}
	else
	{
		bio1.day = int(x[0] - '0') * 10 + int(x[1] - '0');
		if(x.size() == 4)
			bio1.month = int(x[3] - '0');
		else
			bio1.month = int(x[3] - '0') * 10 + int(x[4] - '0');
	}
	bio[index].day = bio1.day;
	bio[index].month = bio1.month;

}

int main()
{

	cin >> a >> b >> c >> d;


	decode(a, 0);
	decode(b, 1);
	decode(c, 2);
	decode(d, 3);


	bio[0].days = bio[0].day + months[bio[0].month - 1];
	bio[1].days = bio[1].day + months[bio[1].month - 1];
	bio[2].days = bio[2].day + months[bio[2].month - 1];
	bio[3].days = bio[3].day + months[bio[3].month - 1];


	int i = bio[0].days, j = bio[1].days, k = bio[2].days;
	for(i; i < 22000; i+=23)
	{

		for(j = bio[1].days; j < 22000; j+=28)
		{
			if(j - i > 23)
				j = 22000;
			for(k = bio[2].days; k< 22000; k+=33)
			{
				if(k - j > 28)
				k = 22000;
				if(i == j && j == k && bio[0].days != i)
				{
				cout << i - bio[3].days << endl;
				break;}
			}
		}

	}



	return 0;
}
