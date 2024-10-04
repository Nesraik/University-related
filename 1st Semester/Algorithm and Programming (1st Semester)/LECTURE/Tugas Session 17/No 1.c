//NO 1

/*
-void*malloc(size_t size);
Allocates the requested memory and returns pointer to it

-void*calloc(size_num,size_t size);
Allocates the requested memory and returns a pointer to it. 
The difference between malloc and calloc is that malloc does not set the memory to zero 
where as calloc sets allocated memory to zero.

-void*realloc(void*memblock, size_t size);
Resize the memory block pointed to by memblock that was previously allocated to malloc or calloc

-void free(void*memblock);
free/deallocte memory previously from a call to malloc, callor or realloc fucntion/syntax
