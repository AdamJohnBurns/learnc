/*
previous attempt spent time allocating memory for hash table, inserting data
into that structure, etc.
instead, a simple sort to just move the items in place would work
we know the array values are sorted, so all we need to do is
    find first item, keep iterating until we find a higher value
    when found, swap the last known spot and this one 
    then ignore this one and keep going

    1222334
    1234

    worst case O(n)
    way less operations than previous attempt

    accepted answer!
*/

#include <stdio.h>

void printArray(char *label, int *array, int size)
{
    printf("%s: [ ", label);
    char *divider;
    char comma[] = ", ";
    char nocomma[] = " ";
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
            divider = comma;
        else
            divider = nocomma;
        printf("%d%s", array[i], divider);
    }
    printf("]\n");
}

int removeDuplicates(int *nums, int numsSize) 
{
    int lastChangedIndex = 0;

    if (nums == NULL || numsSize == 0) return 0;

    for (int currentIndex = 0; currentIndex < numsSize; currentIndex++)
    {
        printf("%d > %d?\n", nums[currentIndex], nums[lastChangedIndex]);
        if (nums[currentIndex] > nums[lastChangedIndex])
        {
            lastChangedIndex++;
            nums[lastChangedIndex] = nums[currentIndex];
        }
    }

    return lastChangedIndex + 1;
}

int main(int argc, char *argv[])
{
    int len = 7;
    int array[] = {-1, 0, 0, 0, 0, 3, 3};

    printArray(">>> Provided", array, len);
    len = removeDuplicates(array, len);
    printArray(">>> Returned", array, len);
}
