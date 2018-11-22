//
// Created by Rodrigo Broggi on 21/11/18.
//
#include <boost/uuid/uuid_io.hpp>
#include "User.h"

const std::string &User::getName() const {
  return name;
}

double User::getSalary() const {
  return salary;
}

const boost::uuids::uuid &User::getId() const {
  return id;
}

User::User(const std::string &name, double salary) : name(name), salary(salary) {}
std::ostream &operator<<(std::ostream &os, const User &user) {
  os << "name: " << user.name << " salary: " << user.salary << " id: " << user.id;
  return os;
}
