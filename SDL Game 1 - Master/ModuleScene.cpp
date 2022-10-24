#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include "ModuleWindow.h"
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
	textures = App->textures->Load("\ken_stage.png");

	if (textures == NULL)
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
	int y = 0;
	int screenWidth = 0;
	int screenHeight = 0;
	SDL_GetWindowSize(App->window->window, &screenWidth, &screenHeight);
	
	SDL_Rect* rect = new SDL_Rect();
	rect->w = 768;
	rect->h = 176;
	rect->x = 72;
	rect->y = 208;
	App->renderer->Blit(textures, -x, 0, rect);
	SDL_Rect* rect2 = new SDL_Rect();
	rect2->w = 896;
	rect2->h = 72;
	rect2->x = 8;
	rect2->y = 391;
	App->renderer->Blit(textures, -x, 176, rect2);
	float scaleX = (768.0 / 248.0) * (static_cast<float>(screenHeight) / 248.0);
	float scaleY = static_cast<float>(screenHeight) / 248.0;
	SDL_RenderSetScale(App->renderer->renderer, scaleX, scaleY);
	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	return UPDATE_CONTINUE;
}

void ModuleScene::updateX(int value) 
{
	x += value;
	if (x <= 0) 
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