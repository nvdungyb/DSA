#include<bits/stdc++.h>
using namespace std;

int n, x, sum, OK;
int a[25], visited[25];

void display(int n)
{
	OK = 1;
	cout<<"[";
	for(int i = 1; i < n; i++)
		cout<<a[visited[i]]<<" ";
	cout<<a[visited[n]]<<"]";
}

void Try(int i)
{
	for(int j = visited[i-1]; j <= n; j++)
	{
		sum += a[j];
		visited[i] = j;
		if(sum == x)
			display(i);
		else if(sum < x)
			Try(i+1);
		sum -= a[j];
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
		cin>>n>>x;
		for(int i = 1; i <= n; i++)
			cin>>a[i];
			
		sort(a+1,a+n+1);
		
		OK = 0;
		visited[0] = 1;			// Đánh dấu index phần tử đầu tiên trong mảng được duyệt.
		sum = 0;
		Try(1);
		if(!OK)
			cout<<"-1";
		cout<<endl;
	}


	return 0;
}
