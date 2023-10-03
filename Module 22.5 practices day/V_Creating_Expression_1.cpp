#include<bits/stdc++.h>
using namespace std;
int n, x;
bool Choice_result(long long sum,int i, int arr[]){
    // base case 
    if(n == i){
        return sum == x;
    }

      bool opt1 = Choice_result(sum + arr[i], i + 1,arr);
      bool opt2 = Choice_result(sum - arr[i], i + 1,arr);

    return opt1 || opt2;
}

int main(){

      cin >> n >> x;
      int arr[21]; 
      for (int i = 0; i < n; i++)
      {
        cin >> arr[i];
      }

      if(Choice_result(arr[0], 1, arr)){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
      

    return 0;
}