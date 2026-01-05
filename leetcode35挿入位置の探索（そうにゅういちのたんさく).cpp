class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // target は左閉右閉の区間 [left, right] 内に存在すると定義
        while (left <= right) { // left == right のとき、区間 [left, right] は依然有効
            int middle = left + ((right - left) / 2); // オーバーフロー防止。等価于 (left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target は左区間に存在するので [left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target は右区間に存在するので [middle + 1, right]
            } else { // nums[middle] == target
                return middle;
            }
        }
        // 以下の4つの場合をそれぞれ処理
        // 1. 目標値が配列のすべての要素より小さい場合 [0, -1]
        // 2. 目標値が配列のいずれかの要素と等しい場合 return middle;
        // 3. 目標値を配列に挿入する位置 [left, right]、return right + 1
        // 4. 目標値が配列のすべての要素より大きい場合 [left, right]、右閉区間なので return right + 1
        return right + 1;
    }
};