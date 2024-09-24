#include "CommandHandler.h"
#include "CreateBufferCommand.h"
#include "DeleteBufferCommand.h"
#include "AddChunkCommand.h"

CommandHandler::CommandHandler(Level* _level)
{
	m_level = _level;
}

CommandHandler::~CommandHandler()
{
	for (auto const& x : m_commands)
	{
		delete x;
	}
}

void CommandHandler::HandleInput(string _command)
{
	CreateBufferCommand* createBuffer = nullptr;
	DeleteBufferCommand* deleteBuffer = nullptr;
	AddChunkCommand* addChunk = nullptr;
	

	if (_command == "CREATE_BUFFER") 
	{
		createBuffer = new CreateBufferCommand(m_level);
	}
	else if (_command == "DELETE_BUFFER")
	{
		deleteBuffer = new DeleteBufferCommand(m_level);
	}
	else if (_command == "ADD_CHUNK")
	{
		addChunk = new AddChunkCommand(m_level);
	}

	if (createBuffer != nullptr)
	{
		createBuffer->Execute();
		m_commands.push_back(createBuffer);
	}
	else if (deleteBuffer != nullptr)
	{
		deleteBuffer->Execute();
		m_commands.push_back(deleteBuffer);
	}
	else if (addChunk != nullptr)
	{
		addChunk->Execute();
		m_commands.push_back(addChunk);
	}
		

	
}

void CommandHandler::Undo()
{

	Command* lastCommand = m_commands.back();
	lastCommand->Undo();
	delete lastCommand;
	m_commands.pop_back();

}