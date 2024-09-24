#include "DeleteBufferCommand.h"

DeleteBufferCommand::DeleteBufferCommand(Level* _level)
{
	m_level = _level;
}

void DeleteBufferCommand::Execute()
{
	delete m_level->GetImgBuffer();
	m_level->SetImgBuffer(nullptr);
}

void DeleteBufferCommand::Undo()
{

}