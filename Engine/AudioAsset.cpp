#include "Core.h"
#include "AudioAsset.h"

IMPLEMENT_DYNAMIC_CLASS(AudioAsset)

AudioAsset::AudioAsset()
{
}

AudioAsset::~AudioAsset()
{
}

sf::SoundBuffer AudioAsset::getAudio()
{
	return audio;
}