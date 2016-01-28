#include "stdafx.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include "AudioManager.h"

Mix_Chunk *flute_sfx = NULL;

bool AudioManager::instanceFlag = false;
AudioManager* AudioManager::instance = NULL;

AudioManager* AudioManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new AudioManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}


void AudioManager::Init()
{
	//Initialize SDL
	SDL_Init(SDL_INIT_AUDIO);

	//Initialize SDL_mixer
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void AudioManager::LoadMedia()
{
	//Load sound effects
	//flute_sfx = Mix_LoadWAV("flute.wav");

	flute_sfx = Mix_LoadWAV("flute.wav");
	if (flute_sfx == NULL)
	{
		printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}

}

void AudioManager::PlaySoundEffect(int effect) {
	if (effect == 1)
	{
		Mix_PlayChannel(-1, flute_sfx, 0);
	}
}
