#pragma once
#include "Asset.h"
class AudioAsset : public Asset
{
	DECLARE_DYNAMIC_DERIVED_CLASS(AudioAsset, Asset)

private:
	sf::SoundBuffer audio;

protected:
	AudioAsset();
	~AudioAsset();

public:
	sf::SoundBuffer getAudio();
};