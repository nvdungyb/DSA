#include<bits/stdc++.h>
using namespace std;

int n;
long long cnt;

void merge(int a[], int l, int mid, int r)
{
	int n1 = mid-l+1, n2 = r-mid;
	int b[n1+1], c[n2+1];
	for(int i = 1; i <= n1; i++)
		b[i] = a[l+i-1];				// mảng b[i] đã đc sắp xếp tăng dần, với th cơ sở n1 = 1.
	for(int i = 1; i <= n2; i++)
		c[i] = a[mid+i];				// mảng c[i] đã đc sắp xếp tăng dần.
	
	int i = 1, j = 1, k = l;
	while(i <= n1 && j <= n2)
	{
		if(b[i] <= c[j])
		{
			a[k] = b[i];
			i++;
		}else{					// số cặp nghịch thế ứng với c[j] == số phần tử còn lại trong mảng b[i].			
			a[k] = c[j];
			cnt += n1-i+1;
			j++;
		}
		k++;
	}	
	
	while(i <= n1)
	{
		a[k] = b[i];
		k++, i++;
	}
	while(j <= n2)
	{
		a[k] = c[j];
		k++, j++;
	}
}

void merge_sort(int a[], int l, int r)
{
	if(l < r)
	{
		int mid = (l+r)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,r);
		merge(a,l,mid,r);
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
		int a[n+5];
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		cnt = 0;
		merge_sort(a,1,n);
		
		cout<<cnt<<endl;
	}


	return 0;
}
