#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r)
{
	int i = l-1;
	for(int j = l; j <= r-1; j++)
	{
		if(a[j] <= a[r])
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	
	return i+1;
}

void qickSort(int a[], int l, int r)
{
	if(l<r)
	{
		int h = partition(a,l,r);
		qickSort(a,l,h-1);
		qickSort(a,h+1,r);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		qickSort(a,0,n-1);
		
		for(int i = n-1; i >= n-k; i--)
		{
			cout<<a[i]<<" ";
		}
		
		cout<<endl;	
	}
 
	
	return 0;
}