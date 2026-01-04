class Solution {
public:
    vector<vector<string>> result; // 全体の分割結果を格納する変数
    vector<string> path;           // 1回の分割結果を格納する変数
    // index: 既に使用済みの文字の位置を記録（終了条件の判定に使用）
    void backtracking(string& s, int index) {
        if (s.size() <= index) { // もし開始位置が文字列sのサイズを超えたら、1つの分割方案が見つかった
            result.push_back(path); 
            return;
        }
        // 1回の操作での列挙処理
        for (int i = index; i < s.size(); i++) {
            // もし回文字列なら
            if (isPalindrome(s, index, i) == true) { 
                // sの[index, i]範囲の部分文字列を取得
                string str = s.substr(index, i - index + 1);
                path.push_back(str); // 部分文字列をpathに追加
            } else {
                continue; // 回文字列でない場合はスキップ
            }
            backtracking(s, i + 1); // 次はi+1からの文字列を探索（index+1ではない）
            path.pop_back(); // バックトラック（pathの最後の要素を削除）
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0); // バックトラック探索を開始（開始位置=0）
        return result;
    }
    // 回文字列判定関数
    bool isPalindrome(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) return false; // 文字が不一致ならfalse
        }
        return true; // 全て一致したらtrue
    }
};