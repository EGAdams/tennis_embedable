#ifndef TRANSLATECONSTANT_H
#define TRANSLATECONSTANT_H

#pragma once
#include <map>
#include <string>

class TranslateConstant {
 public:
  TranslateConstant();
  ~TranslateConstant();
  std::string get_translated_constant(int the_constant);
  std::string get_translated_digital_mode(int the_constant);

 private:
  std::map<int, std::string> _map_constant_to_string;
  std::map<int, std::string> _digital_mode_to_string;
};

#endif
