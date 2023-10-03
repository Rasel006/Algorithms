#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int arry_One[n];
     for (int i = 0; i < n; i++)
     {
        cin >> arry_One[i];
     }
     int m;
     cin >> m;
    int arry_Two[m];
     for (int i = 0; i < n; i++)
     {
        cin >> arry_Two[i];
     }
     
   arry_One[n] = INT_MIN;
   arry_Two[m] = INT_MIN;
   int MergedArry[n+m];
   int first_p = 0, second_p = 0;
   // After mager two arry ouput will be 
   for (int i = 0; i < n+m; i++)
   {
      if(arry_One[first_p] >= arry_Two[second_p]){
         MergedArry[i] = arry_One[first_p];
         first_p++;
      }
      else{
         MergedArry[i] = arry_Two[second_p];
         second_p++;
      }
   }

   for (int i = 0; i < n+m; i++)
   {
      cout << MergedArry[i] << " ";
   }
   
   


    return 0;
}