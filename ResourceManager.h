#pragma once
#include <map>
#include <vector>
#include <string>
#include <atlimage.h>
#include "Collision.h"
struct subImage
{
	CImage img;
	subImage(const std::wstring& image);
	//HBITMAP bitmap;
	//RectU size;
	//subImage(const subImage& other);
};


class ResourceManager
{
	static std::map<std::string, std::vector<subImage>> ImageSet;
	static std::map<std::string, std::vector<CollisionCollection>> CollisionSet;
public:
	static std::vector<subImage>* GetImages(const std::string& tag);
	static std::vector<CollisionCollection>* GetCollision(const std::string& tag);
	static void LoadImages(const std::string& tag, const std::wstring& dir);
	static void LoadCollision(const std::string& tag, const std::string& dir);
};