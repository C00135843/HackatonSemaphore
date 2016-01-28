#include "stdafx.h"
#pragma comment(lib, "SDL2_image.lib")
#include "Level.h"

Level::Level(Renderer& r)
{
	m_render_rect = new SDL_Rect{0, 0, 900, 600};
	m_render_towerRect = new SDL_Rect{ 400, 250, 100, 100 };

	LoadAssets(r);
}

void Level::LoadAssets(Renderer& r)
{
	std::string bgPath = "bg.png";
	std::string towerPath = "tower.png";
	m_bgSurface = IMG_Load(bgPath.c_str());
	m_towerSurface = IMG_Load(towerPath.c_str());

	if (m_bgSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", bgPath.c_str(), IMG_GetError());
	}
	else
	{
		m_bgTexture = SDL_CreateTextureFromSurface(r.getRender(), m_bgSurface);
		if (m_bgTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", bgPath.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(m_bgSurface);
	}
	m_towerTexture = SDL_CreateTextureFromSurface(r.getRender(), m_towerSurface);
	SDL_FreeSurface(m_towerSurface);
}

void Level::Draw(Renderer &r)
{
	SDL_RenderCopy(r.getRender(), m_bgTexture, NULL, m_render_rect);
	SDL_RenderCopy(r.getRender(), m_towerTexture, NULL, m_render_towerRect);
}
