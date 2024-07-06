#include <bits/stdc++.h>
using namespace std;

//! 1 to N or printing N times

void recursiveFn(int n,vector<int>&ans){
    if(n==0)    return;
    recursiveFn(n-1,ans);
    ans.push_back(n);
}

vector<int> printNos(int n){
    vector<int>ans;
    recursiveFn(n,ans);
    return ans;
}


//! Sum of N number
void recursiveFn(long long n,long long &ans){
    if(n==0)    return;
    ans+=n;
    recursiveFn(n-1,ans);
}

long long sumFirstN(long long n) {
    long long ans = 0;
    recursiveFn(n,ans);
    return ans;
}

long long sum(long long n){
    if(n==0)    return 0;
    return n+sum(n-1);
}


//! Factorial Numbers not greater than N
vector<long long> factorialNumbers(long long n) {
    vector<long long>ans;
    long long cnt=2;
    long long fact = 1;
    while(fact<=n){
        ans.push_back(fact);
        fact*=cnt;
        cnt++;
    }
    return ans;
}


//! Reversing an Array
void recursive(int n, int cnt, vector<int>&nums,vector<int>&rev_ans){
    if(n<0)  return;
    rev_ans.push_back(nums[n]);
    recursive(n-1,cnt+1,nums,rev_ans);
}

vector<int> reverseArray(int n, vector<int> &nums)
{   vector<int>rev_ans;
    int cnt = 0;
    recursive(n-1,cnt,nums,rev_ans);
    return rev_ans;
}


//! Palindrome
void recursiveFunc(int n,string &str,string &rev){
    if(n<0)     return;
    rev+=str[n];
    recursiveFunc(n-1,str,rev);
}

bool isPalindrome(string& str) {
    // Write your code here.
    int n = str.length()-1;
    string rev = "";
    recursiveFunc(n,str,rev);
    if(str == rev)  return true;
    return false;
}


//! Fibonacci
void fiboRecursive(int x,int y,int n,vector<int> &ans){
    if(n<0)    return;
    ans.push_back(x);
    fiboRecursive(y,x+y,n-1,ans);
}

vector<int> generateFibonacciNumbers(int n) {
    vector<int> ans;
    int x = 0;
    int y = 1;
    fiboRecursive(x,y,n,ans);
    return ans;
}






int main(){
    int n;
    cin>>n;
    factorial(n);
    
}