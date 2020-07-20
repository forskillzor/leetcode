#include<stdlib.h>
#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NOT -1

//const int input[] = { 23, 99, 100, 2, 10, 9, 17, 0, 8, 11, 4, 3 };
//const int input_length = sizeof(input) / sizeof(input[0]);

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

    if (left >= right)
        return;

    swap(nums, indexes, left, (left + right)/2);
    pivot = left;
    for (i = left + 1; i <= right; i++)
        if (nums[pivot] > nums[i])
            swap(nums, indexes, ++pivot, i);
    swap(nums, indexes, left, pivot);
    qsort_(nums, indexes, left, pivot-1);
    qsort_(nums, indexes, pivot + 1, right);
}

int binsearch(int* arr, int size, int target)
{
    int begin, end, mid;
    begin = 0, end = size-1;
    
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        if (target < arr[mid])
        {
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            begin = mid + 1;
        }
        else
            return mid;
    }
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
    void qsort_(int *items, int *indexes, int left, int right);
    int binsearch(int* arr, int size, int target);
    int* get_indexes(int size);

    int t;
    int n1, n2;

    int idx1 = 0;
    int idx2 = NOT;

    int *res = malloc(sizeof (int)*2);
    int *indexes = get_indexes(numsSize);

    qsort_(nums, indexes, 0, numsSize-1);

    do {
        n1 = nums[idx1++];
        t = target - n1;
        while (((idx2 = binsearch(nums, numsSize, t)) == NOT) || (idx1-1 == idx2))
        {
            if (idx1 >= numsSize)
                break;
            n1 = nums[idx1++];
            t = target - n1;
        }
        n2 = nums[idx2];

    } while ((target - (n1 + n2)) || (idx1-1 == idx2)); 
    --idx1;

    if (idx1 == NOT)
    {
        free(indexes);
        return NULL;
    }

    int i1 = indexes[idx1];
    int i2 = indexes[idx2];

    res[0] = i1 < i2 ? i1 : i2;
    res[1] = i1 > i2 ? i1 : i2;

    *returnSize = 2;

    free(indexes);

    return res;
}

struct inp_data {
    int arr[500];
    int size;
    int target;
    int solution[2];
    int retSize;
};
#define TEST_LENGTH 8
struct inp_data inputs[] = {
    { { 3, 2, 3 }, 3, 6, { 0, 2 }, 2},
    { { -10, -1, -18, -19 }, 4, -19, { 1, 2 }, 2 },
    { {-100, 99, 2, 0, 22, -1001, 500}, 7, -100, { 0,3 }, 2 },
    { { 2, 7, 11, 15 }, 4, 9, { 0, 1 }, 2 },
    { { 3, 2, 4 }, 3, 6, { 1, 2 }, 2 },
    { { 0, 4, 3, 0 }, 4, 0, { 0, 3 }, 2 },
    { { 2, 1, 9, 4, 4, 56, 90, 3}, 8, 8, { 3, 4 }, 2},
    { {572,815,387,418,434,530,376,190,196,74,830,561,973,771,640,37,539,369,327,51,623,575,988,44,659,48,22,776,487,873,486,169,499,82,128,31,386,691,553,848,968,874,692,404,463,285,745,631,304,271,40,921,733,56,883,517,99,580,55,81,232,971,561,683,806,994,823,219,315,564,997,976,158,208,851,206,101,989,542,985,940,116,153,47,806,944,337,903,712,138,236,777,630,912,22,140,525,270,997,763,812,597,806,423,869,926,344,494,858,519,389,627,517,964,74,432,730,843,673,985,819,397,607,34,948,648,43,212,950,235,995,76,439,614,203,313,180,760,210,813,920,229,615,730,359,863,678,43,293,978,305,106,797,769,3,700,945,135,430,965,762,479,152,121,935,809,101,271,428,608,8,983,758,662,755,190,632,792,789,174,869,622,885,626,310,128,233,82,223,339,771,741,227,131,85,51,361,343,641,568,922,145,256,177,329,959,991,293,850,858,76,291,134,254,956,971,718,391,336,899,206,642,254,851,274,239,538,418,21,232,706,275,615,568,714,234,567,994,368,54,744,498,380,594,415,286,260,582,522,795,261,437,292,887,405,293,946,678,686,682,501,238,245,380,218,591,722,519,770,359,340,215,151,368,356,795,91,250,413,970,37,941,356,648,594,513,484,364,484,909,292,501,59,982,686,827,461,60,557,178,952,218,634,785,251,290,156,300,711,322,570,820,191,755,429,950,18,917,905,905,126,790,638,94,857,235,889,611,605,203,859,749,874,530,727,764,197,537,951,919,24,341,334,505,796,619,492,295,380,128,533,600,160,51,249,5,837,905,747,505,82,158,687,507,339,575,206,28,29,91,459,118,284,995,544,3,154,89,840,364,682,700,143,173,216,290,733,525,399,574,693,500,189,590,529,972,378,299,461,866,326,43,711,460,426,947,391,536,26,579,304,852,158,621,683,901,237,22,225,59,52,798,262,754,649,504,861,472,480,570,347,891,956,347,31,784,581,668,127,628,962,698,191,313,714,893}
    ,443 , 101, {0, 0}, 2 }
};

int main(void)
{

    int *nums = NULL;

#define TEST
#ifdef TEST
printf("%d %d\n", inputs[7].arr[83], inputs[7].arr[239]);
    for (long i = 0; i < TEST_LENGTH; ++i)
    {
        if ((nums = twoSum(inputs[i].arr, inputs[i].size,
                        inputs[i].target, &inputs[i].retSize)) != NULL) {
            for(int j = 0; j < inputs[i].size; ++j)
                printf("%d ", inputs[i].arr[j]);
            printf("\ntarget: %d\n", inputs[i].target);
            printf("result:    [%d %d],\n", nums[0], nums[1]);
            printf("soulution: [%d %d], %s\n\n", inputs[i].solution[0],
                    inputs[i].solution[1],
                    (nums[0] == inputs[i].solution[0] 
                    && nums[1] == inputs[i].solution[1]) ? "PASSED" : "FAILED");
        }

    free(nums);
    }
    printf("Done...\n");
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
