#ifndef HOUSE_H_
#define HOUSE_H_

#include "Game_Base.h"

class House{
    public:
    House();
	
	~House();

	void LoadFromFile(std::string path, SDL_Renderer* gRenderer);


	int GetPosX();

	int GetPosY();

	int GetWidth();

	int GetHeight();

	void Free();

    std::vector<House*> MakeHouse() const {return makeHouse;}
private:
	int posX, posY;

	int eWidth, eHeight;

    std::vector<House*> makeHouse;

    SDL_Texture *gHouseTexture;
};

#endif//!HOUSE_H_
