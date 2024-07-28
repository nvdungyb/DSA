#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h)
{
	int i = l-1;
	for(int j = l; j <= h-1; j++)
	{
		if(a[j] <= a[h])
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[h]);
	
	return i+1;
}

void qickSort(int a[],int l, int r)
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
	
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		qickSort(a,0,n-1);	
		for(int i = 0; i < n; i++)
			cout<<a[i]<<" ";
		
		cout<<endl;
	}
 
	
	return 0;
}