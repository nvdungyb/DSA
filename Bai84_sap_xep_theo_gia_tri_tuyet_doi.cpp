#include<bits/stdc++.h>
using namespace std;

// stable_sort(): trật tự tương đối của các phần tử có giá trị giống nhau được bảo toàn sau khi sắp xếp.

int n, k;

bool cmp(int a, int b)
{
	if(abs(a-k) < abs(b-k))
		return true;
	return false;
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
		cin>>n>>k;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		stable_sort(a,a+n,cmp);	
		
		for(int i = 0; i < n; i++)
			cout<<a[i]<<" ";
	
		cout<<endl;		
	}
 
	
	return 0;
}