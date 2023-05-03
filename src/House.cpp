#include "House.h"

House::House(){
    posX = 0;
    posY = 0;

    eWidth = 0;
	eHeight = 0;
}

House::~House(){
    posX = 0;
	posY = 0;

	eWidth = 0;
	eHeight = 0;
}

void House::LoadFromFile(std::string path, SDL_Renderer* gRenderer)
{
	SDL_Texture* tmpTexture = nullptr;

	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	if (tmpSurface == nullptr)
	{
		LogError("Can not load image.", IMG_ERROR);
	}
	else
	{
		SDL_SetColorKey(tmpSurface, SDL_TRUE, SDL_MapRGB(tmpSurface->format, 0, 255, 255));

		tmpTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
		if (tmpTexture == nullptr)
		{
			LogError("Can not create texture from surface.", SDL_ERROR);
		}
		else
		{
			eWidth = tmpSurface->w;
			eHeight = tmpSurface->h;
		}

		SDL_FreeSurface(tmpSurface);
	}

}


int House::GetPosX()
{
	return posX;
}

int House::GetPosY()
{
	return posY;
}

int House::GetWidth()
{
	return eWidth;
}

int House::GetHeight()
{
	return eHeight;
}

void House::Free(){
    SDL_DestroyTexture(gHouseTexture);
}