///************************* OUTS HOMEWORK ****************************************
#ifndef COBJECT_HPP
#define COBJECT_HPP

#include <string>

#include "cVector.hpp"

class cInterpretCommand;

class cObject
{
public:
	cObject(std::string id, const cVector &pos ) : id(id), pos(pos) {}

	virtual ~cObject() {}

	const std::string& Id() const { return id; }
	const cVector& Position() { return pos; }

	void moveTo(const cVector& p) { pos = p; }

	virtual void Execute(const cInterpretCommand& cmd) {};

protected:
	std::string id;
	cVector pos;
};

#endif //#ifndef COBJECT_HPP
