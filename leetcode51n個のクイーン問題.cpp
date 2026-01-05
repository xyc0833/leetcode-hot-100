class Solution {
public:
    vector<vector<string>> result; // 全体の解を格納する変数
    // パラメータは後で決める（visited配列が必要かも）
    // rowは現在のチェス盤の行（深さ）を記録する
    void backtracking(int n, int row, vector<string>& chessboard) {
        // 終了条件：チェス盤の最下行まで到達したら終了
        if (n == row) {
            result.push_back(chessboard);
            return;
        }
        // 再帰の深さはrowで制御（チェス盤の行）
        // colはチェス盤の列（forループで制御）
        // 単層の操作は以下の通り
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n) == true) { // 合法性を検証して配置可能なら
                chessboard[row][col] = 'Q'; // クイーンを配置
                backtracking(n, row + 1, chessboard); // 次の行へ
                chessboard[row][col] = '.'; // バックトラック（クイーンを取り除く）
            }
        }
    }

    bool isValid(int x, int y, vector<string>& chessboard, int n) {
        // 同じ行には配置不可（1行に1つだけなのでチェック不要）
        // 同じ列に既にクイーンがいないか確認
        for (int i = 0; i < x; i++) {
            if (chessboard[i][y] == 'Q') return false;
        }
        // 45度対角線（左上方向）をチェック（コードは上から下に配置するので）
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') return false;
        }
        // 135度対角線（右上方向）をチェック
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') return false;
        }
        return true; // 全てのチェックを通過したら合法
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.')); // n×nの空チェス盤を初期化
        backtracking(n, 0, chessboard); // バックトラック開始（初期行=0）
        return result;
    }
};