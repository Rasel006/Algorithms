#include<bits/stdc++.h>
using namespace std;
void Merge(int arrr[],int l, int r, int mid){
    // make the size of temp arr and create them 
    int leftIndex = mid - l + 1;
    int rightIndex = r - mid ;

    int leftArr[leftIndex + 1];
    int rightArr[rightIndex + 1];
    
    // Assign value in the temp arrys
    for(int i = l,j = 0; i <= mid; i++,j++){
        leftArr[j] = arrr[i];
    }
    for(int i = mid + 1,j = 0; i <= r; i++,j++){
        rightArr[j] = arrr[i];
    }
    
    // extra vluess for the easy 
    leftArr[leftIndex] = INT_MAX;
    rightArr[rightIndex] = INT_MAX;
    // Merge them  
    int lp = 0;
    int rp = 0;
    for(int i = l; i <= r; i++){
        if(leftArr[lp] <= rightArr[rp]){
            arrr[i] = leftArr[lp];
            lp++;
        }
        else{
            arrr[i] = rightArr[rp];
            rp++;
        }
    }

}

void MergeSort(int arrr[],int l, int r){

    if(l < r){
        int mid = (l + r) / 2;
        MergeSort(arrr,l, mid);
        MergeSort(arrr,mid + 1, r);
        Merge(arrr,l, r, mid);
    }
}



int main(){
    
    // Take input 
    int n; cin >> n;
    int arrr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arrr[i];
    }

    MergeSort(arrr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arrr[i] << " ";
    }
    
    
     

    return 0;
}