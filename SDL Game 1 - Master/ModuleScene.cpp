#include "Globals.h"
#include "Application.h"
#include "Application.h"
#include "ModuleScene.h"
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
	texture = App->textures->Load("\ken_stage.png");
	
	
	if (texture == false)
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
	SDL_Rect rect;
	rect.x = 73;
	rect.y = 212;
	SDL_GetWindowSize(App->window->window, &rect.w, &rect.h);
	App->renderer->Blit(texture, 0, 0, &rect);
	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleScene::CleanUp()
{
	LOG("Destroying scene");


	return true;
}