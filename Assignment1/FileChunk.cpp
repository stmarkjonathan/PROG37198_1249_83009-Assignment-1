#include "FileChunk.h"

ObjectPool<FileChunk>* FileChunk::Pool;

FileChunk::FileChunk()
{
	m_chunk = nullptr;
}

FileChunk::~FileChunk()
{

}

void FileChunk::AssignNonDefaultValues()
{
	
}

void FileChunk::Serialize(ostream& _stream)
{
	SerializeAsset(_stream, m_chunk);
	Resource::Serialize(_stream);
}

void FileChunk::Deserialize(istream& _stream)
{	
	DeserializeAsset(_stream, m_chunk);
	Resource::Deserialize(_stream);
	cout << "Deserialized " << m_chunk->GetGUID() << endl;
}

void FileChunk::ToString()
{
	
}