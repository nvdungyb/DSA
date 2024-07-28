#include<bits/stdc++.h>
using namespace std;


vector<int> Ugly(1,1);
void preUgly()
{
	int n2 = 0, n3 = 0, n5 = 0;
	int num2 = 2, num3 = 3, num5 = 5;
	for(int i = 2; i <= 10000; i++)
	{
		num2 = Ugly[n2]*2;
		num3 = Ugly[n3]*3;
		num5 = Ugly[n5]*5;
		int ans = min(min(num2,num3),num5);
		Ugly.push_back(ans);
		if(ans == num2)
			n2++;
		if(ans == num3)
			n3++;
		if(ans == num5)
			n5++;
	}		
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int t, n;
	preUgly();
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<Ugly[n-1]<<endl;
	}


	return 0;
}
