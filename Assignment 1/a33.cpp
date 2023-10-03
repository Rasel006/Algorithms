#include<bits/stdc++.h>


using namespace std;
 bool Search(int v[],int l,int r,int k)
 {
    while(l<=r)
    {
        int mid=l+(r-l)/2;


        if(v[mid]==k && v[mid+1]==k)
        {
            return true;
        }
        else if(v[mid]<k)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return false;
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


    bool result=Search(arr,l,r,m);
    if(!result)
    {
        cout<<"NO"<<endl;
    }    
    else
    {
        cout<<"YES"<<endl;
    }
    return 0;
}
