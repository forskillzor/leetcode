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

void swap(int *nums, int *indexes, int i, int j)
{
    int temp_val;
    int temp_idx;
    
    temp_val = nums[i];
    nums[i] = nums[j];
    nums[j] = temp_val;

    temp_idx = indexes[i];
    indexes[i] = indexes[j];
    indexes[j] = temp_idx;
}

void qsort_(int *nums, int *indexes, int left, int right)
{
    int i, pivot;
    void swap(int *nums, int *indexes, int i, int j);

    if (left >= right)
        return;

    swap(nums, indexes, left, (left + right)/2);
    pivot = left;
    for (i = left + 1; i <= right; i++)
        if (nums[left] > nums[i])
            swap(nums, indexes, ++pivot, i);
    swap(nums, indexes, left, pivot);
    qsort_(nums, indexes, left, pivot-1);
    qsort_(nums, indexes, pivot + 1, right);
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

int* get_indexes(int size)
{
    int *res = malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i)
        res[i] = i;
        
    return res;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    struct item **get_items(int *nums, int size);
    void qsort_(int *items, int *indexes, int left, int right);
    int binsearch(int* arr, int size, int target);
    void freemem(struct item **items, int size);
    int* get_indexes(int size);

    int t;
    int *res = malloc(sizeof (int)*2);
    int n1, n2;
    int *indexes = get_indexes(numsSize);

    qsort_(nums, indexes, 0, numsSize-1);

    int idx1 = 0;
    int idx2 = NOT;

    for (; idx1 < numsSize && nums[idx1] < target; ++idx1)
        ;

    --idx1;

    do 
    {
        n1 = nums[idx1--];
        t = target - n1;
        if ((idx2 = binsearch(nums, numsSize, t)) == NOT
                                    || (idx1 + 1) == idx2)
                continue;

        n2 = nums[idx2];
    }
    while (target - (n1 + n2));


    if (idx2 == NOT) 
    {
        free(indexes);
        return NULL;
    }

    ++idx1;

    int i1 = indexes[idx1];
    int i2 = indexes[idx2];

    res[0] = i1 < i2 ? i1 : i2;
    res[1] = i1 > i2 ? i1 : i2;

    *returnSize = 2;

    free(indexes);

    return res;
}


int main(void)
{
    //int input[] = { 2, 4 ,22, 7, 11, 15, 9 };
    //int input_length = 7;
    int input[] = { 3, 2, 4 };
    int input_length = 3;
    int target = 6;
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
    if ((nums = twoSum(input, input_length, target, &returnSize)) != NULL) {
        for (int i = 0; i < input_length; ++i)
            printf("%d ", input[i]);
        printf("\n");
        printf("target: %d\n", target);
        printf("result is: [%d %d]\n", nums[0], nums[1]);
    }
#endif
    
    exit(EXIT_SUCCESS);

}
