#include "Bullet.h"
#include "Vector.h"
#include"Ltexture.h"

Bullet::Bullet()
{
    posX=0;
    posY=0;
    isMove = false;
    eHeight =0;
    eWidth = 0;
    BulletTexture = nullptr;
}
Bullet::~Bullet(){

}
int Bullet::getX(){
    return posX;
}
int Bullet::getY(){
    return posY;
}
void Bullet::LoadFromFile(std::string path, SDL_Renderer* gRenderer)
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

	BulletTexture = tmpTexture;
}

void Bullet::HandleEvent(SDL_Event& e, Mix_Chunk *gJump,  SDL_Renderer *gRenderer,
 Character Character)
{
    int x = Character.GetPosX();
    int y = Character.GetPosY();
	if (e.type == SDL_MOUSEBUTTONDOWN){
        Bullet* pBullet = new Bullet();
        if (e.button.button == SDL_BUTTON_LEFT){
            
            pBullet->LoadFromFile("imgs/Bullet/Bullet.png",gRenderer);
            pBullet -> posX =x ;
            pBullet ->posY = y;
            pBullet -> isMove = true;
            pBulletList.push_back(pBullet);
        }
        if (e.button.button == SDL_BUTTON_RIGHT){
                    pBullet -> Swap(Character);
                    //Character.Render( currentClip, gRenderer, gCharacterTexture);
        }
    }
}
void Bullet::Render(SDL_Renderer* gRenderer, SDL_Rect* currentClip)
{
	SDL_Rect renderSpace = { posX, posY, eWidth, eHeight };
	if (currentClip != nullptr)
	{
		renderSpace.w = currentClip->w;
		renderSpace.h = currentClip->h;
	}
	SDL_RenderCopy(gRenderer, BulletTexture, currentClip, &renderSpace);
}

void Bullet::HandleMove( const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT){
    /*if (isMove){
        int mouseX = 0;
	    int mouseY = 0;
	    SDL_GetMouseState(&mouseX, &mouseY);
        setInitialMousePos(mouseX, mouseY);
    }*/
    posX += SPEED;
        if (posX > SCREEN_WIDTH || posY > SCREEN_HEIGHT){
            isMove = false;
        }
    }

    /*if(BulletDir == DIR_RIGHT){
        posX += SPEED;
        if (posX > SCREEN_WIDTH){
            isMove = false;
        }
    }
    else if ( BulletDir == DIR_UP_RIGHT)
    
    if (e.type == SDL_MOUSEBUTTONDOWN){
        if (e.button.button == SDL_BUTTON_LEFT){
            void Bullet::LoadFromFile(std::string path, SDL_Renderer* gRenderer)
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
    void Bullet::Render(SDL_Renderer* gRenderer, SDL_Rect* currentClip)
    {
	SDL_Rect renderSpace = { posX, posY, eWidth, eHeight };
	if (currentClip != nullptr)
	{
		renderSpace.w = currentClip->w;
		renderSpace.h = currentClip->h;
	}
	SDL_RenderCopy(gRenderer, EnemyTexture, currentClip, &renderSpace);
    }

            isMove = true;
        }
    }
}*/

/*void Bullet::setInitialMousePos(float x, float y)
{
    initialMousePos.x = x;
    initialMousePos.y = y;
}
void Ball::setVelocity(float x, float y)
{
    velocity.x = x;
    velocity.y = y;
}

void Ball::setLaunchedVelocity(float x, float y)
{
    launchedVelocity.x = x;
    launchedVelocity.y = y;
}*/
void Bullet::Shoot(SDL_Renderer* des){
    for( int i=0; i<pBulletList.size(); i++){
        Bullet* pBullet = pBulletList.at(i);
        if (pBullet != NULL){
            if (pBullet->isMove == true){
                pBullet->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);
                pBullet->Render(des, NULL);
            }
            else {
                pBulletList.erase(pBulletList.begin() +i);
                if (pBullet !=NULL){
                    delete pBullet;
                    pBullet =NULL;
                }
            }
        }
    }
}
void Bullet::Swap(Character Character/*,SDL_Rect* currentClip, SDL_Renderer *gRenderer, LTexture gCharacterTexture*/){
    Character.setRect(posX, posY);
}