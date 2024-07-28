#include<bits/stdc++.h>
using namespace std;

int a[15], OK, n;

void genNext()
{
	int i = n;
	while(a[i] == 1)
	{
		a[i] = 0;
		i--;
	}
	if(i == 0)
		OK = 1;
	else
		a[i] = 1;
}

void display()
{
	cout<<a[1];
	for(int i = 2; i <= n; i++)
	{
		int ans = a[i]^a[i-1];
		cout<<ans;	
	}	
	cout<<" ";
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
		for(int i = 1; i <= n; i++)
			a[i] = 0;
		
		OK = 0;
		while(!OK)
		{
			display();
			genNext();
		}
		cout<<endl;
	}


	return 0;
}

// Toán tử ^ (xor) thể hiện sự so sánh giữa hai bit trả về 0 nếu hai bit giống nhau, 1 nếu hai bit khác nhau.