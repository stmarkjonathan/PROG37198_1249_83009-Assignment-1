#ifndef DELETEBUFFERCMD_H
#define DELETEBUFFERCMD_H

#include "Command.h"
#include "Level.h"

class DeleteBufferCommand : public Command
{
public:

	DeleteBufferCommand(Level* _level);
	virtual void Execute();
	virtual void Undo();

private:

	Level* m_level;

};


#endif