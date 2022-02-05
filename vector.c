//How to create a dynamic resizable array (vector) data strucutre in C
// (c) Max Goren 2022 via MIT License
#include <stdio.h> 
#include <stdlib.h> 
 
//define our vector data struture 
typedef struct _Vector { 
 int N;	    //number of elements in the vector 
 int maxN;   //maximum element vector can hold 
 int* array;  //array to hold the elements 
} Vector; 
 
//helper function to create the vector 
Vector* createVector(int size)  
{ 
 //allocate memory on the heap for the vector 
 Vector* newVector = (Vector*)malloc(sizeof newVector); 
 //set contents to zero 
 newVector->N = 0; 
 //set initial maximum size of the container 
 newVector->maxN = size; 
 //allocate array on the heap 
 newVector->array = (int*)malloc(sizeof(int) * size); 
 //return the whole enchillada. 
 return newVector; 
} 
 
//retrieve a value from the vector 
int vectorGetValue(Vector* vec, int idx_pos) 
{ 
 //make sure index provided doesnt underflow or overflow array 
 if (idx_pos < vec->N && idx_pos >= 0) 
 return vec->array[idx_pos]; 
} 
 
//add an element to the vector, note the pointer to pointer 
//of the first argument 
void vectorPushBack(Vector** vec, int value) 
{  
 //Is there room in the vector? 
 if ((*vec)->N + 1 == (*vec)->maxN) 
 { 
 printf("Resizing.\n"); 
 //copy current array to temp 
 int *temp = (*vec)->array; 
 //allocate a new array double the size of the old 
 int* next = (int*)malloc((*vec)->maxN * 2); 
  //copy old array contents  to new array 
 for (int i = 0; i < (*vec)->N; i++) 
 { 
 next[i] = temp[i]; 
 } 
  //deallocate old array 
 free(temp); 
 //and assign the new array to the vector 
 (*vec)->array = next; 
 //and double the max size of the vector until the next resize 
 (*vec)->maxN *= 2; 
 } 
 //add the value at the end of the array. 
 (*vec)->array[(*vec)->N++] = value; 
} 
 
//return the number of elements currently in the vector 
int vectorSize(Vector* vec) 
{ 
 return vec->N; 
} 
 
//a little tester/driver for our vector DS 
int main() 
{ 
 Vector* myVec = createVector(10); 
 for (int i = 0; i < 30; i++) 
 { 
 vectorPushBack(&myVec, i); 
 } 
 //you can retrieve info this away 
 for (int i = 0; i < myVec->N; i++) 
 printf("%d ", myVec->array[i]); 
 printf("\n"); 
 //or this way 
 for (int i = 0; i < vectorSize(myVec); i++) 
 printf("%d ", vectorGetValue(myVec, i)); 
 printf("\n"); 
 return 0; 
}
