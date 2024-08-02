#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>
#include <stack>
#include <string>
#include "Chess.h"

std::vector<Move> gen_possible_moves(const ChessBoard& cb, PlaySide side){
	std::vector<Move> pm;
    char p;
    for (int32_t r = 0; r < BOARD_ROW_LEN; ++r) {
        for (int32_t c = 0; c < BOARD_COL_LEN; ++c){
            p = cb.get(r, c);
            if( side == RED){
                switch (p) {
                    case 'R':
                        generateJuMoves(cb, r, c, side, pm);
                        break;
                    case 'C':
                        generatePaoMoves(cb, r, c, side, pm);
                        break;
                    case 'N':
                        generateMaMoves(cb, r, c, side, pm);
                        break;
                    case 'B':
                        generateXiangMoves(cb, r, c, side, pm);
                        break;
                    case 'A':
                        generateShiMoves(cb,  r, c, side, pm);
                        break;
                    case 'K':
                        generateJiangMoves(cb,  r, c, side, pm);
                        break;
                    case 'P':
                        generateBingMoves(cb, r, c, side, pm);
                        break;
                    default:
                        break;
                }
            }
            else{
                switch( p ){
                    case 'r':
                        generateJuMoves(cb, r, c, side, pm);
                        break;
                    case 'c':
                        generatePaoMoves(cb, r, c, side, pm);
                        break;
                    case 'n':
                        generateMaMoves(cb, r, c, side, pm);
                        break;
                    case 'b':
                        generateXiangMoves(cb, r, c, side, pm);
                        break;
                    case 'a':
                        generateShiMoves(cb, r, c, side, pm);
                        break;
                    case 'k':
                        generateJiangMoves(cb, r, c, side, pm);
                        break;
                    case 'p':
                        generateBingMoves(cb, r, c, side, pm);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    return pm;
}

int evaluateNode(ChessBoard& cb) {
    //TODO
    int max = 0;  //红方
    int min = 0;  //黑方
    for(int i = 0; i < BOARD_ROW_LEN; i++){
        for(int j = 0; j < BOARD_COL_LEN; j++){
            switch (cb.get(i,j))
            {
            case 'r': 
                min += 500 + JuPosition[j][i];
                break;
            case 'R': 
                max += 500 + JuPosition[j][9 -i];
                break;
            case 'k': 
                min += 10000 + JiangPosition[j][i];
                break;
            case 'K': 
                max += 10000 + JiangPosition[j][9 - i];
                break;
            case 'n':
                min += 300 + MaPosition[j][i];
                break;
            case 'N': 
                max += 300 + MaPosition[j][9 - i];
                break;
            case 'b':
                min += 30 + XiangPosition[j][i];
                break;
            case 'B': 
                max += 30 + XiangPosition[j][9 - i];
                break;
            case 'a': 
                min += 10 + ShiPosition[j][i];
                break; 
            case 'A': 
                max += 10 + ShiPosition[j][9 - i];
                break;
            case 'c': 
                min += 300 + PaoPosition[j][i];
                break;
            case 'C': 
                max += 300 +  PaoPosition[j][9 - i];
                break;
            case 'p': 
                min += 90 + BingPosition[j][i];
                break;
            case 'P': 
                max += 90 + BingPosition[j][9 - i];
                break;
            default:
                break;
            }
        }
    }
    return max - min;
}

void PrintMove(Move move, PlaySide side){
    if(side == RED) std::cout << "RED:"<< std::endl;
    else  std::cout << "BLACK:"<< std::endl;
    std::cout << '(' << move.init_x << ',' << move.init_y << ')' <<
                "--->" << '(' <<  move.next_x << ',' << move.next_y << ')' << std::endl;
}

// min-max algorithm, with alpha-beta pruning.
int32_t min_max(ChessBoard& cb, int32_t searchDepth, int32_t alpha, int32_t beta, PlaySide side){
    if (searchDepth == 0){
        return evaluateNode(cb);
    }

    int32_t minMaxValue;
    if (side == BLACK){
        int32_t minValue = std::numeric_limits<int32_t>::max();
        std::vector<Move> possibleMoves = gen_possible_moves(cb, BLACK);

        for (const Move& node : possibleMoves) {
            cb.move(node);
            minMaxValue = min_max(cb, searchDepth - 1, alpha, beta, RED);
            minValue = std::min(minValue, minMaxValue);
            cb.undo();

            beta = std::min(beta, minValue);
            if (alpha >= beta){
                break;
            }
        }

        return minValue;
    }
    else if (side == RED){
        int32_t maxValue = std::numeric_limits<int32_t>::min();
        std::vector<Move> possibleMoves = gen_possible_moves(cb, RED);

        for (const Move& node : possibleMoves) {
            cb.move(node);
            minMaxValue = min_max(cb, searchDepth - 1, alpha, beta, BLACK);
            maxValue = std::max(maxValue, minMaxValue);
            cb.undo();

            alpha = std::max(alpha, maxValue);
            if (alpha >= beta){
                break;
            }
        }

        return maxValue;
    }
    else return 0;
}
/* 
    gen best move for one side. 
    searchDepth is used as difficulty rank, the bigger it is, the more time the generation costs.
    give param enum PieceSide: PS_EXTRA to this function is meaningless, you will always get a struct MoveNode object with {0, 0, 0, 0}.
*/
Move gen_best_move(ChessBoard& cb, PlaySide side, int32_t searchDepth){
    int32_t value;
    int32_t alpha = std::numeric_limits<int32_t>::min();
    int32_t beta = std::numeric_limits<int32_t>::max();

    Move bestMove;

    if (side == BLACK){
        int32_t minValue = beta;
        std::vector<Move> possibleMoves = gen_possible_moves(cb, BLACK);

        for (const Move & node : possibleMoves){
            cb.move(node);
            value = min_max(cb, searchDepth, alpha, beta, RED);
            cb.undo();

            if (value <= minValue){
                minValue = value;
                bestMove = node;
            }
        }
    }
    else {
        int32_t maxValue = alpha;
        std::vector<Move> possibleMoves  = gen_possible_moves(cb, RED);

        for (const Move& node : possibleMoves){
            cb.move(node);
            value = min_max(cb, searchDepth, alpha, beta, BLACK);
            cb.undo();

            if (value >= maxValue){
                maxValue = value;
                bestMove = node;
            }
        }
    }
    
    return bestMove;
}

int main() {
    ChessBoard cb;
    std::string path = "../input/";
    for(int i = 1; i <= 10; i++){
        std::string path = "../input/" + std::to_string(i) + ".txt";
        std::ifstream file(path);
        std::string line;
        int n = 0;
        while (std::getline(file, line)) {
            std::vector<char> row;
        
            for (char ch : line) {
                row.push_back(ch);
            }

            cb.getBoard().push_back(row);
            n = n + 1;
            if (n >= 10) break;
        }
        Move aiMove = gen_best_move(cb, RED, DEFAULT_AI_SEARCH_DEPTH);
        std::ofstream outfile;
        outfile.open("../output/output_" + std::to_string(i) + ".txt"); 
        if (outfile.is_open()) {
            std::string str = std::string(1, cb.get(aiMove.init_x,aiMove.init_y));
            std::string record =    str
                                    + '(' + std::to_string(aiMove.init_x) + ',' + std::to_string(aiMove.init_y) + ')' + ' '
                                    + '(' + std::to_string(aiMove.next_x) + ',' + std::to_string(aiMove.next_y) + ')';
            outfile << record << std::endl; // 将记录写入文件
            outfile.close(); // 关闭文件
        }
        cb.ChessBoardClear();
        file.close();
    }

}