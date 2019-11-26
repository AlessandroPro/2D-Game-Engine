#include "Core.h"

#include "Object.h"
#include "GameObject.h"
#include "Component.h"
#include "Sprite.h"
#include "Transform.h"
#include "Asset.h"
#include "PrefabAsset.h"
#include "TextureAsset.h"
#include "AudioAsset.h"
#include "FontAsset.h"

void registerEngineClasses()
{
	REGISTER_ABSTRACT_CLASS(Object);
	REGISTER_ABSTRACT_CLASS(Component);
	REGISTER_DYNAMIC_CLASS(GameObject);
	REGISTER_DYNAMIC_CLASS(Sprite);
	REGISTER_DYNAMIC_CLASS(Transform);
	REGISTER_DYNAMIC_CLASS(Asset);
	REGISTER_DYNAMIC_CLASS(PrefabAsset);
	REGISTER_DYNAMIC_CLASS(TextureAsset);
	REGISTER_DYNAMIC_CLASS(AudioAsset);
	REGISTER_DYNAMIC_CLASS(FontAsset);
}