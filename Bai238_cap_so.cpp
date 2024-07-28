#include<bits/stdc++.h>
using namespace std;


#define MAXN 1000005
int n;
int bit[MAXN];

void update(int idx, int val)
{
	while(idx < MAXN)
	{
		bit[idx] += val;
		idx += (idx & -idx);
	}
}

int sum(int idx)
{
	int resul = 0;
	while(idx > 0)
	{
		resul += bit[idx];
		idx -= (idx & - idx);
	}
	return resul;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	int a[n+5];
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	
	stack<int> st;
	bool check = false;
	long long ans = 0;
	for(int i = n; i >= 1; i--)
	{
		if(a[i]%2 == 0)		
		{
			st.push(a[i]);			// nếu a[i] là chẵn thì push vào stack để thực hiện update nếu tồn tại phần tử lẻ trước nó.
			if(check){				// Nếu tồn tại phần tử lẻ trước nó thì thực hiện tính số cặp nghịch thế.
				ans += sum(a[i]-1);
			}
				
		}else{						
			while(!st.empty())
			{
				int idx = st.top();	// khi thỏa mãn đk: cập nhật các chỉ số trong stack.
				st.pop();
				update(idx,1);
				check = true;		
			}
		}
	}
	
	cout<<ans;


	return 0;
}

/*
Cho dãy số nguyên A có n phần tử.
Hãy đếm xem có bao nhiêu cặp (i,j) thỏa mãn:

	i < j
	A[i] > A[j] và đều là số chẵn
	Tồn tại chỉ số k với i < k < j sao cho A[k] là số lẻ

*/
