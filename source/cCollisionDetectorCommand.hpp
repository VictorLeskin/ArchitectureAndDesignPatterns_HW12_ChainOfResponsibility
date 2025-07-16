///************************* OUTS HOMEWORK ****************************************
#ifndef CCOLLISIONDETECTORCOMMAND_HPP
#define CCOLLISIONDETECTORCOMMAND_HPP

#include "iCommand.hpp"
#include <typeinfo>

class cCollisionDetectorCommand : public iCommand
{
public:
	void Execute() override;
	const char* Type() const override { return typeid(*this).name(); }
};

#endif //#ifndef CCOLLISIONDETECTORCOMMAND_HPP
