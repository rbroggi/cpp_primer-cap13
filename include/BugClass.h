//
// Created by Rodrigo Broggi on 21/11/18.
//

#ifndef CAP13_BUGCLASS_H
#define CAP13_BUGCLASS_H

#include "User.h"

//Example of Bug due to usage of Default copy constructor and defined destructor
class BugClass {
 public:
  BugClass(User user) : user(new User(user)) {}
  BugClass(const BugClass&) = default;

 public:
  virtual ~BugClass();
 private:
  User* user;
};

#endif //CAP13_BUGCLASS_H
