#ifndef ___SOUND_SOURCE_H___
#define ___SOUND_SOURCE_H___

#include "visualobject.h"

#include "Framework.h"

class SoundSource :	public VisualObject
{
	public:

	SoundSource(string soundFileName);

	// Destructor
	virtual~SoundSource();
 
	//virtual void initialize();

	virtual void update(float elapsedTimeSeconds);

	void play();

	void stop();

	void pause();

	bool isPlaying();

	void setLooping(bool loopingOn);

	string soundFileName;
	ALuint      uiSource; 

	static bool soundInitialized;
};

#endif // ___SOUND_SOURCE_H___