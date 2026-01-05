class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 第一种写法 左闭右闭の写法
        // 初期化：左指针を配列の最初のインデックス（0）に設定
        int left = 0;
        // 初期化：右指针を配列の最後のインデックス（nums.size() - 1）に設定
        int right = nums.size() - 1;
        
        // ループ条件：左指针が右指针以下の間継続（左闭じた右闭じた区間なので等号が必要）
        while(left <= right){ 
            // 中央インデックスを計算（整数除算で切り捨て）
            int mid = (right + left) / 2;
            
            // ターゲットが中央値より小さい場合
            if(target < nums[mid]){ 
                // 右边界を更新：中央値の左隣に移動（右闭じた区間なので -1）
                right = mid - 1;
            }
            // ターゲットが中央値より大きい場合
            else if(target > nums[mid]){
                // 左边界を更新：中央値の右隣に移動（左闭じた区間なので +1）
                left = mid + 1; 
            }
            // ターゲットが中央値と一致する場合
            else if(target == nums[mid]){
                // 見つかったのでインデックスを返す
                return mid;
            }
        }
        // ループを抜けた場合はターゲットが存在しないので -1 を返す
        return -1;
    }
};