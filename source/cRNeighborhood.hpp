///************************* OUTS HOMEWORK ****************************************
#ifndef CRNEIGHBORHOOD_HPP
#define CRNEIGHBORHOOD_HPP

#include "cVector.hpp"
#include <vector>

class cGameFieldPartition;
class cObject;

class cRNeighborhood
{
public:
  cRNeighborhood(const cGameFieldPartition* rN, int x, int y, int R)
    : rN(rN), lb(x, y), R(R) {}

  bool IsInside(const cVector& pos) const;

  bool contains(const cObject* obj) const { return find(objects, obj); }

  const std::vector<cObject*>& ListOfObjects() const { return objects; }
  static bool find(const std::vector<cObject*>& objects, const cObject* obj);

  void remove(const cObject* obj);
  void add(cObject* obj) { objects.push_back(obj); }
  const cVector& LeftBottomCorner() const { return lb; }

protected:
  const cGameFieldPartition* rN;
  cVector lb; // left bottom corner on r-neighbourhoud 
  int R;

  std::vector<cObject*>objects;
};

#endif //#ifndef CRNEIGHBORHOOD_HPP
