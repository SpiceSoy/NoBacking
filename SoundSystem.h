#pragma once
#include "fmod.hpp"
#include <string>
#include <map>
class SoundSystem
{
private:
	static FMOD::System* System;
	static FMOD::Channel* EffectChannel;
	static FMOD::Channel* BackgroundChannel;
	static std::map<std::string, std::pair<bool,FMOD::Sound*>> Sounds;
public:
	static void OnInitalize();
	static void Load(const std::string& tag, const std::string& dir, bool isBgm = false);
	static void OnDestory();
	static void Update();
	static void PlaySound(const std::string& tag);
};