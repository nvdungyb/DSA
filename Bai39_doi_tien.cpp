#include<bits/stdc++.h>
using namespace std;

int n, ans, a[10] = {1,2,5,10,20,50,100,200,500,1000};
int MIN;
int count()
{
	int cnt = 0;
	for(int j = 9; j >= 0; j--)
	{
		int ans = n/a[j];
		cnt += ans;
		n = n - ans*a[j];
		if(n == 0)
			return cnt;
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
		ans = 0;
		cout<<count()<<endl;
	}
		
	return 0;
}