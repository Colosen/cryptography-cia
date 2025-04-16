//
// Created by Jitheesh V J on 4/16/25.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

int determinant(int a11, int a12, int a21, int a22);

int determinant(std::vector<std::vector<int>> mat);

int minor(std::vector<std::vector<int>> mat, int row, int col);

std::vector<std::vector<int>> inverse(std::vector<std::vector<int>> mat, int row, int col);

#endif // MATRIX_H
