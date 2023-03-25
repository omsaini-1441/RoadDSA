// https://leetcode.com/problems/trapping-rain-water/

// main thing to do is - min(left[maxIndex],right[maxIndex])-a[i] gonna give you water stored in every single index.


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        int leftMax = height[left], rightMax = height[right];
        int water = 0;
        while (left < right) {
          
            if (height[left] < height[right]) {         // this will make sure that on the right isde there is atleast similar or a bigger pillar there to store water
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};
