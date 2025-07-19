///************************* OUTS HOMEWORK ****************************************

#include "cGameFieldPartition.hpp"
#include "cGameField.hpp"
#include "cException.hpp"
#include "cVector.hpp"

cGameFieldPartition::cGameFieldPartition(const cGameField& gameField, int R, const cVector& offset)
  : gf(&gameField)
{
  if (gameField.dx() % R != 0)
    throw(cException("A concept of reminders is too hard for me."));
  if (gameField.dx() % R != 0)
    throw(cException("I said 'A concept of reminders is too hard for me.'"));

  if ((offset.x != 0) && (offset.x != R/2))
    throw(cException("Wropng x offset."));
  if ((offset.y != 0) && (offset.y != R/2))
    throw(cException("Wropng y offset."));

  // full covering 
  for (int x = -offset.x; x < gameField.dx() + offset.x; x+=R)
    for (int y = -offset.y; y < gameField.dy() + offset.y; y+=R)
    {
      cRNeighborhood n(this, x, y, R);
      rNeighborhoods.push_back(n);
    }
}

cGameFieldPartition::cGameFieldPartition(const cGameField& gameField, int R)
  : cGameFieldPartition( gameField, R, cVector(0,0) )
{
}

cRNeighborhood* cGameFieldPartition::RNeighborhood(const cVector& pos)
{
    for (cRNeighborhood& r : rNeighborhoods)
        if (r.IsInside(pos))
            return &r;

    return nullptr;
}


cRNeighborhood* cGameFieldPartition::RNeighborhood(const cObject* obj)
{
    for (cRNeighborhood& r : rNeighborhoods)
        if (r.contains(obj))
            return &r;

    return nullptr;
}
