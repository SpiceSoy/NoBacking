#include "pch.h"
#include "State.h"

State::State(GameStateObject* obj) : object(obj) , state(CharacterNormalState::None) 
{
}

void State::SetStateFunction(CharacterNormalState state, StateFunction& functionSet)
{
	functionMap[state] = (functionSet);
}

void State::SetStateFunction(CharacterNormalState state, StateFunction&& functionSet)
{
	functionMap[state] = std::move(functionSet);
}

void State::SetStateFunctionSet(CharacterNormalState state, StateFunction::StartFuncType&& startFunc, StateFunction::UpdateFuncType&& UpdateFunc, StateFunction::EndFuncType&& endFunc, StateFunction::CollisionFuncType&& colFunc)
{
	functionMap.emplace(state, StateFunction(std::move(startFunc), std::move(UpdateFunc), std::move(endFunc), std::move(colFunc)));
	//functionMap.emplace(state, std::move(startFunc), std::move(UpdateFunc), std::move(endFunc), std::move(colFunc));
}

bool State::ChangeState(CharacterNormalState state)
{
	if ((this->functionMap.count(state) != 0 || state == CharacterNormalState::None) && functionMap[this->state].End(state, *object))
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

bool State::isCollision(GameStateObject& other)
{
	if (this->functionMap.count(this->state) != 0)
	{
		return this->functionMap.at(state).Collision(*this->object,other,CollisionResult::GetResult(this->object));
	}
	else 
	{
		return false;
	}
}
