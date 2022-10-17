#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
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

	if (ret == false)
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