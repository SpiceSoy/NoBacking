#include "pch.h"
#include "ResourceManager.h"
#include "Collision.h"

std::map<std::string, std::vector<subImage>> ResourceManager::ImageSet;
std::map<std::string, std::vector<CollisionCollection>> ResourceManager::CollisionSet;

std::vector<subImage>* ResourceManager::GetImages(const std::string& tag)
{
	return &ResourceManager::ImageSet.at(tag);
}

std::vector<CollisionCollection>* ResourceManager::GetCollision(const std::string& tag)
{
	return &ResourceManager::CollisionSet.at(tag);
}

void ResourceManager::LoadImages(const std::string& tag, const std::wstring& dir)
{
	ResourceManager::ImageSet.emplace((tag, subImage(dir)));
}

void ResourceManager::LoadCollision(const std::string& tag, const std::string& dir)
{
	ResourceManager::ImageSet.emplace((tag, CollisionCollection(dir)));
}
