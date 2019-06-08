#include "pch.h"
#include "ResourceManager.h"
#include "Collision.h"
#include <atlimage.h>

std::map<std::string, std::vector<subImage>> ResourceManager::ImageSet = std::map<std::string, std::vector<subImage>>();
std::map<std::string, std::vector<CollisionCollection>> ResourceManager::CollisionSet = std::map<std::string, std::vector<CollisionCollection>>();
std::map<std::string, std::unordered_map<CharacterNormalState, subAnimation>> ResourceManager::MotionSet = std::map<std::string, std::unordered_map<CharacterNormalState, subAnimation>>();
subImage::subImage(const std::wstring& image,bool isAlphaCheck)
{
	img = new CImage();
	//img->Load(image.c_str());
	if (SUCCEEDED(img->Load(image.c_str())) && isAlphaCheck)
	{
		if (img->GetBPP() == 32)
		{
			{
				unsigned char * pCol = 0;
				long w = img->GetWidth();
				long h = img->GetHeight();
				for (long y = 0; y < h; y++)
				{
					for (long x = 0; x < w; x++)
					{
						pCol = (unsigned char *)img->GetPixelAddress(x, y);
						unsigned char alpha = pCol[3];
						if (alpha != 255)
						{
							pCol[0] = ((pCol[0] * alpha) + 128) >> 8;
							pCol[1] = ((pCol[1] * alpha) + 128) >> 8;
							pCol[2] = ((pCol[2] * alpha) + 128) >> 8;
						}
					}
				}
			}
			img->SetHasAlphaChannel(true);
		}
	}
}

subImage::subImage(subImage&& other)
{
	this->img = other.img;
	other.img = nullptr;
}

subImage::~subImage()
{
	if (img != nullptr)
	{
		delete img;
	}
}

ImageSetContainer* ResourceManager::GetImages(const std::string& tag)
{
	return &ResourceManager::ImageSet.at(tag);
}

CollisionCollectionContainer* ResourceManager::GetCollision(const std::string& tag)
{
	if (ResourceManager::CollisionSet.count(tag) == 0)
	{
		return nullptr;
	}
	else 
	{
		return &ResourceManager::CollisionSet.at(tag);
	}
}
MotionContainer* ResourceManager::GetMotion(const std::string& tag)
{
	return &ResourceManager::MotionSet.at(tag);
}

void ResourceManager::AddImages(const std::string& tag, const std::wstring& dir , bool isAlphaCheck)
{
	if (ImageSet.size() == 0 || ImageSet.count(tag) == 0)
	{
		ResourceManager::ImageSet.emplace(tag, std::vector<subImage>());
	}
	ResourceManager::ImageSet[tag].emplace_back(dir, isAlphaCheck);
}

void ResourceManager::AddCollision(const std::string& tag, const std::string& dir, float scale)
{
	if (CollisionSet.size() == 0 || CollisionSet.count(tag) == 0)
	{
		ResourceManager::CollisionSet.emplace(tag, std::vector<CollisionCollection>());
	}
	ResourceManager::CollisionSet[tag].emplace_back(dir, scale);
}
void ResourceManager::AddMotion(const std::string& tag, MotionContainer&& motion)
{
	ResourceManager::MotionSet[tag] = std::move(motion);
}


void ResourceManager::Load(const std::string& tag)
{
}
