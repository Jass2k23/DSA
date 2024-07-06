#include <bits/stdc++.h>
using namespace std;

//! Counting frequency of number in an array using Array
vector<int> countFrequency_array(int n, int x, vector<int> &nums){    //10,14, <11,14,8,3,12,14,1,7,4,3>
    x = max(n,x);
    int hash[x+1];     //15
    for(int i=0;i<x+1;i++){
        hash[i] = 0;
    }
    vector<int>ans;
    
    for(int i=0;i<n;i++){
        hash[nums[i]]+=1;   //hash[11]
    }

    for(int i=1;i<=n;i++){
        ans.push_back(hash[i]);
    }
    return ans;
}

//! Counting frequency of number in an array using vector
vector<int> countFrequency_map(int n, int x, vector<int> &nums){
    map<int,int> m;
    vector<int>ans;
    for(int i=0;i<n;i++){
        m[nums[i]]++;
    }
    for(int i=1;i<=n;i++){
        ans.push_back(m[i]); 
    }
    return ans;
}

//! Find highest and lowest freq elements
vector<int> getFrequencies(vector<int>& v) {
    map<int,int> m;
    vector<int>ans;
    vector<int>maximum_elements;
    vector<int>minimum_elements;
    int max_freq = 0;
    int min_freq = INT_MAX;
    for(int i=0;i<v.size();i++){
        m[v[i]]++;
    }
    for(auto i:m){
        if(i.second>max_freq){
            max_freq = i.second;
        }    
        if(i.second<min_freq){
            min_freq = i.second;
        }
    }
    for(auto i:m){
        if(i.second == max_freq){
            maximum_elements.push_back(i.first);
        }
        if(i.second == min_freq){
            minimum_elements.push_back(i.first);
        }
    }
    // for(int i=0;i<elements.size();i++){
    //     cout<<elements[i]<<" ";
    // }
    auto max = *min_element(maximum_elements.begin(),maximum_elements.end());
    auto min = *min_element(minimum_elements.begin(),minimum_elements.end());
    ans.push_back(max);
    ans.push_back(min);
    return ans;
}

int main(){
    