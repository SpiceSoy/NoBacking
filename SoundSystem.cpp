#include "pch.h"
#include <iostream>
#include <vector>
#include "SoundSystem.h"
#include "fmod.hpp"

FMOD::System* SoundSystem::System = nullptr;
FMOD::Channel* SoundSystem::EffectChannel = nullptr;
FMOD::Channel* SoundSystem::BackgroundChannel = nullptr;
std::map<std::string, std::pair<bool, FMOD::Sound*>> SoundSystem::Sounds = std::map<std::string, std::pair<bool, FMOD::Sound*>>();

void SoundSystem::OnInitalize()
{
	FMOD::System_Create(&System);
	System->init(3, FMOD_INIT_NORMAL, NULL);
}
void SoundSystem::Load(const std::string& tag, const std::string& dir, bool isBgm)
{
	FMOD::Sound* sound;
	if (isBgm)
	{
		System->createSound(dir.c_str(), FMOD_LOOP_NORMAL | FMOD_DEFAULT, NULL, &sound);
	}
	else 
	{
		System->createSound(dir.c_str(), FMOD_DEFAULT, NULL, &sound);
	}
	SoundSystem::Sounds[tag] = std::make_pair(isBgm, sound);
}

void SoundSystem::OnDestory()
{
	//for (auto& pr : SoundSystem::Sounds)
	//{
	//	if (pr.second.second != nullptr)
	//	{
	//		pr.second.second->release();
	//	}
	//}
	if (SoundSystem::System != nullptr)
	{
		SoundSystem::System->close();
		SoundSystem::System->release();
	}
}

void SoundSystem::Update()
{
	if (SoundSystem::System != nullptr)
	{
		System->update();
	}
}

void SoundSystem::PlaySound(const std::string& tag)
{
	if (SoundSystem::System != nullptr || SoundSystem::Sounds.count(tag) != 0)
	{
		System->playSound(SoundSystem::Sounds[tag].second, NULL, false, (SoundSystem::Sounds[tag].first) ? (&BackgroundChannel) : (&EffectChannel));
	}
}
