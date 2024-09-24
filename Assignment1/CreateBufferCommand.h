#ifndef CREATEBUFFERCMD_H
#define CREATEBUFFERCMD_H

#include "Command.h"
#include "Level.h"

class CreateBufferCommand : public Command
{
public:

	CreateBufferCommand(Level* _level);
	virtual void Execute();
	virtual void Undo();

private:

	Level* m_level;
	
};


#endif