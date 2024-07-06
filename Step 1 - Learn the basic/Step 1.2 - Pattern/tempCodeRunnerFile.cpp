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