//
// Created by Rodrigo Broggi on 21/11/18.
//

#ifndef CAP13_USER_H
#define CAP13_USER_H
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <ostream>

class User {
 public:
  User(const std::string &name, double salary);
  const std::string &getName() const;
  double getSalary() const;
  const boost::uuids::uuid &getId() const;
  friend std::ostream &operator<<(std::ostream &os, const User &user);
 private:
  const std::string name;
  double salary;
  const boost::uuids::uuid id = boost::uuids::random_generator()();
};

#endif //CAP13_USER_H
