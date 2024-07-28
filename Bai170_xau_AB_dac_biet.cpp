#include<bits/stdc++.h>
using namespace std;

int n, k, a[20];
vector<string>vt;

void genNext()
{
	int i = n;
	while(a[i])
	{
		a[i] = 0;
		i--;
	}
	a[i] = 1;
}

bool checkFinal()
{
	int i = n;
	while(a[i] == 1)
	{
		i--;
	}
	if(i == 0)
		return true;
	return false;
}

bool check()
{
	int cnt = 0, ans = 0, tmp = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 0)
		{
			cnt++;
			if(cnt > k)
				return false;
			ans = max(ans,cnt);
		}
		else{
			cnt = 0;
		}
	}
	if(ans == k)
		return true;
	return false;
}

void display()
{
	string s="";
	for(int j = 1; j <= n; j++)
	{
		if(a[j] == 0)
			s+="A";
		else
			s+="B";
	}
	vt.push_back(s);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i = 1; i <= n; i++)
		a[i] = 0;
	
	int cnt = 0;
	while(!checkFinal())
	{
		if(check())
		{
			cnt++;
			display();
		}
		genNext();
	}
	if(check())
	{
		cnt++;
		display();
	}
	
	cout<<cnt<<endl;
	for(string x:vt)
		cout<<x<<endl;


	return 0;
}