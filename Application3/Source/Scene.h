#ifndef SCENE_H
#define SCENE_H

#include "Camera2.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Light.h"
#include "Utility.h"
#include "Application.h"
#include "collisionSphere.h"
#include "collisionVolume.h"
#include "GL\glew.h"
#include "Time.h"
#include "shader.hpp"
#include "Mtx44.h"
#include "Application.h"
#include "MeshBuilder.h"
#include "LoadTGA.h"
#include "stdint.h"
#include "Time.h"
#include <irrKlang.h>
#include <Windows.h>
#include <string>
#include <sstream>

class Scene
{

public:
	Scene() {}
	~Scene() {}

	virtual void Init() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;



		enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHTENABLED,
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,
		U_NUMLIGHTS,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,
		U_TOTAL,
	};

	enum GEOMETRY_TYPE
	{
		GEO_AXES = 1,
		GEO_LIGHTBALL,
		GEO_LEFT,
		GEO_RIGHT,
		GEO_TOP,
		GEO_BOTTOM,
		GEO_FRONT,
		GEO_BACK,
		GEO_NOOB,
		GEO_MODEL1,
		GEO_MODEL4,
		GEO_MODEL6,
		TELEPORTER,
		THIRDFLOOR,
		GEO_TEXT,
		NUM_GEOMETRY,
	};



	void RenderMesh(Mesh *mesh, bool enableLight);
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	void RenderImageOnScreen(Mesh* mesh, float size, float x, float y);
	void RenderSkybox();
	int sound();
	//void RenderTriggeredText(size_t target);
	//size_t collideWith();
	


	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	collisionVolume* cV[NUM_GEOMETRY];
	collisionSphere *Player, *Teleporter;

	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	Vector3 charPos;
	bool lightOn;
	bool isFixed;

	Camera2 camera;
	Light lights[1];

	MS modelStack, viewStack, projectionStack;
};

#endif