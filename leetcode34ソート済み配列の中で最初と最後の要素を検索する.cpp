class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binSearch(nums,target,true);  // まず左境界を探す
        int right = binSearch(nums,target,false); // 右境界を探す
        return {left,right};
    }
    int binSearch(vector<int>& nums,int target,int isLeft){
        // 二分探索（左閉右閉の書き方を参考）
        int left = 0,right = nums.size()-1;
        int index = -1; // 一時的な左右境界を保存するための変数
        while(left<=right){
            int mid = (right+left)/2;
            if(target<nums[mid]){
                right = mid - 1;
            }else if(target>nums[mid]){
                left = mid + 1;
            }else if(target == nums[mid]){
                index = mid; // indexを更新
                if(isLeft == true){ // 左境界を探している場合
                    // rightの値を更新する必要がある
                    right = mid - 1; // 引き続き中間位置の左側で目標値を探す
                }else{ // 右境界を探している場合
                    // leftの値を更新する
                    left = mid + 1;
                }
            }
        }
        return index;
    }
};