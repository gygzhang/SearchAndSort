#include<stdio.h>
#include<stdlib.h>

void print(int *arr,int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

//in one time,find the maximum value in the unsorted area,move it in the front of the sorted area
void bubble_sort(int **arr,int length) {
	//be sure that i start with 1,because j can't equals to length(j compares to j+1 ,array out of boundary)
	for (int i = 1; i < length; ++i) {
		for (int j = 0; j < length-i; ++j) {
			if (*(*arr+j) > *(*arr+j + 1)) {
				int temp = *(*arr + j);
				*(*arr + j) = *(*arr + j + 1);
				*(*arr + j + 1) = temp;
			}
		}
	}
}

void insert_sort(int** arr, int length) {
	//i start with index 1 signify that select a number one by one
		for (int i = 1; i < length; i++) {
			//j equals to i-1 indicate that the arr[i] will
			//compares to arr[0...i-1]
			for (int j = i-1; j >=0; j--) {
				//pay attention here, next arr[j+1]>arr[j] indicate that it's in order
				if (*(*arr + j+1) > *(*arr + j)) break;
				//else , exchange the adjacent two number
				else {
					int temp = *(*arr + j + 1);
					*(*arr + j + 1) = *(*arr + j);
					*(*arr + j) = temp;
				}
			}
		}
}
//find the minimum value in the rest of unsort area,and append it to the backmost of sorted area
void select_sort(int **arr, int length) {
	//record the minimum value and it's index in arr
	int min,index;
	for (int i = 0; i < length; ++i) {
		min = *(*arr + i); index = i;
		for (int j = i+1; j < length; ++j) {
			if (min > *(*arr + j)) {
				min = *(*arr + j); index = j;
			}
		}
		*(*arr + index) = *(*arr + i);
		*(*arr + i) = min;
	}
}

void shell_sort(int **arr, int length) {
	int d = length;
	for (int i = 0; i < length; ++i) {
		d = d / 2;
		for (int  j = 0; j < length&&d>0&&j+d<length; j++)
		{		
			if (*(*arr + j) > *(*arr + j + d)) {
				int temp = *(*arr + j);
				*(*arr + j) = *(*arr + j + d);
				*(*arr + j + d) = temp;
			}
		}
	}
}

void quick_sort(int **arr, int length) {	
	for (int i = 0; i < length; i++) {
		int temp = *(*arr);
		int a=0, b=length;
		while (a!=b) {
			while (1) {
				if (*(*arr + b) < temp) {
					*(*arr + a) = *(*arr + b);
					b--;
					break;
				}
				//a--;
			}

			while (1) {
				if (*(*arr + b) < temp) {
					*(*arr + a) = *(*arr + b);
					a--;
					break;
				}
				//b--;
			}

		}
		quick_sort(arr, a - 1);
		quick_sort(arr+b,length-a);
			
	}
}

int main() {
	int *arr=(int*)malloc(5*sizeof(int));
	/*for (int i = 0; i < 5; i++)
		*(arr + i) = 5 - i;*/
	*(arr + 0) = 4;
	*(arr + 1) = 3;
	*(arr + 2) = 2;
	*(arr + 3) = 1;
	*(arr + 4) = 5;

	print(arr,5);
	//bubble_sort(&arr, 5);
	//insert_sort(&arr, 5);
	//select_sort(&arr,5);
	//shell_sort(&arr, 5);
	quick_sort(&arr, 5);
	print(arr, 5);
	system("pause");
}