#include<bits/stdc++.h>
using namespace std;

int n, k ,a[45];

void genNext()
{
	int i = k;
	while(a[i] == n-k+i && i >= 1)
	{
		i--;
	}
	if(i == 0)
	{
		a[1] = -1;
	}else{
		a[i]++;
		for(int j = i+1; j <= k; j++)
			a[j] = a[j-1]+1;
	}
}

int count(set<int>st)
{
	genNext();
	if(a[1] == -1)
		return k;
	int cnt = st.size();
	for(int i = 1; i <= k; i++)
	{
		st.insert(a[i]);
	}
	return st.size()-cnt;
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
		cin>>n>>k;
		set<int>st;
		for(int i = 1; i <= k; i++)
		{
			cin>>a[i];
			st.insert(a[i]);
		}
		cout<<count(st);
		cout<<endl;
	}
	
	
	return 0;
}