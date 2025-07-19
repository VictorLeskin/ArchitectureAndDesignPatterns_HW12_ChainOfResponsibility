///************************* OUTS HOMEWORK ****************************************
#ifndef CCOLLISIONDETECTORCOMMAND_HPP
#define CCOLLISIONDETECTORCOMMAND_HPP

#include "iCommand.hpp"
#include "cObject.hpp"
#include <typeinfo>
#include <vector>

class cGame;

class cCollisionDetectorCommand : public iCommand
{
public:
	void Execute() override;
	const char* Type() const override { return typeid(*this).name(); }

	cCollisionDetectorCommand(const cObject* a, const cObject* b) : a(a), b(b)
	{
		if (a > b)
			std::swap(a, b);
	}

	bool operator==(const cCollisionDetectorCommand& other)
	{
		return (a == other.a && b == other.b);
	}

	const cObject* a, * b; // a < b for sorting purposes
};


class cAllCollisionDetectorCommand : public iCommand
{
public:
	cAllCollisionDetectorCommand(cGame* game) : game(game) {}
	void Execute() override;
	const char* Type() const override { return typeid(*this).name(); }

	void append(cCollisionDetectorCommand cmd);

	std::vector<cCollisionDetectorCommand> CollisionDectectionCommands() const
	{
		return collisionDectectionCommands;
	}

   protected:

	cGame* game;
	std::vector<cCollisionDetectorCommand> collisionDectectionCommands;
};


#endif //#ifndef CCOLLISIONDETECTORCOMMAND_HPP
