#include <bits/stdc++.h>
using namespace std;


//! Row with maximum 1s
//* Have to travese in row, so optimise the traversal in columns using binary 
int numberOf1s(vector<int>row, int m){
    int low = 0, high = m-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(row[mid] == 0){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return m-low;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int count = 0;
    int index = -1;
    for(int i=0;i<n;i++){
        int value = numberOf1s(matrix[i],m);
        if(value > count){
            count = value;
            index = i;
        }
    }
    return index;
}




//! Search in 2D Array
//* Flatten the 2D array into 1D array
//* O(log(n*m))
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = n*m-1;
    while(low<=high){
        int mid = (low+high)/2;
        //* converting 1D co-ordinates into 2D co-ordinates
        int row = mid/m;
        int col = mid%m;

        if(mat[row][col] == target)
            return true;
        else if(mat[row][col] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return false;
}




//! Find Peak Element
int max_element_index(vector<vector<int>> &mat,int n,int m,int mid){
    int maxElement = INT_MIN;
    int maxElement_row = -1;
    for(int i=0;i<n-1;i++){
        if(mat[i][mid] > maxElement){
            maxElement = mat[i][mid];
            maxElement_row = i;
        }
    }
    return maxElement_row;
}

vector<int> findPeakGrid(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m-1;
    while(low<=high){
        int mid = (low+high)/2;
        int row = maximum(mat[][mid]);
        int left = mid - 1 >= 0 ? mat[row][mid-1] : -1;
        int right = mid + 1 < m ? mat[row][mid+1] : -1;
        if(mat[row][mid] > mat[row][mid-1] && mat[row][mid] > mat[row][mid+1])
            return { row, mid };
        else if(mat[row][mid] < left)
            high = mid-1;
        else
            low = mid+1;
    }
    return { -1, -1 };
}



int main(){

}