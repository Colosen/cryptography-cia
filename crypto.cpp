//
// Created by Jitheesh V J on 4/12/25.
//

#include <iostream>
#include <string>
#include <utility>
#include <vector>

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

std::string autokey_gen_master_key(const std::string& key, const std::string& m) {
  if (key.size() >= m.size()) {
    return key;
  }

  std::string master_key = key;
  int m_index = 0;
  while (master_key.size() < m.size()) {
    master_key += m[m_index];
    m_index = (m_index + 1) % static_cast<int>(m.size());
  }

  return master_key;
}

std::string autokey_encrypt(const std::string& m, const std::string& k) {
  std::string master_key = autokey_gen_master_key(k, m);
  std::string c;
  for (int i = 0; i < m.size(); i++) {
    int j = static_cast<int>(m[i]) - static_cast<int>('a');
    j = (j + static_cast<int>(master_key[i]) - static_cast<int>('a')) % 26 + static_cast<int>('a');
    c += static_cast<char>(j);
  }

  return c;
}

std::string autokey_decrypt(const std::string& c, std::string k) {
  std::string m;
  for (int i = 0; i < c.size(); i++) {
    int j = static_cast<int>(c[i]) - static_cast<int>('a');
    j = (j + 26 - (static_cast<int>(k[i]) - static_cast<int>('a'))) % 26 + static_cast<int>('a');
    m += static_cast<char>(j);
    k += m[i];
  }

  return m;
}

std::vector<int> string_encode(const std::string& m) {
  std::vector<int> encoded_string;
  for (char c : m) {
    int i = static_cast<int>(c) - static_cast<int>('a');
    encoded_string.push_back(i);
  }

  return encoded_string;
}

std::string string_decode(std::vector<int> encoded_string) {
  std::string decoded_string;
  for (int c : encoded_string) {
    int i = static_cast<int>(c) + static_cast<int>('a');
    decoded_string += i;
  }

  return decoded_string;
}

std::vector<std::vector<int>> trigrammize(const std::vector<int>& encoded_string) {
  std::vector<std::vector<int>> trigrams;

  int counter = 0;
  for (int c : encoded_string) {
    trigrams[counter / 3][counter % 3] = c;
  }
  return trigrams;
}

std::vector<int> untrigrammize(const std::vector<std::vector<int>>& trigrams) {
  std::vector<int> encoded_string;

  int counter = 0;
  for (std::vector<int> trigram : trigrams) {
    for (int a : trigram) {
      encoded_string.push_back(a);
    }
  }
  return encoded_string;
}

std::vector<int> mat_mul(std::vector<std::vector<int>> k, std::vector<int> trigram) {
  std::vector<int> encrypted_trigram(3, 0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      encrypted_trigram[i] += k[i][j] * trigram[j];
    }
  }
  return encrypted_trigram;
}

std::string hill_encrypt(const std::string& m, const std::vector<std::vector<int>>& k) {
  // convert plaintext to integer vector
  std::vector<int> encoded_m = string_encode(m);

  // convert to trigrams
  std::vector<std::vector<int>> trigrams = trigrammize(encoded_m);
  std::vector<std::vector<int>> encrypted_trigrams;
  for (std::vector<int> trigram : trigrams) {
    std::vector<int> encrypted_trigram = mat_mul(k, trigram);
    encrypted_trigrams.push_back(encrypted_trigram);
  }

  std::vector<int> encoded_s = untrigrammize(encrypted_trigrams);
  std::string ciphertext = string_decode(encoded_s);

  return ciphertext;
}

std::string hill_decrypt(const std::string c, const std::vector<std::vector<int>> k) {
  // convert ciphertext into integer vector
  std::vector<int> encoded_c = string_encode(c);

  // convert to trigrams
  std::vector<std::vector<int>> trigrams = trigrammize(encoded_c);
  std::vector<std::vector<int>> decrypted_trigrams;
  for (std::vector<int> trigram : trigrams) {
    std::vector<int> decrypted_trigram = mat_mul(k, trigram);
    decrypted_trigrams.push_back(decrypted_trigram);
  }

  std::vector<int> encoded_m = untrigrammize(decrypted_trigrams);
  std::string plaintext = string_decode(encoded_m);

  return plaintext;
}