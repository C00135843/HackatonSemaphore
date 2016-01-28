#include "stdafx.h"
#include "Enemy.h"
#pragma comment(lib, "SDL2_image.lib")

Enemy::Enemy() {}

Enemy::Enemy(int xPos,int yPos, int width, int height, Renderer& r, int t):type(t)
{
	m_render_rect = new SDL_Rect{ xPos + width / 2, yPos + height / 2,width,height };
	xPosition = xPos;
	yPosition = yPos;
	LoadAssets(r);
	//center->x = ((900 - width) / 2);
	//center->y = ((600 - height) / 2);
	updateSem = SDL_CreateSemaphore(1);
	
}

Enemy::~Enemy()
{
	SDL_DestroySemaphore(updateSem);
}

void Enemy::LoadAssets(Renderer& r)
{
	std::string path;
	if (type == 0) {
		path = "enemy.png";
		m_surface = IMG_Load(path.c_str());
	}
	else if (type == 1)
	{
		std::string path = "enemy.png";
		m_surface = IMG_Load(path.c_str());
	}
	else
	{
		std::string path = "enemy.png";
		m_surface = IMG_Load(path.c_str());
	}

	if (m_surface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		m_texture = SDL_CreateTextureFromSurface(r.getRender(), m_surface);
		if (m_texture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
		SDL_FreeSurface(m_surface);
	}
}

void Enemy::Update(SDL_Rect* playerPos, bool threadEnabled)
{
	Direction(playerPos, threadEnabled);
	Movement();

}
void Enemy::Movement()
{
	SDL_SemWait(updateSem);
	xPosition += (cos(directionAngle *3.14159 / 180.0) * 1 / 10) / speed;
	yPosition += (sin(directionAngle *3.14159 / 180.0) * 1 / 10) / speed;
	m_render_rect->x = xPosition;
	m_render_rect->y = yPosition;
	SDL_SemPost(updateSem);
}
void Enemy::Direction(SDL_Rect* playerPos, bool threadEnabled)
{
	SDL_SemWait(updateSem);
	directionAngleX = playerPos->x - m_render_rect->x - m_render_rect->w/2;
	directionAngleY = playerPos->y - m_render_rect->y- m_render_rect->h / 2;

	directionAngle = atan2f(directionAngleY, directionAngleX) *180/3.14159;

	if (threadEnabled)
	{
		speed = 250;
	}
	if (!threadEnabled)
	{
		speed = 2;
	}
	SDL_SemPost(updateSem);
}

void Enemy::CollisionResponse()
{
}

bool Enemy::CheckAlive()
{
	return alive;
}

unsigned int Enemy::Draw(Renderer &r)
{
	SDL_RenderCopyEx(r.getRender(), m_texture, NULL, m_render_rect, directionAngle, NULL,SDL_FLIP_NONE);
	return 1;
}

string Enemy::GetString()
{
	return "Hello world!";
}
