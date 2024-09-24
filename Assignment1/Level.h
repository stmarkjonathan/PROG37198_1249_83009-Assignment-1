#ifndef Level_H
#define Level_H

#include "FileChunk.h"

class Level : public Resource
{

public:
	Level();
	virtual ~Level();

	byte* GetImgBuffer() { return m_imgBuffer; }
	void SetImgBuffer(byte* _buffer) { m_imgBuffer = _buffer; }
	vector<FileChunk*> GetFileChunks() { return m_fileChunks; }

	void Initiate();
	void Clear();

	virtual void Serialize(ostream& _stream) override;
	virtual void Deserialize(istream& _stream) override;
	virtual void AssignNonDefaultValues() override;
	virtual void ToString() override;

private:
	byte* m_imgBuffer;
	std::vector<FileChunk*> m_fileChunks;
};

#endif