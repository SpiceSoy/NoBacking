#pragma once
#include <map>
#include <vector>
#include <string>
#include <atlimage.h>
#include "Collision.h"

struct subImage
{
	CImage* img = nullptr;
	subImage(const std::wstring& image);
	subImage(const subImage& other) = delete;
	subImage(subImage&& other);
	~subImage();
};

class ResourceManager
{
	static std::map<std::string, std::vector<subImage>> ImageSet;
	static std::map<std::string, std::vector<CollisionCollection>> CollisionSet;
public:
	static std::vector<subImage>* GetImages(const std::string& tag);
	static std::vector<CollisionCollection>* GetCollision(const std::string& tag);
	static void AddImages(const std::string& tag, const std::wstring& dir);
	static void AddCollision(const std::string& tag, const std::string& dir);
	static void Load(const std::string& tag);
};