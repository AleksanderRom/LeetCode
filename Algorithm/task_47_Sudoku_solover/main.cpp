#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std::literals;

class CheckSudoku {
public:
    bool CheckPosition(int i, int j) {
        if (i == 1 || i == 4 || i == 7) {
            return (j == 1 || j == 4 || j == 7);
        }
        return false;
    }
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            std::unordered_map<char, int> row;
            std::unordered_map<char, int> collum;
            for (int j = 0; j < 9; ++j) {
                if (row.count(board[i][j]) || collum.count(board[j][i])) {
                    return false;
                }else {
                    if (board[i][j] != '.') {
                        ++row[board[i][j]];
                    }
                    if (board[j][i] != '.') {
                        ++collum[board[j][i]];
                    }
                }
                        // check square
            if (CheckPosition(i, j)) {
                    std::unordered_map<char, int> square;
                    for (int n = -1; n < 2; ++n) {
                        for (int k = -1; k < 2; ++k) {
                            if (square.count(board[i + n][j + k])) {
                                return false;
                            }else {
                                if (board[i + n][j + k] != '.') {
                                    ++square[board[i + n][j + k]];
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

// class Cell {


//     private:
//     std::vector<std::vector<char>>& board;

// };

std::ostream& operator<<(std::ostream& out, const std::unordered_set<char>& conds) {
    char i = '9';
    auto it = conds.begin();
    while (i != '0') {
        if (it != conds.end() && *it == i) {
            std::cout << *it;
            ++it; --i;
        } else  {
            std::cout << '.';
            --i;
        }
        // } else if (conds.size() == 1 && *conds.begin() == '.') {
    // }
    // for (auto it = conds.begin(); it != conds.end(); ++it) {
    //     // while (i != 0) {
    //         if (*it == i--) {
    //             std::cout << *it;
    //         } else if (conds.size() == 1 && *conds.begin() == '.') {
    //             std::cout << "........."s;
    //         } else {
    //             std::cout << '.';
    //         }
        // }
        
    }
    return out;
}

class Solution {
private:
int iteration_ = 0;
std::vector<std::vector<std::unordered_set<char>>> condidate_;
public:

    void PrintBoard(std::vector<std::vector<char>>& board, int row, int colum) {
        std::cout << "iteration: " << iteration_++ << std::endl;
        std::cout << "row: " << row << std::endl;
        std::cout << "colum: " << colum << std::endl;
        std::cout << "value: " << board[row][colum] << std::endl;
        std::cout << "----------------------" << std::endl;
        for (int row = 0; row < 9; ++row) {
            if (row == 3 || row == 6) {
                std::cout << "----------------------" << std::endl;
            }
            for (int colum = 0; colum < 9; ++colum) {
                if (colum == 3 || colum == 6 || colum == 0) {
                    std::cout << '|';
                } 
                std::cout  << board[row][colum] << ' ' ;
            }
            std::cout << '|' << std::endl;
            }
            std::cout << "----------------------" << std::endl;
            std::cout << std::endl;
    }



    void PrintCondidate() {
        std::cout << "condidate: "  << std::endl;

        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
        for (int row = 0; row < 9; ++row) {
            if (row == 3 || row == 6) {
                std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
            }
            for (int colum = 0; colum < 9; ++colum) {
                if (colum == 3 || colum == 6 || colum == 0) {
                    std::cout << '|';
                } 
                // std::cout << tttt << ' ' ;
                std::cout << condidate_[row][colum] << ' ' ;
            }
            std::cout << '|' << std::endl;
            }
            std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;
    }

    std::vector<char> GetBox(std::vector<std::vector<char>>& board, int row, int colum) {
        int min_row = (row / 3) * 3;
        int min_colum = (colum / 3) * 3;
        std::vector<char> result;
        result.reserve(8);
        for (int i = min_row; i < min_row + 3; ++i) {
            for (int j = min_colum; j < min_colum + 3; ++j) {
                    result.push_back(board[i][j]);
            }
        }
        return result;
    }

    std::vector<char> InsertInt(std::vector<std::vector<char>>& board, int row, int colum) {
        std::unordered_set<char> available_number{'1','2','3','4','5','6','7','8','9'};
        std::vector<char> box_n = GetBox(board, row, colum);
        for (int i = 0; i < 9; ++i){
            if (board[row][i] != '.') {
                available_number.erase(board[row][i]);
            }
            if (board[i][colum] != '.') {
                available_number.erase(board[i][colum]);
            }
            if (box_n[i] != '.') {
                available_number.erase(box_n[i]);
            }
        }
        return {available_number.begin(), available_number.end()};

    }

    void InsertBox(std::vector<std::vector<char>>& board, int row, int colum) {
        int row_min = (row / 3) * 3;
        int colum_min = (colum / 3) * 3;
        for (char number = '1'; number <= '9'; ++number) {// проверка каждого числа
            std::vector<char> box_index(9, number); //индексы в боксе

            for (int i = row_min; i < row_min + 3; ++i) {
                if (CheckNumberInRow(board, i, number)) {
                    int row_min = (i % 3) * 3;
                    for (int r = row_min; r < row_min + 3; ++r) {
                        box_index[r] = '.';
                    }
                }
            }

            for (int j = colum_min; j < colum_min + 3; ++j) {
                    if (CheckNumberInColum(board, j, number)) {
                        int colum_min = (j % 3);
                        for (int c = colum_min; c < colum_min + 7; c += 3) {
                            box_index[c] = '.';
                        }
                    }
            }

            auto box = GetBox(board, row, colum);
            for (int i = 0; i < 9; ++i) {
                if (box[i] == number) {
                    box_index.resize(0);
                    break;
                    // box_index[i] = '.';
                }
            }

            //подсчет количеста
            if (box_index.size() > 0) {
            int pos = PositionIsCountNumber(box_index);
                if (pos >= 0) {
                    board[row + pos / 3][colum + (pos % 3)] = number;
                    condidate_[row + pos / 3][colum + (pos % 3)].clear();
                    condidate_[row + pos / 3][colum + (pos % 3)].insert('.'); // = std::unordered_set<char>('.');
                    PrintBoard(board, (row + pos / 3), (colum + (pos % 3)));
                    PrintCondidate();
                    // int hhh = 0;
                }
            }
            }
        }

        int PositionIsCountNumber (std::vector<char>& box_index) {
            int position = -1;
            bool first = true;
            for (int i = 0; i < 9; ++i) {
                if (box_index[i] != '.') {
                    position = i;
                    if (!first) return -1;
                    first = false;
                }
            }
            return position;
        }

    // }
    // }
    bool CheckSolover(std::vector<std::vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int colum = 0; colum < 9; ++colum) {
                if (board[row][colum] == '.') {
                    return false;
                }
            }
        }
        return true;
    }
    void GetTableCondidate(std::vector<std::vector<char>>& board){
        std::unordered_set set{'1','2','3','4','5','6','7','8','9'};
        std::unordered_set set_void{'.'};
        std::vector<std::unordered_set<char>> v_set(9, set);
        std::vector<std::vector<std::unordered_set<char>>> condidate(9, v_set);
        condidate_ = std::move(condidate);
        for (int row = 0; row < 9; ++row) {
            for (int colum = 0; colum < 9; ++colum) {
                if (board[row][colum] != '.') {
                    condidate_[row][colum].clear();
                    condidate_[row][colum] = set_void;
                }
            }
        }

    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        GetTableCondidate(board);
        PrintBoard(board, 0, 0);
        PrintCondidate();
        int iter = 1;
        while(true) {
            for (int row = 0; row < 9; ++row) {
                for (int colum = 0; colum < 9; ++colum) {
                    if (board[row][colum] == '.') {
                        auto temp = InsertInt(board, row, colum);
                        if (temp.size() == 1) {
                            board[row][colum] = temp.back();
                             condidate_[row][colum].clear();
                            condidate_[row][colum].insert('.'); // = std::unordered_set<char>('.');
                            // condidate_[row][colum].insert('.');
                            PrintBoard(board, row, colum);
                            PrintCondidate();
                            row = 0;
                            colum = 0;
                        }
                    }
                }
            }
            if (CheckSolover(board)) return;

            for (int i = 0; i < 9; i += 3) {
                for (int j = 0; j < 9; j += 3) {
                    InsertBox(board, i, j);
                }
            }
        }
        
    }
    private:
    bool CheckNumberInRow(std::vector<std::vector<char>>& board, int row, char number) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == number) {
                return true;
            }
        }
        return false;
    }
    bool CheckNumberInColum(std::vector<std::vector<char>>& board, int colum, char number) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][colum] == number) {
                return true;
            }
        }
        return false;
    }

    // bool CheckNumberInBox(std::vector<std::vector<char>>& board, int row, int colum, char number) {
    //     auto box = GetBox(board, row, colum);
    //     for (const auto& num : box) {
    //         if (num == number) return true;
    //     }
    //     return false;
    // }
    // std::vector<std::unordered_set<char>> row_;
    // std::vector<std::unordered_set<char>> colum_;
};




int main () {
Solution s;
{
    std::vector<std::vector<char>> v
{{'.','.','9','7','4','8','.','.','.'}
,{'7','.','.','.','.','.','.','.','.'}
,{'.','2','.','1','.','9','.','.','.'}
,{'.','.','7','.','.','.','2','4','.'}
,{'.','6','4','.','1','.','5','9','.'}
,{'.','9','8','.','.','.','3','.','.'}
,{'.','.','.','8','.','3','.','2','.'}
,{'.','.','.','.','.','.','.','.','6'}
,{'.','.','.','2','7','5','9','.','.'}};
s.solveSudoku(v);
}
// {
//     std::vector<std::vector<char>> v
// {{'5','3','.','.','7','.','.','.','.'}
// ,{'6','.','.','1','9','5','.','.','.'}
// ,{'.','9','8','.','.','.','.','6','.'}
// ,{'8','.','.','.','6','.','.','.','3'}
// ,{'4','.','.','8','.','3','.','.','1'}
// ,{'7','.','.','.','2','.','.','.','6'}
// ,{'.','6','.','.','.','.','2','8','.'}
// ,{'.','.','.','4','1','9','.','.','5'}
// ,{'.','.','.','.','8','.','.','7','9'}};
// s.solveSudoku(v);
// }

int i = 0;
/*
{
    std::vector<std::vector<char>> v 
{{'.','.','.','9','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.','.'}
,{'.','.','3','.','.','.','.','.','1'}
,{'.','.','.','.','.','.','.','.','.'}
,{'1','.','.','.','.','.','3','.','.'}
,{'.','.','.','.','2','.','6','.','.'}
,{'.','9','.','.','.','.','.','7','.'}
,{'.','.','.','.','.','.','.','.','.'}
,{'8','.','.','8','.','.','.','.','.'}};
 assert(false == s.isValidSudoku(v));
}
{
    std::vector<std::vector<char>> v 
{{'.','.','.','9','.','.','.','.','1'}
,{'.','.','.','.','.','.','.','.','.'}
,{'.','.','3','.','.','.','.','.','1'}
,{'.','.','.','.','.','.','.','.','.'}
,{'1','.','.','.','.','.','3','.','.'}
,{'.','.','.','.','2','.','6','.','.'}
,{'.','9','.','.','.','.','.','7','.'}
,{'.','.','.','.','.','.','.','.','.'}
,{'8','.','.','8','.','.','.','.','.'}};
 assert(false == s.isValidSudoku(v));
}
 */
// {
//     std::vector<std::vector<char>> v 
// {{'5','3','.','.','7','.','.','.','.'}
// ,{'6','.','.','1','9','5','.','.','.'}
// ,{'.','9','8','.','.','.','.','6','.'}
// ,{'8','.','.','.','6','.','.','.','3'}
// ,{'4','.','.','8','.','3','.','.','1'}
// ,{'7','.','.','.','2','.','.','.','6'}
// ,{'.','6','.','.','.','.','2','8','.'}
// ,{'.','.','.','4','1','9','.','.','5'}
// ,{'.','.','.','.','8','.','.','7','9'}};
//  assert(true == s.isValidSudoku(v));
// }
// {
//     std::vector<std::vector<char>> v 
// {{'8','3','.','.','7','.','.','.','.'}
// ,{'6','.','.','1','9','5','.','.','.'}
// ,{'.','9','8','.','.','.','.','6','.'}
// ,{'8','.','.','.','6','.','.','.','3'}
// ,{'4','.','.','8','.','3','.','.','1'}
// ,{'7','.','.','.','2','.','.','.','6'}
// ,{'.','6','.','.','.','.','2','8','.'}
// ,{'.','.','.','4','1','9','.','.','5'}
// ,{'.','.','.','.','8','.','.','7','9'}};
//  assert(false == s.isValidSudoku(v));
// }
// {
//     std::vector<std::vector<char>> v 
// {{'.','.','.','.','.','.','.','.','.'}
// ,{'.','.','.','.','.','.','.','.','.'}
// ,{'.','.','.','.','.','.','.','.','.'}
// ,{'.','.','.','.','.','.','.','.','.'}
// ,{'.','.','.','.','.','.','.','.','.'}
// ,{'.','.','.','.','.','.','.','.','.'}
// ,{'.','.','.','.','.','.','3','.','.'}
// ,{'.','.','.','.','.','.','.','.','.'}
// ,{'.','.','.','.','.','.','.','.','3'}};
//  assert(false == s.isValidSudoku(v));
// }
}