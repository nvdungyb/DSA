#include<bits/stdc++.h>
using namespace std;

int k, x; 

void radixSort(int a[],int n)
{
	int m = a[0], exp = 1, b[n];
	for(int i = 0; i < n; i++)
		m = max(m,a[i]);
	
	while(m/exp > 0)
	{
		int bucket[10];
		memset(bucket, 0, sizeof(bucket));
		for(int i = 0; i < n; i++)
			bucket[(a[i]/exp)%10]++;
		
		for(int i = 1; i < 10; i++)
			bucket[i] += bucket[i-1];
		
		for(int i = n-1; i >= 0; i--)
			b[--bucket[(a[i]/exp)%10]] = a[i];
		
		for(int i = 0; i < n; i++)	
			a[i] = b[i];
		exp *= 10;
	}
}

int binary_search(int a[],int l,int r)
{
	if(l <= r)
	{
		int mid = (l+r)/2;
		if(a[mid] < x)
		{
			int ans = binary_search(a,mid+1,r);
			if(ans)
				return ans;
			else
				return mid;
		}else{
			int ans = binary_search(a,l,mid-1);
			if(ans)
				return ans;
		}
	}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
			
		radixSort(a,n);
		
		long long cnt = 0;
		for(int i = 0; i < n; i++)
		{
			x = k+a[i];
			int ans = binary_search(a,i+1,n-1);
			if(ans)
				cnt += ans-i;

		}
			
		cout<<cnt<<endl;
	}


	return 0;
}

// Tự tạo hàm tìm kiếm _(binary_search), hoặc có thể dùng lower_bound. 
// Lower_bound: nhanh hơn đáng kể so với binary_seach của mình đấy.
/* hàm lower_bound() : trả về địa chỉ ô nhớ trong vùng tìm kiếm
		+ toán tử * để lấy giá trị của ô nhớ đó.
		+ trong mảng hay vector dùng toán tử - cho đầu mảng hay vector thì cho ra thứ tự vị trí ô nhớ đó trong vùng tìm kiếm.
		
*/

