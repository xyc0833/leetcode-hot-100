class Solution {
private:
    string lettermap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    // 単一レベルの結果を何で保存するか
    string path;
    // 引数の決め方：このindexは何番目の数字を処理しているかを記録
    void backtracking(string digits, int index) {
        // バックトラッキングの終了条件：digitsの長さ == pathの長さ
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }
        // 3. 単一レベルのループロジックを決定
        // digits文字列は文字配列として扱える
        int x = digits[index] - '0'; // ここで文字列を数字の差分に変換しないと、次の行で範囲外エラーが発生する
        string cur = lettermap[x];
        for (int i = 0; i < cur.size(); i++) {
            path.push_back(cur[i]);
            // cout << cur[i] << endl;
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        backtracking(digits, 0);
        return result;
    }
};