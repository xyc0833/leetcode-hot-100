class Solution {
private:
    vector<vector<int>> result;  // 条件を満たす結果の集合を格納
    vector<int> path; // 条件を満たす現在の結果を格納
    // n と k は問題のパラメータ、startIndex はこのレベルの再帰で集合の走査をどこから始めるかを記録
    void backtracking(int n, int k, int startIndex) {
        // pathのサイズがkに達した場合、サイズkの組み合わせを見つけたことを意味する（根ノードから葉ノードまで走査）
        if (path.size() == k) {
            result.push_back(path); // 最終的な結果はresultに格納されるので、この解をresultに追加
            return;
        }
        for (int i = startIndex; i <= n; i++) { // 数の横方向の走査を制御
            path.push_back(i); // ノードを処理
            backtracking(n, k, i + 1); // 再帰：木の縦方向の走査を制御、次のレベルの検索はi+1から開始
            path.pop_back(); // バックトラック：処理したノードを取り消す
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};