#include "CreateBufferCommand.h"

CreateBufferCommand::CreateBufferCommand(Level* _level)
{
	m_level = _level;
}

void CreateBufferCommand::Execute()
{

	int totalBytes = 0;

	for (auto const& x : m_level->GetFileChunks())
	{
		totalBytes += x->GetChunk()->GetDataSize();
	}

	m_level->SetImgBuffer(new byte[totalBytes]);
	memset(m_level->GetImgBuffer(), 0, totalBytes);

	ofstream writeStream("NewImage.tga", ios::out | ios::binary);
	writeStream.write(reinterpret_cast<char*>(m_level->GetImgBuffer()), sizeof(m_level->GetImgBuffer()));
	writeStream.close();

}

void CreateBufferCommand::Undo()
{

}