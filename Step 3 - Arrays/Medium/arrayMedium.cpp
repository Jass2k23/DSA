#include <bits/stdc++.h>
using namespace std;

// //! Two Sum using map
// // string read0(int n, vector<int> book, int target)
// // {   
// //     unordered_map<int,int>m;
// //     vector<int>ans;
// //     for(int i=0;i<n;i++){
// //         int more = target - book[i];
// //         if(m.find(more) != m.end())
// //             ans.push_back(i,m[more]);
// //             return ans;
// //         m[book[i]]=i;
// //     }
// //     return ans;
// //     return "NO";
// // }

// //! using two pointers
// string read(int n,vector<int>book, int target){
//     int right = n-1;
//     int left = 0;
//     int sum = 0;
//     sort(book.begin(),book.end());
//     while(left<right){
//         sum = book[left] + book[right];
//         if(sum < target)
//             left++;
//         else if(sum > target)
//             right--;
//         else
//             return "YES";
//     }
//     return "NO";
// }




// //! Sorting array with 0s,1s,2s
// //* O(2N + logN)
// void sortArray0(vector<int>& arr, int n)
// {
//     map<int,int>m;
//     for(int i=0;i<n;i++){
//         m[arr[i]]++;
//     }
//     int zeroes = m[0];
//     int ones = m[1];
//     int twos = m[2];
//     int index = 0;
//     for(int i=0;i<zeroes;i++){
//         arr[index] = 0;
//         index++;
//     }
//     for(int i=0;i<ones;i++){
//         arr[index] = 1;
//         index++;
//     }
//     for(int i=0;i<twos;i++){
//         arr[index] = 2;
//         index++;
//     }
// }

// //* better way, O(2N)
// //? running a loop through array and counting 0s,1s,2s with 3 varibles and then changing the array.         O(N) + O(N)

// //! Dutch National Flag Algo
// //* Optimal Way, O(N)
// //In each iteration we r sorting 1 element, either from left(mid) or from right(high)
// void sortArray(vector<int>& arr, int n){
//     int mid = 0;
//     int high = n-1;
//     int low = 0;
//     while(mid<=high){
//         if(arr[mid]==0){
//             swap(arr[mid],arr[low]);
//             mid++;
//             low++;
//         }
//         else if(arr[mid]==1){
//             mid++;
//         }
//         else{
//             swap(arr[mid],arr[high]);
//             high--;
//         }
//     }
// }




// //! Mojority Element
// //* Brute, O(N+N)
// int majorityElement(vector<int> v) {
//     int n = v.size();
//     unordered_map<int,int>m;
//     for(int i=0;i<n;i++){
//         m[v[i]]++;
//     }
//     for(auto i:m){
//         if(i.second >= n/2)
//             return i.first;
//     }
//     return -1;
// }

// //* Optimal way, O(N)
// //! Moore's Voting Algo
// int majorityElement(vector<int>& nums) {
//         int el = nums[0];
//         int cnt = 0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i] == el){
//                 cnt++;
//             }
//             else
//                 cnt--;
//             if(cnt == 0){
//                 el = nums[i+1];
//             }
//         }
//         return el;
        
//         //* If the question doesn't guarantees, they we have to check
//         // int temp = 0;
//         // for(int i=0;i<nums.size();i++){
//         //     if(nums[i] == el)
//         //         temp++;
//         // }
//         // if(temp > nums.size()/2)
//         //     return el;
//         // else return -1;
//     }




// //! Max Subarray Sum
// //* Brute, O(N^2)
// long long maxSubarraySum0(vector<int> arr, int n)
// {
//     long long maxSum = 0;
//     for(int i=0;i<n;i++){
//         long long sum = arr[i];
//         // In case the last element is greater than the maxSum
//         if(sum > maxSum)
//             maxSum = sum;
//         if(sum>maxSum)
//             maxSum = sum;
//         for(int j=i+1;j<n;j++){
//             sum += arr[j];
//             if(sum>maxSum)
//                 maxSum = sum;
//         }
//     }
//     return maxSum;
// }

// //* Optimal, O(N)
// //! Kadane's algo
// long long maxSubarraySum(vector<int> arr, int n)
// {
//     long long maxSum = LONG_MIN;
//     long long sum = 0;
//     for(int i=0;i<n;i++){
//         sum += arr[i];
//         if(sum < 0)
//             sum = 0;
//         maxSum = max(maxSum,sum);
//     }
//     return maxSum;
// }

// //* If they also want the subarray
// long long maxSubarraySum1(vector<int> arr, int n)
// {
//     long long maxSum = LONG_MIN;
//     long long sum = 0;
//     int start = 0;
//     int arrSt = -1;
//     int arrEnd = -1;
//     for(int i=0;i<n;i++){
//         if(sum == 0){
//             start = i;
//         }
//         sum += arr[i];
//         if(sum > maxSum){
//             maxSum = sum;
//             arrSt = start;
//             arrEnd = i;
//         }
//         else if(sum < 0)
//             sum = 0;
//     }
//     return maxSum;
// }



// //! Best time to buy and sell Stock
// //* Brute, O(N^2)
// int bestTimeToBuyAndSellStock0(vector<int>&prices) {
//     int n = prices.size();
//     int maxProfit = INT_MIN;
//     for(int i=0;i<n-1;i++){
//         int buy = -1*prices[i];
//         for(int j=i+1;j<n;j++){
//             int profit =  buy + prices[j];
//             if(profit > maxProfit)
//                 maxProfit = profit;
//         }
//     }
//     return maxProfit;
// }

// //* Optimal, O(N)
// int bestTimeToBuyAndSellStock(vector<int>&arr) {
//     int n = arr.size();
//     int mini = arr[0];
//     int maxProfit = 0;
//     for(int i=1;i<n;i++){
//         int profit = arr[i] - mini;
//         maxProfit = max(maxProfit,profit);
//         mini = min(mini,arr[i]);
//     }
//     return maxProfit;
// }



// //! Alternate Numbers
// //*Optimal, O(N)
// vector<int> alternateNumbers(vector<int>&a) {
//     int size = a.size();
//     int p = 0;
//     int n = 1;
//     vector<int>arranged_a(size);
//     for(int i=0;i<size;i++){
//         if(a[i] < 0){
//             arranged_a[n] = a[i];
//             n+=2;
//         }
//         else{
//             arranged_a[p] = a[i];
//             p+=2;
//         }
//     }
//     return arranged_a;
// }



// //! Alternate Numbers but num of +ve and -ve r not same
// void rearrange(vector<int> &arr)
// {
// 	int n = arr.size();
// 	vector<int>pos,neg;
// 	for(int i=0;i<n;i++){
// 		if(arr[i]<0)
// 			neg.push_back(arr[i]);
// 		else
// 			pos.push_back(arr[i]);
// 	}
// 	if(pos.size()>neg.size()){
// 		for(int i=0;i<neg.size();i++){
// 			arr[2*i] = pos[i];
// 			arr[(2*i)+1] = neg[i];
// 		}
// 		int index = neg.size() * 2;
// 		for(int i=neg.size();i<pos.size();i++){
// 			arr[index] = pos[i];
// 			index++;
// 		}
// 	}
// 	else{
// 		for(int i=0;i<pos.size();i++){
// 			arr[2*i] = pos[i];
// 			arr[(2*i)+1] = neg[i];
// 		}
// 		int index = pos.size() * 2;
// 		for(int i=pos.size();i<neg.size();i++){
// 			arr[index] = neg[i];
//         }
// 	}
// }



// //! Next Permutation
// //* O(3N)
// vector<int> nextGreaterPermutation(vector<int> &arr) {
//     int n = arr.size();
//     int index = -1;
//     for(int i=n-2;i>=0;i--){
//         if(arr[i]<arr[i+1]){
//             index = i;
//             break;
//         }
//     }
//     if(index == -1){
//         reverse(arr.begin(),arr.end());
//         return arr;
//     }
//     for(int i=n-1;i>index;i--){
//         if(arr[i]>arr[index]){
//             swap(arr[i],arr[index]);
//             break;
//         }
//     }  
//     reverse(arr.begin()+index+1,arr.end());
//     return arr;
// }



// //! Suprior Elements
// //* O(N), s->O(N) for storing the ans
// vector<int> superiorElements(vector<int>&a) {
//     int n = a.size();
//     int max_el = a[n-1];
//     vector<int>ans;
//     ans.push_back(max_el);
//     for(int i=n-2;i>=0;i--){
//         if(a[i] > max_el){
//             ans.push_back(a[i]);
//             max_el = a[i];
//         }
//     }
//     return ans;
// }



// //! Longest Consecutive Seq
// //* Brute, O(NlogN + N)
// int longestSuccessiveElements0(vector<int>&nums) {
//     int n = nums.size();
//     sort(nums.begin(),nums.end());
//     int maxCount = 1;
//     for(int i=0;i<n-1;i++){
//         int cnt = 1;
//         if(nums[i+1] - nums[i] == 1){
//             cnt++;
//         }
//         else{
//             maxCount = max(cnt,maxCount);
//             cnt = 1;
//         }
//     }
//     return maxCount;
// }

// //*Optimal, O(3N)
// int longestConsecutive(vector<int>& arr) {
//     int n = arr.size();
//         if(n == 0){
//             return 0;
//         }
//         unordered_set<int> s;
//         int longestSeq = 1;
//         int cnt = 1;
//         for(int i=0;i<n;i++){
//             s.insert(arr[i]);
//         }
//         for(auto i:s){
//             if(s.find(i-1) == s.end()){
//                 cnt = 1;
//                 int x = i;
//                 while(s.find(x+1) != s.end()){
//                     cnt++;
//                     x += 1;
//                 }
//                 longestSeq = max(cnt,longestSeq);
//             }
//         }
//         return longestSeq;
// }



// //! Zero Matrix
// //* Hashing, O(2*row*col) & s-O(row)+O(col)
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
// 	int row[n] = {0};
// 	int col[m] = {0};
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			if(matrix[i][j] == 0){
// 				row[i] = 1;
// 				col[j] = 1;
// 			}
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			if(row[i] == 1 || col[j] == 1){
// 				matrix[i][j] = 0;
// 			}
// 		}
// 	}
// 	return matrix;
// }

// //* s- O(1)
// void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int col0 = 1;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==0){
//                     matrix[i][0] = 0;   //rows
//                     if(j != 0)
//                         matrix[0][j] = 0;   //columns
//                     else
//                         col0 = 0;
//                 }
//             }
//         }

//         for(int i=1;i<n;i++){
//             for(int j=1;j<m;j++){
//                 if(matrix[i][0] == 0 || matrix[0][j] == 0){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }

//         if(matrix[0][0] == 0){
//             for(int j=0;j<m;j++){
//                 matrix[0][j] = 0;
//             }
//         }

//         if(col0 == 0){
//             for(int i=0;i<n;i++){
//                 matrix[i][0] = 0;
//             }
//         }
//     }



// //! Rotate Array 90degree clockwise
// void rotateMatrix(vector<vector<int>> &mat){
// 	int n = mat.size();		//rows
// 	for(int i=0;i<n-1;i++){
// 		for(int j=1;j<n-1-i;j++){
// 			swap(mat[i][j],mat[j][i]);
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		reverse(mat[i].begin(),mat[i].end());
// 	}
// }



//! Subarray Sum Equal to K
//* O(N)
int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        m[0] = 1;
        int prefixSum = 0, cnt = 0;
        
        for(int i=0;i<arr.size();i++){
            prefixSum += arr[i];
            int inMap = prefixSum - k;
            
            cnt += m[inMap];
            m[prefixSum] += 1;
        }
        return cnt;
    }


int main(){

    int n = 3;

    // cin>>n;
    vector<int>v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    cout<<subarraySum(v,2)<<endl;
}