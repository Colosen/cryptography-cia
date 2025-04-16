//
// Created by Jitheesh V J on 4/16/25.
//

#include <iostream>
#include <vector>

int determinant(int a11, int a12, int a21, int a22) {
  return a11 * a21 - a12 * a22;
}

int determinant(std::vector<std::vector<int>> mat) {
  if (mat.size() != 3 || mat[0].size() != 3) {
    std::cout << "Improper matrix size!" << std::endl;
    return -1;
  }

  return mat[0][0] * determinant(mat[1][1], mat[1][2], mat[2][1], mat[2][2])
          - mat[0][1] * determinant(mat[0][1], mat[0][2], mat[2][0], mat[2][2])
          + mat[0][2] * determinant(mat[1][1], mat[1][2], mat[2][1], mat[2][2]);
}

int determinant(std::vector<std::vector<int>> mat, int row, int col) {
  if (mat.size() != 3 || mat[0].size() != 3) {
    std::cout << "Improper matrix size!" << std::endl;
    return -1;
  }

}

int minor(std::vector<std::vector<int>> mat, int row, int col) {

}