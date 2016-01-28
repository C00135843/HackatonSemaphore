#pragma once
#include <SDL.h>
#include "Renderer.h"
#include <SDL_image.h>
#include "InputManager.h"
#include "Bullet.h"

#include <vector>

using namespace std;
class Player
{
private:
	SDL_Rect* m_render_rect;
	SDL_Rect rect;
	SDL_Texture* m_texture = NULL;
	SDL_Surface* m_surface;
	SDL_Point position;
	int type;
	bool alive;
	void LoadAssets(Renderer &r);
	float directionAngle;

	float differenceX;
	float differenceY;

	vector<Bullet*> bullets;
	std::vector<Bullet*>::iterator bulletIterator;

public:
	Player(SDL_Point pos, int width, int height, Renderer &r, int t);
	~Player();
	unsigned int Update(Renderer &r);
	void Rotate(float angle);
	void Draw(Renderer &r);
	void Shoot(Renderer &r);

	SDL_Rect* GetRect();
};