//
// Created by Rodrigo Broggi on 22/11/18.
//

#ifndef CAP13_VALUELIKEDATA_H
#define CAP13_VALUELIKEDATA_H
#include <string>

// class with a 'value-like' behavior (not 'pointer-like')
class ValueLikeData {
 public:
  ValueLikeData(std::string , int);
  ValueLikeData(const ValueLikeData&);

  ValueLikeData& operator=(const ValueLikeData&);

  ~ValueLikeData();
 private:
  std::string* ptr;
  int num;

};

#endif //CAP13_VALUELIKEDATA_H
