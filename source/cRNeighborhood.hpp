///************************* OUTS HOMEWORK ****************************************
#ifndef CRNEIGHBORHOOD_HPP
#define CRNEIGHBORHOOD_HPP

#include "cVector.hpp"
class cGameFieldPartition;

class cRNeighborhood
{
public:
  cRNeighborhood(const cGameFieldPartition* rN, int x, int y, int R)
    : rN(rN), lb(x, y), R(R) {}

protected:

  const cGameFieldPartition* rN;
  cVector lb; // left bottom corner on r-neighbourhoud 
  int R;


};

#endif //#ifndef CRNEIGHBORHOOD_HPP
