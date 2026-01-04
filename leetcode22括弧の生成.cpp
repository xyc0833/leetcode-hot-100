class Solution {
public:
    vector<string> result; // 結果を格納する配列
    string path;           // 現在のパス（括弧の組み合わせ）

    void dfs(int n, int left, int right) {
        // 終了条件：左括弧と右括弧の数が共にnに達した場合
        if (left == n && right == n) {
            result.push_back(path); // 結果に追加
            return;
        }

        // 左括弧を追加できる条件：左括弧の数 < n
        if (left < n) {
            path.push_back('(');    // 左括弧を追加
            dfs(n, left + 1, right); // 再帰呼び出し
            path.pop_back();        // バックトラック（追加した括弧を取り除く）
        }

        // 右括弧を追加できる条件：右括弧の数 < 左括弧の数
        if (right < left) {
            path.push_back(')');    // 右括弧を追加
            dfs(n, left, right + 1); // 再帰呼び出し
            path.pop_back();        // バックトラック（追加した括弧を取り除く）
        }
    }

    vector<string> generateParenthesis(int n) {
        int left = 0, right = 0;  // 左括弧と右括弧の初期カウント
        dfs(n, left, right);      // 深さ優先探索（DFS）開始
        return result;            // 結果を返す
    }
};