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
	void initialize(std::string GUID, std::string assetPath) override;

public:
	sf::SoundBuffer getAudio();
};