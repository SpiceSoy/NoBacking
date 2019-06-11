#pragma once
#include "PaintInfo.h"
#include "GameObject.h"
#include <vector>
class ObjectContainer;
class Player;
class Camera;
class UIObject;
class GameFramework
{
private:
	int maxScore = 0;
	bool isPause = false;
	bool isDrawCollision = false;
	bool GameStart = false;
	bool tast = false;
	bool isCheat = false;
	bool isCleared = false;
	std::vector<std::unique_ptr<UIObject>> uiObjects;
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
	bool CheckBound(GameStateObject& obj);
	void ToggleDebugCollision();
	void OnEffect(const std::string& tag, const Vec2DF& Position, bool isCopy = false);
	Vec2DF GetDisplaySize() const;
	Vec2DF GetMargin() const;
	void MouseInput(Vec2DU MousePos, UINT iMessage);
	Player& GetPlayer() const;
	ObjectContainer& operator()() { return *container; }
	Camera& GetCamera() const;
	Vec2DF GetCameraTransform(const Vec2DF& transform) const;
	void PlayerHPBar(float destPercent);
	void EnemyHPBar(float destPercent, void* enemyPtr, const std::string& markTag);
	bool GetGameState() const { return this->GameStart; }
	void SetGameState(bool gameState) { (gameState) ? (Start()): (End()); }
	void SetOnePunchMan(bool On) { this->isCheat = On; }
	void ToggleOnePunchMan() { this->isCheat = ! this->isCheat; }
	bool GetOnePunchMan() const { return this->isCheat; }
	void OnGameover();
	void OnGameClear();
};