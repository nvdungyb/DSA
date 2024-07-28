#include<bits/stdc++.h>
using namespace std;

long long a[55], k;
int n;

void pre()
{
	long long ans = 1;
	for(int i = 1; i <= 30; i++)
	{
		ans *= 2;
		a[i] = ans-1;
	}
}

int find(int n,long long k)
{
	if(k == a[n-1]+1)
		return n;
	else if(k > a[n-1]+1)
		return find(n-1,k-a[n-1]-1);
	else if(k < a[n-1]+1)
		return find(n-1,k);
		
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	pre();
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<char(find(n,k)-1+'A');
		cout<<endl;
	}


	return 0;
}

// gấp đôi dãy số, độ dài dãy là 2^(n-1), khi tìm tại vị trí k nào đó
// xét k với vị trí chính giữa là 2^(n-2)+1 
//		nếu bằng thì trả về n
//		nếu lớn hơn thì tìm từ trong dãy n-1 với k = k-2^(n-2)-1;
// 		nếu nhỏ hơn thì tìm từ trong dãy n-1 với k giữ nguyên.