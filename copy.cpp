#include <iostream>
#include <memory>
#include <vector>
#include "CopyData.h"
#include "NonCopyData.h"
#include "User.h"
#include "BugClass.h"
#include "CopyRefData.h"
#include "PointerLikeData.h"

void copy_constructor();
template <typename T>
void print(T copyData) {
  std::cout << copyData << std::endl;
}

template <typename T>
void print_ref(T &copyData) {
  std::cout << copyData << std::endl;
}

int main() {
  {
    CopyData copyData{};
    print(copyData);
    print_ref(copyData);
  }

  {
    NonCopyData nonCopyData(5);
    //The following call can't be done because the
    //default copy constructor will be deleted since one of the
    //class members (unique_ptr) can't be copied
    //print(nonCopyData);
    print_ref(nonCopyData);
  }

  //Creation of objects and allocations with copy-constructor
  copy_constructor();

  //change condition for the breaking example of wrong usage of Copy/destructor
  //Big Bug - usually when destructor is defined also the copy consutructor and copy-assingnment
  //need to be defined
  if (false) {
    BugClass bugClass(User("Rod", 30000.));
    {
      BugClass bugClass1(bugClass);
    }
  }

  {
    std::string str("rod");
    CopyRefData copyRefData(str, 29);
    CopyRefData copyRefData1(copyRefData);
    std::cout << copyRefData << std::endl;
    std::cout << copyRefData1 << std::endl;
    std::string str2("rod2");
    copyRefData.setName(str2);
    std::cout << copyRefData << std::endl;
    std::cout << copyRefData1 << std::endl;
  }

  {
    PointerLikeData pointerLikeData("Rod", 29);
    std::cout << "Refs count " << pointerLikeData.getRefs() << std::endl;
    {
      PointerLikeData pointerLikeData1(pointerLikeData);
      std::cout << "Refs count " << pointerLikeData.getRefs() << std::endl;
      std::cout << "Refs count " << pointerLikeData1.getRefs() << std::endl;
      PointerLikeData pointerLikeData2 = pointerLikeData;
      std::cout << "Refs count " << pointerLikeData.getRefs() << std::endl;
      std::cout << "Refs count " << pointerLikeData1.getRefs() << std::endl;
      std::cout << "Refs count " << pointerLikeData2.getRefs() << std::endl;
    }
    std::cout << "Refs count " << pointerLikeData.getRefs() << std::endl;
  }

  return 0;
}

void copy_constructor() {
    User *usr_ptr = new User("Rodrigo", 40000.);
    std::__1::cout << "First user: " << *usr_ptr << std::__1::endl;

    auto usr_shared_ptr = std::__1::make_shared<User>("Fernanda", 42000.);
    std::__1::cout << "Second user: " << *usr_shared_ptr << std::__1::endl;

    //Copy constructor
    User usr_cp(*usr_ptr);
    std::__1::cout << "First user copy: " << usr_cp << std::__1::endl;

    //Copy constructor
    std::__1::vector<User> vec{*usr_ptr, *usr_shared_ptr, usr_cp};

    delete usr_ptr;
    std::__1::cout << "[";
    for (auto& el: vec) {
      std::__1::cout << el << ",";
    }
    std::__1::cout << "]" << std::__1::endl;
  }