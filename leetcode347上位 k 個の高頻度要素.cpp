class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 頻度を統計する
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        // キーと値のペアを配列に格納する
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        // 頻度の降順でソートする
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        // 上位 k 個の数字を抽出する
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVec[i].first);
        }
        return result;
    }
};