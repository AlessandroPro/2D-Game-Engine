#ifndef _AUDIOASSET_H
#define _AUDIOASSET_H
#pragma once
#include "Asset.h"
class AudioAsset : public Asset
{
	DECLARE_DYNAMIC_DERIVED_CLASS(AudioAsset, Asset)

private:
	//sf::SoundBuffer audio;

protected:
	AudioAsset();
	~AudioAsset();
	void initialize() override;
	void load(std::string GUID, std::string assetPath) override;

public:
	//const sf::SoundBuffer& getAudio();
};

#endif