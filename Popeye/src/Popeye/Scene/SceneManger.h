#pragma once

namespace Popeye {
	class Scene;

	class SceneManager //load/ save scene :: make it near future...  
	{
	private:
		static SceneManager* instance;
		SceneManager();
		~SceneManager();
		std::vector<int> scene_IDs;
	public:
		Scene* currentScene;
	public:
		static SceneManager* GetInstance();
		static void DestroyInstance();
		int SceneCreated(Scene&);
		void LoadScene();
		void SaveScene();
	};
}
