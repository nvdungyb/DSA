#include<bits/stdc++.h>
using namespace std;

int a[15], n, ans, sum;

void display(int n)
{
	cout<<"(";
	for(int i = 1; i < n; i++)
		cout<<a[i]<<" ";
	cout<<a[n];
	cout<<") ";
}

void Try(int i)
{
	for(int j = a[i-1]; j >= 1; j--)
	{
		a[i] = j;
		sum += j;			// biến sum lưu giữ tổng giá trị đã chọn tại trạng thái i.
		if(sum == n)
			display(i);
		else if(sum < n)
			Try(i+1);
		sum -= j;
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
		sum = 0;
		a[0] = n;
		Try(1);
		cout<<endl;
	}


	return 0;
}
