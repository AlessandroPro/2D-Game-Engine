#include "Core.h"
#include "AudioAsset.h"

IMPLEMENT_DYNAMIC_CLASS(AudioAsset)

AudioAsset::AudioAsset()
{
}

AudioAsset::~AudioAsset()
{
}

void AudioAsset::initialize(std::string GUID, std::string assetPath)
{
}

sf::SoundBuffer AudioAsset::getAudio()
{
	return audio;
}