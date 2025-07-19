///************************* OUTS HOMEWORK ****************************************
#ifndef CGAMEFIELD_HPP
#define CGAMEFIELD_HPP

#include "cObject.hpp"
#include <vector>

class cGameField
{
public:
  cGameField(int x, int y) : dx_(x), dy_(y) {}

  int dx() const { return dx_; }
  int dy() const { return dy_; }


protected:
  int dx_, dy_;
};

#endif //#ifndef CGAMEFIELD_HPP
