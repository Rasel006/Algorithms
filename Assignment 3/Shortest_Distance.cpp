#include<bits/stdc++.h>
using namespace std;
const long long int n=1e18; 

int main()
{
    
     int x,y;
     cin>>x>>y;

     long long ds[x+1][x+1];

     for(int i=1;i<=x;i++)
     {
        for (int j=1;j<=x;j++)
        {
            if(i==j)
            {
                ds[i][j]=0;
            }
            else
            { 
                ds[i][j]=n;
            }
        }
        
     }

     while(y--)
     {
        int p,q,w;
        cin>>p>>q>>w;

        if(ds[p][q]<w) 
        continue;
        ds[p][q]=w;
     }
    
     for (int t=1;t<=x;t++)
     {
        for (int i=1;i<=x;i++)
        {
            for (int j=1;j<=x;j++)
            {
                if(ds[i][j]>ds[i][t]+ds[t][j])
                {
                    ds[i][j]=ds[i][t]+ds[t][j];
                }
            }
            
        }
        
     }
     
   int k;
   cin>>k;

   while(k--)
   {
     int p,q;
     cin>>p>>q;

     if(ds[p][q]==n)
     {
        cout<<-1<<endl;
     }
     else
     {
        cout<<ds[p][q] << endl;
     }

   }
   
     

    return 0;
}