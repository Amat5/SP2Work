#ifndef SCENE_TEXT_H
#define SCENE_TEXT_H

#include "Scene.h"


class SceneText  : public Scene
{
public:
	SceneText ();
	~SceneText ();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
private:
	int sound();
	//void RenderTriggeredText(size_t target);
	//size_t collideWith();
	




	float LSPEED;
	float rotateCharacter, rotateTele;
	float engineHeat;
	std::string warningTest;
	bool JetPackActivated;
	bool Teleport;
	bool test;
};

#endif