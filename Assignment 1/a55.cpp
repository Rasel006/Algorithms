#include<bits/stdc++.h>


using namespace std;


void marge(int arr1[],int arr2[],int p,int q,int r[])
{
    int a=0,b=0,c=0;
    while(a<p && b<q)
    {
        if(arr1[a]>=arr2[b])
        {
            r[c++]=arr1[a++];
        }
        else
        {
            r[c++]=arr2[b++];
        }
    }
   
    while(a<p)
    {
        r[c++]=arr1[a++];
    }
    while (b<q)
    {
        r[c++]=arr2[b++];
    }
 
   
}
int main()
{
    int p,q;
    cin>>p;
   
    int arr1[p];
    for(int i=0;i<p;i++)
    {
        cin>>arr1[i];
    }


    cin>>q;
    int arr2[q];
    for (int i=0;i<q;i++)
    {
        cin>>arr2[i];
    }


    int r[p+q];
    marge(arr1,arr2,p,q,r);


    for(int i=0;i<p+q;i++)
    {
    cout<<r[i]<< " ";
    }


    return 0;
}
