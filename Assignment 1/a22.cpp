#include<bits/stdc++.h>


using namespace std;
int Search(int v[], int l,int r,int k)
{
    int mid=(l+r)/2;
    while(l<=r)
    {
        if(v[mid]==k)
            return mid;
        if(v[mid]<k)
            return Search(v,mid+1,r,k);
        if(v[mid]>k)
            return Search(v,l,mid-1,k);
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;


    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    int l=0;
    int r=n-1;
    int m;
    cin>>m;


    int result=Search(arr,l,r,m);
    if(result==-1)
    {
        cout<<"Not Found"<<endl;
    }
    else
    {
        cout<<result<<endl;
    }


    return 0;
}
