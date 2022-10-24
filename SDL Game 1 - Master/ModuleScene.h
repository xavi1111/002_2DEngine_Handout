#pragma once
#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL.h"

struct SDL_Scene;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	void updateX(int value);
	bool CleanUp();

public:
	std::list<SDL_Texture*> textures;
	std::list<SDL_Rect*> rects;
private:
	int x = 0;
};