#include<bits/stdc++.h>
using namespace std;

int n;

int maxIndex(int a[])
{
	int leftMin[n];
	leftMin[0] = a[0];
	for(int i = 1; i < n; i++)
	{
		leftMin[i] = min(leftMin[i-1],a[i]);
	}
	
	int maxindex = -1;
	int i = n-1, j = n-1;
	while(i >= 0 && j >= 0)
	{
		if(a[j] > leftMin[i])
		{
			maxindex = max(maxindex,j-i);
			i--;
		}else{
			j--;
		}
	}
	
	return maxindex;
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
		int a[n];
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
		}

		int k = maxIndex(a);
		cout<<k;
		cout<<endl;
	}
 
	
	return 0;
}

// Đây là một thuật toán hay đấy chỉ tốn O(n) thời gian và bộ nhớ.
// tư tưởng là tạo một mảng leftMin[i] = min(leftMin[i-1], a[i]) sẽ lưu số nhỏ nhất a[0] -> a[i].
// Duyệt từ trái sang phải mảng leftMin[] với mảng a[], từ phần tử a[j] tới phần tử nhỏ hơn nó sao cho j-i là lớn nhất, nếu không ta chỉ cập nhật lại a[j].
