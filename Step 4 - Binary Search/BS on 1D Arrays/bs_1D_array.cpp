#include <bits/stdc++.h>
using namespace std;

//! The MAIN IDEA is to eliminate on half of the array & proceed forward

//! Binary Search
//* Iterative way, O(log2(N)) as it can be expressed as 2^N
int search0(vector<int> &arr, int target) {
    int low = 0, high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target)
            return mid;
        else if(target > arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

//* Recursive Way
int bs(vector<int>&arr,int low, int high, int target){
    if(low>high)
        return -1;
    int mid = (low+high)/2;
    if (arr[mid] == target)
        return mid;
    else if(target > arr[mid])
        return bs(arr,mid+1,high,target);
    else
        return bs(arr,low,mid-1,target);
}

int search(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1;
    return bs(arr,low,high,target);
}



//! Lower Bound
//*  'lower_bound' of a number 'x' is defined as the smallest index 'idx' such that arr[idx] >= x
int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n-1;
	int ans = n;
	while(low<=high){
		int mid = (low+high)/2;
		if(x > arr[mid]){
			low = mid+1;
		}
		else{
			ans = min(ans,mid);
			high = mid-1;
		}
	}
	return ans;
}

//* with STL
int lowerBoundEasy(vector<int> arr, int n, int x){
    return (lower_bound(arr.begin(),arr.end(),x) - arr.begin());
}



//! Upper Bound
//* Smallest index such that, arr[ind] > x
int upperBound(vector<int> &arr, int x, int n){
	int low = 0, high = n-1;
	int ans = n;
	while(low<=high){
		int mid = (low + high)/2;
		if(arr[mid] > x){
			high = mid - 1;
			ans = mid;
		}
		else{
			low = mid+1;
		}
	}
	return ans;

    //* return upper_bound(arr.begin(),arr.end(),x) - arr.begin();
}



//! Floor/Ceil in Sorted array
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	// floor(largest in array) <= x
	// ceil(smallest in array) >= x
	int floor = -1, ceil = -1;
	int low = 0, high = n-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid] == x){
			floor = x;
			ceil = x;
			break; 
		}
		else if(x > arr[mid]){
			low = mid+1;
			floor = arr[mid];
		}
		else{
			high = mid-1;
			ceil = arr[mid];
		}
	}
	return {floor,ceil};
}



//! Find First & Last Position of Element in array
//* Approach - 1
//? Use the concept of lower and upper bound

//* For finding first Position
int firstPos(vector<int>&arr,int n, int target){
        int low = 0, high = n-1;
        int fo = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == target){
                fo = mid;
                if(fo != -1){
                    fo = min(fo,mid);
                }
                high = mid-1;
            }
            else if(arr[mid] < target){
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return fo;
    }

//* For finding last Position
    int lastPos(vector<int>&arr,int n, int target){
        int low = 0, high = n-1;
        int lo = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == target){
                low = mid+1;
                lo = max(lo,mid);
            }
            else if(arr[mid] < target){
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return lo;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>ans;
        ans.push_back(firstPos(arr,n,target));
        ans.push_back(lastPos(arr,n,target));
        return ans;
    }



//! Number of Occurence
int count(vector<int>& arr, int n, int x) {
	int lowerBound = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
	int upperBound = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
	return (upperBound - lowerBound);
}



//! Search In Rotated Sorted Array with no duplicates
//* O(rotated) + O(log2N) or O(2log2N)
int search(vector<int>& arr, int n, int k)
{
    int low=0;
    int high=n-1;
    while(arr[low]>=arr[high]){
        low++;
    }

    int index1 = binarySearch(arr,k,low,n-1);
    if(index1 == -1){
        int index2 = binarySearch(arr,k,0,low-1);
        if(index2 == -1)
            return -1;
        else    
            return index2;
    }
    else{
        return index1;
    }
}




//! Search In Rotated Sorted Array with duplicates
bool search(vector<int>& arr, int k) {
        int n = arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == k)
                return true;
            else if(arr[low] == arr[mid] && arr[mid] == arr[high]){
                low++;
                high--;
                continue;
            }
            else if(arr[low] <= arr[mid]){
                if(arr[low] <= k && k <= arr[mid]){
                    high = mid-1;
                }
                else
                    low = mid+1;
            }
            else{
                if(arr[mid] <= k && k <= arr[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return false;
    }




//! Search Minimum in Sorted Rotated Array
int findMin(vector<int>& arr)
{
    int low=0,high=arr.size()-1;
    int smallest = INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low] <= arr[mid]){
            smallest = min(smallest,arr[low]);
            low=mid+1;
        }
        else{
            smallest=min(smallest,arr[mid]);
            high=mid-1;
        }
    }
    return smallest;
}



//! Find the number of time Rotation occured
int findKRotation(vector<int> &arr){
    int low=0,high=arr.size()-1;
    int smallest = 999999999;
    int smallest_index = 0;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[low]<=arr[mid]){
            if(arr[low] < smallest){
                smallest_index = low;
                smallest=arr[low];
            }
            low=mid+1;
        }
        else{
            if(arr[mid]<smallest){
                smallest_index=mid;
                smallest=arr[mid];
            }
            high=mid-1;
        }
    }
    return smallest_index;
}



//! Single element in sorted array
int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return arr[0];
        else if(arr[0]!=arr[1])
            return arr[0];
        else if(arr[n-1]!=arr[n-2])
            return arr[n-1];
        else{
            int low=1,high=n-2;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
                    return arr[mid];
                else if(arr[mid] != arr[mid+1]){
                    if((mid-1)%2==0){
                        low=mid+1;
                    }
                    else
                        high=mid-1;
                }
                else{
                    if((mid+1)%2==0)   
                        high=mid-1;
                    else
                        low=mid+1;
                }
            }
        }
        return -1;
    }



//! Finding Peak Element
//* An element which is greater than it's neighbour
//? O(N)
int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return 0;
        else if(arr[0]>arr[1])
            return 0;
        else if(arr[n-1]>arr[n-2])
            return n-1;
        
        for(int i=1;i<=n-2;i++){
            if(arr[i] > arr[i-1] && arr[i]>arr[i+1])
                return i;
        }
        return -1;
}

//* Optimal way, O(log2N)


int main(){

    vector<int>arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(10);

    cout<smallestElement(arr)<<endl;
}