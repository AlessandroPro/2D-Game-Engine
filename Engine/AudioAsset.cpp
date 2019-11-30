#include "Core.h"
#include "AudioAsset.h"

IMPLEMENT_DYNAMIC_CLASS(AudioAsset)

AudioAsset::AudioAsset()
{
}

AudioAsset::~AudioAsset()
{
}

void AudioAsset::initialize()
{
	initialized = true;
}

void AudioAsset::load(std::string GUID, std::string assetPath)
{
	guid = GUID;
	id = GUIDToSTRCODE(GUID);
	//audio.loadFromFile(assetPath);
}

//sf::SoundBuffer AudioAsset::getAudio()
//{
//	return audio;
//}