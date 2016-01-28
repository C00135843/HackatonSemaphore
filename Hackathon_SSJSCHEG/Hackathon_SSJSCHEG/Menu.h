#pragma once
#include <SDL.h>
#include "Renderer.h"
#include <SDL_image.h>
using namespace std;
class Menu
{
private:
	SDL_Rect* m_render_rect;
	SDL_Rect rect;
	SDL_Texture* m_texture = NULL;
	SDL_Surface* m_surface;
	SDL_Point position;
	int type;
	bool alive;
	void LoadBackground(Renderer &r);
	void LoadPlayButton(Renderer &r);
	void LoadExitButton(Renderer &r);
	float direction;

public:
	Menu(SDL_Point pos, int width, int height, Renderer &r, int t, string type);
	~Menu();
	void Draw(Renderer &r);

	bool IsClicked(int x, int y);
};
