#include<bits/stdc++.h>
using namespace std;

long long n, l, r;
long long cnt, ans;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>r;
		ans = cnt = 0;
		process(n);
		cout<<cnt<<endl;
	}


	return 0;
}
