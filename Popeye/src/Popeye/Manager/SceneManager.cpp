#include "SceneManager.h"
#include "../Scene/Scene.h"

namespace Popeye {

	//SceneManager
	SceneManager::SceneManager()
	{
		currentScene = nullptr;
	}

	SceneManager::~SceneManager()
	{}

	SceneManager* SceneManager::instance = nullptr;

	SceneManager* SceneManager::GetInstance()
	{
		if (!instance)
		{
			instance = new SceneManager;
		}
		return instance;
	}

	void SceneManager::DestroyInstance()
	{
		if (!instance)
		{
			return;
		}
		delete instance;
		instance = nullptr;
	}

	int SceneManager::SceneCreated(Scene& scene)
	{
		//this->scene_IDs.push_back((int)&scene);
		return (int)&scene;
	}

	void SceneManager::UnloadScene()
	{
		delete(currentScene);
	}
}