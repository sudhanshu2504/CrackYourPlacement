class RandomizedCollection {
public:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> map;

    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool present = map.find(val) == map.end();
        
        map[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, map[val].size() - 1));
        
        return present;
    }
    
    bool remove(int val) {
        auto result = map.find(val) != map.end();
        if(result){
            auto last = nums.back();
            map[last.first][last.second] = map[val].back();
            nums[map[val].back()] = last;
            map[val].pop_back();
            if(map[val].empty()) map.erase(val);
            nums.pop_back();
        }
        return result;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};