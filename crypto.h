//
// Created by Jitheesh V J on 4/12/25.
//

#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <vector>

std::string caesar_encrypt(const std::string& m, int k);

std::string caesar_decrypt(const std::string& c, int k);

std::string atbash_encrypt(const std::string& m);

std::string atbash_decrypt(const std::string& c);

std::string august_encrypt(const std::string &m);

std::string august_decrypt(const std::string &c);

std::string affine_encrypt(const std::string &m, int A, int B);

std::string affine_decrypt(const std::string &c, int A, int B);

std::string vignere_encrypt(const std::string m, const std::string k);

std::string vignere_decrypt(const std::string c, const std::string k);

std::string beaufort_encrypt(const std::string m, int k);

std::string beaufort_decrypt(const std::string c, int k);

std::string autokey_encrypt(const std::string m, std::string k);

std::string autokey_decrypt(const std::string c, std::string k);

std::string hill_encrypt(const std::string m, const std::vector<std::vector<int>> k);

std::string hill_decrypt(const std::string c, const std::vector<std::vector<int>> k);

#endif //CRYPTO_H
