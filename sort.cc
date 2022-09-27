/**
 * COMPLETE:
 *
 * @file sort.cc
 * @author Chloe Albright
 * 
 * @brief Project 4: Sorting library implementation file:
    this program is implemented to perform sorting methods 
	within appropriate time complexities, including: 
	selection_sort: 
	uses findsmallest, time complexity :O(n) linear time 
	uses swap, time complexity :O(1) constant time 
	insetion_sort:
	uses findpos, time complexity :O(n) linear time 
	uses moveup1, time complexity :O(n) linear time 
	merge_sort:
	uses merge_sort recursively,
	uses merge, time complexity :O(n) linear time 
 * @version 0.1
 * @date May 6, 2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sort.h"
#include <utility> // for std::swap(), etc.

/** @brief selection_sort
* finds target element in array and swaps until order is complete.
* @param arr, @param asize, 
* @post sorted array.
*/
template <typename Comparable>
void selection_sort(Comparable arr[], int asize){
	// sort all the info in arr (total size: asize) from smallest to largest.
	int nsort = 0; // size of the sorted section.

	while (nsort < asize){
		int spos = findsmallest(arr, nsort, asize - 1);
		swap(arr, spos, nsort); // interchange the 2 values.
		++nsort;
	}
}//end selection_sort

/** @brief insertion_sort
* takes element in unsorted region and puts it in the correct order in sorted region.
* @param arr, @param asize, 
* @post sorted array.
*/
template <typename Comparable>
void insertion_sort(Comparable arr[], int asize){
	int nsort = 0; // size of the sorted section.

	while (nsort < asize){
		Comparable copy = std::move(arr[nsort]);
		int pos = findpos(arr, copy, nsort);
		// pos is the position for copy.
		// nsort is size of sorted values.

		moveup1(arr, pos, nsort - 1);
		// move data from pos to nsort-1 inclusive.

		arr[pos] = std::move(copy);
		++nsort;
	}
}//end insertion_sort

/** @brief merge_sort
* recursively calls itself until a[] size is 1, then to sorts using merge.
* @param arr = 'a' is an array of 'Items' whose valid elements are between 'start' and 'end', inclusively.
* @param start = start index of range to sort, @param right = end index of range to sort, 
* @param pivot = 'mid' is the position in 'a' in which to divide the array.
* @post sorted array.
*/
template <typename Comparable>
void merge_sort(Comparable a[], int start, int end, int mid){
	if (start >= end) // the array is either empty or contains a single element.
		return;		  // sorting problem already solved. Nothing to do.

	// sort the left portion of the array.
	merge_sort(a, start, mid, (start + mid) / 2);

	// sort the right portion of the array
	merge_sort(a, mid + 1, end, (mid + 1 + end) / 2);

	// combined the two sorted array portions in a single sorted array.
	merge(a, start, end, mid);
}//end merge_sort

/** @brief findsmallest is selection_sort's helper function 
* Returns the position of the smallest Comparable in arr from start to end inclusive
* @pre start <= end O(n) time 
* @param arr = target array to search and find smallest position index, 
* @param start = start of index range, @param end = end of index range, 
* @return index position of smallest value in array portion
*/
template <typename Comparable>
int findsmallest(const Comparable arr[], int start, int end){
	// COMPLETE
	if(start > end){//handles edge case when array size = 0
		return -1;
	}
	int smallest = arr[start];//initialize with first element in portioned array
	int index = start;
	
	for(int i = start;i < end+1; i++){//from start to end inclusive = end+1
		//if current element is < smallest, then update smallest with the new smallest element, 
		//by the end of the loop, index = smallest element's index
		if(arr[i] < smallest){
			smallest = arr[i];
			index = i;
		}		
	}
	return index;

}//end findsmallest

/** @brief swap is selection_sort's helper function
* Swaps the element at position pos1 with the element at position pos2 in arr, using O(1) constant time.
* @param arr = array where swap is performed, @param pos1 @param pos2 = index to access arrat values to swap. 
* @post pos1 and pos2 value's are swapped.
*/
template <typename Comparable>
void swap(Comparable arr[], int pos1, int pos2){
	// COMPLETE
	std::swap(arr[pos1],arr[pos2]); 
	
}//end swap

/** @brief findpos is insertion_sort's helper function 
* Returns the position, between 0 and size, in arr to insert the target value in insertion sort, using O(n) linear time.
* @param arr = array to find position in, @param target = value to insert, @param size = size of arr.
* @returns index to insert target in array.
*/
template <typename Comparable>
int findpos(const Comparable arr[], Comparable target, int size){
	// COMPLETE
	// 1 2 3 4 5 7
	//try to insert 6
	if(size==0){//edge case for empty arr
		return 0;
	}

	for(int i = 0; i < size; i++){
		if(target < arr[i]){
			return i;//return index
		}
		else if(i == size-1){//end of array is reached
			return i+1; 
		}
	}

}//end findpos

/** @brief insertion_sort's helper function 
*	Moves up all data in arr from start to end inclusive one space. O(n) time
* @param arr = array where move takes place, @param start = start range of move, @param end = end range of move, 
* @post data from start to end inclusive is moved up one space.
*/
template <typename Comparable>
void moveup1(Comparable arr[], int start, int end)
{
	// COMPLETED
	if(start > end){//edge case for dealing with 1st item in arr
		return;
	}

	for(int i = end+1; i > start; i--)//move up one from back of array to front
		arr[i] = arr[i-1];
		// 1 2 3 4 5 6 7
		//start is 1 = 2 and end is 4 = 5, from 2 to 5
		//first pass: arr[5] = 5
		//2nd pass: arr[4] =4


}//end moveup1

/** @brief merge_sort's helper function 
	Combines two sorted sub-arrays of arr 
	(i.e., the inclusive intervals [left, pivot] and [pivot+1, right])
    to a single sorted array. O(n) time
* @param arr = array being sorted, @param left = start, @param right = end, 
* @param pivot = middle and end of left sub array.
* @post sorted array.
*/
template <typename Comparable>
void merge(Comparable arr[], int left, int right, int pivot){
	// COMPLETE
	int size = right - left +1;//size of portion to merge
	Comparable temp[size];

	int pos = 0;//position of temp array
	int sizeL = pivot-left+1;//size of Left arr[]
	
	int sizeR = right-pivot;//size of Right arr[]
	
	int i = 0; //index count of Left sub array
	int j = 0; //index count of Right sub array

	if(left>right){//handles edge cases  
		return;
	}
	if(pivot<left){
		return;
	}

	while(i<sizeL && j<sizeR){
		if(arr[i+left] <= arr[j+pivot+1]){
			temp[pos] = arr[i+left];
			i++;
			pos++;
		}
		else{
			temp[pos] = arr[j+pivot+1];
			j++;
			pos++;	
		}
	}
	//edge cases to handle when while loop condition breaks
	while(i<sizeL){
		temp[pos] = arr[i+left];
		i++;
		pos++;
	}

	while(j<sizeR){
		temp[pos] = arr[j+pivot+1];
		j++;
		pos++;
	}

	//for the range 0 to size of the sum of sorted Left & Right sub arrays
	for(int i = 0; i < size; i++){
		arr[left+i] = temp[i];//handles case where left != 0
	}

}//end merge

// Template instantiations. Only ints are supported for now. Do not change these but add more instantiations
// for other types if you like.
template void selection_sort<int>(int[], int);
template int findsmallest<int>(const int[], int, int);
template void insertion_sort<int>(int[], int);
template void merge_sort<int>(int[], int, int, int);
