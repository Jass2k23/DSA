#include <bits/stdc++.h>
using namespace std;

//! If u need 2 find min or max and u know the range, try using binary search


//! Square root of num
int floorSqrt(int n)
{
    int low=1,high=n;
    long long ans = 1;
    while(low<=high){
        long long mid=(low+high)/2;
        ans = mid*mid;
        if(ans<=n){
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return high;
}



//! Nth root of Interger
int rootExsist(int n, int m,int mid){
    long long product = 1;
    for(int i=1;i<=n;i++){
        product *= mid;
        if(product == m){
            return 1;
        }
        else if(product > m){
            return -1;
        }
    }
    return 0;
}

int NthRoot(int n, int m) {
    int low=1,high=m;
    while(low<=high){
        int mid=(low+high)/2;
        int value = rootExsist(n,m,mid);

        if(value == 1){
            return mid;
        }
        else if(value == -1){
            high=mid-1;
        }
        else{
            low=mid+1;
        }    

    }
    return -1;
}




//! Koko Eating Banana
long long check(vector<int>&arr,int mid){
    long long total=0;
    for(int i=0;i<arr.size();i++){
        total+= ceil(double(arr[i])/double(mid));
    }
    return total;
}

int minimumRateToEatBananas(vector<int> arr, int h) {
    int maximum = *max_element(arr.begin(),arr.end());
    int low=1,high=maximum;
    while(low<=high){
        int mid=(low+high)/2;
        long long total=check(arr,mid);
        if(total<=h)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}




//! Rose Garden
int possible(vector<int>arr,int mid, int k, int m){
	int cnt=0;
	int ans = 0;
	for(int i=0;i<arr.size();i++){
		if((arr[i]/mid) <= arr[i]){
			cnt++;
		} 
		else {
			ans += (cnt / k);
			cnt=0;
		}
    
	}
    return ans;
}

int roseGarden(vector<int> arr, int k, int m)
{
	int low=*min_element(arr.begin(),arr.end()),high=*max_element(arr.begin(),arr.end());
	while(low<=high){
		int mid=(low+high)/2;
		int ans=possible(arr,mid,k,m);
		if(ans==m)
			return mid;
		else if(ans>m)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}



//! Smallest Divisor
bool check(vector<int>arr,int mid,int limit){
	int sum=0;
	for(int i=0;i<arr.size();i++){
		sum+=ceil(double(arr[i])/double(mid));
	}
	if(sum<=limit)
		return true;
	else	
		return false;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	int low=1,high=*max_element(arr.begin(),arr.end());
	while(low<=high){
		int mid=(low+high)/2;
		bool value=check(arr,mid,limit);
		if(value==true){
			high=mid-1;
		}
		else
			low=mid+1;
	}
	return low;
}



//! Capacity to Ship Packages within D days
//* O(log2(sum-max+1))*O(N)
int days(vector<int>arr,int capacity){
    int sum=0;
    int days=1;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>capacity){
            days++;
            sum=arr[i];
        }
        else{
            continue;
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int max_days)
{
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int req_days = days(weights,mid);
        if(req_days<=max_days)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}



//! kth Missing Positive Number
//* Brute 
// int missingK(vector < int > arr, int n, int value) {
//     int i=0,k=1,cnt=0;
//     while(i<=n){
//         if(value==cnt)
//             return k-1;
//         else if(arr[i] != k){
//             cnt++;
//         }
//         else{
//             i++;
//         }
//         k++;
//     }
//     return k-1;
// }

//* Optimal
int missingK(vector < int > arr, int n, int k) {
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing = arr[mid] - (mid+1);
        if(missing < k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low+k;
}


//! BS on answers -> (min)max or (max)min



//! Aggressive Cows
bool canWePlace(vector<int>& stalls, int dist, int cows){
    int cnt_cows=1,last=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-last >= dist){
            cnt_cows++;
            last=stalls[i];
        }
        if(cnt_cows>=cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int low=1,high=(stalls[stalls.size()-1]-stalls[0]);
    while(low<=high){
        int mid=(low+high)/2;
        bool value = canWePlace(stalls,mid,k);
        if(value==true){
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return high;
}




//! Book Allocation
#include <bits/stdc++.h>
bool possible(vector<int>& arr, int max_allocated,int students){
    int sum=0,cnt_students=1;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>max_allocated){
            sum=arr[i];
            cnt_students++;
        }
    }
    if(cnt_students>students){
        return false;
    }
    return true;
}

int sum(vector<int> &arr){
    int total=0;
    for(int i=0;i<arr.size();i++){
        total+=arr[i];
    }
    return total;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m>n)
        return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=sum(arr);
    while(low<=high){
        int mid=(low+high)/2;
        bool value=possible(arr,mid,m);
        if(value==true){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}




//! Painter's Partition and Split Array - Largest Sum
class Solution {
public:
    bool possible(vector<int>& arr, int max_sum,int split){
        int sum=0,cnt_split=1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>max_sum){
                sum=arr[i];
                cnt_split++;
            }
        }
        if(cnt_split>split){
            return false;
        }
        return true;
    }


    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            bool value=possible(arr,mid,k);
            if(value==true){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};




//! Minimise Maximum Distance between Gas Station
//* Using Priority Queue, O(NlogN + klogN), s-O(n-1)
#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	priority_queue<pair<long double,int>> pq;
	vector<int>howMany(n-1,0);
	for(int i=0;i<n-1;i++){
		pq.push({arr[i+1]-arr[i],i});
	}
	for(int i=0;i<k;i++){
		auto tp=pq.top(); pq.pop();
		int secIndex=tp.second;
		howMany[secIndex]++;
		long double initial_diff=arr[secIndex+1]-arr[secIndex];
		long double newSection=initial_diff/(long double)(howMany[secIndex]+1);
		pq.push({newSection,secIndex});
	}
	return pq.top().first;
}
//* Optimal Solution, in Screen Shot



//! Median of 2 Sorted Arrays
//* Brute Force
// double median(vector<int>& nums1, vector<int>& nums2) {
// 		vector<int>arr;
//         for(int i=0;i<nums1.size();i++){
//             arr.push_back(nums1[i]);
//         }
//         for(int i=0;i<nums2.size();i++){
//             arr.push_back(nums2[i]);
//         }
//         sort(arr.begin(),arr.end());
//         int combined_size=arr.size();
//         if(combined_size%2!=0){
//             return arr[(combined_size)/2];
//         }
//         else{
//             double n1=arr[combined_size/2];
//             double n2=arr[(combined_size/2)-1];
//             return (n1+n2)/2.0; 
//         }
// }

//* Better Solution, with space - O(1)
// just calculate the element we need from the indexes, (n+m) -> even - (n+m)/2 & (n+m)/2-1, odd - (n+m)/2
// use two pointers for tracking 2 arrays and a count variable to check if your index == ans's indexes

//* Optimal, using Binary Search
//! IMPORTANT HARD
double median(vector<int>& arr1, vector<int>& arr2){
    int n1=arr1.size(),n2=arr2.size();
    if(n1>n2)   return median(arr2,arr1);
    int low=0,high=n1;
    int left=(n1+n2+1)/2;
    while(low<=high){
        int mid1=(low+high)/2;      // for left array
        int mid2=left-mid1;            // for ryt array
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n1)
            r1=arr1[mid1];
        if(mid2<n2)
            r2=arr2[mid2];
        if(mid1-1>=0)
            l1=arr1[mid1-1];
        if(mid2-1>=0)
            l2=arr2[mid2-1];

        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2!=0)    return max(l1,l2);
            else    return double((max(l1,l2) + min(r1,r2)))/2.0;
        }

        if(l1>r2)
            high=mid1-1;
        if(l2>r1)
            low=mid1+1;
    }
    return 0;
}



//! K-th element of two sorted array
int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
  if (n > m)
    return kthElement(arr2, arr1, m, n, k);
  int low = max(0, k - m);
  int high = min(n, k);
  int left = k;
  while (low <= high) {
    int mid1 = (low + high) / 2;
    int mid2 = left - mid1;
    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;
    if (mid1 < n)
      r1 = arr1[mid1];
    if (mid2 < m)
      r2 = arr2[mid2];
    if (mid1 - 1 >= 0)
      l1 = arr1[mid1 - 1];
    if (mid2 - 1 >= 0)
      l2 = arr2[mid2 - 1];

    if (l1 <= r2 && l2 <= r1) {
      return max(l1, l2);
    }
    if (l2 > r1)
      low = mid1 + 1;
    if (l1 > r2)
      high = mid1 - 1;
  }
  return 0;
}

int main(){

}