//
// Created by Jitheesh V J on 4/12/25.
//

#include <iostream>

#include "crypto.h"

int main()
{
  std::string c = caesar_encrypt("helloworld", 1);
  std::cout << c << std::endl;
  std::cout << caesar_decrypt(c, 1) << std::endl;

  c = atbash_encrypt("abcd");
  std::cout << c << std::endl;
  std::cout << atbash_decrypt(c) << std::endl;

  c = august_encrypt("helloworld");
  std::cout << c << std::endl;
  std::cout << august_decrypt(c) << std::endl;

  c = affine_encrypt("helloworld", 3, 5);
  std::cout << c << std::endl;
  std::cout << affine_decrypt(c, 3, 5) << std::endl;

  const std::string k = "mykey";
  c = vignere_encrypt("hellohello", k);
  std::cout << c << std::endl;
  std::cout << vignere_decrypt(c, k) << std::endl;

  c = beaufort_encrypt("helloworld", 1);
  std::cout << c << std::endl;
  std::cout <<  beaufort_decrypt(c, 1) << std::endl;

  c = autokey_encrypt("helloworld", k);
  std::cout << c << std::endl;
  std::cout <<  autokey_decrypt(c, k) << std::endl;
}
