#include <bits/stdc++.h>
using namespace std;

int countDigits(int n){
    int ans=0;
    int n_copy = n;
    while(n_copy>0){
        int temp = n_copy%10;
        if(temp==0){
            n_copy/=10;
            continue;
        }
        else{
            if(n%temp==0)ans++;
            n_copy/=10;
        }
    }
    return ans;
}


//! Reverse Bits
long long unsigned int reverseBits(int n){
    string binary = bitset<32>(n).to_string();
    reverse(binary.begin(),binary.end());
    return stol(binary,0,2);
}

//* Reverse Integer, LC
int revInterger(int n){
    bool negative = false;
    if(n<0) negative = true;
    int num_magnitude = abs(n);
    long int ans = 0;
    while(num_magnitude>0){
        int temp = num_magnitude%10;

        //? By checking ans > INT_MAX/10, the code ensures that multiplying ans by 10 won't exceed the maximum limit before adding the next digit. If this condition is met, it means that adding the next digit would lead to an overflow.
        
        if(ans > INT_MAX/10 ||  ans<INT_MIN/10)     return 0;

        ans = ans * 10 + temp;
        num_magnitude/=10;
    }
    if(negative)    ans = -ans;
    return ans;
}

// palindrome
bool isPalindrome(int n){
    int n_copy = n;
    long int ans=0;
    while(n_copy>0){
        int temp = n_copy % 10;
        ans = ans * 10 + temp;
        n_copy/=10;
    }
    if (ans == n)  return true;
    else    return false;
}


//! GCD
int calcGCD(int n, int m){
    // int iterations = min(n,m);
    // int gcd = 0;
    // for(int i=1;i<=iterations;i++){
    //     if((n%i == 0) && (m%i == 0)){
    //         gcd=i;
    //     }
    // }
    // return gcd;

    //! making it optimal(time complexity - log(N))
    while(n!=0 && m!=0){
        if(n>m)     n = n%m;
        else        m = m%n;
    }
    if(n==0)    return m;
    else        return n;
} 

//! Armstrong
bool checkArmstrong(int n){
    int n_copy = n;
    int num=0;
    string numStr = to_string(n);
    int power = numStr.length();

    while(n_copy>0){
        int temp = n_copy%10;
        num+=pow(temp,power);
        n_copy/=10;
    }

    if(num==n)      return true;
    else        return false;
}

//! Sum of Divisors
// int sumOfAllDivisors(int n){
//     int ans = 0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             if(i%j==0)      ans+=j;
//         }
//     }
//     return ans;
// }

//! optimal case using root 
    // int calcDivisor(int n){
    //     int sum = 0;
    //     for(int i=1;i<=sqrt(n);i++){
    //         if(n%i == 0){
    //             sum+=i;
    //             if(i!=n/i)  sum+=n/i;
    //         }
    //     }
    //     return sum;
    // }

    // int sumOfAllDivisors(int n){
    //     int sumOfAllDivisors = 0;
    //     for(int i=1;i<=n;i++){
    //         sumOfAllDivisors+=calcDivisor(i);
    //     }
    //     return sumOfAllDivisors;
    // }

//! best method to find sum of all divisor
int sumOfAllDivisors(int n){
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=(n/i) * i;
    }
    return sum;
}

// Prime no.
bool isPrime(int n)
{
    if(n==1)    return false;
	for(int i=2;i<n;i++){
		if(n%i == 0){
			return false;
		}
		else	return true;
	}
}

int main(){
    int n;
    cin>>n;

    cout<<sumOfAllDivisors(n)<<endl;
}