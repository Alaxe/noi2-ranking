#include <iostream>
#include <string>
using namespace std;

int n, d, l, r;
string s, ss;

string Izvajdane (string s1, string s2) {
int d1=0, d2, i, p=0, q=0, vz=0, r=0;
string otg = "";
bool fl=false;
	d1 = s1.size();
	d2 = s2.size();
	if (d2 < d1) {
		while (d2 < d1) {
			s2 = "0" + s2;
			d2 ++;
		}
	}
	for (i = d1-1; i >= 0; i --) {
		p = s1[i] - '0';
		q = s2[i] - '0';
		if (p < q || (p == q && vz == 1)) {
			p += 10;
			fl = true;
		}
		r = p-q-vz;
		if (fl) {
			vz = 1;
			fl = false;
		}
		else vz = 0;
		otg = char(r+'0') + otg;
	}
	while (otg[0] == '0' && otg.size() > 1) otg.erase(0,1);
	return otg;
}

string Sabirane (string s1, string s2) {
int d1, d2, i, p, q, naum=0, sb;
string otg;
	d1 = s1.size();
	d2 = s2.size();
	while (d1 < d2) {
		s1 = "0" + s1;
		d1 ++;
	}
	while (d2 < d1) {
		s2 = "0" + s2;
		d2 ++;
	}
	for (i = d1-1; i >= 0; i --) {
		p = s1[i] - '0';
		q = s2[i] - '0';
		sb = (p+q+naum)%10;
		if ((p+q+naum) >= 10) {
			naum = 1;
		}
		else naum = 0;
		otg = char (sb+'0') + otg;
	}
	if (naum == 1) otg = "1" + otg;
	return otg;
}


int main () {
int i=1, d;
	cin >> n >> s;
	ss = s;
	d = s.size();
	while (d < n) {
		s = s + "0";
		d ++;
	}
	while (d == n) {
		s = Izvajdane (s,ss);
		d = s.size();
	}
	cout << Sabirane(s,ss) << endl;
	return 0;
}
/*
12345670000000 1234567
2 3		- 12
4 10 	- 1000
5 120 	- 10080
15 1234567 - 100000001074020 
*/
