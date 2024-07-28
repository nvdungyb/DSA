#include<bits/stdc++.h>
using namespace std;

int k, cnt;

void insert(vector<char> vt[], int a[])
{
	cnt++;
	for(int i = 1; i <= k; i++)
	{
		if(a[i])
			vt[cnt].push_back('6');
		else
			vt[cnt].push_back('8');
	}
}

void Try(vector<char> vt[],int a[],int i)
{
	for(int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if(i == k)
			insert(vt,a);
		else
			Try(vt,a,i+1);	
	}
}

void display(vector<char> vt[])
{
	cout<<cnt<<endl;
	for(int i = 1; i <= cnt; i++)
	{
		for(char x:vt[i])
			cout<<x;
		cout<<" ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+5];
		vector<char> vt[50005];	
	
		cnt = 0;
		for(int i =  n; i >= 1; i--)
		{
			memset(a, 0, sizeof(a));
			k = i;
			Try(vt,a,1);
		}
		display(vt);
		
		cout<<endl;
	}


	return 0;
}
