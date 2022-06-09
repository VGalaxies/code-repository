#include "exception.h"

void User::createUsers(const char *id, const char *passwd) {
  assert(id != nullptr && passwd != nullptr);

  if (!isupper(id[0]) && id[0] != '_') {
    throw(-1);
  }
  for (size_t i = 1; i < strlen(id); ++i) {
    if (!isalnum(id[i])) {
      throw "ID contains special characters."s;
    }
  }
  if (strlen(id) >= 11) {
    throw MyException("ID is too long.");
  }

  int passwd_length = strlen(passwd);
  if (passwd_length < 6) {
    throw "Password is too short."s;
  }
  if (passwd_length >= 16) {
    throw MyException("Password is too long.");
  }

  strcpy(ID, id);
  strcpy(password, passwd);

  fstream file("user.dat", ios::app);
  if (!file.is_open()) {
    throw MyException("File cannot open.");
  }
  file << ID << " " << passwd << endl;
  file.close();
}

void User::varifyUsers() {
  fstream file("user.dat", ios::in);
  if (!file.is_open()) {
    throw MyException("File cannot open.");
  }

  bool found_flag = false;
  while (!file.eof() && !found_flag) {
    string temp;
    getline(file, temp);
    if (temp.find(this->ID) != string::npos) {
      found_flag = true;
      if (temp.find(this->password) == string::npos) {
        throw MyException("Password is wrong.");
      }
    }
  }

  if (!found_flag) {
    throw "No such ID."s;
  }

  cout << "Pass." << endl;
  file.close();
}

void clear_file() {
  fstream file("user.dat", ios::out);
  if (!file.is_open()) {
    throw MyException("File cannot open.");
  }
  file.close();
}

void correct() {
  User user;
  user.createUsers("VGalaxy", "12345678");
  user.varifyUsers();
}

void special_character_wrong() {
  User user;
  user.createUsers("V?alaxy", "12345678");
  user.varifyUsers();
}

void first_character_wrong() {
  User user;
  user.createUsers("?Galaxy", "12345678");
  user.varifyUsers();
}

void id_too_long_wrong() {
  User user;
  user.createUsers("VGalaxyVincent", "12345678");
  user.varifyUsers();
}

void passwd_too_short_wrong() {
  User user;
  user.createUsers("VGalaxy", "12345");
  user.varifyUsers();
}

void passwd_too_long_wrong() {
  User user;
  user.createUsers("VGalaxy", "12345123451234512345");
  user.varifyUsers();
}

void no_such_id_wrong() {
  User user;
  user.createUsers("VGalaxy", "12345678");

  clear_file();

  user.varifyUsers();
}

void passwd_wrong() {
  User user;
  user.createUsers("VGalaxy", "12345678");

  clear_file();
  fstream file("user.dat", ios::app);
  if (!file.is_open()) {
    throw MyException("File cannot open.");
  }
  file << "VGalaxy"
       << " "
       << "123456" << endl;
  file.close();

  user.varifyUsers();
}

int main() {
  vector<void (*)(void)> tests;
  tests.push_back(correct);
  tests.push_back(first_character_wrong);
  tests.push_back(special_character_wrong);
  tests.push_back(id_too_long_wrong);
  tests.push_back(passwd_too_short_wrong);
  tests.push_back(passwd_too_long_wrong);
  tests.push_back(no_such_id_wrong);
  tests.push_back(passwd_wrong);

  for (auto test : tests) {
    try {
      clear_file();
      test();
    } catch (int) {
      cout << "The first character of ID is invalid." << endl;
    } catch (string msg) {
      cout << msg << endl;
    } catch (MyException &ex) {
      cout << ex.what() << endl;
    }
  }
}
