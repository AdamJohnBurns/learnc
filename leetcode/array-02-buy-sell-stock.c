/*
https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/564/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

/*
Obvious solution:
Until end
    Find the lowest in the row.
    Then find the next highest available.
Poor performance: O(n^2)

Can we use sorting and hash tables
Sort to get lowest/highest values, store the original sort order in a new array of the same length
Then work from opposite ends of the array to calculate the best possible value
O(n)
*/

#include <stdio.h>
#include <stdbool.h>

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

// horrible results!
int linearStupid(int *arr, int size)
{
    int profit = 0;
    bool isBuying = true;
    int currentValue = 0;
    int lastValue = 0;

    for (int i = 0; i < size; i++)
    {
        currentValue = arr[i];
        printf("isBuying: %d, currentValue: %d, lastValue: %d\n", isBuying, currentValue, lastValue);

        if (isBuying && currentValue > lastValue)
        {
            profit -= currentValue;
            printf("Bought for %d, profit is now %d.\n", currentValue, profit);
            lastValue = arr[i];
            isBuying = false;
        }
        else if (!isBuying && currentValue < lastValue)
        {
            profit += currentValue;
            printf("Sold for %d, profit is now %d.\n", currentValue, profit);
            lastValue = arr[i];
            isBuying = true;
        }
    }

    return profit;
}

int maxProfit(int *prices, int pricesSize)
{
    return linearStupid(prices, pricesSize);
}

int main (int argc, char *argv[])
{
    // expected: 7
    int arraySize = 6;
    int array[] = {7,1,5,3,6,4};

    printArray(">>> Provided", array, arraySize);

    printf(">>> Final profit: %d\n", maxProfit(array, arraySize));

    return 0;
}
