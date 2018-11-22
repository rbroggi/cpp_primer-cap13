//
// Created by Rodrigo Broggi on 22/11/18.
//

#ifndef CAP13_POINTERLIKEDATA_H
#define CAP13_POINTERLIKEDATA_H
#include <string>
#include <atomic>

/**
 *
 * \brief This class is a sample of a class that behave like a shared_ptr.
 *
 *
 */
class PointerLikeData {
 public:
  PointerLikeData(const std::string str, int _num) : ptr(new std::string(str)), num(_num), refs(new std::atomic_uint(1)){}

  /**
   * @param const PointerLikeData& - reference to
   * @brief copy constructor
   *    \li copy ptr to data pointing to same underlying heap memory address
   *    \li copy values that are not pointers
   *    \li increments the reference count of rhs object
   *    \li decrements the reference count of the lhs object
   *    \li if after decreasing ref count on lhs it becomes zero then the memory data is freed (delete)
   */
  PointerLikeData(const PointerLikeData&);
  ~PointerLikeData();
  PointerLikeData& operator=(const PointerLikeData&);
  const std::string getPtr() const;
  int getNum() const;
  unsigned  int getRefs() const;

 private:
  std::string* ptr;
  int num;
  std::atomic<unsigned int>* refs;

};

#endif //CAP13_POINTERLIKEDATA_H
