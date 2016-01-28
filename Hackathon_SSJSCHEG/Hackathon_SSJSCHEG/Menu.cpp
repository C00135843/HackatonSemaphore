#include "stdafx.h"
#include "Menu.h"
#pragma comment(lib, "SDL2_image.lib")

Menu::Menu(SDL_Point pos, int width, int height, Renderer& r, int t, string type) :type(t)
{
	m_render_rect = new SDL_Rect{ pos.x, pos.y,width,height };

	rect.x = pos.x;
	rect.y = pos.y;
	rect.w = width;
	rect.h = height;

	if(type == "background")
		LoadBackground(r);
	else if (type == "playBtn")
		LoadPlayButton(r);
	else if (type == "exitBtn")
		LoadExitButton(r);
}

Menu::~Menu()
{
}

void Menu::LoadBackground(Renderer& r)
{
	std::string path = "wildwest.png";
	m_surface = IMG_Load(path.c_str());

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

void Menu::LoadPlayButton(Renderer& r)
{
	std::string path = "PlayBtn.png";
	m_surface = IMG_Load(path.c_str());

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

void Menu::LoadExitButton(Renderer& r)
{
	std::string path = "ExitBtn.png";
	m_surface = IMG_Load(path.c_str());

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

bool Menu::IsClicked(int x, int y)
{
	if (rect.x + rect.w > x && rect.x < x && rect.y + rect.h > y && rect.y < y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Menu::Draw(Renderer &r)
{
	SDL_RenderCopy(r.getRender(), m_texture, NULL, m_render_rect);
}