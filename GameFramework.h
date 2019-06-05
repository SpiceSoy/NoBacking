#pragma once
#include "PaintInfo.h"
#include "GameObject.h"
#include <vector>
class ObjectContainer;
class Player;
class Camera;
class GameFramework
{
private:
	int maxScore = 0;
	bool isPause = false;
	bool isDrawCollision = false;
public:
	ObjectContainer* container = nullptr;
	GameFramework();
	~GameFramework();
	void Start();
	void End();
	void Create();
	void Destory();
	void Update(float deltaTime);
	void Draw(PaintInfo info);
	void Load();
	bool CheckCollision(GameStateObject& obj);
	void ToggleDebugCollision();
	void OnEffect(const std::string& tag, const Vec2DF& Position, bool isCopy = false);
	Vec2DF GetDisplaySize() const;
	Vec2DF GetMargin() const;
	void MouseInput(Vec2DU MousePos, UINT iMessage);
	Player& GetPlayer() const;
	ObjectContainer& operator()() { return *container; }
	Camera& GetCamera() const;
	Vec2DF GetCameraTransform(const Vec2DF& transform) const;
};