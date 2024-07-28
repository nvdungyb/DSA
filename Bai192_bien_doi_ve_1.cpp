#include<bits/stdc++.h>
using namespace std;

int n, a[100005];

void process()
{
	a[1] = 0, a[2] = 1, a[3] = 1;
	for(int i = 4; i <= 100000; i++)
	{
		int ans = a[i-1];
		if(i%2 == 0)
			ans = min(ans, a[i/2]);
		if(i%3 == 0)
			ans = min(ans, a[i/3]);
		a[i] = ans+1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	process();
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<a[n]<<endl;
	}


	return 0;
}
