// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [Yun-Kuan Lin]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for (int i = 1; i < data.size(); i++){
        int flag = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > flag){
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = flag;
    }
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    SortSubVector(data, 0, data.size() - 1);
}

// Sort subvector
void SortTool::SortSubVector(vector<int>& data, int low, int high) {
    // Function : Sort subvector
    // TODO : Please complete SortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if(low != high){
        SortSubVector(data, low, (low + high) / 2);
        SortSubVector(data, (low + high) / 2 + 1, high);  
        Merge(data, low, (low + high) / 2, (low + high) / 2 + 1, high);  
    }

}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    vector<int> v;
    int start = low;
    int end = high;
    while (low <= middle1 && middle2 <= high){
        if (data[low] <= data[middle2]){
            v.push_back(data[low]);
            low++;
        }
        else{
            v.push_back(data[middle2]);
            middle2++;
        }
    }
    while (low <= middle1){
    	v.push_back(data[low]);
    	low++;
	}
	while (middle2 <= high){
		v.push_back(data[middle2]);
		middle2++;
	}
    int i = 0;
    for (int item = start; item <= end; item++){
        data[item] = v[i];
        i++;
    }

}

//Max heapify
void SortTool::Max_Heapify(vector<int>& data, int root, int n) {
    // Function : Make tree with given root be a max-heap 
    //            if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    if (2 * root + 1 <= n){
        int largerchild = 2 * root + 1;
        if (2 * root + 2 <= n){
            int rightchild = 2 * root + 2;
            if(data[rightchild] > data[largerchild])
                largerchild = rightchild;
        }
        if (data[root] < data[largerchild]){
        	int temp = data[root];
            data[root] = data[largerchild];
            data[largerchild] = temp;
            int next_root = largerchild;
            Max_Heapify(data, next_root, n);
        }
    }
}

//Build max heap
void SortTool::Build_Max_Heap(vector<int>& data) {
    // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete Build_Max_Heap code here
    for (int i = data.size()/2 - 1; i >= 0; i--){
        Max_Heapify(data, i, data.size()-1);
        }
}
// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    Build_Max_Heap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        int temp = data[i];
        data[i] = data[0];
        data[0] = temp;
        Max_Heapify(data, 0, i-1);
    }
}

