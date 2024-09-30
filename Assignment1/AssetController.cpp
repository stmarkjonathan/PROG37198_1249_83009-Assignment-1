#include "AssetController.h"
#include "FileController.h"

StackAllocator* AssetController::Stack = nullptr;

AssetController::AssetController()
{
}

void AssetController::Initialize(int _stackSize)
{
	Stack = new StackAllocator();
	AssetController::Stack->AllocateStack(_stackSize);
	Asset::Pool = new ObjectPool<Asset>();
}

AssetController::~AssetController()
{
	Clear();
}

void AssetController::Clear()
{
	for (auto const& x : m_assets)
	{
		cout << "Deleting asset: " << x.first << endl;
		Asset::Pool->ReleaseResource(x.second);
	}
	delete Asset::Pool;
	Stack->ClearMemory();
	m_assets.clear();
}

Asset* AssetController::GetAsset(string _guid)
{
	if (m_assets.count(_guid) != 0)
	{
		return m_assets[_guid];
	}

	Asset* asset = Asset::Pool->GetResource();
	asset->SetGUID(_guid);
	asset->SetDataSize(FileController::Instance().GetFileSize(_guid));
	asset->SetData(Stack->GetMemory(asset->GetDataSize()));
	FileController::Instance().ReadFile(_guid, asset->GetData(), asset->GetDataSize());

	m_assets[_guid] = asset;

	return asset;
}

