
/*
    0. clarify, make assumptions
        one array, only ints (not floats), always one solution, no repeating elements for result
        items are in lowest > highest order
 
    1. strategys
        a) brute force
            iterate over each element, and then again to find value that matches
            bad performance, O(n^2)
            
        b)
            calculate in one iteration by ruling out what it can't be
            target = x + y
            find y, 9 = 5 + 4
            
            LOOP find largest number below target
                LOOP start at beginning and linear search for matching number
                    IF found, return result
            
        c) TODO use hashmap
    
    2. big picture algorithm
        a)
            LOOP item1
                LOOP item2
                    IF item1 + item2 = target
                        SAVE item1, item2
                        BREAK
    
        b)
            [2,7,11,15], target 9
            LOOP 15 > 9
                11 > 9
                7 > 9 NOPE
                    LOOP 2 + 7 = 9? 
                        YUP!
                
                
    3. test
        a)
            [1,2,3], target 4
            LOOP 1
                LOOP 1, 1 + 1 = 4?
                LOOP 2, 1 + 2 = 4?
                LOOP 3, 1 + 3 = 4? 
                    SAVE 1, 4
                
    4. implement
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    printf("Hello world\n");

    // this allocates an empty array in the heap at runtime
    // result points to the address of the allocated heap space
    // use malloc to determine size of bytes needed
    int *result = (int *)malloc(sizeof(int) * 2);

    // always check memory was allocated ok
    if (result == NULL)
        printf("Error allocating memory");

    // memory is allocated, but is by default just garbage.
    // need to initialise it
    printf("Garbage memory: %d, %d\n", result[0], result[1]);

    result[0] = 0;
    result[1] = 0;
    // result[2] = 0; // this is out of bounds of allocated amount, will error

    // memory now initialised ok
    printf("Initialised memory: %d, %d\n", result[0], result[1]);

    // now implement the algorithm

    // a) brute force
    /*
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            printf("Comparing %d + %d = %d? ", nums[i], nums[j], target);
            if (nums[i] + nums[j] == target) {
                printf("Found match!\n");
                result[0] = nums[i];
                result[1] = nums[j];
                return result;
            } else {
                printf("...nope\n");
            }
        }
    }
    */

    // b)
    for (int i = numsSize - 1; i >= 0; i--)
    {
        if (nums[i] < target)
        {
            printf("Found number %d, less than target %d\n", nums[i], target);
            for (int j = 0; j < i; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    printf("Found match of %d + %d = %d\n", nums[j], nums[i], target);
                    result[0] = nums[j];
                    result[1] = nums[i];
                    return result;
                }
                else
                {
                    printf("No match for %d\n", nums[j]);
                }
            }
        }
        else
        {
            printf("Number %d is too big!\n", nums[i]);
        }
    }

    printf("Goodbye world\n");

    return result;
}
