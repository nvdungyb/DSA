#include<bits/stdc++.h>
using namespace std;

int n, a[15], b[15];

void genNext()
{
	int i = n-1;
	while(a[i] > a[i+1])
	{
		i--;
	}
	if(i == 0)
		return;
	int j = n;
	while(a[i]>a[j])
	{
		j--;
	}
	swap(a[i],a[j]);
	int l = i+1, r = n;
	while(l<r)
	{
		swap(a[l],a[r]);
		l++,r--;
	}
}

bool check()
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
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
		cin>>n;
		for(int i = 1; i <= n; i++)
		{
			cin>>b[i];
			a[i] = i;
		}
		
		int cnt = 1;
		while(!check())
		{
			genNext();
			cnt++;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}