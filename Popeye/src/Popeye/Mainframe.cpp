#include "pch.h"
#include "Mainframe.h"
#include "GUI/GUIManager.h"
#include "System/RenderingSystem.h"
#include "System/EventSystem.h"
#include "Scene/SceneManger.h"
#include "Scene/Scene.h"
#include "Scene/GameObject.h"
#include "Component/ComponentManager.h"

namespace Popeye {

	Mainframe::Mainframe(){}
	Mainframe::~Mainframe(){}

	bool Mainframe::Init()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->window = glfwCreateWindow(1200, 600, "Popeye Engine", NULL, NULL);
		if (!this->window)
		{
			return false;
		}
		glfwMakeContextCurrent(this->window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			return false;
		}
		return true;
	}

	void Mainframe::Run()
	{
		ComponentManager::GetInstance()->InitComponents();

		Scene* scene = new Scene();
		scene->SetName("example");

		SceneManager::GetInstance()->currentScene = scene;

		EventSystem* eventSystem = new EventSystem();
		eventSystem->SetEventCallbacks(window);

		static GUIManager* guimanager = new GUIManager();
		guimanager->OnSet(window);

		float vertices[] = {
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f, 0.0f, 0.0f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  0.0f, 1.0f
		};

		float vertices2[] = {
		-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.0f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.5f, 0.0f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.5f, 0.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.5f, 0.0f,  0.0f, 0.0f,
		};

		unsigned int indices[] = {
			0, 1, 3,
			1, 2, 3
		};

		RenderingSystem* renderer = new RenderingSystem();

		Popeye::Mesh object;
		object.id = GET_NAME(object);
		object.vertsize = sizeof(vertices);
		object.vertices = vertices;
		object.indicies = indices;
		object.indsize = sizeof(indices);

		Popeye::Mesh object2;
		object2.id = GET_NAME(object2);
		object2.vertsize = sizeof(vertices2);
		object2.vertices = vertices2;
		object2.indicies = indices;
		object2.indsize = sizeof(indices);

		Popeye::Material material0;
		material0.id = GET_NAME(material0);
		material0.albedo = glm::vec3(1.0f, 0.5f, 0.5f);
		material0.texture.InitTexture("texture/test.jpg");

		Popeye::Material material1;
		material1.id = GET_NAME(material1);
		material1.albedo = glm::vec3(1.0f, 1.0f, 1.0f);

		scene->CreateGameObject();
		scene->CreateGameObject();
		scene->CreateGameObject();
		scene->CreateGameObject();
		scene->CreateGameObject();
		scene->CreateGameObject();

		scene->gameObjects[0]->SetName("gameObject1");
		scene->gameObjects[0]->AddComponent<MeshRenderer>();
		scene->gameObjects[0]->GetComponent<MeshRenderer>().SetMesh(object);
		scene->gameObjects[0]->GetComponent<MeshRenderer>().SetMaterial(material1);
		scene->gameObjects[0]->transform.position = { 0.0f, 0.0f, 0.0f };
		scene->gameObjects[0]->transform.scale = { 1.0f, 2.0f, 1.0f };

		scene->gameObjects[1]->SetName("gameObject2");
		scene->gameObjects[1]->AddComponent<MeshRenderer>();
		scene->gameObjects[1]->GetComponent<MeshRenderer>().SetMesh(object);
		scene->gameObjects[1]->GetComponent<MeshRenderer>().SetMaterial(material0);
		scene->gameObjects[1]->transform.position = { 2.0f, 3.0f, 3.0f };

		scene->gameObjects[2]->SetName("gameObject3");
		scene->gameObjects[2]->AddComponent<MeshRenderer>();
		scene->gameObjects[2]->GetComponent<MeshRenderer>().SetMesh(object2);
		scene->gameObjects[2]->GetComponent<MeshRenderer>().SetMaterial(material0);
		scene->gameObjects[2]->transform.position = { 2.0f, 0.0f, -1.0f };
		scene->gameObjects[2]->transform.scale = { 1.0f, 2.0f, 1.0f };

		scene->gameObjects[3]->SetName("gameObject4");
		scene->gameObjects[3]->AddComponent<MeshRenderer>();
		scene->gameObjects[3]->GetComponent<MeshRenderer>().SetMesh(object2);
		scene->gameObjects[3]->GetComponent<MeshRenderer>().SetMaterial(material0);
		scene->gameObjects[3]->transform.position = { 1.0f, 4.0f, 5.0f };
		scene->gameObjects[3]->transform.scale = { 6.0f, 2.0f, 6.0f };

		scene->gameObjects[4]->SetName("Camera");
		scene->gameObjects[4]->AddComponent<Camera>();
		scene->mainCameraID = scene->gameObjects[4]->GetID();
		scene->gameObjects[4]->transform.position = { 8.0f, 8.0f, 8.0f };
		scene->gameObjects[4]->transform.rotation = { -22.5f, 45.0f, 0.0f };

		scene->gameObjects[5]->SetName("Light");
		scene->gameObjects[5]->AddComponent<Light>();
		scene->gameObjects[5]->transform.position = { 5.0f, 5.0f, 5.0f };


		POPEYE_CORE_INFO("sds");
		int display_w, display_h;
		while (!glfwWindowShouldClose(window))
		{
			glfwGetFramebufferSize(window, &display_w, &display_h);
			renderer->SystemRunning();
			
			eventSystem->SystemRunning();

			guimanager->OnRun();

			glfwSwapBuffers(window);
		}

		guimanager->OnClosed();
		delete(guimanager);
		delete(renderer);
	}

	void Mainframe::Close()
	{
		glfwTerminate();
	}
}