#include "Level.h"

Level::Level()
{
	m_imgBuffer = nullptr;
	Initiate();
}

Level::~Level()
{
	Clear();
}

void Level::Initiate()
{
	AssetController::Instance().Initialize(50000000);
	FileChunk::Pool = new ObjectPool<FileChunk>();
	m_imgBuffer = nullptr;
	m_fileChunks.clear();
}

void Level::Clear() 
{
	if (m_imgBuffer != nullptr) 
	{
		delete m_imgBuffer;
	}
	m_fileChunks.clear();
	delete FileChunk::Pool;
	AssetController::Instance().Clear();
}

void Level::AssignNonDefaultValues()
{
	for (int count = 0; count < 7; count++)
	{
		cout << "Reading file: " << "chunk" + to_string(count) + ".bin" << endl;
		FileChunk* fileChunk = FileChunk::Pool->GetResource();
		fileChunk->SetChunk(AssetController::Instance().GetAsset("chunk" + to_string(count) + ".bin"));
		m_fileChunks.push_back(fileChunk);	
	}

	Resource::AssignNonDefaultValues();
}

void Level::Serialize(ostream& _stream)
{

	int numberOfChunks = m_fileChunks.size();
	_stream.write(reinterpret_cast<char*>(&numberOfChunks), sizeof(numberOfChunks));
	for (int count = 0; count < numberOfChunks; count++)
	{
		SerializePointer(_stream, m_fileChunks[count]);
	}

	Resource::Serialize(_stream);
}

void Level::Deserialize(istream& _stream)
{

	Clear();
	Initiate();

	int numberOfChunks;

	_stream.read(reinterpret_cast<char*>(&numberOfChunks), sizeof(numberOfChunks));
	for (int count = 0; count < numberOfChunks; count++)
	{
		FileChunk* chunk;
		DeserializePointer(_stream, chunk);
		m_fileChunks.push_back(chunk);
	}

	Resource::Deserialize(_stream);
}

void Level::ToString()
{
	Resource::ToString();
}