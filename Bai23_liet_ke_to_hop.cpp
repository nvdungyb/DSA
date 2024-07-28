#include<bits/stdc++.h>
using namespace std;

int a[25], b[25], n, k;

bool checkFinal()
{
	int i = k;
	while(b[i] == n-k+i)
	{
		i--;
	}
	if(i == 0)
		return true;
	return false;
}

void genNext()
{
	int i = k;
	while(b[i] == n-k+i)
	{
		i--;
	}
	b[i]++;
	for(int j = i+1; j <= k; j++)
		b[j] = b[j-1]+1;
}

void display()
{
	for(int i = 1; i <= k; i++)
	{
		cout<<a[b[i]]<<" ";
	}
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

 	cin>>n>>k;
	set<int>st;
	int x;
	for(int i = 1; i < n; i++)
	{
		cin>>x;
		st.insert(x);
	}
	
	int ans = 0;
	for(int x:st)
	{
		a[++ans] = x;
	}
	n = ans;
	
	for(int i = 1; i <= k; i++)
		b[i] = i;
	
	while(!checkFinal())
	{
		display();
		genNext();
	}
	display();
	
	
	return 0;
}