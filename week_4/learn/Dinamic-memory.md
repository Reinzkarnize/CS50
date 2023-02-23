☄️ Dinamic memory allocation ❄️🛎️🏯🚨
 _________________________________
|              Text               |
|_________________________________|
|        Initialized data         |
|        Unitialized data         |
|              Heap               |
|               |                 |
|               |                 |
|               V                 |
|                                 |
|               ^                 |
|               |                 |
|               |                 |
|             Stack               |
|---------------------------------|
|      Environment Variable       |
|_________________________________|


malloc() = request some bytes of DAM by search requested byte of memory from the heap
            and give back address of that memory. IF can't find memory it will return
            NULL

how to use:
- import stdlib.h

- int* px = malloc(4)
                   ^
                   size of bytes data type needed

  or we can use:
- int* px = malloc(sizeof(int))

     ______________________________
    |  byte needed each data type  |
    |------------------------------|
    | int    = 4 bytes             |
    | char   = 1 bytes             |
    | long   = 8 bytes             |
    | float  = 4 bytes             |
    | double = 8 bytes             |
    |______________________________|

// get integer from user
- int x = get_int();

// array of float on the "stack" memory
- float stack_array[x];

// array of float on the "heap" memory
float* heap_array = malloc(x * sizeof(float))


 if we are done with memory, we need to free() it
- free(px)


=============================================
 brakdown:

1. int m;

    🟩
     m

2. int* a;

     🟩
      m

     🟨
      a


3. int* b = malloc(sizeof(int));

    🟩     🟩
     m      |
            |
    🟨     🟨
     a      b

4. a = &m;

   🟩m     🟩
    |       |
    |       |
   🟨      🟨
    a       b

5. a = b;

       m🟩   🟩
            /   \
           /     \
          /       \
         🟨      🟨
          a       b

6. m = 10

        10
         ^
       m🟩   🟩
            /   \
           /     \
          /       \
         🟨      🟨
          a       b

7. *b = m + 2;

        10    12
         ^    ^
       m🟩   🟩
            /   \
           /     \
          /       \
         🟨      🟨
          a       b

8. free(b);

        10
         ^
       m🟩   ⬜
            /   \
           /     \
          /       \
         🟨      🟨
          a       b


