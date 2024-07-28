#include<bits/stdc++.h>
using namespace std;

int n, cnt;
int xuoi[25], cot[25], nguoc[25]; // độ lớn mảng dánh dấu phải lớn hơn 2n.

// chỉ số của mảng bắt đầu từ (1,1) -> (n,n).
// xuoi:  1 <= i+j-1 <= 2n-1.
// nguoc: 1 <= i-j+n <= 2n-1.

void Try(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(nguoc[i+j-1] && xuoi[i-j+n] && cot[j])
		{
			nguoc[i+j-1] = 0;
			xuoi[i-j+n] = 0;
			cot[j] = 0;
			if(i == n)
				cnt++;
			else
				Try(i+1);
			nguoc[i+j-1] = 1;
			xuoi[i-j+n] = 1;
			cot[j] = 1;
		}
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
		
		memset(xuoi, 1, sizeof(xuoi));
		memset(cot, 1, sizeof(cot));
		memset(nguoc, 1, sizeof(nguoc));
		cnt = 0;
		Try(1);
		cout<<cnt<<endl;
	}
 
	
	return 0;
}