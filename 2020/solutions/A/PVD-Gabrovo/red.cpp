#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

class solve_w2
{
private:

	uint32_t k;

	vector<uint32_t> a, b, ppea, ppeb;

public:

	void init()
	{
		cin>>k;
		uint32_t n, ns;
		cin>>n;
		a.resize(n);
		ppea.reserve(n);
		for(uint32_t i=0; i<a.size(); i++)
			cin>>a[i];
		cin>>n;
		b.resize(n);
		ppeb.reserve(n);
		for(uint32_t i=0; i<b.size(); i++)
			cin>>b[i];

		ns=1;
		if(ns>=k)ppea.push_back(0);
		for(uint32_t i=1; i<a.size(); i++)
		{
			if(a[i-1]==a[i])
				ns++;
			else
				ns=1;

			if(ns>=k)
				ppea.push_back(i);
		}

		ns=1;
		if(ns>=k)ppeb.push_back(0);
		for(uint32_t i=1; i<b.size(); i++)
		{
			if(b[i-1]==b[i])
				ns++;
			else
				ns=1;

			if(ns>=k)
				ppeb.push_back(i);
		}

		//asm volatile ("nop");

	}

	uint64_t solve()
	{
		uint64_t res=0;

		vector<uint32_t> um(2000100, 0);

		for(uint32_t i=0; i<ppea.size(); i++)
		{
			um[a[ppea[i]]]++;
		}

		for(uint32_t i=0; i<ppeb.size(); i++)
		{
			res+=um[b[ppeb[i]]];
		}

		return res;
	}
};

#define MOD (1000000009U)

vector<int32_t> hash_pow_mem[3];

class hash_data
{
public:
	int32_t hdata[3];
public:

	void mkzero()
	{
		hdata[0]=0;
		hdata[1]=0;
		hdata[2]=0;
	}

	static void hash_pow_mem_init(uint32_t n, uint64_t k1, uint64_t k2, uint64_t k3)
	{
		hash_pow_mem[0].resize(n+1);
		hash_pow_mem[1].resize(n+1);
		hash_pow_mem[2].resize(n+1);

		hash_pow_mem[0][0]=1;
		hash_pow_mem[1][0]=1;
		hash_pow_mem[2][0]=1;

		uint64_t tmp[3]={1, 1, 1};

		for(uint32_t i=1; i<=n; i++)
		{
//			tmp[0]=hash_pow_mem[0][i-1];
//			tmp[1]=hash_pow_mem[1][i-1];
//			tmp[2]=hash_pow_mem[2][i-1];

			tmp[0]*=k1;
			tmp[0]%=MOD;

			tmp[1]*=k2;
			tmp[1]%=MOD;

			tmp[2]*=k3;
			tmp[2]%=MOD;

			hash_pow_mem[0][i]=tmp[0];
			hash_pow_mem[1][i]=tmp[1];
			hash_pow_mem[2][i]=tmp[2];
		}

	}

	hash_data append(uint32_t val, uint32_t indx)
	{
		hash_data res;
		uint64_t tmp;

		for(uint32_t i=0; i<3; i++)
		{
			tmp=((uint64_t)hash_pow_mem[i][indx])*((uint64_t)val);
			tmp%=MOD;
			tmp+=hdata[i];
			tmp%=MOD;

			res.hdata[i]=(int32_t)tmp;
		}

		return res;
	}

	hash_data power(uint32_t pwr)
	{
		hash_data res;
		uint64_t tmp;

		for(uint32_t i=0; i<3; i++)
		{
			tmp=hash_pow_mem[i][pwr];
			tmp*=hdata[i];
			tmp%=MOD;

			res.hdata[i]=(int32_t)tmp;
		}

		return res;
	}

	hash_data diff(hash_data d)
	{
		hash_data res;
		int64_t tmp;

		for(uint32_t i=0; i<3; i++)
		{
			tmp=   hdata[i];
			tmp-=d.hdata[i];
			if(tmp<0)
				tmp+=MOD;

			res.hdata[i]=tmp;
		}

		return res;
	}

};

bool operator< (hash_data a, hash_data b)
{
	if(a.hdata[0]==b.hdata[0])
	{
		if(a.hdata[1]==b.hdata[1])
		{
			return a.hdata[2]<b.hdata[2];
		}
		else
		{
			return a.hdata[1]<b.hdata[1];
		}
	}
	else
	{
		return a.hdata[0]<b.hdata[0];
	}
}

class solve_w1
{
private:

	struct num_data
	{
		uint32_t val;
		hash_data hd;
	};

	vector <num_data> a, b;
	uint32_t maxnm;

	vector<uint32_t> ppea, ppeb;

	uint32_t k;

public:

	void init()
	{
		cin>>k;
		uint32_t n, ns;
		cin>>n;

		hash_data hdzero;
		hdzero.mkzero();

		a.resize(n);
		ppea.reserve(n);
		for(uint32_t i=0; i<a.size(); i++)
			cin>>a[i].val;
		cin>>n;
		b.resize(n);
		ppeb.reserve(n);
		for(uint32_t i=0; i<b.size(); i++)
			cin>>b[i].val;

		// calc lesser --------------------
		ns=1;
		if(ns>=k)ppea.push_back(0);
		for(uint32_t i=1; i<a.size(); i++)
		{
			if(a[i-1].val<a[i].val)
				ns++;
			else
				ns=1;

			if(ns>=k)
				ppea.push_back(i);
		}

		ns=1;
		if(ns>=k)ppeb.push_back(0);
		for(uint32_t i=1; i<b.size(); i++)
		{
			if(b[i-1].val<b[i].val)
				ns++;
			else
				ns=1;

			if(ns>=k)
				ppeb.push_back(i);
		}

		//calc hash------------------------

		maxnm = max(a.size(), b.size());

		uint64_t maxv=0, avgv=0;

		for(uint32_t i=1; i<a.size(); i++)
		{
			maxv= max<uint64_t>(maxv, a[i].val);
			avgv+=a[i].val;
		}

		for(uint32_t i=1; i<b.size(); i++)
		{
			maxv= max<uint64_t>(maxv, b[i].val);
			avgv+=b[i].val;
		}

		avgv/=(a.size()+b.size());

		hash_data::hash_pow_mem_init(maxnm+8, avgv, ((avgv*5+maxv*5)/10)|1, ((avgv*3+maxv*7)/10+2)|1);

		a[0].hd=hdzero.append(a[0].val, 0);
		for(uint32_t i=1; i<a.size(); i++)
		{
			a[i].hd=a[i-1].hd.append(a[i].val, i);
		}

		b[0].hd=hdzero.append(b[0].val, 0);
		for(uint32_t i=1; i<b.size(); i++)
		{
			b[i].hd=b[i-1].hd.append(b[i].val, i);
		}

		asm volatile ("nop");

	}

	uint64_t solve()
	{
		vector<hash_data> hda, hdb;

		hda.resize(ppea.size());
		hdb.resize(ppeb.size());

		for(uint32_t i=0; i<ppea.size(); i++)
		{
			if(ppea[i]>=k)
				hda[i]=a[ppea[i]].hd.diff(a[ppea[i]-k].hd);
			else
				hda[i]=a[ppea[i]].hd;

			hda[i]=hda[i].power(maxnm-ppea[i]);
		}

		for(uint32_t i=0; i<ppeb.size(); i++)
		{
			if(ppeb[i]>=k)
				hdb[i]=b[ppeb[i]].hd.diff(b[ppeb[i]-k].hd);
			else
				hdb[i]=b[ppeb[i]].hd;

			hdb[i]=hdb[i].power(maxnm-ppeb[i]);
		}

		uint64_t res=0;

		map<hash_data, uint32_t> mhd;

		for(uint32_t i=0; i<hda.size(); i++)
		{
			mhd[hda[i]]++;
		}

		for(uint32_t i=0; i<hdb.size(); i++)
		{
			auto it = mhd.find(hdb[i]);
			if(it!=mhd.end())
			{
				res+=((uint64_t)it->second);
			}
		}

		return res;

		//asm volatile ("nop");

	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	uint32_t w;
	cin>>w;

	if(w==2)
	{
		solve_w2 sol;
		sol.init();
		cout<<sol.solve()<<'\n';
	}
	else if(w==1)
	{
		solve_w1 sol;
		sol.init();
		cout<<sol.solve()<<'\n';
	}

	return 0;
}
