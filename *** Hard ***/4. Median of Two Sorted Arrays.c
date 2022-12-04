#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size, half = n / 2, li = 0, ri = nums2Size;

    while (li <= ri) {
        int mid = (li + ri) / 2, rem = half - mid;
        if (rem > nums1Size) { li = mid + 1; continue; }
        if (rem < 0) { ri = mid - 1; continue; }
        int num1ValLower = rem == 0 ? -1000001 : nums1[rem - 1], num1ValUpper = rem == nums1Size ? 1000001 : nums1[rem];
        int num2ValLower = mid == 0 ? -1000001 : nums2[mid - 1], num2ValUpper = mid == nums2Size ? 1000001 : nums2[mid];

        bool flag1 = num1ValLower > num2ValUpper ? false : true, flag2 = num2ValLower > num1ValUpper ? false : true;
        if (flag1 && flag2) return n % 2 == 0 ? ((double)MAX(num1ValLower, num2ValLower) + MIN(num1ValUpper, num2ValUpper)) / 2 : MIN(num1ValUpper, num2ValUpper);
        else if (!flag1) li = mid + 1;
        else ri = mid - 1; 
    }
    return -1;
}
