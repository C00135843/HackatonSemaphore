#pragma once
#include <SDL.h>
#include "Renderer.h"
#include <SDL_image.h>
#include "InputManager.h"

using namespace std;
class Bullet
{
private:
	SDL_Rect* m_render_rect;
	SDL_Texture* m_texture = NULL;
	SDL_Surface* m_surface;
	SDL_Point m_position;
	int type;
	bool alive;
	void LoadAssets(Renderer &r);
	float directionAngle;

	float directionX;
	float directionY;

	float delta2X;
	float delta2Y;

	float angle;

	float dx;
	float dy;

	

public:
	Bullet(int posX, int posY, int width, int height, Renderer &r, float angle);
	~Bullet();
	void Update(float dirAngle);
	void Rotate(float angle);
	void CollisionResponse();
	bool CheckAlive();
	void Draw(Renderer &r);
	void Shoot();
	bool offScreen();
};
