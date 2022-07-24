#pragma once

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
  char ID[11];
  char password[16];

public:
  void createUsers(const char *, const char *);
  void varifyUsers();
};

class MyException : public runtime_error {
private:
  string msg;

public:
  explicit MyException(const string &msg) : runtime_error(msg) {}
};
