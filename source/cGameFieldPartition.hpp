///************************* OUTS HOMEWORK ****************************************
#ifndef CGAMEFIELDPARTITION_HPP
#define CGAMEFIELDPARTITION_HPP

#include "cRNeighborhood.hpp"
#include <vector>

class cGameField;
class cVector;


class cGameFieldPartition
{
public:
  cGameFieldPartition(const cGameField& gameField, int R, const cVector& offset);
  cGameFieldPartition(const cGameField& gameField, int R);

  cRNeighborhood *RNeighborhood(const cVector& pos);
  cRNeighborhood* RNeighborhood(const cObject* obj);

protected:
  const cGameField* gf;
  std::vector<cRNeighborhood> rNeighborhoods;
};

#endif //#ifndef CGAMEFIELDPARTITION_HPP
