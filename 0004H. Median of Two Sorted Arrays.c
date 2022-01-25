// Runtime: 8 ms, faster than 98.38% of C online submissions for Median of Two Sorted Arrays.
// Memory Usage: 6.5 MB, less than 69.65% of C online submissions for Median of Two Sorted Arrays.

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1Size < nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    if (nums2Size == 0) {
        if (nums1Size%2 == 1) {
            return nums1[nums1Size/2];
        }
        else {
            return (nums1[nums1Size/2 - 1] + nums1[nums1Size/2])/2.0;
        }
    }
    if (nums1Size + nums2Size == 2) {
        return (nums1[0] + nums2[0])/2.0;
    }
    
int idx1 = 0;
int idx2 = 0;
    
    if ((nums1Size + nums2Size) % 2 == 1) {
        int idx = (nums1Size + nums2Size)/2;
        while ((idx1 + idx2) < idx) {
            if (idx2 < nums2Size && nums2[idx2] <= nums1[idx1]) {
                idx2++;
            }
            else {
                idx1++;
            }
        }
        if (idx2 == nums2Size || nums1[idx1] < nums2[idx2]) {
            return nums1[idx1];
        }
        else {
            return nums2[idx2];
        }
    }
    else {
        int idx = (nums1Size + nums2Size)/2 - 1;
        while ((idx1 + idx2) < idx) {
            if (idx2 < nums2Size && nums2[idx2] <= nums1[idx1]) {
                idx2++;
            }
            else {
                idx1++;
            }
        }
        if (idx2 == nums2Size) {
            return (nums1[idx1] + nums1[idx1+1])/2.0;
        }
        if (idx1+1 != nums1Size && nums1[idx1+1] < nums2[idx2]) {
            return (nums1[idx1] + nums1[idx1+1])/2.0;
        }
        if (idx2+1 != nums2Size && nums2[idx2+1] < nums1[idx1]) {
            return (nums2[idx2] + nums2[idx2+1])/2.0;
        }
        return (nums1[idx1] + nums2[idx2])/2.0;
    }
}
