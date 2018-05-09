/**
@file
OOP spring2016 assignment 1.
A program that sorts integers which are randomly generated in range of 10 to 100000000
Program includes 3 different sorting algoritms; Merge sort, Bubble sort and Selection sort

@author
Name: Abdullah Enes Keskin
Student no: 16011100
Date: 30/10/2016
E-Mail: aekeskin96@gmail.com
Compiler used: GCC 4.9.2 64bit
IDE: Dev-C++
Operating System Windows 10
Ram: 8GB DDR3 1600MHz
CPU: Intel(R) Core(TM) i5-4210M CPU @ 2.60GHz
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void bubblesort(int *array,int N);
void selectionsort(int *array,int N);
void mergesort(int *array, int N);
void split(int *temp,int begin,int end,int *array);
void merge(int *array,int begin,int mid,int end,int *temp);
/**
	Main function reads the inputs and prints the results
*/
int main() {
	int *array,N,i,j,M,s,m;
	printf("Enter the N:\n");
	scanf("%d",&N); //N is the size of array
	if(N<=0){
		printf("Wrong input of N");
		return 0;
	}
	array = (int*)malloc(N*sizeof(int));
	printf("Enter the M:\n");
	scanf("%d",&M); //M is the number of resort
	if(M<10){
		printf("M should be bigger than 9");
		return 0;
	} 
	printf("Select the Sorting Algorithm:\n1: Bubble Sort\n2: Selection Sort\n3: Merge Sort\n");
	scanf("%d",&s);	//s is the selection
	if(s<1||s>3){
		printf("Wrong selection");
		return 0;
	}
	clock_t t;
	t = clock();
	for(m=0;m<M;m++){
		for(i=0; i<N;i++)
			array[i]=11+((rand() ^ (rand()<<15))  % 999999989); 
			//This generates integers 10 to 1000000000 normally rand() returns a value ranged 0 to 326767
			//to generate to 1000000000 had to shift a rand() value for 15 bits 
			//this way it is not exacly uniformed evenly but it is the best I got
			//rand()*rand() wouldn't generate ints which are primary and bigger than 32767
	//	for(i=0; i<N;i++)
	//		printf("%d: %d\n",i,array[i]);
		printf("\nSorting: ");
		switch(s){
			case 1:
				printf("Bubble Sort\n");
				bubblesort(array,N);
				break;
			case 2:
				printf("Selection Sort\n");
				selectionsort(array,N);
				break;
			case 3:
				printf("Merge Sort\n");
				mergesort(array,N);
				break;
			default:
				printf("Wrong selection\n");
				return 1;
		}
		for(i=0; i<N;i++)
			printf("%d: %d\n",i,array[i]);
		printf("\n");
		
	}	
	t = clock() - t;
	printf("Run time: %f seconds.",((float)t/CLOCKS_PER_SEC));
	return 0;
}
/**
	function which sorts the given array using bubble sort technique
	@param array array which contains the integers to sort
	@paran N size of array
*/
void bubblesort(int *array,int N){
	int i,j,temp;
	for(i=0;i<N-1;i++)
		for(j=i+1;j<N;j++)
			if(array[i]>array[j]){
				temp=array[i];
				array[i] = array[j];
				array[j]=temp;
			}
				
}
/**
	function which sorts the given array using selection sort technique
	@param array array which contains the integers to sort
	@paran N size of array
*/
void selectionsort(int *array,int N){
	int i,j,temp;
	for(j=0; j<N-1;j++){
		int iMin = j;
		for(i=j+1;i<N;i++)
			if(array[i]<array[iMin])
				iMin=i;
		if(iMin!=j){
			temp=array[j];
			array[j]=array[iMin];
			array[iMin]=temp;
		}
	}
}
/**
	function which sorts the given array using selection sort technique
	@param array array which contains the integers to sort
	@paran N size of array
*/
void mergesort(int *array, int N){
	int *temp,i;
	temp= (int*)malloc(N*sizeof(int)); //temp is the work array
	for(i=0;i<N;i++)
		temp[i]=array[i];
	split(temp,0,N,array);
	
}
/**
	function Sort the given run of array using temp as a source.
	@param temp which contains a copy of array 
	@param begin beginning of the array which is to be sorted
	@param end end of the array which is to be sorted
	@param array array which contains the integers to sort
*/
void split(int *temp,int begin,int end,int *array){
	if((end-begin)<2)	//if run size ==1 
		return;			//considers it sorted
	int mid=(end+begin)/2; //mid is the mid pont of array
	split(array,begin,mid,temp); //sort of the left run
	split(array,mid,end,temp);  // sort of the right run
	// merge the resulting runs from array temp into array
	merge(temp,begin,mid,end,array);
}
/**
	function which merges the array to finilize the merge sort
	@param array array which contains the integers to sort	
	@param begin beginning of the array which is to be merged
	@param mid middle of the array which is to be merged
	@param end end of the array which is to be merged
	@param temp which contains a copy of array 
*/
void merge(int *array,int begin,int mid,int end,int *temp){
	int i=begin, j=mid,k;
	for(k=begin;k<end;k++){
		if(i<mid&&(j>=end||array[i]<=array[j])){
			temp[k]=array[i];
			i=i+1;
		}else{
			temp[k]=array[j];
			j=j+1;
		}
	}
}
