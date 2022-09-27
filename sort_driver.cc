/**
 * COMPLETE:
 *
 * @file sort_driver.cc
 * @author Chloe Albright
 * 
 * @brief Project 4: Sorting library tester file:
	this program is implemented to test sorting methods and helper functions, including:
	selection_sort, 
	findsmallest, 
	swap, 
	insetion_sort,
	findpos,
	moveup1,
	merge_sort,
	merge.
 * @version 0.1
 * @date May 6, 2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sort.cc" // include the sort library

#include <iostream>
using namespace std;

int main(){
	
	// COMPLETE: Test sorted library.
	
	
	//Test int findsmallest(const Comparable arr[], int start, int end)
	int arr[8] = {7,8,2,1,4,3,6,5}; //count is 1 index is 0
	int size = (sizeof(arr)/sizeof(arr[0]));
	//cout<<size<<" "<<endl;
	//7 8 2 1 4 3 6 5
	//range 0-3 = 7 8 2 1
	/*
	int smallest = findsmallest(arr, 0, 3);
	cout<< smallest << endl;
	*/

	//Test void swap(Comparable arr[], int pos1, int pos2)
	
	//swap(arr, 0, 2); //should output 
	//cout<<arr[0]<<" "<<arr[2]<<endl;
	

	//Test int findpos(const Comparable arr[], Comparable target, int size)
	/*
	cout<<findpos(arr, 8, 8)<<endl;//if 2nd param = 1, output 3. if 5, output = 7
	*/

	//Test void moveup1(Comparable arr[], int start, int end)
	/*
	int move_arr[8] = {1,2,3,4,5,6,7,8};
	moveup1(move_arr, 2, 6); //output: 1 1 2 3 4 5 7 8, end + 1 is overwritten
	//if 2nd param is 2, output: 1 2 3 3 4 5 7 8
	for(int i : move_arr)
		cout<< i <<" ";
	*/

	//Test selection sort void selection_sort(Comparable arr[], int asize)
	//selection_sort(arr, size); 
	//original 7 8 1 2 3 5 4 6
	//outputs  8 1 2 3 4 7 6 5
	/*
	for(int i : arr)
		cout<< i <<" ";
	
	cout<< endl;
	*/
	
	
	//Test insertion_sort(Comparable arr[], int asize)
	/*
	insertion_sort(arr, size);//uses findpos and moveup1
	for(int i : arr)
		cout<< i <<" ";
	
	cout<< endl;
	*/

	//Test void merge(Comparable arr[], int left, int right, int pivot)
	//with void merge_sort(Comparable a[], int start, int end, int mid)
	
	merge_sort(arr, 0, 7, 3);
	for(int i : arr)
		cout<< i <<" ";
	
	cout<< endl;	
	

}
