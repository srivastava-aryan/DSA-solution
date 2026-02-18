#include<bits/stdc++.h>
using namespace std;

// PROBLEM: Max consecutive ones-III
class Solution {
public:
    // Function to find the longest subarray with at most k zero flips
    int longestOnes(vector<int>& nums, int k) {

        // Left pointer of the sliding window
        int left = 0;

        // Counter for zeros in the current window
        int zerocount = 0;

        // Variable to store the maximum valid window length
        int maxlen = 0;

        // Right pointer expands the window
        for (int right = 0; right < nums.size(); right++) {

            // If current element is 0, increment zerocount
            if (nums[right] == 0) {
                zerocount++;
            }

            // If zero count exceeds k, move left pointer and adjust zerocount
            if (zerocount > k) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                // Shrink the window from left
                left++; 
            }

            // Update the maximum window size
            maxlen = max(maxlen, right - left + 1);
        }

        // Return the maximum length found
        return maxlen;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    // Output the result
    cout << sol.longestOnes(nums, k) << endl;
    return 0;
}


