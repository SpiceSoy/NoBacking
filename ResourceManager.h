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
struct subAnimation
{
	size_t subImageStartIndex = 0;
	size_t subImageSize = 0;
	float scale = 1.0f;
	CharacterNormalState next = CharacterNormalState::LOOP;
};


using ImageSetContainer = std::vector<subImage>;
using CollisionCollectionContainer =  std::vector<CollisionCollection>;
using MotionContainer = std::unordered_map<CharacterNormalState, subAnimation>;

class ResourceManager
{
	static std::map<std::string, ImageSetContainer> ImageSet;
	static std::map<std::string, CollisionCollectionContainer> CollisionSet;
	static std::map<std::string, MotionContainer> MotionSet;
public:
	static MotionContainer* GetMotion(const std::string& tag);
	static ImageSetContainer* GetImages(const std::string& tag);
	static CollisionCollectionContainer* GetCollision(const std::string& tag);
	static void AddImages(const std::string& tag, const std::wstring& dir);
	static void AddCollision(const std::string& tag, const std::string& dir,float scale = 0.0f);
	static void AddMotion(const std::string& tag, MotionContainer&& motion);
	static void Load(const std::string& tag);
};