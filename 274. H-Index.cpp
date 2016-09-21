class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> stat (citations.size() + 1, 0);
        for (int i = 0; i < citations.size(); i++) {
            stat[citations[i] > citations.size()? citations.size() : citations[i]]++;
        }
        int sum = 0;
        for (int i = stat.size() - 1; i >= 0; i--) {
            sum += stat[i];
            // 如果引用大于等于i次的文章数量，大于引用次数i，说明是H index
            if (sum >= i)
                return i;
        }
        return 0;
    }
};
