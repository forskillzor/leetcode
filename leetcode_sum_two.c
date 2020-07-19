#include<stdlib.h>
#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NOT -1

struct item
{
    int idx;
    int n;
};

struct item **get_items(int *nums, int size)
{
    struct item **items = malloc(sizeof(struct item*) * size);
    
    for (int i = 0; i < size; ++i)
    {
        items[i] = malloc(sizeof(struct item));
        items[i]->n = nums[i];
        items[i]->idx = i;
    }
    return items;
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
    int i, pivot;
    void swap(struct item **items, int i, int j);

    if (left >= right)
        return;

    swap(items, left, (left + right)/2);
    pivot = left;
    for (i = left + 1; i <= right; i++)
        if (items[left]->n > items[i]->n)
            swap(items, ++pivot, i);
    swap(items, left, pivot);
    qsort_(items, left, pivot-1);
    qsort_(items, pivot + 1, right);
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

void freemem(struct item **items, int size)
{
    for (int i = 0; i < size; ++i)
        free(items[i]);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    struct item **get_items(int *nums, int size);
    void qsort_(struct item **items, int left, int right);
    int binsearch(int* arr, int size, int target);
    void freemem(struct item **items, int size);

    int t;
    int *res = malloc(sizeof (int)*2);
    int n1, n2;
    struct item **items = get_items(nums, numsSize);

    qsort_(items, 0, numsSize-1);

    int idx1 = 0;
    int idx2 = NOT;

    for (; idx1 < numsSize && items[idx1]->n < target; ++idx1)
        ;

    --idx1;

    do 
    {
        n1 = items[idx1--]->n;
        t = target - n1;
        if ((idx2 = binsearch(nums, numsSize, t)) == NOT
                                    || (idx1 + 1) == idx2)
                continue;

        n2 = items[idx2]->n;
    }
    while (target - (n1 + n2));

    freemem(items, numsSize);
    free(items);
    
    if (idx2 == NOT)
        return NULL;

    ++idx1;

    res[0] = idx1 < idx2 ? idx1 : idx2;
    res[1] = idx1 < idx2 ? idx2 : idx1;

    *returnSize = 2;

    return res;
}


int main(void)
{
    int input[] = {2, 4 ,22, 7, 11, 15, 9};
    int input_length = 7;
    int target = 19;
    int returnSize = 2;

    int *nums = NULL;

#define TEST
#ifdef TEST
    for (long i = 0; i < 100000000; ++i)
    {
        if ((nums = twoSum(input, input_length, target, &returnSize)) != NULL)
            ;
    free(nums);
    }
    printf("looking for memory usage...\n");
    getchar();
#else
    if ((nums = twoSum(input, input_length, target, &returnSize)) != NULL)
        printf("result is: [%d %d]\n", nums[0], nums[1]);
#endif
    
    exit(EXIT_SUCCESS);

}
