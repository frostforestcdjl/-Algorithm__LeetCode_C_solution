//Runtime: 88 ms, faster than 53.85% of C online submissions for Two Sum.
//Memory Usage: 6.3 MB, less than 68.05% of C online submissions for Two Sum.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *returnValues = malloc((*returnSize) * sizeof(int));
    
    for (int i = 0; i < numsSize -1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                returnValues[0] = i;
                returnValues[1] = j;
                break;
            }
        }
    }
    
    return returnValues;
}
