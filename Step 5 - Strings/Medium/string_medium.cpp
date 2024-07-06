#include <bits/stdc++.h>
using namespace std;

//! Sorting Characters by Frequncy
string sortByFrequency(int n, string& s)
{
	unordered_map<char,int>m;
	for(int i=0;i<n;i++){
		m[s[i]]++;
	}
	vector<char>elements;
	for(auto i:m)
		elements.push_back(i.first);
	sort(elements.begin(),elements.end(),[&](char a, char b){
		return m[a] > m[b];
	});
	string ans;
	for(char i:elements){
		ans += string(m[i],i);
	}
	return ans;
}



//! Roman to Integer
int romanToInt(string s) {
    unordered_map<char, int> m = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int n = s.size();
    if(n == 1){
        return m[s[0]];
    }
    int i=0,j=1;
    int result = 0;
    for(int i=0;i<n-1;i++){
        char el1 = s[i];
        char el2 = s[i+1];
        int val1 = m[el1];
        int val2 = m[el2];
        if(val1>=val2){
            result += val1;
        }
        else{
            result -= val1;
        }
    }
    result += m[s[n-1]];
    return result;
}



//! Implement Atoi Func
int createAtoi(string s) {
    // Write your code here.
    int n = s.size();
    bool neg = false;
    int i = 0;
    long result = 0;
    while(i<n && s[i] == ' '){
        i++;
    }
    if(s[i] == '-'){
        neg = true;
        i++;
    }
    else if(s[i] == '+'){
        i++;
    }
    while(i<n && (s[i]>47 && s[i]<58)){
        result = result * 10 + (s[i] - '0');
        if(result > INT_MAX && neg)
            return INT_MIN;
        else if(result > INT_MAX)
            return INT_MAX;
        i++;
    }
    if(neg)
        return result * (-1);
    return result;
}



//! Count with K Different Characters
//* Brute O(n^3)
bool check(vector<char> unique_elements,char el){
    for(int i=0;i<unique_elements.size();i++){
        if(unique_elements[i] == el)
            return true;
    }
    return false;
}

int countSubStrings(string s, int k) 
{
    int n = s.size();
    if(n == 0)
        return 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        vector<char>unique_elements;
        
        for(int j=i;j<n;j++){
            char el = s[j];
            if(!check(unique_elements, el)){
                unique_elements.push_back(el);
            }
            if(unique_elements.size() == k){
                cnt++;
            }
        }
    }
    return cnt;
}



//! Sum of Beauty of all Substrings
int maxFreq(int arr[]){
	int freq = 1;
	for(int i=0;i<26;i++){
		if(arr[i] != 0){
			if(arr[i] > freq)
				freq = arr[i];
		}
	}
	return freq;
}

int minFreq(int arr[]){
	int freq = INT_MAX;
	for(int i=0;i<26;i++){
		if(arr[i] != 0){
			if(arr[i] < freq)
				freq = arr[i];
		}
	}
	return freq;
}

int sumOfBeauty(string s) {
	int n = s.size();
	int beauty = 0;
	int max = 0, min = 0, ans = 0;
	for(int i=0;i<n;i++){
		int hash[26] = {0};
		for(int j=i;j<n;j++){
			hash[s[j]-'a'] += 1;

			max = maxFreq(hash);
			min = minFreq(hash);

			beauty = max - min;

			ans += beauty;
		}
	}
	return ans;
}




//! Reverse every Word in a String



int main(){

}