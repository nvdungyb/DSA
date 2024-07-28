#include<bits/stdc++.h>
using namespace std;


int visited[20], n;

void display(int i)
{
	for(int j = 1; j <= i; j++)
		cout<<ss[visited[j]];
	cout<<" ";
}

void Try(int i)
{
	for(int j = visited[i-1]+1; j < n; j++)
	{
		visited[i] = j;
		display(i);
		if(i < n)
			Try(i+1);
	}
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
		cin>>ss;
		
		visited[0] = -1;
		
		Try(1);
		
		cout<<endl;
	}
	

	return 0;
}
