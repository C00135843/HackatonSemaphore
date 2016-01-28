#pragma once
#ifndef AUDIOMANGER
#define AUDIOMANGER

class AudioManager {
public:
	~AudioManager()
	{
		delete instance;
		instanceFlag = false;
	}
	static AudioManager* GetInstance();

	void Init();
	void LoadMedia();
	void PlaySoundEffect(int);

private:
	AudioManager() {

	}
	static bool instanceFlag;
	static AudioManager* instance;
};
#endif

