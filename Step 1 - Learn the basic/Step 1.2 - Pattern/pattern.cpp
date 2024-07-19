#include<bits/stdc++.h>
using namespace std;

	//   *
    //  ***
    // *****
	void print1(int n){
		for(int i=0;i<n;i++){
				for(int j=0;j<n-i-1;j++){
					cout<<" ";
				}
				for(int j=0;j<2*i+1;j++){
					cout<<"*";
				}
				
				cout<<endl;
			}
	}


    // *****
    //  ***
    //   *
	void print2(int n){
		for(int i=n;i>0;i--){
			for(int j=0;j<n-i;j++){
				cout<<" ";
			}
			for(int j=2*i-1;j>0;j--){
				cout<<"*";
			}
			cout<<endl;
		}
	}



	//   *
	//  ***
	// *****
	//  ***
	//   *
	void print3(int n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				cout<<" ";
			}
			for(int j=0;j<2*i+1;j++){
				cout<<"*";
			}
			
			cout<<endl;
		}
		for(int i=n;i>0;i--){
			for(int j=0;j<n-i;j++){
				cout<<" ";
			}
			for(int j=2*i-1;j>0;j--){
				cout<<"*";
			}
			cout<<endl;
		}
	}


	// *
	// **
	// ***
	// **
	// *
	void print4(int n){
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				cout<<"*";
			}
			cout<<endl;
		}
		for(int i=n-1;i>0;i--){
			for(int j=0;j<i;j++){
				cout<<"*";
			}
			cout<<endl;
		}
	}


	//* 1
	//* 0 1
	//* 1 0 1
	//* 0 1 0 1
	void print5(int n){		// n=4
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				if(i==j){
					cout<<1<<" ";
				}
				else if((i+j)%2 == 0){
					cout<<1<<" ";
				}
				else{
					cout<<0<<" ";
				}
			}
			cout<<endl;
		}
	}


	//! 1      1
	//! 12    21
	//! 123  321
	//! 12344321
	void print6(int n){		// n = 4
		int gap = 2*(n-1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				cout<<j;
			}
			for(int j=1;j<=gap;j++){
				cout<<" ";
			}
			gap-=2;
			for(int j=i;j>=1;j--){
				cout<<j;
			}
			cout<<endl;
		}
	}


	//* 1   1
	//* 12  21
	//* 123 321
	//* 12344321
	void print7(int n){
		int gap = n-1;
		for(int i=0;i<n;i++){
			for(int j=1;j<=i+1;j++){
				cout<<j;
			}
			for(int j=gap;j>0;j--){
				cout<<" ";
			}
			gap--;
			for(int j=i+1;j>0;j--){
				cout<<j;
			}
			cout<<endl;
		}
	}

	//* 1
	//* 2 3
	//* 4 5 6
	//* 7 8 9 10
	void print8(int n){
		int num = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				num++;
				cout<<num<<" ";
			}
			cout<<endl;
		}
	}

	//* A
	//* A B 
	//* A B C 
	//* A B C D
	void print9(int n){			// n = 4
		for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<char('A' + j - 1)<<" ";
		}
		cout<<endl;
	}
	}

	//* A B C D
	//* A B C
	//* A B  
	//* A 
	void print10(int n){
		for(int i=n;i>=1;i--){
			int num = 'A';
			for(int j=i;j>=1;j--){
				cout<<char(num)<<" ";
				num++;
			}
			cout<<endl;
		}
	}


	//* D C B A
	//* C B A
	//* B A 
	//* A
	void print10_(int n){
		for(int i=n;i>=1;i--){
			for(int j=i;j>=1;j--){
				cout<<char('A' + j - 1)<<" ";
			}
			cout<<endl;
		}
	}


	//! 	  A
    //!     A B A
	//!   A B C B A
	//! A B C D C B A
	void print11(int n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				cout<<" ";
			}

			char ch = 'A';
			int breakpoint = (2*i+1)/2;
			for(int j=1;j<=2*i+1;j++){
				cout<<ch;
				if(j<=breakpoint)ch++;
				else ch--;
			}
			cout<<endl;
		}
	}

	//! E
	//! D E 
	//! C D E 
	//! B C D E 
	//! A B C D E
	void print12(int n){
		for(int i=0;i<n;i++){
			char ch = 'A';
			int num = n-i-1;
			ch+=num;
			for(int j=0;j<=i;j++){
				cout<<ch<<" ";
				ch++;
			}
			cout<<endl;
		}
	}

	//* D
 	//* D C  
	//* D C B 
	//* D C B A
	void print13(int n){
		for(int i=0;i<n;i++){
			char ch = 'A';
			ch+=n-1;
			for(int j=0;j<=i;j++){
				cout<<ch<<" ";
				ch--;
			}
			cout<<endl;
		}
	}

	//! ******
	//! **  **
	//! *    *
	//! *    *
	//! **  **
	//! ******
	void print14(int n){
		for(int i=n;i>0;i--){
			int space = 2*(n-i);
			for(int j=0;j<i;j++){
				cout<<"*";
			}
			for(int j=0;j<space;j++){
				cout<<" ";
			}
			for(int j=0;j<i;j++){
				cout<<"*";
			}
			cout<<endl;
		}
		for(int i=0;i<n;i++){
			int space = 2*(n-i-1);
			for(int j=0;j<=i;j++){
				cout<<"*";
			}
			for(int j=0;j<space;j++){
				cout<<" ";
			}
			for(int j=0;j<=i;j++){
				cout<<"*";
			}
			cout<<endl;
		}
	}

	// *         *
	// * *     * *
	// * * * * * *
	// * *     * *
	// *         *
	void print15(int n){
		for(int i=0;i<n;i++){
			int space = 2*(n-1-i);
			for(int j=0;j<=i;j++){
				cout<<"* ";
			}
			for(int j=0;j<space;j++){
				cout<<"  ";
			}
			for(int j=0;j<=i;j++){
				cout<<"* ";
			}
			cout<<endl;
		}
		
		int gap = 2;
		for(int i=n-1;i>0;i--){
			for(int j=0;j<i;j++){
				cout<<"* ";
			}
			for(int j=0;j<gap;j++){
				cout<<"  ";
			}
			for(int j=0;j<i;j++){
				cout<<"* ";
			}
			cout<<endl;
			gap+=2;
		}
	}


	// ****
	// *  *
	// *  *
	// ****
	void print16(int n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((i==0 || j==0) || (i==n-1 || j==n-1)){
					cout<<"*";
				}
				else cout<<" ";
			}
			cout<<endl;
		}
	}


	//! 4444444
	//! 4333334
	//! 4322234
	//! 4321234
	//! 4322234
	//! 4333334
	//! 4444444
	void print17(int n){
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<2*n-1;j++){
				int top = i;
				int left = j;
				int right = 2*n-2-j;
				int bottom = 2*n-2-i;
				cout<<n-min(min(top,bottom),min(left,right));
			}
			cout<<endl;
		}
	}


int main(){
	int n;
	cin>>n;
	print2(n);
	
	
}