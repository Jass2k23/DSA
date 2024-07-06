#include <bits/stdc++.h>
using namespace std;

//! Selection Sort
//* O(n*n)
void selectionSort(int arr[], int n)
{ // 13 46 24 52 20 9
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini]) // 9 < 13
                mini = j;
        }
        swap(arr[mini], arr[i]);
    }
}

//! Bubble Sort
//* O(n*n)
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        bool didSwap = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        if (didSwap == false)
            break;
    }
}

//! Insertion Sort
//* O(n*n)
void insertionSort(int arr[], int n)
{ // 14 9 15 12 6 8 13
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

//! Merge Sort
//* O(nlogn), s-> O(n)

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // pushing remaing elements
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        //* low might not initiate from 0, so we r balancing just like we subtract '0' from char to get digit 
        arr[i] = temp[i - low];
    }
}

void MS(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    MS(arr, low, mid);
    MS(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n)
{
    MS(arr, 0, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //* Section Sort
    // selectionSort(arr,n);

    //* Bubble Sort
    // bubbleSort(arr,n);

    //* Insertion Sort
    // insertionSort(arr,n);

    //* Merge Sort
    mergeSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}