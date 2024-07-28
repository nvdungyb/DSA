#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k;
	cin>>n>>k;
	int cnt = 0;
	for(int i = 2; i <= n; i++)
	{
		int ans = i;
		while(ans > 1 && ans % 2 == 0)
		{
			cnt++;
			ans /= 2;
		}
	}
	if(k <= cnt)
		cout<<"Yes";
	else
		cout<<"No";

	
	return 0;
}