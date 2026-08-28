bool invalid(const vector<char>& v) {
    //we just want to check no double no no order, no multi and no map
    std::unordered_set<char> seen;

    //insert returns a pair iterator, bool
    for (const auto& c : v) {
        if ((!seen.insert(c).second)&&(c!='.')) return true;  
    }
    return false;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (auto row:board){
            if (invalid(row)) return false;
        }

        vector<char> col(9);

        for (int icol{0}; icol<9; icol++){

            for (int j{0}; j<9; j++){
                col[j] = board[j][icol];
            }
            if (invalid(col)) return false;

        }

        vector<char> block(9);

        for (int iblock{0};iblock<9; iblock++){
            const int base_i = (iblock/3)*3;//0->0, 1->0, 2->0, 3->3
            const int base_j = (iblock*3)%9;// 0->0, 1->3, 2->6, 3->0

            //std::cout<<"iblock= "<<iblock<<" base=["<<base_i<<","<<base_j<<"]\n";

            for (int k{0}; k<9; k++){
                const int i = base_i + k/3;//0->0, 1->0, 2->0, 3->1
                const int j = base_j + k%3;//0->0, 1->1, 2->2, 3->0
                //std::cout<<"k= "<<k<<" base=["<<k/3<<","<<k%3<<"]\n";

                block[k] = board[i][j];
            }

            if (invalid(block)) return false;
        }

        return true;
    }
};
