#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>>& matrix);
void printMatrix(std::vector<std::vector<int>> matrix);

int main(int argc, char** argv)
{
    std::vector<std::vector<int>> matrix;
    matrix.push_back({1,1,1,1,1 });
    matrix.push_back({2,2,2,2,2});
    matrix.push_back({3,3,3,3,3});
    matrix.push_back({4,4,4,4,4});
    matrix.push_back({5,5,5,5,5});

    std::vector<std::vector<int>> matrix2;
    matrix2.push_back({1,1,1,1 });
    matrix2.push_back({2,2,2,2});
    matrix2.push_back({3,3,3,3});
    matrix2.push_back({4,4,4,4});

    std::vector<std::vector<int>> matrix3;
    matrix3.push_back({1,1,1});
    matrix3.push_back({2,2,2});
    matrix3.push_back({3,3,3});

    printMatrix(matrix2);
    rotate(matrix2);
    std::cout << std::endl;
    printMatrix(matrix2);

    return 0;
}

void rotate(std::vector<std::vector<int>>& matrix) {
    int posX = 0;
    int posY = 0;
    int startX = 0;
    int startY = 0;
    int size = matrix.size();
    int count;
    int capture = matrix[0][0];
    int writes = 0;
    int resets = 0;

    if(matrix.size()%2 == 0)
        count = size * size;
    else
        count = size * size -1;
        
    for(int i = 0; i < size*size -1; i++){ 
        int newX = posY;
        int newY = matrix.size() - (1 + posX);

        int store = matrix[newX][newY];

        matrix[newX][newY] = capture;
        writes++;
        if(writes == 4){
            if(resets == matrix.size() - 2){
                posX = startX++;
                posY = startY++;
                resets = 0;
                writes = 0;
                store = matrix[posX][posY];
            } 
            else {
                posX = newX;
                posY = newY + 1;
                resets++;
                writes = 0;
                store = matrix[posX][posY];
            }
        }
        else {
            posX = newX;
            posY = newY;
        }
        capture = store;
        printMatrix(matrix);
        std::cout << "--------\n";
    } 
}

void printMatrix(std::vector<std::vector<int>> matrix){
    for(int i=0; i < matrix.size(); i++){
        for(int j=0; j < matrix.size(); j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl << std::endl;
    }
}