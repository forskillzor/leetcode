#include<stdlib.h>
#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NOT -1

const int input[] = { 23, 99, 100, 2, 10, 9, 17, 0, 8, 11, 4, 3 };
const int input_length = sizeof(input) / sizeof(input[0]);

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

struct item * get_items(int *nums, int size)
{
    struct item *items = malloc(sizeof(struct item) * size);
    
    for (int i = 0; i < size; ++i)
    {
        items[i].n = nums[i];
        items[i].idx = i;
    }
    return items;
}

void swap(struct item *items, int i, int j)
{
    struct item temp = items[i];
    items[i] = items[j];
    items[j] = temp;
}

void qsort_(struct item *items, int left, int right) // не выглядит как правильная имплементация квиксорта
{
    int i, last;

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

struct inp_data {
    int arr[10];
    int size;
    int target;
    int solution[2];
    int retSize;
};

int main(void)
{
    struct inp_data inputs[] = {
        {
            { 2, 7, 11, 15 }, 4, 9, {0, 1}, 2
        },
        {
            { 3, 2, 4 }, 3, 6, {1, 2}, 2
        }
    };

    int *nums = NULL;

#define TEST
#ifdef TEST
    for (long i = 0; i < 2; ++i)
    {
        if ((nums = twoSum(inputs[i].arr, inputs[i].size,
                        inputs[i].target, &inputs[i].retSize)) != NULL) {
            for(int j = 0; j < inputs[i].size; ++j)
                printf("%d ", inputs[i].arr[j]);
            printf("\ntarget: %d\n", inputs[i].target);
            printf("solution: [%d %d]\n\n", nums[0], nums[1]);
        }

    free(nums);
    }
    printf("Done...\n");
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
