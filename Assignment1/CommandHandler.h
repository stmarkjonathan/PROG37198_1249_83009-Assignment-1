#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "Command.h"
#include "Level.h"

class CommandHandler
{

public:

	CommandHandler(Level* _level);
	virtual ~CommandHandler();
	void HandleInput(string _command);
	void Undo();

private:

	Level* m_level;
	std::vector<Command*> m_commands;
};

#endif