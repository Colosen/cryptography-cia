//
// Created by Jitheesh V J on 4/12/25.
//

#include <iostream>
#include <string>
#include <utility>

std::string caesar_encrypt(const std::string& m, int k) {
  std::string c;
  for (const char i : m) {
    int encoded_value = static_cast<int>(i) - static_cast<int>('a');
    int encrypted_value = (encoded_value + k) % 26;
    int decoded_value = encrypted_value + static_cast<int>('a');
    c += static_cast<char>(decoded_value);
  }

  return c;
}

std::string caesar_decrypt(const std::string& c, int k) {
  std::string m;
  for (const char i : c) {
    int encoded_value = static_cast<int>(i) - static_cast<int>('a');
    int decrypted_value = (encoded_value - k) % 26;
    int decoded_value = decrypted_value + static_cast<int>('a');
    m += static_cast<char>(decoded_value);
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

int gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int mod_mul_inv(int a, int m) {
  int x, y;
  int g = gcd(a, m, x, y);
  if (g != 1) {
    std::cout << "No solution for modular multiplicative inverse!" << std::endl;
    return -1;
  }

  x = (x % m + m) % m;
  return x;
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
    int A_inv = mod_mul_inv(A, 26);
    j = (A_inv * (j - B) + 26) % 26;
    i = static_cast<char>(static_cast<int>('a') + j);
    m += i;
  }

  return m;
}

std::string vignere_encrypt(const std::string m, const std::string k) {
  std::string c;
  int k_index = 0;
  for (const char i : m) {
    int j = (static_cast<int>(i) + static_cast<int>(k[k_index]) - 2 * static_cast<int>('a')) % 26 + static_cast<int>('a');
    k_index = (k_index + 1) % static_cast<int>(k.size());
    c += static_cast<char>(j);
  }

  return c;
}

std::string vignere_decrypt(const std::string c, const std::string k) {
  std::string m;
  int k_index = 0;
  for (const char i : c) {
    int j = (static_cast<int>(i) + 26 - static_cast<int>(k[k_index])) % 26 + static_cast<int>('a');
    k_index = (k_index + 1) % static_cast<int>(k.size());
    m += static_cast<char>(j);
  }

  return m;
}

std::string beaufort_encrypt(const std::string m, int k) {
  std::string c;
  for (const char i : m) {
    int encoded_value = static_cast<int>(i) - static_cast<int>('a');
    int encrypted_value = (51 - k + static_cast<int>('a') - i) % 26;
    int decoded_value = encrypted_value + static_cast<int>('a');
    c += static_cast<char>(decoded_value);
  }

  return c;
}

std::string beaufort_decrypt(const std::string c, int k) {
  std::string m;
  for (const char i : c) {
    int encoded_value = static_cast<int>(i) - static_cast<int>('a');
    int decrypted_value = (51 - k + static_cast<int>('a') - i) % 26;
    int decoded_value = decrypted_value + static_cast<int>('a');
    m += static_cast<char>(decoded_value);
  }

  return m;
}

std::string autokey_gen_master_key(const std::string key, const std::string m) {
  if (key.size() >= m.size()) {
    return key;
  }

  std::string master_key = key;
  int m_index = 0;
  while (master_key.size() < m.size()) {
    master_key += m[m_index];
    m_index = (m_index + 1) % static_cast<int>(m.size());
  }
}

std::string autokey_encrypt(const std::string m, std::string k) {
  std::string master_key = autokey_gen_master_key(std::move(k), m);
  std::string c;
  for (int i = 0; i < m.size(); i++) {
    int j = static_cast<int>(m[i]) - static_cast<int>('a');
    j = (j + static_cast<int>(k[i])) % 26 + static_cast<int>('a');
    c += static_cast<char>(j);
  }

  return c;
}

std::string autokey_decrypt(const std::string c, std::string k) {
  std::string master_key = autokey_gen_master_key(std::move(k), c);
  std::string m;
  for (int i = 0; i < c.size(); i++) {
    int j = static_cast<int>(c[i]) - static_cast<int>('a');
    j = (j + static_cast<int>(k[i])) % 26 + static_cast<int>('a');
    m += static_cast<char>(j);
  }

  return m;
}
