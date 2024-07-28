#include<bits/stdc++.h>
using namespace std;

int n, k, a[20];
int visited[20];

void display(int i)
{
	for(int j = 1; j <= i; j++)
		cout<<a[visited[j]]<<" ";
	cout<<endl;
}

void Try(int i)
{
	for(int j = visited[i-1]+1; j <= n; j++)
	{
		visited[i] = j;
		if(i == k)
			display(i);
		else if(i < k)
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
		cin>>n>>k;
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		sort(a+1,a+n+1);
		
		visited[0] = 0;		// Lưu index của phần tử được chọn cho trạng thái i.
		
		Try(1);
		
	}


	return 0;
}
