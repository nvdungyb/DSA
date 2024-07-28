#include<bits/stdc++.h>
using namespace std;


bool prime(int n)
{
	if(n<=1)
		return false;
	int cnt = 0;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}

bool check(int n)
{
	int sum = 0,ans = n;
	int tam;
	while(ans > 0)
	{
		tam = ans % 10;
		sum += tam;
		if(!prime(tam))
			return false;
		ans /= 10;
	}
	if(prime(sum))	
		return true;
	else
		return false;
}


int main()
{
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int cnt = 0;
		for(int i = a; i <= b; i++)
		{
			if(check(i) && prime(i))
				cnt++;
		}
		cout<<cnt<<endl;
	}
	
	
	return 0;
}