#include <bits/stdc++.h>
using namespace std;

//! 1 to N or printing N times

void recursiveFn(int n, vector<int> &ans)
{
    if (n == 0)
        return;
    recursiveFn(n - 1, ans);
    ans.push_back(n);
}

vector<int> printNos(int n)
{
    vector<int> ans;
    recursiveFn(n, ans);
    return ans;
}

//! Sum of N number
void recursiveFn(long long n, long long &ans)
{
    if (n == 0)
        return;
    ans += n;
    recursiveFn(n - 1, ans);
}

long long sumFirstN(long long n)
{
    long long ans = 0;
    recursiveFn(n, ans);
    return ans;
}

long long sum(long long n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

//! Factorial Numbers not greater than N
void helper(vector<long long> &ans, long long val, long long cntr, long long n)
{
    val = val * cntr;
    cntr = cntr + 1;
    if (val > n)
    {
        return;
    }
    ans.push_back(val);
    helper(ans, val, cntr, n);
}

vector<long long> factorialNumbers(long long n)
{
    vector<long long> ans;
    long long val = 1;
    long long cntr = 1;

    helper(ans, val, cntr, n);
    return ans;
}

//! Reversing an Array
void recursive(int n, int cnt, vector<int> &nums, vector<int> &rev_ans)
{
    if (n < 0)
        return;
    rev_ans.push_back(nums[n]);
    recursive(n - 1, cnt + 1, nums, rev_ans);
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    vector<int> rev_ans;
    int cnt = 0;
    recursive(n - 1, cnt, nums, rev_ans);
    return rev_ans;
}

//! Palindrome
bool isPalindrome(int cnt, int n, string str){
    if(cnt >= n){
        return true;
    }
    if(str[cnt] != str[n])
        return false;
    return isPalindrome(cnt+1,n-1,str);
}

//! Fibonacci
void fiboRecursive(int x, int y, int n, vector<int> &ans)
{
    if (n < 0)
        return;
    ans.push_back(x);
    fiboRecursive(y, x + y, n - 1, ans);
}

vector<int> generateFibonacciNumbers(int n)
{
    vector<int> ans;
    int x = 0;
    int y = 1;
    fiboRecursive(x, y, n, ans);
    return ans;
}

int main()
{

}