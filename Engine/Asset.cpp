#include "Core.h"
#include "Asset.h"

IMPLEMENT_ABSTRACT_CLASS(Asset)

Asset::~Asset()
{
}

void Asset::initialize()
{
	Object::initialize();
}

void Asset::load(std::string GUID, std::string assetPath)
{

}