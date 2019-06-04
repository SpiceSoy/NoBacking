#pragma once
#include <functional>
#include <unordered_map>
#include "StateEnum.h"
#include "Collision.h"

class GameStateObject;
struct StateFunction
{
	using StartFuncType = std::function<void(GameStateObject&)>;
	using UpdateFuncType = std::function<void(GameStateObject&, float)>;
	using CollisionFuncType = std::function<bool(GameStateObject&, GameStateObject&, const CollisionResult::ResultVector&)>;
	//다음 상태로 넘어갈 수 있는지 체크도 겸함
	using EndFuncType = std::function<bool(GameStateObject&, CharacterNormalState)>;

	StateFunction() = default;
	//StateFunction(StateFunction::StartFuncType startFunc, StateFunction::UpdateFuncType UpdateFunc, StateFunction::EndFuncType endFunc, StateFunction::CollisionFuncType colFunc)
	//	:_stateStart((startFunc)), _stateUpdate((UpdateFunc)), _stateEnd((endFunc)), _stateCollision((colFunc))
	//{
	//}
	StateFunction(StateFunction::StartFuncType&& startFunc, StateFunction::UpdateFuncType&& UpdateFunc, StateFunction::EndFuncType&& endFunc, StateFunction::CollisionFuncType&& colFunc)
		:_stateStart(std::move(startFunc)) , _stateUpdate(std::move(UpdateFunc)), _stateEnd(std::move(endFunc)),_stateCollision(std::move(colFunc))
	{
	}

	StartFuncType _stateStart = nullptr;
	UpdateFuncType _stateUpdate = nullptr;
	EndFuncType _stateEnd = nullptr;
	CollisionFuncType _stateCollision = nullptr;
	void Start(GameStateObject& object)
	{
		if (this->_stateStart != nullptr) { return _stateStart(object); } 
	}
	void Update(GameStateObject& object, float deltaTime)
	{
		if (this->_stateUpdate != nullptr) { return _stateUpdate(object,deltaTime); }
	}
	bool End(CharacterNormalState state, GameStateObject& object)
	{
		if (this->_stateEnd != nullptr) { return _stateEnd(object, state); }
		else { return true; }
	}
	bool Collision(GameStateObject& object, GameStateObject& other, const CollisionResult::ResultVector& result)
	{
		if (this->_stateCollision != nullptr) { return _stateCollision(object,other,result); }
		else { return false; }
	}
};

class State
{
	GameStateObject* object;
	CharacterNormalState state;
public:
	State(GameStateObject* obj);
	std::unordered_map<CharacterNormalState, StateFunction> functionMap;
	auto GetCurrentState() const { return this->state; }
	void SetStateFunction(CharacterNormalState state, StateFunction& functionSet);
	void SetStateFunction(CharacterNormalState state, StateFunction&& functionSet);
	void SetStateFunctionSet(CharacterNormalState state, StateFunction::StartFuncType&& startFunc = nullptr, StateFunction::UpdateFuncType&& UpdateFunc = nullptr, StateFunction::EndFuncType&& endFunc = nullptr, StateFunction::CollisionFuncType&& colFunc = nullptr);
	bool ChangeState(CharacterNormalState state);
	void Update(float deltaTime);
	bool isCollision(GameStateObject& other);
};