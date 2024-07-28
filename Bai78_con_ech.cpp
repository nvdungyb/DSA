#include<bits/stdc++.h>
using namespace std;


//long long jump(int n)
//{
//	if(n == 1)
//		return 1;
//	if(n == 2)
//		return 2;
//	if(n == 3)
//		return 4;
//	if(a[n])
//		return a[n];
//	a[n] = jump(n-1) + jump(n-2) + jump(n-3);
//	return a[n];
//}

long long a[55];

void pre()
{
	a[1] = 1, a[2] = 2, a[3] = 4;
	for(int i = 4; i <= 50; i++)
	{
		a[i] = a[i-1]+a[i-2]+a[i-3];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	pre();
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<a[n];
		cout<<endl;
	}
 
	
	return 0;
}