class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        map<int, int> sum;
        sum[0] = 1;
        int prefSum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];
            int remainder = prefSum % k;
            if (remainder < 0) {
                remainder += k;
            }
            if (sum.find(remainder) != sum.end()) {
                count += sum[remainder];
                sum[remainder]++;
            } else {
                sum[remainder] = 1;
            }
        }
        return count;
    }
};