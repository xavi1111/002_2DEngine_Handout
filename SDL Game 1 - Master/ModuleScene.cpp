#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "SDL/include/SDL.h"

ModuleScene::ModuleScene()
{
}

// Destructor
ModuleScene::~ModuleScene()
{}

// Called before render is available
bool ModuleScene::Init()
{
	LOG("Creating Scene context");
	bool ret = true;
	int screenWidth = 0;
	int screenHeight = 0;
	SDL_GetWindowSize(App->window->window, &screenWidth, &screenHeight);
	textures.push_back(App->textures->Load("\sea.png"));
	SDL_Rect rect;
	rect.h = screenHeight -100;
	rect.w = screenWidth;
	rect.y = 0;
	rect.x = 0;
	rects.push_back(&rect);

	textures.push_back(App->textures->Load("\Floor.png"));
	SDL_Rect rect2;
	rect2.h = 100;
	rect2.w = screenWidth;
	rect2.y = screenHeight - 100;
	rect2.x = 0;
	rects.push_back(&rect2);

	if (textures.size() <= 0)
	{
		LOG("Scene could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleScene::PreUpdate()
{


	return UPDATE_CONTINUE;
}

update_status ModuleScene::Update()
{
	int maxheight = 0;
	int maxwidth = 0;
	std::list<SDL_Texture*>::iterator it1 = textures.begin();
	std::list<SDL_Rect*>::iterator it2 = rects.begin();

	for (; it1 != textures.end() && it2 != rects.end(); ++it1, ++it2)
	{
		SDL_QueryTexture(*it1, NULL, NULL, &maxwidth, &maxheight);
		if (x >= maxwidth) {
			x = maxwidth;
		}
		//(*it2)->x = x;
		App->renderer->Blit(*it1, 0, 0, *it2);
	}
	
	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	return UPDATE_CONTINUE;
}

void ModuleScene::updateX(int value) 
{
	x += value;
	if (x < 0) 
	{
		x = 0;
	}
}

// Called before quitting
bool ModuleScene::CleanUp()
{
	LOG("Destroying scene");


	return true;
}