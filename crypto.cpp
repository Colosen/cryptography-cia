//
// Created by Jitheesh V J on 4/12/25.
//

#include <iostream>
#include <string>

std::string caesar_encrypt(const std::string& m, int k) {
  std::string c;
  for (const char i : m) {
    int encoded_value = static_cast<int>(i) - static_cast<int>('a');
    int encrypted_value = (encoded_value + k) % 26;
    int decoded_value = encrypted_value + static_cast<int>('a');
    c += (char) decoded_value;
  }

  return c;
}

std::string caesar_decrypt(const std::string& c, int k) {
  std::string m;
  for (const char i : c) {
    int encoded_value = static_cast<int>(i) - static_cast<int>('a');
    int decrypted_value = (encoded_value - k) % 26;
    int decoded_value = decrypted_value + static_cast<int>('a');
    m += (char) decoded_value;
  }

  return m;
}

std::string atbash(const std::string& m) {
  std::string c;
  for (const char i : m) {
    c += static_cast<char>(2 * static_cast<int>('a') + 26 - i - 1);
  }

  return c;
}

std::string atbash_encrypt(const std::string& m) {
  return atbash(m);
}

std::string atbash_decrypt(const std::string& c) {
  return atbash(c);
}

std::string august_encrypt(const std::string &m) {
  return caesar_encrypt(m, 1);
}

std::string august_decrypt(const std::string &c) {
  return caesar_decrypt(c, 1);
}

std::string affine_encrypt(const std::string &m, int A, int B) {
  std::string c;
  for (char i : m) {
    int j = i - static_cast<int>('a');
    j = (A * j + B) % 26;
    i = static_cast<char>(static_cast<int>('a') + j);
    c += i;
  }

  return c;
}

std::string affine_decrypt(const std::string &c, int A, int B) {
  std::string m;
  for (char i : c) {
    int j = i - static_cast<int>('a');
    j = (A * j + B) % 26;
    i = static_cast<char>(static_cast<int>('a') + j);
    m += i;
  }

  return m;
}