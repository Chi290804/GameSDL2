#ifndef BULLET_H_
#define BULLET_H_

//#include"Game_Base.h"
//#include"Game_Utils.h"
#include"Character.h"
#include <vector>
#include "Vector.h"

class Bullet
{
private:
    int posX;
    int posY;
    SDL_Rect _rect;
    bool isMove;
    int eWidth, eHeight;
    std::vector<Bullet*> pBulletList;
    SDL_Texture *BulletTexture;
    /*Vectorc initialMousePos;
    Vectorc velocity;
    Vectorc launchedVelocity;
    int dirX=1;
    int dirY = 1;*/

    //const unsigned int BulletDir;
public:
    const int BWIDTH = 57;
    const int BHEIGHT = 33;
    static const int SPEED = 16;
    Bullet();
    ~Bullet();
    /*enum BulletDir{
        DIR_RIGHT = 20;
        DIR_UP = 22;
        DIR_UP_RIGHT = 23;
        DIR_DOWN = 24;
        DIR_DOWN_RIGHT = 25;
    }*/
   
    int getX();
    int getY();
    void Render(SDL_Renderer* gRenderer, SDL_Rect* currentClip);
    void HandleMove( const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT);
    void setBulletList(std::vector<Bullet*> bulletList){
		pBulletList = bulletList;
	}
	std::vector<Bullet*> getBulletList() const {return pBulletList;}
    void LoadFromFile(std::string path, SDL_Renderer* gRenderer);
    void HandleEvent(SDL_Event& e, Mix_Chunk *gJump, SDL_Renderer *gRenderer,Character Character);
    void Shoot(SDL_Renderer* des);
    void Remove(const int& bli);
    void setRect() { _rect.x = posX ; _rect.y = posY;}
    SDL_Rect GetRect() const{return _rect;}
    //void Swap(Character Character);
    //void setBulletDir(const unsigned int & bulletDir) (BulletDir = *bulletDir;)
    //int getBulletDir() const (return BulletDir;)
    /*void setInitialMousePos(float x, float y);
    Vectorc& getInitialMousePos()
	{
		return initialMousePos;
	}
    Vectorc& getVelocity()
	{
		return velocity;
	}
    void setVelocity(float x, float y);
    void setLaunchedVelocity(float x, float y);*/
};
#endif

