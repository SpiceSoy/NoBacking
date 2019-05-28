#include "pch.h"
#include "State.h"

State::State(GameObject* obj) : object(obj) , state(CharacterNormalState::None) 
{
}

void State::SetStateFunction(CharacterNormalState state, StateFunction&& functionSet)
{
	functionMap[state] = std::move(functionSet);
}

void State::SetStateFunctionSet(CharacterNormalState state, StateFunction::StartFuncType&& startFunc, StateFunction::UpdateFuncType&& UpdateFunc, StateFunction::EndFuncType&& endFunc)
{
	functionMap.emplace(state, StateFunction(std::move(startFunc), std::move(UpdateFunc), std::move(endFunc)));
}

bool State::ChangeState(CharacterNormalState state)
{
	if ((this->functionMap.count(state) != 0 || state == CharacterNormalState::None) && functionMap[state].End(state, *object))
	{
		this->state = state;
		functionMap[state].Start(*object);
		return true;
	}
	else 
	{
		return false;
	}
}

void State::Update(float deltaTime)
{
	if (this->functionMap.count(this->state) != 0)
	{
		this->functionMap.at(state).Update(*this->object,deltaTime);
	}
}
