#include<stdlib.h>
#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NOT -1

int input[] = { 23, 99, 100, 2, 10, 9, 17, 0, 8, 11, 4, 3 };
int input_length = 12;

struct item
{
    int idx;
    int n;
};

struct item **get_items(int *nums, int size)
{
    struct item *items[size];
    struct item **res = items;
    
    for (int i = 0; i < size; ++i)
    {
        items[i] = malloc(sizeof(struct item));
        items[i]->n = nums[i];
        items[i]->idx = i;
    }
    return res;
}

void swap(struct item **items, int i, int j)
{
    struct item *temp = NULL;

    temp = items[i];
    items[i] = items[j];
    items[j] = temp;
}

void qsort_(struct item **items, int left, int right)
{
    int i, last;
    void swap(struct item **items, int i, int j);

    if (left >= right)
        return;

    swap(items, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; ++i)
        if (items[left]->n > items[right]->n)
            swap(items, ++last, i);
    swap(items, left, last);
    qsort_(items, left, last-1);
    qsort_(items, last + 1, right);
}

int binsearch(int* arr, int size, int target)
{
    int begin, end, mid;
    begin = 0, end = size, mid = size/2;
    
    while (target != arr[mid] && begin < mid)
    {
        if (target > arr[mid])
        {
            begin = mid + 1;
            mid = (end - begin)/2;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
            mid = (end - begin)/2;
        }
    }
    if (target == arr[mid])
        return mid;
    else 
        return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int t;
    int *res = malloc(sizeof (int)*2);
    int binsearch(int* arr, int size, int target);
    
    for (int i = 0, j; i < numsSize; ++i)
    {
        t = target - nums[i];
        
        if ((j = binsearch(nums, numsSize, t)) != NOT
           && j != i)
        {
            *res = i;
            *(res+1) = j;
            *returnSize = 2;
            return res;
        }
    }
    return NULL;
}

int main(void)
{
    struct item **get_items(int *nums, int size);
    void qsort_(struct item **items, int left, int right);

    for (int i = 0; i < input_length; ++i)
        printf("%d ", input[i]);
    printf("\n");

    struct item **items = get_items(input, input_length);

    for (int i = 0; i < input_length; ++i)
        printf("%d %d\n", i, items[i]->n);

    for (int i = 0; i < input_length; ++i)
        printf("%d %d\n", i, items[i]->n);



}
