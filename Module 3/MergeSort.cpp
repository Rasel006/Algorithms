#include<bits/stdc++.h>
using namespace std;
int const N = 1e5+7;
int arry[N];

// Conquror
void marge(int l, int r, int mid){
   // Make left subarry
   int left_Size = mid - l + 1;
   int left_arr[left_Size + 1];
   // Make right subarry 
   int right_Size = r - mid;
   int right_arr[right_Size + 1];

   // put value int left and right subarry
   for(int i = l, j = 0; i <= mid; i++, j++) left_arr[j] = arry[i];
   for(int i = mid+1, j = 0; i <= r; i++, j++) right_arr[j] = arry[i];

  //  For extra cases 
  left_arr[left_Size] = INT_MAX;
  right_arr[right_Size] = INT_MAX;

  // Now MERGE the hole arry 
    // make pointers 
  int lp  = 0, rp = 0;

  for(int i = l; i <= r; i++){
    if(left_arr[lp] <= right_arr[rp]){
      arry[i] = left_arr[lp];
      lp++;
    }
    else{
      arry[i] = right_arr[rp];
      rp++;
    }
  }

}
// Divede 
void margetSort(int l, int r){

   // Base case 
   if(l == r) return;

   int mid = (l + r) / 2;
   margetSort(l, mid);
   margetSort(mid + 1, r);
   marge(l, r, mid);
}

int main(){
   // TAke input 
     int n; cin >> n;

     for(int i = 0; i < n; i++){
        int x; cin >> x;
        arry[i] = x;
     }

   // Before sort print 
     for (int i = 0; i < n; i++)
     {
       cout << arry[i] << " "; 
     }

    margetSort(0, n-1);
    cout << endl;
   //   After aplly mergre sort print
     for (int i = 0; i < n; i++)
     {
       cout << arry[i] << " "; 
     }
     
     

    return 0;
}