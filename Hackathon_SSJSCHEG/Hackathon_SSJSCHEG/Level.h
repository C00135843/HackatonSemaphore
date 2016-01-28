#include <iostream>
#include <SDL.h>
#include "Renderer.h"
#include <SDL_image.h>
using namespace std;

class Level
{
public:
	Level(Renderer &r);
	void Draw(Renderer &r);

private:
	SDL_Rect* m_render_rect;
	SDL_Rect* m_render_towerRect;
	SDL_Texture* m_bgTexture = NULL;
	SDL_Texture* m_towerTexture = NULL;
	SDL_Surface* m_bgSurface;
	SDL_Surface* m_towerSurface;
	SDL_Point position;
	void LoadAssets(Renderer &r);
};
