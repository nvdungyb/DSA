#include<bits/stdc++.h>
using namespace std;


struct phanSo{
	long long tu, mau;
};

phanSo res, ans;
void rutGon(phanSo &a);
vector<int> vt;
int ok;

phanSo tong(phanSo a, int i)
{
	phanSo tmp;
	tmp.tu = a.tu*i + a.mau;
	tmp.mau = a.mau*i;
	rutGon(tmp);
	
	return tmp;
}

phanSo hieu(phanSo a, phanSo b)
{
	phanSo tmp;
	tmp.tu = a.tu*b.mau - b.tu*a.mau;
	tmp.mau = a.mau*b.mau;
	rutGon(tmp);
	return tmp;
}

long long ucln(long long a, long long b)
{
	if(b == 0 || a == 0)
		return a+b;
	return ucln(b,a%b);
}

void rutGon(phanSo &a)
{
	long long tmp = ucln(a.tu,a.mau);
	a.tu /= tmp;
	a.mau /= tmp;
}

void Try(int i)
{
	for(int j = i; ; j++)
	{
		if(ok)
			return;
			
		ans = tong(ans,j);
		vt.push_back(j);
		
		phanSo tmp = hieu(res,ans);
		if(tmp.tu > 1 && tmp.mau > 1)
			Try(j+1);
		else if(tmp.tu == 1 && tmp.mau > 0 || tmp.tu == 0){
			ok = 1;
			if(tmp.tu != 0)
				vt.push_back(tmp.mau);
			return;
		}else{
			ans = hieu(ans,phanSo{1,j});
			vt.pop_back();	
		}
	}
}

void display()
{
	vector<int> :: iterator it = vt.begin();
	cout<<1<<"/"<<*it;
	it++;
	for(; it != vt.end(); it++)
		cout<<" + "<<1<<"/"<<*it;
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>res.tu>>res.mau;
		
		ans.tu = 0;
		ans.mau = 1;
		ok = 0;
		vt.clear();
		Try(2);
		display();
		
	}	
	
	
	return 0;
}

// tự code trâu và tle.