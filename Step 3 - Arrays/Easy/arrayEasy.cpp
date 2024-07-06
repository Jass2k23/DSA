#include <bits/stdc++.h>
using namespace std;

//! Finding second largest in an array
//* brute force, O(Nlog(N))
vector<int> getSecondOrderElements0(int n, vector<int> &a) {
    sort(a.begin(),a.end());        
    vector<int>ans;
    ans.push_back(a[n-2]);
    ans.push_back(a[1]);
    return ans;
}

//* Optimal way, O(2N)
int sLargest(vector<int> a){        // 7 2 4 1 7 6
    int largest = a[0];
    int sLargest = INT_MIN;
    for(int i=1;i<a.size();i++){
        if(a[i] > largest){
            sLargest = largest;
            largest = a[i];
        }
        else if(a[i] > sLargest && a[i] < largest){
            sLargest = a[i];
        }
    }

    return sLargest;
}

int sSmallest(vector<int> a){
    int smallest = a[0];
    int sSmallest = INT_MAX;
    for(int i=1;i<a.size();i++){
        if(smallest > a[i]){
            sSmallest = smallest;
            smallest = a[i];
        }
        else if(sSmallest > a[i] && smallest < a[i]){
            sSmallest = a[i];
        }
    }
    return sSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    vector<int>ans;
    ans.push_back(sLargest(a));
    ans.push_back(sSmallest(a));
    return ans;
}


//! Removing duplicates in-place from sorted array
int removeDuplicates(vector<int> &arr){
    int i=0;
    for(int j=1;j<arr.size();j++){      // 1st place is taken by the 1st element in the array
        if(arr[i] != arr[j]){}
            arr[i+1] = arr[j];
            i++;
    }
    // Returns the number of distinct numbers in the array
    return i+1;
}



//! Left rotation
//* Brute force , O(N+d) & space O(d)
vector<int> rotateArray(vector<int>arr, int d) {        // 1 2 3 4 5 6 , 3 => 4 5 6 1 2 3
    int temp[d];
    int n = arr.size();
    for(int i=0;i<d;i++){
        temp[i] = arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d] = arr[i];
    }
    int j = 0;
    for(int i=n-d;i<n;i++){
        arr[i] = temp[j];
        j++;
    }
    return arr;
}

//* Easier way but with slightly higher time complexity
vector<int> rotateArray(vector<int>&arr, int d) {
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());
    return arr;
}


//! Right Rotation
void rotate(vector<int>& arr, int d) {
        int n = arr.size();
        d = d%n;
        reverse(arr.begin(),arr.begin()+(n-d));
        reverse(arr.begin()+(n-d),arr.end());
        reverse(arr.begin(),arr.end());
    }


//! Moving 0s to last
void moveZeroes(vector<int> &arr){      // 0 1 0 3 12
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                int j = i;
                int temp = j;
                while(arr[j] == 0 && j<n-1){
                    j++;
                }
                swap(arr[temp],arr[j]);
            }
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
}

//* Optimal Solution\
// Moving non zeroes to the front and changing the remaining elements with 0.
void moveZeroes1(vector<int> & arr){
        int n = arr.size();
        int lastNonZero = 0;        //keeps track of no. of zeroes
        for(int i=0;i<n;i++){
            if(arr[i] != 0){
                arr[lastNonZero++] = arr[i];
            }
        }
        for(int i=lastNonZero;i<n;i++){
            arr[i] = 0;
        }
}

//! Union
// vector < int > sortedArray(vector < int > a, vector < int > b) {
//     set<int> temp;
//     for(int i=0;i<a.size();i++){
//         temp.insert(a[i]);
//     }
//     for(int i=0;i<b.size();i++){
//         temp.insert(b[i]);
//     }
//     vector<int>ans;
//     for(auto i:temp){
//         ans.push_back(i);
//     }

//     return ans;
// }

//* Optimal way
vector < int > sortedArray(vector < int > a, vector < int > b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int>ans;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(a[i] <=b[j]){
            if(ans.back() != a[i] || ans.size()==0){
                ans.push_back(a[i]);
            }
            i++;
        }
        else{
            if(ans.back() != b[j] || ans.size() == 0){
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(ans.back() != a[i] || ans.size()==0){
                ans.push_back(a[i]);
            }
            i++;
    }
    while(j<n2){
        if(ans.back() != b[j] || ans.size() == 0){
                ans.push_back(b[j]);
            }
            j++;
    }
    return ans;
}


//! Intersection
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int>ans;
	int i = 0;
	int j = 0;
	while(i<n && j<m){
		if(arr1[i] < arr2[j]){
			i++;
		}
		else if(arr2[j] < arr1[i]){
			j++;
		}
		else{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	return ans;
}


//! finding twice
int getSingleElement0(vector<int> &arr){
	unordered_map<int,int> m;
	for(int i=0;i<arr.size();i++){
		m[arr[i]]++;
	}
	for(auto i:m){
		if(i.second == 1){
			return i.first;
		}
	}
}

//* using XOR 
//? num XOR num = 0, num XOR 0 = num
int getSingleElement(vector<int> &arr){
    int x = 0;
    for(int i = 0;i < arr.size();i++ ){
        x ^= arr[i];
        cout<<x<<endl;
    }   
    cout<<"\n\n"<<x<<endl;
    //thus giving the only number which doesn't have a duplicate
    return x;
}


//! Longest Subarray with sum, for positive and zeroes
int maxLength(vector<int>a, long long k){
    int right = 0, left = 0;
    long long sum = 0;
    int length = 0;
    while(right < a.size()){
        while(sum > k){
            sum -= a[left];
            left++;
        }
        if(sum == k)
            length = max(length,right-left);
        sum += a[right];
        right++;
    }

    return length;
}


int main(){
    int n;
    int m;
    // cin>>n>>m;
    vector<int>a;

    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    a.push_back(1);
    a.push_back(2);
    a.push_back(1);
    a.push_back(3);
    cout<<maxLength(a,2)<<endl;
}