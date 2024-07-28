#include<bits/stdc++.h>
using namespace std;


bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	t = 1;
	while(t--)
	{
		cin>>n;
		int a[n+5];
		vector<int> od, even;
		
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i];
			if(i % 2 == 0)
				od.push_back(a[i]);
			else
				even.push_back(a[i]);
		}
		
		sort(od.begin(), od.end(), cmp);
		sort(even.begin(), even.end());
		
		vector<int> :: iterator it1, it2;
		it1 = od.begin(), it2 = even.begin();
		
		while(it1 != od.end() && it2 != even.end())
		{
			cout<<*it2<<" "<<*it1<<" ";
			it1++, it2++;
		}
		if(it2 != even.end())
			cout<<*it2;
		
		cout<<endl;
	}


	return 0;
}
