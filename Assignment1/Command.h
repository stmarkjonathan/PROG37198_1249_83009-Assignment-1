#ifndef COMMAND_H
#define COMMAND_H

#include "StandardIncludes.h"

class Command
{

public:

	virtual ~Command() {}
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

#endif