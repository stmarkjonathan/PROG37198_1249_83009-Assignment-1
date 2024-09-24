#ifndef ADDCHUNKCMD_H
#define ADDCHUNKCMD_H

#include "Command.h"
#include "Level.h"

class AddChunkCommand : public Command
{
public:

	AddChunkCommand(Level* _level);
	virtual void Execute();
	virtual void Undo();

private:

	Level* m_level;

};


#endif