#pragma once
#include <functional>
#include <unordered_map>
#include "StateEnum.h"

class GameObject;
struct StateFunction
{
	using StartFuncType = std::function<void(GameObject&)>;
	using UpdateFuncType = std::function<void(GameObject&, float)>;
	//다음 상태로 넘어갈 수 있는지 체크도 겸함
	using EndFuncType = std::function<bool(GameObject&, CharacterNormalState)>;

	StateFunction() = default;
	StateFunction(StateFunction::StartFuncType&& startFunc, StateFunction::UpdateFuncType&& UpdateFunc, StateFunction::EndFuncType&& endFunc)
		:_stateStart(std::move(startFunc)) , _stateUpdate(std::move(UpdateFunc)), _stateEnd(std::move(endFunc))
	{
	}

	StartFuncType _stateStart = nullptr;
	UpdateFuncType _stateUpdate = nullptr;
	EndFuncType _stateEnd = nullptr;
	void Start(GameObject& object)
	{
		if (this->_stateStart != nullptr) { return _stateStart(object); } 
	}
	void Update(GameObject& object, float deltaTime)
	{
		if (this->_stateUpdate != nullptr) { return _stateUpdate(object,deltaTime); }
	}
	bool End(CharacterNormalState state, GameObject& object)
	{
		if (this->_stateEnd != nullptr) { return _stateEnd(object, state); }
		else { return true; }
	}
};

class State
{
	GameObject* object;
	CharacterNormalState state;
public:
	State(GameObject* obj);
	std::unordered_map<CharacterNormalState, StateFunction> functionMap;
	auto GetCurrentState() const { return this->state; }
	void SetStateFunction(CharacterNormalState state, StateFunction&& functionSet);
	void SetStateFunctionSet(CharacterNormalState state, StateFunction::StartFuncType&& startFunc, StateFunction::UpdateFuncType&& UpdateFunc, StateFunction::EndFuncType&& endFunc);
	bool ChangeState(CharacterNormalState state);
	void Update(float deltaTime);
};