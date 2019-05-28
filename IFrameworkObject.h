#pragma once
class GameFramework;

class IFrameworkObject
{
protected:
	GameFramework* framework;
	IFrameworkObject(GameFramework* framework) : framework(framework) {};
};
