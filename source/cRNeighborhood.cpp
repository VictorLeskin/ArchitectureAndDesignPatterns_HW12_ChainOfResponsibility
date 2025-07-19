///************************* OUTS HOMEWORK ****************************************

#include "cRNeighborhood.hpp"

bool cRNeighborhood::IsInside(const cVector& pos) const
{
    if (lb.x <= pos.x
        && lb.y <= pos.y
        && pos.x < lb.x + R
        && pos.y < lb.y + R)
        return true;
    return false;
}

bool cRNeighborhood::find(const std::vector<cObject*>& objects, const cObject* obj)
{
    return std::find(objects.begin(), objects.end(), obj) != objects.end();
}

void cRNeighborhood::remove(const cObject* obj)
{
    if (auto it = std::find(objects.begin(), objects.end(), obj); it != objects.end())
        objects.erase(it);
}
