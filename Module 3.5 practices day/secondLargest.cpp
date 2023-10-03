Coding Ninja : https://www.codingninjas.com/studio/problems/second-largest-element-in-the-array_873375?leftPanelTab=0
#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    bool flag = false;
    int first_Max = arr[0];
    for(auto && val : arr){
        if(val != first_Max){
            flag = true;
            break;
        }
    }
    if(!flag) return -1;
    for(auto && val : arr){
        if(val > first_Max) first_Max = val;
    }
    int second_max = INT_MIN;
    for(auto && val : arr){
        if(val > second_max && first_Max > val) second_max = val;
    }
    return second_max;
}