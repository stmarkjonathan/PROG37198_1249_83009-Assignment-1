#include "AddChunkCommand.h"

AddChunkCommand::AddChunkCommand(Level* _level)
{
	m_level = _level;
}

void AddChunkCommand::Execute()
{

	int offset = 0;
	int numChunks = 6;

	for (int i= 0; i <= numChunks; i++)
	{
		memcpy(m_level->GetImgBuffer() + offset, m_level->GetFileChunks()[i]->GetChunk()->GetData(), m_level->GetFileChunks()[i]->GetChunk()->GetDataSize());

		offset += m_level->GetFileChunks()[i]->GetChunk()->GetDataSize();
	}

	ofstream writeStream("NewImage.tga", ios::out | ios::binary);
	writeStream.write(reinterpret_cast<char*>(m_level->GetImgBuffer()), offset);
	writeStream.close();
	
}

void AddChunkCommand::Undo()
{

}