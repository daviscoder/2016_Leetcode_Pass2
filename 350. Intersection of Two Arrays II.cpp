class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> myMap;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            if (myMap.count (nums1[i]) == 0)
                myMap[nums1[i]] = 1;
            else
                myMap[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (myMap.count (nums2[i]) && myMap[nums2[i]]) {
                res.push_back (nums2[i]);
                myMap[nums2[i]]--;
            }
        }
        return res;
    }
};
/**
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 * - Leveraging the idea of merge sort.
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * - Iterate each element in num1 and do a  binary search in nums2.
 * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 * 因为nums1是可以放到内存的，所以就把nums1放到hashmap里，然后从disk分多次取出nums2，判断一下就好了
 **/
