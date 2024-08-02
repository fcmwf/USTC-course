#include <vector>
#include <map>
#include <string>

std::vector<std::vector<int>> JiangPosition = {
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {1, -8, -9, 0, 0, 0, 0, 0, 0, 0},
                                            {5, -8, -9, 0, 0, 0, 0, 0, 0, 0},
                                            {1, -8, -9, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                        };

std::vector<std::vector<int>> ShiPosition = {
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                        };
    
std::vector<std::vector<int>> XiangPosition = {
                                            {0, 0, -2, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 3, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, -2, 0, 0, 0, 0, 0, 0, 0},
                                        };

std::vector<std::vector<int>> MaPosition = {
                                            {0, -3, 5, 4, 2, 2, 5, 4, 2, 2},
                                            {-3, 2, 4, 6, 10, 12, 20, 10, 8, 2},
                                            {2, 4, 6, 10, 13, 11, 12, 11, 15, 2},
                                            {0, 5, 7, 7, 14, 15, 19, 15, 9, 8},
                                            {2, -10, 4, 10, 15, 16, 12, 11, 6, 2},
                                            {0, 5, 7, 7, 14, 15, 19, 15, 9, 8},
                                            {2, 4, 6, 10, 13, 11, 12, 11, 15, 2},
                                            {-3, 2, 4, 6, 10, 12, 20, 10, 8, 2},
                                            {0, -3, 5, 4, 2, 2, 5, 4, 2, 2},
                                        };

std::vector<std::vector<int>> PaoPosition = {
                                            {0, 0, 1, 0, -1, 0, 0, 1, 2, 4},
                                            {0, 1, 0, 0, 0, 0, 3, 1, 2, 4},
                                            {1, 2, 4, 0, 3, 0, 3, 0, 0, 0},
                                            {3, 2, 3, 0, 0, 0, 2, -5, -4, -5},
                                            {3, 2, 5, 0, 4, 4, 4, -4, -7, -6},
                                            {3, 2, 3, 0, 0, 0, 2, -5, -4, -5},
                                            {1, 2, 4, 0, 3, 0, 3, 0, 0, 0},
                                            {0, 1, 0, 0, 0, 0, 3, 1, 2, 4},
                                            {0, 0, 1, 0, -1, 0, 0, 1, 2, 4},
                                        };

std::vector<std::vector<int>> JuPosition = {
                                            {-6, 5, -2, 4, 8, 8, 6, 6, 6, 6},
                                            {6, 8, 8, 9, 12, 11, 13, 8, 12, 8},
                                            {4, 6, 4, 4, 12, 11, 13, 7, 9, 7},
                                            {12, 12, 12, 12, 14, 14, 16, 14, 16, 13},
                                            {0, 0, 12, 14, 15, 15, 16, 16, 33, 14},
                                            {12, 12, 12, 12, 14, 14, 16, 14, 16, 13},
                                            {4, 6, 4, 4, 12, 11, 13, 7, 9, 7},
                                            {6, 8, 8, 9, 12, 11, 13, 8, 12, 8},
                                            {-6, 5, -2, 4, 8, 8, 6, 6, 6, 6},
                                        };

std::vector<std::vector<int>> BingPosition = {
                                            {0, 0, 0, -2, 3, 10, 20, 20, 20, 0},
                                            {0, 0, 0, 0, 0, 18, 27, 30, 30, 0},
                                            {0, 0, 0, -2, 4, 22, 30, 45, 50, 0},
                                            {0, 0, 0, 0, 0, 35, 40, 55, 65, 2},
                                            {0, 0, 0, 6, 7, 40, 42, 55, 70, 4},
                                            {0, 0, 0, 0, 0, 35, 40, 55, 65, 2},
                                            {0, 0, 0, -2, 4, 22, 30, 45, 50, 0},
                                            {0, 0, 0, 0, 0, 18, 27, 30, 30, 0},
                                            {0, 0, 0, -2, 3, 10, 20, 20, 20, 0},
                                        };

//棋子价值评估
std::map<std::string, int> piece_values = {
                                        {"Jiang", 10000},
                                        {"Shi", 10},
                                        {"Xiang", 30},
                                        {"Ma", 300},
                                        {"Ju", 500},
                                        {"Pao", 300},
                                        {"Bing", 90}
                                    };

//行期可能性评估，这里更多是对下一步动作的评估
std::map<std::string, int> next_move_values = {
                                        {"Jiang", 9999},
                                        {"Ma", 100},
                                        {"Ju", 500},
                                        {"Pao", 100},
                                        {"Bing", -20}
                                    };


#define RED true
#define BLACK false
typedef bool PlaySide;

// Chinese chess board is 10 x 9
constexpr int32_t BOARD_ROW_LEN = 10;
constexpr int32_t BOARD_COL_LEN = 9;

// if a pawn has crossed the faced river, then he can move forward, left or right.
constexpr int32_t BOARD_RIVER_UP =   4;
constexpr int32_t BOARD_RIVER_DOWN =   5;

// piece: general and advisor must stay within the 9 palace.
constexpr int32_t BOARD_PALACE_UP_TOP     = 0;
constexpr int32_t BOARD_PALACE_UP_BOTTOM  = 2;

constexpr int32_t BOARD_PALACE_DOWN_TOP     =   7;
constexpr int32_t BOARD_PALACE_DOWN_BOTTOM  =   9;

constexpr int32_t BOARD_PALACE_LEFT    =   3;
constexpr int32_t BOARD_PALACE_RIGHT   =   5;

// default AI difficulty.
constexpr int32_t DEFAULT_AI_SEARCH_DEPTH = 5;


//动作结构体，每个动作设置score，可以方便剪枝
struct Move {
    int init_x;
    int init_y;
    int next_x;
    int next_y;
};

struct HistoryNode{
    Move move;
    char beginPiece;
    char endPiece;

};

// chess board.
class ChessBoard{
    std::vector<std::vector<char>>  data;
    std::stack <HistoryNode> history;
public:
    char get(int32_t r, int32_t c) const  {
        return data[r][c];
    }

    void set(int32_t r, int32_t c, char p)  {
        data[r][c] = p;
    }

    void move(const Move& moveNode){
        char beginPiece = get(moveNode.init_x, moveNode.init_y);
        char endPiece   = get(moveNode.next_x, moveNode.next_y);

        // record the history.
        HistoryNode Node = { moveNode, beginPiece, endPiece};
        history.push(Node);

        // move the pieces.
        set(moveNode.init_x, moveNode.init_y, '.');
        set(moveNode.next_x, moveNode.next_y, beginPiece);
    }

    void undo(){
        if (!history.empty()){   // if history is not empty, reset pieces and pop back.
            const HistoryNode& node = history.top();

            set(node.move.init_x, node.move.init_y, node.beginPiece);
            set(node.move.next_x, node.move.next_y, node.endPiece);

            history.pop();
        }
    }

    void BoardPrint(){
        for (const auto& row : data) {
            for (char piece : row) {
                std::cout << piece << " ";
            }
            std::cout << std::endl;
        }
    }
    bool judgeTermination(){
        bool RedAlive = false;
        bool BlackAlive = false;
        for(int i = BOARD_PALACE_UP_TOP; i <= BOARD_PALACE_UP_BOTTOM ; i++){
            for(int j = BOARD_PALACE_LEFT; j <= BOARD_PALACE_RIGHT; j++){
                if(data[i][j] == 'k'){
                    BlackAlive = true;
                    break;
                }
            }
        }
        for(int i = BOARD_PALACE_DOWN_TOP; i <= BOARD_PALACE_DOWN_BOTTOM ; i++){
            for(int j = BOARD_PALACE_LEFT; j <= BOARD_PALACE_RIGHT; j++){
                if(data[i][j] == 'K'){
                    RedAlive = true;
                    break;
                }
            }
        }
        if(!RedAlive || !BlackAlive) return true;
        return false;
    }
    std::vector<std::vector<char>> & getBoard() {
        return data;
    }
    void ChessBoardClear(){
        data.clear();
    }
};

// Possible Ju Moves
void generateJuMoves_for_one_direction(const ChessBoard& cb, std::vector<Move> & pm, int32_t r, int32_t c, int xDirect, int yDirect, PlaySide side){
    //前后左右分别进行搜索，遇到棋子停止，不同阵营可以吃掉
    int32_t row, col;
    for (row = r + xDirect, col = c + yDirect; (row >= 0 && row < BOARD_ROW_LEN)&&(col >= 0 && col < BOARD_COL_LEN) ;row += xDirect, col += yDirect){
        Move cur_move = {r,c,row,col};
        if (cb.get(row,col) != '.') {
            PlaySide cur_side = (cb.get(row,col) && cb.get(row,col) <= 'Z');
            if (cur_side != side) {
                pm.push_back(cur_move);
            }
            break;
        }
        pm.push_back(cur_move);
    }
}
void generateJuMoves(const ChessBoard& cb, int32_t r, int32_t c, PlaySide side, std::vector<Move> & pm){
    // go up, down, left, right.
    generateJuMoves_for_one_direction(cb, pm, r, c, -1, 0, side);
    generateJuMoves_for_one_direction(cb, pm, r, c, +1, 0, side);
    generateJuMoves_for_one_direction(cb, pm, r, c, 0, -1, side);
    generateJuMoves_for_one_direction(cb, pm, r, c, 0, +1, side);
}

// Possible Pao Moves
void generatePaoMoves_for_one_direction(const ChessBoard& cb, std::vector<Move> & pm, int32_t r, int32_t c, int xDirect, int yDirect, PlaySide side){
    int32_t row, col;
    for (row = r + xDirect, col = c + yDirect; (row >= 0 && row < BOARD_ROW_LEN)&&(col >= 0 && col < BOARD_COL_LEN) ;row += xDirect, col += yDirect){
        Move cur_move = {r,c,row,col};
        if (cb.get(row,col) != '.') {
            break;
        }
        pm.push_back(cur_move);
    }
    for(row  +=  xDirect, col  +=  yDirect; (row >= 0 && row < BOARD_ROW_LEN)&&(col >= 0 && col < BOARD_COL_LEN) ;row += xDirect, col += yDirect){
        Move cur_move = {r,c,row,col};
        if (cb.get(row,col) != '.') {
            PlaySide cur_side = (cb.get(row,col) && cb.get(row,col) <= 'Z');
            if (cur_side != side) {
                pm.push_back(cur_move);
            }
            break;
        }
    }
}
void generatePaoMoves(const ChessBoard& cb, int32_t r, int32_t c, PlaySide side, std::vector<Move> & pm){
    // go up, down, left, right.
    generatePaoMoves_for_one_direction(cb, pm, r, c, -1, 0, side);
    generatePaoMoves_for_one_direction(cb, pm, r, c, +1, 0, side);
    generatePaoMoves_for_one_direction(cb, pm, r, c, 0, -1, side);
    generatePaoMoves_for_one_direction(cb, pm, r, c, 0, +1, side);
}

// Possible Ma Moves
void generateMaMoves(const ChessBoard& cb, int32_t x, int32_t y, PlaySide side, std::vector<Move> & pm){

    int dx[] = {2, 1, -1, -2, -2, -1,  1,  2};
    int dy[] = {1, 2,  2,  1, -1, -2, -2, -1};
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= BOARD_ROW_LEN || ny < 0 || ny >= BOARD_COL_LEN) continue;
        Move cur_move = {x,y,nx,ny};
        bool Stumbling = false;
        if(abs(dx[i])==2){
            if( dx[i]<0 && cb.get(nx+1,y) != '.')   Stumbling = true;
            else if ( dx[i] > 0 && cb.get(nx-1,y) != '.')   Stumbling = true;
        }
        else{
            if(dy[i] <0 && cb.get(x,ny+1) != '.')   Stumbling = true;
            else if (dy[i] >0 && cb.get(x,ny-1) != '.')   Stumbling = true;
        }
        if(!Stumbling){
            if ( cb.get(nx,ny) != '.') {
                PlaySide cur_side = (cb.get(nx,ny) >= 'A' && cb.get(nx,ny) <= 'Z');
                if (cur_side != side) {
                    pm.push_back(cur_move);
                }
                continue;
            }
            pm.push_back(cur_move);
        }
    }

}

// Possible Xiang Moves
void generateXiangMoves(const ChessBoard& cb, int32_t x, int32_t y, PlaySide side, std::vector<Move> & pm){

    int dx[] = {2,  2, -2, -2};
    int dy[] = {2, -2,  2, -2};
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || ny >= BOARD_COL_LEN) continue;
        if (side  && (nx >= BOARD_ROW_LEN || nx <= BOARD_RIVER_UP)) continue;  
        if (!side && (nx < 0  ||  nx >= BOARD_RIVER_DOWN))  continue;
        Move cur_move = {x,y,nx,ny};
        bool Stumbling = ( cb.get(x+dx[i]/2, y+dy[i]/2) != '.');
        if(!Stumbling){
            if ( cb.get(nx,ny) != '.') {
                PlaySide cur_side = (cb.get(nx,ny) >= 'A' && cb.get(nx,ny) <= 'Z');
                if (cur_side != side) {
                    pm.push_back(cur_move);
                }
                continue;
            }
            pm.push_back(cur_move);
        }
    }
}

// Possible Shi Moves
void generateShiMoves(const ChessBoard& cb, int32_t x, int32_t y, PlaySide side, std::vector<Move> & pm){

    int dx[] = {1,  1, -1, -1};
    int dy[] = {1, -1,  1, -1};
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < BOARD_PALACE_LEFT || ny > BOARD_PALACE_RIGHT ) continue;
        if(side  && (nx > BOARD_PALACE_DOWN_BOTTOM || nx < BOARD_PALACE_DOWN_TOP))  continue;  //士的范围
        if(!side && (nx < BOARD_PALACE_UP_TOP || nx > BOARD_PALACE_UP_BOTTOM))  continue;
        Move cur_move = {x,y,nx,ny};
        if ( cb.get(nx,ny) != '.') {
            PlaySide cur_side = (cb.get(nx,ny) >= 'A' && cb.get(nx,ny) <= 'Z');
            if (cur_side != side) {
                pm.push_back(cur_move);
            }
            continue;
        }
        pm.push_back(cur_move);
    }
}

// Possible Jiang Moves
void generateJiangMoves(const ChessBoard& cb, int32_t x, int32_t y, PlaySide side, std::vector<Move> & pm){

    int dx[] = {1, -1,  0, 0};
    int dy[] = {0,  0, -1, 1};
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < BOARD_PALACE_LEFT || ny > BOARD_PALACE_RIGHT ) continue;
        if(side  && (nx > BOARD_PALACE_DOWN_BOTTOM || nx < BOARD_PALACE_DOWN_TOP))  continue;  
        if(!side && (nx < BOARD_PALACE_UP_TOP || nx > BOARD_PALACE_UP_BOTTOM))  continue;
        Move cur_move = {x,y,nx,ny};
        if ( cb.get(nx,ny) != '.') {
            PlaySide cur_side = (cb.get(nx,ny) >= 'A' && cb.get(nx,ny) <= 'Z');
            if (cur_side != side) {
                pm.push_back(cur_move);
            }
            continue;
        }
        pm.push_back(cur_move);
    }
}

// Possible Bing Moves
void generateBingMoves_for_one_direction(const ChessBoard& cb, std::vector<Move> & pm, int32_t x, int32_t y, int Direct, bool CrossRiver, PlaySide side){
    //前后左右分别进行搜索，遇到棋子停止，不同阵营可以吃掉
    int32_t row, col;
    std::vector<int> dx, dy;
    if (CrossRiver) {
        dx = {0, 0, Direct};
        dy = {-1, 1, 0};
    }
    else {
        dx = {Direct};
        dy = {0};
    }
    for(int i = 0; i < dx.size(); i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= BOARD_ROW_LEN || ny < 0 || ny >= BOARD_COL_LEN) continue;
        Move cur_move = {x,y,nx,ny};
        if ( cb.get(nx,ny) != '.') {
            PlaySide cur_side = (cb.get(nx,ny) >= 'A' && cb.get(nx,ny) <= 'Z');
            if (cur_side != side) {
                pm.push_back(cur_move);
            }
            continue;
        }
        pm.push_back(cur_move);
    }

}
void generateBingMoves(const ChessBoard& cb, int32_t x, int32_t y, PlaySide side, std::vector<Move> & pm){
    if(side){
        if(x <= BOARD_RIVER_UP)  generateBingMoves_for_one_direction(cb, pm, x, y,  -1, true, side);
        else generateBingMoves_for_one_direction(cb, pm, x, y,  -1, false, side);
    }
    else{
        if(x >= BOARD_RIVER_DOWN)  generateBingMoves_for_one_direction(cb, pm, x, y,  1, true, side);
        else generateBingMoves_for_one_direction(cb, pm, x, y,  1, false, side);
    }
}