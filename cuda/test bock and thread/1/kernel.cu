
#include "cuda_runtime.h"
#include "device_launch_parameters.h"


#include <stdio.h>
#define N (2048*2048)
#define THREADS_PER_BLOCK 512

__global__ void add(int *a, int *b, int *c) {
	int index = threadIdx.x + blockIdx.x * blockDim.x;
	c[index] = a[index] + b[index];
}


int main(void) {
	int *d_a = 0; 
	int *d_b=0;
	int *d_c=0;
	int size = N * sizeof(int);
	const int arraySize = 5;
	const int a[arraySize] = { 1, 2, 3, 4, 5 };
	const int b[arraySize] = { 10, 20, 30, 40, 50 };
	int c[arraySize] = { 0 };
	// Alloc space for device copies of a, b, c
	cudaMalloc((void **)&d_a, size);
	cudaMalloc((void **)&d_b, size);
	cudaMalloc((void **)&d_c, size);
	// Alloc space for host copies of a, b, c and setup input values
	

	// Copy inputs to device
	cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);
	// Launch add() kernel on GPU
	add << <N / THREADS_PER_BLOCK, THREADS_PER_BLOCK >> > (d_a, d_b, d_c);
	// Copy result back to host
	cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);
	printf("{1,2,3,4,5} + {10,20,30,40,50} = {%d,%d,%d,%d,%d}\n",
		c[0], c[1], c[2], c[3], c[4]);

	// Cleanup
	//free(a); free(b); free(c);
	cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
	return 0;
}

