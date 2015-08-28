#include "SceneText.h"
#include "GL\glew.h"
#include "shader.hpp"
#include "MeshBuilder.h"
#include "Application.h"
#include "Utility.h"
#include "LoadTGA.h"

#include <sstream>
#include <irrKlang.h>
#pragma comment (lib, "irrKlang.lib")
using namespace irrklang;

bool SceneText::bReset;
static char CHAR_HEROKEY;
static const float TILE_SIZE = 32;

ISoundEngine *Name	= createIrrKlangDevice(ESOD_AUTO_DETECT, ESEO_MULTI_THREADED | ESEO_LOAD_PLUGINS | ESEO_USE_3D_BUFFERS);

SceneText::SceneText()
	: CurrentMap(NULL)
	, BossPointer(NULL)
	, RenderDim(false)
	, onHero(false)
	, lockMovement(false)
	, CurrentMiniMap(NULL)
{
	bReset = false;
}

SceneText::~SceneText()
{
}

// =============================== INITIALIZING OF VARIABLES/FUNCTIONS ===============================

void SceneText::InitMiniMap_Level1()
{
	// Set New Minimap
	minimap.InitMiniMap_1();
	CurrentMiniMap = minimap.m_cMiniMap1;

	CurrentMiniMap->SetBackground(MeshBuilder::GenerateMinimap("MINIMAP", Color(1, 1, 1), 1.f));
	CurrentMiniMap->GetBackground()->textureID = LoadTGA("Image//Minimap//level1_minimap.tga");
	CurrentMiniMap->SetBorder(MeshBuilder::GenerateMinimapBorder("MINIMAPBORDER", Color(1, 1, 0), 1.f));
	CurrentMiniMap->SetAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetAvatar()->textureID = LoadTGA("Image//Minimap//player.tga");
	CurrentMiniMap->SetEnemyAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetEnemyAvatar()->textureID = LoadTGA("Image//Minimap//enemy.tga");
	CurrentMiniMap->SetDiamondAvatar(MeshBuilder::GenerateMinimapAvatar("DIAMONDAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetDiamondAvatar()->textureID = LoadTGA("Image//Goodies//diamond.tga");
	CurrentMiniMap->SetKeyAvatar(MeshBuilder::GenerateMinimapAvatar("KEYAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetKeyAvatar()->textureID = LoadTGA("Image//Goodies//key.tga");
	CurrentMiniMap->SetBarrelAvatar(MeshBuilder::GenerateMinimapAvatar("BARRELAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBarrelAvater()->textureID = LoadTGA("Image//Goodies//barrel.tga");
	CurrentMiniMap->SetBossAvatar(MeshBuilder::GenerateMinimapAvatar("BOSSAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBossAvatar()->textureID = LoadTGA("Image//Minimap//boss.tga");
}

void SceneText::InitMiniMap_Level2()
{
	minimap.InitMiniMap_2();
	CurrentMiniMap = minimap.m_cMiniMap2;

	CurrentMiniMap->SetBackground(MeshBuilder::GenerateMinimap("MINIMAP", Color(1, 1, 1), 1.f));
	CurrentMiniMap->GetBackground()->textureID = LoadTGA("Image//Minimap//boss_minimap.tga");
	CurrentMiniMap->SetBorder(MeshBuilder::GenerateMinimapBorder("MINIMAPBORDER", Color(1, 1, 0), 1.f));
	CurrentMiniMap->SetAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetAvatar()->textureID = LoadTGA("Image//Minimap//player.tga");
	CurrentMiniMap->SetEnemyAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetEnemyAvatar()->textureID = LoadTGA("Image//Minimap//enemy.tga");
	CurrentMiniMap->SetDiamondAvatar(MeshBuilder::GenerateMinimapAvatar("DIAMONDAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetDiamondAvatar()->textureID = LoadTGA("Image//Goodies//diamond.tga");
	CurrentMiniMap->SetKeyAvatar(MeshBuilder::GenerateMinimapAvatar("KEYAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetKeyAvatar()->textureID = LoadTGA("Image//Goodies//key.tga");
	CurrentMiniMap->SetBarrelAvatar(MeshBuilder::GenerateMinimapAvatar("BARRELAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBarrelAvater()->textureID = LoadTGA("Image//Goodies//barrel.tga");
	CurrentMiniMap->SetBossAvatar(MeshBuilder::GenerateMinimapAvatar("BOSSAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBossAvatar()->textureID = LoadTGA("Image//Minimap//boss.tga");
}

void SceneText::InitMiniMap_Level3()
{
	// Set New Minimap
	minimap.InitMiniMap_3();
	CurrentMiniMap = minimap.m_cMiniMap3;

	CurrentMiniMap->SetBackground(MeshBuilder::GenerateMinimap("MINIMAP", Color(1, 1, 1), 1.f));
	CurrentMiniMap->GetBackground()->textureID = LoadTGA("Image//Minimap//level5_minimap.tga");
	CurrentMiniMap->SetBorder(MeshBuilder::GenerateMinimapBorder("MINIMAPBORDER", Color(1, 1, 0), 1.f));
	CurrentMiniMap->SetAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetAvatar()->textureID = LoadTGA("Image//Minimap//player.tga");
	CurrentMiniMap->SetEnemyAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetEnemyAvatar()->textureID = LoadTGA("Image//Minimap//enemy.tga");
	CurrentMiniMap->SetDiamondAvatar(MeshBuilder::GenerateMinimapAvatar("DIAMONDAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetDiamondAvatar()->textureID = LoadTGA("Image//Goodies//diamond.tga");
	CurrentMiniMap->SetKeyAvatar(MeshBuilder::GenerateMinimapAvatar("KEYAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetKeyAvatar()->textureID = LoadTGA("Image//Goodies//key.tga");
	CurrentMiniMap->SetBarrelAvatar(MeshBuilder::GenerateMinimapAvatar("BARRELAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBarrelAvater()->textureID = LoadTGA("Image//Goodies//barrel.tga");
	CurrentMiniMap->SetBossAvatar(MeshBuilder::GenerateMinimapAvatar("BOSSAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBossAvatar()->textureID = LoadTGA("Image//Minimap//boss.tga");
}

void SceneText::InitMiniMap_Level4()
{
	// Set New Minimap
	minimap.InitMiniMap_4();
	CurrentMiniMap = minimap.m_cMiniMap4;

	CurrentMiniMap->SetBackground(MeshBuilder::GenerateMinimap("MINIMAP", Color(1, 1, 1), 1.f));
	CurrentMiniMap->GetBackground()->textureID = LoadTGA("Image//Minimap//level5_minimap.tga");
	CurrentMiniMap->SetBorder(MeshBuilder::GenerateMinimapBorder("MINIMAPBORDER", Color(1, 1, 0), 1.f));
	CurrentMiniMap->SetAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetAvatar()->textureID = LoadTGA("Image//Minimap//player.tga");
	CurrentMiniMap->SetEnemyAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetEnemyAvatar()->textureID = LoadTGA("Image//Minimap//enemy.tga");
	CurrentMiniMap->SetDiamondAvatar(MeshBuilder::GenerateMinimapAvatar("DIAMONDAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetDiamondAvatar()->textureID = LoadTGA("Image//Goodies//diamond.tga");
	CurrentMiniMap->SetKeyAvatar(MeshBuilder::GenerateMinimapAvatar("KEYAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetKeyAvatar()->textureID = LoadTGA("Image//Goodies//key.tga");
	CurrentMiniMap->SetBarrelAvatar(MeshBuilder::GenerateMinimapAvatar("BARRELAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBarrelAvater()->textureID = LoadTGA("Image//Goodies//barrel.tga");
	CurrentMiniMap->SetBossAvatar(MeshBuilder::GenerateMinimapAvatar("BOSSAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBossAvatar()->textureID = LoadTGA("Image//Minimap//boss.tga");
}

void SceneText::InitMiniMap_Level5()
{
	// Set New Minimap
	minimap.InitMiniMap_5();
	CurrentMiniMap = minimap.m_cMiniMap5;

	CurrentMiniMap->SetBackground(MeshBuilder::GenerateMinimap("MINIMAP", Color(1, 1, 1), 1.f));
	CurrentMiniMap->GetBackground()->textureID = LoadTGA("Image//Minimap//level5_minimap.tga");
	CurrentMiniMap->SetBorder(MeshBuilder::GenerateMinimapBorder("MINIMAPBORDER", Color(1, 1, 0), 1.f));
	CurrentMiniMap->SetAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetAvatar()->textureID = LoadTGA("Image//Minimap//player.tga");
	CurrentMiniMap->SetEnemyAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetEnemyAvatar()->textureID = LoadTGA("Image//Minimap//enemy.tga");
	CurrentMiniMap->SetDiamondAvatar(MeshBuilder::GenerateMinimapAvatar("DIAMONDAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetDiamondAvatar()->textureID = LoadTGA("Image//Goodies//diamond.tga");
	CurrentMiniMap->SetKeyAvatar(MeshBuilder::GenerateMinimapAvatar("KEYAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetKeyAvatar()->textureID = LoadTGA("Image//Goodies//key.tga");
	CurrentMiniMap->SetBarrelAvatar(MeshBuilder::GenerateMinimapAvatar("BARRELAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBarrelAvater()->textureID = LoadTGA("Image//Goodies//barrel.tga");
	CurrentMiniMap->SetBossAvatar(MeshBuilder::GenerateMinimapAvatar("BOSSAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBossAvatar()->textureID = LoadTGA("Image//Minimap//boss.tga");
}

void SceneText::InitMiniMap_Level6()
{
	// Set New Minimap
	minimap.InitMiniMap_6();
	CurrentMiniMap = minimap.m_cMiniMap6;

	CurrentMiniMap->SetBackground(MeshBuilder::GenerateMinimap("MINIMAP", Color(1, 1, 1), 1.f));
	CurrentMiniMap->GetBackground()->textureID = LoadTGA("Image//Minimap//level1_minimap.tga");
	CurrentMiniMap->SetBorder(MeshBuilder::GenerateMinimapBorder("MINIMAPBORDER", Color(1, 1, 0), 1.f));
	CurrentMiniMap->SetAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetAvatar()->textureID = LoadTGA("Image//Minimap//player.tga");
	CurrentMiniMap->SetEnemyAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetEnemyAvatar()->textureID = LoadTGA("Image//Minimap//enemy.tga");
	CurrentMiniMap->SetDiamondAvatar(MeshBuilder::GenerateMinimapAvatar("DIAMONDAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetDiamondAvatar()->textureID = LoadTGA("Image//Goodies//diamond.tga");
	CurrentMiniMap->SetKeyAvatar(MeshBuilder::GenerateMinimapAvatar("KEYAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetKeyAvatar()->textureID = LoadTGA("Image//Goodies//key.tga");
	CurrentMiniMap->SetBarrelAvatar(MeshBuilder::GenerateMinimapAvatar("BARRELAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBarrelAvater()->textureID = LoadTGA("Image//Goodies//barrel.tga");
	CurrentMiniMap->SetBossAvatar(MeshBuilder::GenerateMinimapAvatar("BOSSAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBossAvatar()->textureID = LoadTGA("Image//Minimap//boss.tga");
}

void SceneText::InitMiniMap_Level7()
{
	// Set New Minimap
	minimap.InitMiniMap_7();
	CurrentMiniMap = minimap.m_cMiniMap7;

	CurrentMiniMap->SetBackground(MeshBuilder::GenerateMinimap("MINIMAP", Color(1, 1, 1), 1.f));
	CurrentMiniMap->GetBackground()->textureID = LoadTGA("Image//Minimap//boss_minimap.tga");
	CurrentMiniMap->SetBorder(MeshBuilder::GenerateMinimapBorder("MINIMAPBORDER", Color(1, 1, 0), 1.f));
	CurrentMiniMap->SetAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetAvatar()->textureID = LoadTGA("Image//Minimap//player.tga");
	CurrentMiniMap->SetEnemyAvatar(MeshBuilder::GenerateMinimapAvatar("MINIMAPAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetEnemyAvatar()->textureID = LoadTGA("Image//Minimap//enemy.tga");
	CurrentMiniMap->SetDiamondAvatar(MeshBuilder::GenerateMinimapAvatar("DIAMONDAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetDiamondAvatar()->textureID = LoadTGA("Image//Goodies//diamond.tga");
	CurrentMiniMap->SetKeyAvatar(MeshBuilder::GenerateMinimapAvatar("KEYAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetKeyAvatar()->textureID = LoadTGA("Image//Goodies//key.tga");
	CurrentMiniMap->SetBarrelAvatar(MeshBuilder::GenerateMinimapAvatar("BARRELAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBarrelAvater()->textureID = LoadTGA("Image//Goodies//barrel.tga");
	CurrentMiniMap->SetBossAvatar(MeshBuilder::GenerateMinimapAvatar("BOSSAVATAR", Color(1, 1, 0), 1));
	CurrentMiniMap->GetBossAvatar()->textureID = LoadTGA("Image//Minimap//boss.tga");
}

void SceneText::Init()
{
	//Screen background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//Enable depth test
	glEnable(GL_DEPTH_TEST);

	//Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 
	glEnable(GL_CULL_FACE);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	//Load shaders
	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");

	// Get a handle for our uniform
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	//m_parameters[U_MODEL] = glGetUniformLocation(m_programID, "M");
	//m_parameters[U_VIEW] = glGetUniformLocation(m_programID, "V");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");
	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

	// Get a handle for our "colorTexture" uniform
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");

	// Get a handle for our "textColor" uniform
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

	// Use our shader
	glUseProgram(m_programID);

	lights[0].type = Light::LIGHT_DIRECTIONAL;
	lights[0].position.Set(0, 20, 0);
	lights[0].color.Set(1, 1, 1);
	lights[0].power = 1;
	lights[0].kC = 1.f;
	lights[0].kL = 0.01f;
	lights[0].kQ = 0.001f;
	lights[0].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[0].cosInner = cos(Math::DegreeToRadian(30));
	lights[0].exponent = 3.f;
	lights[0].spotDirection.Set(0.f, 1.f, 0.f);

	lights[1].type = Light::LIGHT_DIRECTIONAL;
	lights[1].position.Set(1, 1, 0);
	lights[1].color.Set(1, 1, 0.5f);
	lights[1].power = 0.4f;

	glUniform1i(m_parameters[U_NUMLIGHTS], 1);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);

	glUniform1i(m_parameters[U_LIGHT0_TYPE], lights[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &lights[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], lights[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], lights[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], lights[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], lights[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], lights[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], lights[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], lights[0].exponent);

	glUniform1i(m_parameters[U_LIGHT1_TYPE], lights[1].type);
	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &lights[1].color.r);
	glUniform1f(m_parameters[U_LIGHT1_POWER], lights[1].power);
	glUniform1f(m_parameters[U_LIGHT1_KC], lights[1].kC);
	glUniform1f(m_parameters[U_LIGHT1_KL], lights[1].kL);
	glUniform1f(m_parameters[U_LIGHT1_KQ], lights[1].kQ);
	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], lights[1].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT1_COSINNER], lights[1].cosInner);
	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], lights[1].exponent);

	camera.Init(Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));

	for(int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = NULL;
	}

	// ================================= LOAD MESHES =================================

	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference");//, 1000, 1000, 1000);

	meshList[GEO_QUAD] = MeshBuilder::GenerateQuad("quad", Color(1, 0, 0), 1.f);

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//Font//c.tga");

	//meshList[GEO_SPHERE] = MeshBuilder::GenerateSphere("sphere", Color(0.5, 0.5, 0.5), 18, 36, 1.f);
	meshList[GEO_SPHERE] = MeshBuilder::GenerateSprites("GEO_SHURIKEN", 3, 3);
	meshList[GEO_SPHERE]->textureID = LoadTGA("Image//shuriken.tga");

	meshList[GEO_SPHERE2] = MeshBuilder::GenerateSphere("sphere2", Color(0.5, 1, 0.5), 18, 36, 1.f);
	
	meshList[GEO_AIM] = MeshBuilder::GenerateQuad("GEO_AIM", Color(1, 0, 0), 3.f);
	meshList[GEO_AIM]->textureID = LoadTGA("Image//aim.tga");

	meshList[GEO_CUBE] = MeshBuilder::GenerateCube("cube",Color(1, 0, 0),1.f);

	// ============================== Load Map tiles (Screen & scrolling) =============================

	meshList[GEO_TILEBACKGROUND] = MeshBuilder::Generate2DMesh("GEO_S_TILEGROUND", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_TILEBACKGROUND]->textureID = LoadTGA("Image//ground.tga");

	meshList[GEO_TILEDOOR] = MeshBuilder::Generate2DMesh("GEO_WALL", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_TILEDOOR]->textureID = LoadTGA("Image//door.tga");

	meshList[GEO_TILEDETECTIONRADIUS] = MeshBuilder::Generate2DMesh("GEO_TILE_WAYPOINT", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_TILEDETECTIONRADIUS]->textureID = LoadTGA("Image//tile0_blank_red.tga");

	meshList[GEO_TILESHEET_DESERT] = MeshBuilder::GenerateTileMap("GEO_TILESHEET_DESERT", 8, 8);
	meshList[GEO_TILESHEET_DESERT]->textureID = LoadTGA("Image//Desert//desert_tile1.tga");

	// =================================== Load Hero ===================================

	meshList[GEO_TILEHEROSHEET] = MeshBuilder::GenerateSprites("GEO_TILEHEROSHEET", 4, 4);
	meshList[GEO_TILEHEROSHEET]->textureID = LoadTGA("Image//Hero//hero.tga");

	meshList[GEO_TILEHEROSHEET2] = MeshBuilder::GenerateSprites("GEO_TILEHEROSHEET2", 4, 4);
	meshList[GEO_TILEHEROSHEET2]->textureID = LoadTGA("Image//Hero//hero2.tga");

	meshList[GEO_TRANSFORMATIONSHEET] = MeshBuilder::GenerateSprites("GEO_TRANSFORMATIONSHEET", 3, 3);
	meshList[GEO_TRANSFORMATIONSHEET]->textureID = LoadTGA("Image//Hero//transformation.tga");

	// ================================= Load Customisation Menu =================================
	
	meshList[GEO_CUSTOM_MENU] = MeshBuilder::GenerateQuad("GEO_CUSTOM_MENU", Color(1, 1, 1), 1);
	meshList[GEO_CUSTOM_MENU]->textureID = LoadTGA("Image//CustomMenu//menu.tga");

	meshList[GEO_HERO_RED] = MeshBuilder::GenerateQuad("GEO_HERO_RED", Color(1, 1, 1), 1);
	meshList[GEO_HERO_RED]->textureID = LoadTGA("Image//CustomMenu//Hero_Red.tga");

	meshList[GEO_HERO_BLUE] = MeshBuilder::GenerateQuad("GEO_HERO_BLUE", Color(1, 1, 1), 1);
	meshList[GEO_HERO_BLUE]->textureID = LoadTGA("Image//CustomMenu//Hero_Blue.tga");

	// ================================= Load Enemies =================================

	meshList[GEO_TILEENEMYSHEET] = MeshBuilder::GenerateSprites("GEO_TILEENEMYSHEET", 5, 5);
	meshList[GEO_TILEENEMYSHEET]->textureID = LoadTGA("Image//Enemy//enemy.tga");

	meshList[GEO_TILEENEMYSHEET2] = MeshBuilder::GenerateSprites("GEO_TILEENEMYSHEET2", 5, 5);
	meshList[GEO_TILEENEMYSHEET2]->textureID = LoadTGA("Image//Enemy//enemy2.tga");

	meshList[GEO_EXCLAMATIONMARK] = MeshBuilder::Generate2DMesh("GEO_TILEEXCLAMATIONMARK", Color(1, 1, 1), 0.0f, 0.0f, 1.0f, 1.0f);
	meshList[GEO_EXCLAMATIONMARK]->textureID = LoadTGA("Image//Enemy//exclamationmark.tga");

	meshList[GEO_STUNSHEET] = MeshBuilder::GenerateSprites("GEO_STUNSHEET", 3, 3);
	meshList[GEO_STUNSHEET]->textureID = LoadTGA("Image//Enemy//stun.tga");

	// ================================= Load Boss =================================

	meshList[GEO_TILEBOSS_FRAME0] = MeshBuilder::GenerateSprites("GEO_TILEENEMY_FRAME0", 3, 3);
	meshList[GEO_TILEBOSS_FRAME0]->textureID = LoadTGA("Image//Enemy//boss.tga");

	// ==================================== Goodies ====================================

	meshList[GEO_DIAMOND] = MeshBuilder::Generate2DMesh("GEO_DIAMOND", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_DIAMOND]->textureID = LoadTGA("Image//Goodies//diamond.tga");

	meshList[GEO_KEY] = MeshBuilder::Generate2DMesh("GEO_KEY", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_KEY]->textureID = LoadTGA("Image//Goodies//key.tga");

	meshList[GEO_CHEST] = MeshBuilder::Generate2DMesh("GEO_CHEST", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_CHEST]->textureID = LoadTGA("Image//Goodies//chest.tga");

	meshList[GEO_CHEST_OPENED] = MeshBuilder::Generate2DMesh("GEO_CHEST_OPENED", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_CHEST_OPENED]->textureID = LoadTGA("Image//Goodies//chest_opened.tga");

	meshList[GEO_BARREL] = MeshBuilder::Generate2DMesh("GEO_BARREL", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_BARREL]->textureID = LoadTGA("Image//Goodies//barrel.tga");

	meshList[GEO_BARREL_BROKEN] = MeshBuilder::Generate2DMesh("GEO_BARREL_BROKEN", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_BARREL_BROKEN]->textureID = LoadTGA("Image//Goodies//barrel_broken.tga");

	meshList[GEO_HAY] = MeshBuilder::Generate2DMesh("GEO_HAY", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_HAY]->textureID = LoadTGA("Image//Goodies//hay2.tga");

	meshList[GEO_HPPOT] = MeshBuilder::Generate2DMesh("GEO_HPPOT", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_HPPOT]->textureID = LoadTGA("Image//Goodies//potions.tga");

	meshList[GEO_MAXHP] = MeshBuilder::Generate2DMesh("GEO_MAX	HP", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_MAXHP]->textureID = LoadTGA("Image//Goodies//maxhpup.tga");

	meshList[GEO_SCROLL] = MeshBuilder::Generate2DMesh("GEO_SCROLL", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_SCROLL]->textureID = LoadTGA("Image//Goodies//scroll.tga");
	//meshList[GEO_SCROLL]->textureID = LoadTGA("Image//OldMan.tga");
	
	meshList[GEO_HOLE] = MeshBuilder::Generate2DMesh("GEO_HOLE", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_HOLE]->textureID = LoadTGA("Image//Goodies//hole.tga");

	// ==================================== Load HUD ====================================

	meshList[GEO_HUD_HEART] = MeshBuilder::Generate2DMesh("GEO_HUD_HEART", Color(1, 1, 1), 0.0f, 0.0f, 1.0f, 1.0f);
	meshList[GEO_HUD_HEART]->textureID = LoadTGA("Image//HUD//heart.tga");

	meshList[GEO_HUD_KEY] = MeshBuilder::Generate2DMesh("GEO_HUD_KEY", Color(1, 1, 1), 0.0f, 0.0f, 1.0f, 1.0f);
	meshList[GEO_HUD_KEY]->textureID = LoadTGA("Image//Goodies//key.tga");

	meshList[GEO_HUD_DIAMOND] = MeshBuilder::Generate2DMesh("GEO_HUD_DIAMOND", Color(1, 1, 1), 0.0f, 0.0f, 1.0f, 1.0f);
	meshList[GEO_HUD_DIAMOND]->textureID = LoadTGA("Image//HUD//diamond.tga");

	meshList[GEO_HUD_SHURIKEN] = MeshBuilder::Generate2DMesh("GEO_HUD_SLINGSHOT", Color(1, 1, 1), 0.0f, 0.0f, 1.0f, 1.0f);
	meshList[GEO_HUD_SHURIKEN]->textureID = LoadTGA("Image//HUD//shurikenHUD.tga");

	meshList[GEO_DETECTIONEYE] = MeshBuilder::Generate2DMesh("GEO_DETECTIONEYE", Color(1, 1, 1), 0.0f, 0.0f, 1.0f, 1.0f);
	meshList[GEO_DETECTIONEYE]->textureID = LoadTGA("Image//HUD//detectioneye.tga");

	meshList[GEO_DETECTIONEYE2] = MeshBuilder::Generate2DMesh("GEO_DETECTIONEYE2", Color(1, 1, 1), 0.0f, 0.0f, 1.0f, 1.0f);
	meshList[GEO_DETECTIONEYE2]->textureID = LoadTGA("Image//HUD//detectioneye2.tga");
	
	meshList[GEO_DIM] = MeshBuilder::Generate2DMesh("GEO_DIM", Color(1, 1, 1), 0.0f, 0.0f, TILE_SIZE, TILE_SIZE);
	meshList[GEO_DIM]->textureID = LoadTGA("Image//tile0_blank_grey.tga");

	// ================================= Game Screens =================================

	meshList[GEO_MENU] = MeshBuilder::GenerateQuad("menu", Color(1, 1, 1), 1);
	meshList[GEO_MENU]->textureID = LoadTGA("Image//menu.tga");
	
	meshList[GEO_LOSE] = MeshBuilder::GenerateQuad("gameover", Color(1, 1, 1), 1);
	meshList[GEO_LOSE]->textureID = LoadTGA("Image//lose_screen.tga");

	// ==================================================================================

	Mtx44 perspective;
	perspective.SetToPerspective(45.0f, 4.0f / 3.0f, 0.1f, 10000.0f);
	projectionStack.LoadMatrix(perspective);

	// === Set hero's position ===

	hero.settheHeroPositionx(128);
	hero.settheHeroPositiony(640);
	int tempHeroPosX = (int) ceil ((float)(128) / 32);
	int tempHeroPosY = 25 - (int) ceil ((float)(640 + 32) / 32);
	hero.heroCurrTile = Vector3(tempHeroPosX, tempHeroPosY, 0);

	// === Variables ===
	
	rotateAngle = 0;

	// === MiniMap Variables ===
	MiniMapRendered = false;
	OpenCloseMiniMap = 0;
	MiniMapDelay = 0;

	// === Game variables ===	
	InShop = false;
	stage = 1;
	attackSpeed = 0;	
	stabOnce = false;
	RenderDim = false;
	shurikenTileID = 0;

	// === Boss's Variables and Pointers ===

	BossPointer = new CBoss();
	BossPointer->BossInit();
	BossTileID = 0;
	bossCounter = 0.0f;
	IsTurn = false;
	EnemiesRendered = false;
	derenderDoor = false;
	GetKey = false;

	// === HUD Variables ===

	diamondCount = 11;
	keyCount = 0;
	PointSystem = 0;

	// === Menu Variables ===

	menu = true;
	InteractHighLight = 0;
	delay = 0;
	Text[0] = "Start Game";
	Text[1] = "How To Play?";

	// === Custom cMenu Variables ===
	
	CustomMenuRendered		= false;
	Blue_Selected			= false;
	Red_Selected			= false;
	Temp_Red_Selected		= false;
	CustomMenuSelected		= false;
	CloseOpenCustomMenu		= 1;
	CustomMenuDelay			= 0;

	Custom_HeroSize_Red		= 20;
	Custom_HeroSize_Blue	= 20;
	
	// === GameOver Variables ===
	
	lose = false;
	LoseTimer = 0.0f;

	// === Screen Dimensions ===

	m_worldHeight = 800.f;
	m_worldWidth = 1024.0f;

	// ================================= Minimap =================================

	if(stage == 1)
	{
		InitMiniMap_Level1();
	}
	
	else if(stage == 2)
	{
		InitMiniMap_Level2();
	}
	
	else if(stage == 3)
	{
		InitMiniMap_Level3();
	}
	
	else if(stage == 4)
	{
		InitMiniMap_Level4();
	}
	
	else if(stage == 5)
	{
		InitMiniMap_Level5();
	}
	
	else if(stage == 6)
	{
		InitMiniMap_Level6();
	}
	
	else if(stage == 7)
	{
		InitMiniMap_Level7();
	}

	// ========================== Initializing Map Inits ==========================

	if(stage == 1)
	{
		map.InitScreenMap(enemyList, GoodiesList, BarrelList, m_goList);
		CurrentMap = map.m_cScreenMap;
	}

	else if(stage == 2)
	{
		map.InitScrollingMap(enemyList, GoodiesList, BarrelList, m_goList);
		CurrentMap = map.m_cScrollingMap;
	}

	else if (stage == 3)
	{
		map.InitScreenMap2(enemyList, GoodiesList, BarrelList, m_goList);
		CurrentMap = map.m_cScreenMap2;
	}

	else if(stage == 4)
	{
		map.InitScrollingMap2(enemyList, GoodiesList, BarrelList, m_goList);
		CurrentMap = map.m_cScrollingMap2;
	}

	else if(stage == 5)
	{
		map.InitScreenMap3(enemyList, GoodiesList, BarrelList, m_goList);
		CurrentMap = map.m_cScreenMap3;
	}

	else if(stage == 6)
	{
		map.InitScrollingMap3(enemyList, GoodiesList, BarrelList, m_goList);
		CurrentMap = map.m_cScrollingMap3;
	}

	else if(stage == 7)
	{
		map.InitBossMap(enemyList, GoodiesList, BarrelList, HoleList, m_goList);
		CurrentMap = map.m_cBossMap;
	}

	m_ghost = new GameObject(GameObject::GO_BALL);
	m_ghost->active = false;
}

// ================================== PHYSICS METHODS AND FUNCTIONS ==================================

GameObject* SceneText::FetchGO()
{
	//Exercise 2a: implement FetchGO()
	for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
	{
		GameObject *go = static_cast<GameObject *>(*it);

		if(!go->active)
		{
			go->active = true;
			go->reset();
			return go;
		}
	}

	for ( unsigned i = 0; i < 30; ++i ) {
		GameObject* go = new GameObject(GameObject::GO_BALL);
		m_goList.push_back(go);
	}

	GameObject *go = m_goList.back();
	go->active = true;
	return go;
}

void SceneText::RenderGO(GameObject *go)
{
	switch(go->type)
	{
		case GameObject::GO_BALL:
		modelStack.PushMatrix();
		if(go->timer < 3)
		{
			//Render2DMesh(meshList[GEO_SPHERE], false, go->scale.x, go->pos.x - CurrentMap->mapOffset_x, go->pos.y);
			RenderSprites(meshList[GEO_SPHERE], shurikenTileID, go->scale.x * 5, go->pos.x - CurrentMap->mapOffset_x - 15, go->pos.y - 15);
		}
		
		else
		{
			//Render2DMesh(meshList[GEO_SPHERE2], false, go->scale.x, go->pos.x - CurrentMap->mapOffset_x, go->pos.y);
			RenderSprites(meshList[GEO_SPHERE], 0, go->scale.x * 5, go->pos.x - CurrentMap->mapOffset_x - 15, go->pos.y - 15);
		}
		modelStack.PopMatrix();
		break;

		case GameObject::GO_WALL:
		{
		}
		break;

		case GameObject::GO_PILLAR:
		{
		}
		break;

		case GameObject::GO_AIM:
		{
			if(go->render == true)
			{
				modelStack.PushMatrix();
				Render2DMesh(meshList[GEO_AIM], false, go->scale.x, go->pos.x, go->pos.y);
				modelStack.PopMatrix();
			}
			break;
		}
	}
}

bool SceneText::checkCollision(GameObject* go, GameObject* go2, double dt)
{
	switch (go2->type)
	{

		case GameObject::GO_WALL:
		{
			Vector3 w0 = go2->pos;
			Vector3 b1 = go->pos + go->vel * dt;
			Vector3 N = go2->normal;
			Vector3 NP = N.Cross(Vector3(0,0,1));
			float r = go->scale.x;
			float h = go2->scale.x;
			float l = go2->scale.y;

			if ((abs((w0 - b1).Dot(N)) < r + h * 0.5f) &&
				(abs((w0 - b1).Dot(NP)) < r + l * 0.5f) )
				return true;

			return false;
		}

		break;

	case GameObject::GO_AIM:
		return false;
		break;

	default:
		{
			Vector3 c = go->vel - go2->vel;
			Vector3 d = go2->pos - go->pos;

			float distanceSquared = (go->pos - go2->pos).LengthSquared();
			float combinedRadius = go->scale.x + go2->scale.x;

			if(distanceSquared <= combinedRadius * combinedRadius && c.Dot(d) > 0)
			{
				return true;
			}

			return false;
		}

		break;
	}

	return false;
}

void SceneText::collisionResponse(GameObject* go, GameObject* go2)
{
	switch(go2->type)
	{
		case GameObject::GO_BALL:
		{
			m1 = go->mass;
			m2 = go2->mass;
			u1 = go->vel;
			u2 = go2->vel;

			Vector3 N = (go2->pos - go->pos).Normalized();
			Vector3 u1N = u1.Dot(N) * N; 
			Vector3 u2N = u2.Dot(N) * N; 

			go->vel = u1 + (2 * m2 / (m1 + m2)) * (u2N - u1N);
			go2->vel = u2 + (2 * m1 / (m1 + m2)) * (u1N - u2N);

			//go2->vel = (2 * m1 * u1 + u2 * (m2 - m1)) * (1 / (m1 + m2));
			//go->vel = (2 * m2 * u2 + u1 * (m1 - m2)) * (1 / (m1 + m2));

			v1 = go->vel;
		}

		break;

		case GameObject::GO_WALL:
		{
			Vector3 w0 = go2->pos;
			Vector3 b1 = go->pos;
			Vector3 N = go2->normal;
			Vector3 NP = N.Cross(Vector3(0,0,1));
			float r = go->scale.x;
			float h = go2->scale.x;
			float l = go2->scale.y;

			if (abs((w0 - b1).Dot(N)) > r + h * 0.5f)
			{
				Vector3 u = go->vel;
				Vector3 v = u - 2 * u.Dot(N) * N;
				go->vel = v * 0.85;
			}

			if (abs((w0 - b1).Dot(NP)) > r + l * 0.5f)
			{
				Vector3 u = go->vel;
				Vector3 v = u - 2 * u.Dot(NP) * NP;
				go->vel = v * 0.85;
			}
		}

		break;

		case GameObject::GO_PILLAR:
		{
			Vector3 N = (go2->pos - go->pos).Normalize();
			Vector3 u = go->vel;
			Vector3 v = u - 2 * u.Dot(N) * N;

			if (go2->ID == CMap::BARREL || go2->ID >= CMap::ENEMY_50)
				go->vel = v * 0.5;
			else
				go->vel = v * 0.85;
		}

		break;
	}
}

// ================================== UPDATES ==================================

void SceneText::Update(double dt)
{
	if(Application::IsKeyPressed('1'))
		glEnable(GL_CULL_FACE);

	if(Application::IsKeyPressed('2'))
		glDisable(GL_CULL_FACE);

	if(Application::IsKeyPressed('3'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if(Application::IsKeyPressed('4'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if(Application::IsKeyPressed('5'))
	{
		lights[0].type = Light::LIGHT_POINT;
		glUniform1i(m_parameters[U_LIGHT0_TYPE], lights[0].type);
	}

	else if(Application::IsKeyPressed('6'))
	{
		lights[0].type = Light::LIGHT_DIRECTIONAL;
		glUniform1i(m_parameters[U_LIGHT0_TYPE], lights[0].type);
	}

	else if(Application::IsKeyPressed('7'))
	{
		lights[0].type = Light::LIGHT_SPOT;
		glUniform1i(m_parameters[U_LIGHT0_TYPE], lights[0].type);
	}

	else if(Application::IsKeyPressed('8'))
	{
		bLightEnabled = true;
	}

	else if(Application::IsKeyPressed('9'))
	{
		bLightEnabled = false;
	}

	//Map traversing aka character can move from 1 map to another 
	int checkPosition_X = (int)((CurrentMap->mapOffset_x + hero.gettheHeroPositionx()) / CurrentMap->GetTileSize());
	int checkPosition_Y = CurrentMap->GetNumOfTiles_Height() - (int)((hero.gettheHeroPositiony() + CurrentMap->GetTileSize()) / CurrentMap->GetTileSize());

	UpdateHero(dt);
	UpdateEnemies(dt);
	UpdateGoodies();
	UpdateBossLevel(checkPosition_X, checkPosition_Y);
	UpdateCustomisation(dt);
	UpdateGameOver();
	UpdateMouse();
	UpdatePhysics(dt);
	MainUpdates(checkPosition_X, checkPosition_Y);
	UpdateMiniMap(dt);

	camera.Update(dt);
	fps = (float)(1.f / dt);
}

void SceneText::UpdateCameraStatus(const unsigned char key, const bool status)
{
}

void SceneText::UpdateAttackStatus(const unsigned char key)
{
	if(key == CA_ATTACK && hero.GetDaggerAcquired() == true && hero.invisibleStatus == false)
	{
		hero.SetAttackStatus(true);
	}
}

void SceneText::CheckEnemiesInRange(CEnemy *go,  Hero hero, int DistanceFromEnemyX, int DistanceFromEnemyY)
{
	//Check hero's attack status
	if(hero.GetAttackStatus() == true && stabOnce == false)
	{
		//Check enemies in x-order
		if(DistanceFromEnemyY >= 0 && DistanceFromEnemyY <= 1)
		{
			if(DistanceFromEnemyX >= 0 && DistanceFromEnemyX <= 32)
			{
				//Hero facing left
				if(hero.heroTileID >= 4 && hero.heroTileID <= 6)
				{
					//Backstab enemy
					if(go->direction == Vector3(-1, 0, 0))
					{
						//Normal soldier
						if(go->ID >= 50 && go->ID < 80)
						{
							go->health -= 2;
						}

						//Amoured soldier
						else if(go->ID >= 80)
						{
							go->health -= 3;
						}
					}

					//Attack enemy from front
					else if(go->direction == Vector3(1, 0, 0))
					{
						go->health--;
					}

					stabOnce = true;
				}
			}

			else if(DistanceFromEnemyX <= 0 && DistanceFromEnemyX >= -32)
			{
				//Hero facing right
				if(hero.heroTileID >= 8 && hero.heroTileID <= 10)
				{
					//Backstab enemy
					if(go->direction == Vector3(1, 0, 0))
					{
						//Normal soldier
						if(go->ID >= 50 && go->ID < 80)
						{
							go->health -= 2;
						}

						//Amoured soldier
						else if(go->ID >= 80)
						{
							go->health -= 3;
						}
					}

					//Attack enemy from front
					else if(go->direction == Vector3(-1, 0, 0))
					{
						go->health--;
					}

					stabOnce = true;
				}
			}
		}

		//Check enemies in Y-order
		else if(DistanceFromEnemyX >= 0 && DistanceFromEnemyX <= 1)
		{
			if(DistanceFromEnemyY >= 0 && DistanceFromEnemyY <= 32)
			{
				//Hero is facing down
				if(hero.heroTileID >= 0 && hero.heroTileID <= 2)
				{
					//Backstab enemy
					if(go->direction == Vector3(0, -1, 0))
					{
						//Normal soldier
						if(go->ID >= 50 && go->ID < 80)
						{
							go->health -= 2;
						}

						//Amoured soldier
						else if(go->ID >= 80)
						{
							go->health -= 3;
						}
					}

					//Attack enemy from front
					else if(go->direction == Vector3(0, 1, 0))
					{
						go->health--;
					}

					stabOnce = true;
				}
			}

			else if(DistanceFromEnemyY <= 0 && DistanceFromEnemyY >= -32)
			{
				//Hero is facing up
				if(hero.heroTileID >= 12 && hero.heroTileID <= 14)
				{
					//Backstab enemy
					if(go->direction == Vector3(0, 1, 0))
					{
						//Normal soldier
						if(go->ID >= 50 && go->ID < 80)
						{
							go->health -= 2;
						}

						//Amoured soldier
						else if(go->ID >= 80)
						{
							go->health -= 3;
						}
					}

					//Attack enemy from front
					else if(go->direction == Vector3(0, -1, 0))
					{
						go->health--;
					}

					stabOnce = true;
				}
			}
		}

		//Assassination from haystack
		else
		{
			if(hero.hiding == true)
			{
				if(hero.GetAttackStatus() == true && stabOnce == false)
				{
					if((DistanceFromEnemyX >= -32 && DistanceFromEnemyX <= 32) && (DistanceFromEnemyY >= -50 && DistanceFromEnemyY <= 50) || (DistanceFromEnemyY >= -4 && DistanceFromEnemyY <= 4) && (DistanceFromEnemyX >= -50 && DistanceFromEnemyX <= 50))
					{
						if(go->theStrategy->CurrentState == CStrategy::PATROL)
						{
							//Normal soldier
							if(go->ID >= 50 && go->ID < 80)
							{
								go->health -= 2;
							}

							//Amoured soldier
							else if(go->ID >= 80)
							{
								go->health -= 3;
							}

							stabOnce = true;
						}
					}		
				}
			}
		}
	}

	//Reset for hero to hit again
	else if(hero.GetAttackStatus() == false && stabOnce == true)
	{
		stabOnce = false;
	}

	//Check enemies' health
	if(go->health <= 0)
	{
		go->active = false;
		go->health = 0;
		go->attackReactionTime = 0;
	}

	//Checking if enemy can attack hero
	if(go->eneCurrTile == hero.heroCurrTile)
	{
		go->attackStatus = true;
	}

	else
	{
		go->attackStatus = false;
	}
}

void SceneText::UpdateHero(double dt)
{
	if(lockMovement == false)
	{
		if(Application::IsKeyPressed('A') && hero.transform == false)
		{
			hero.direction = Vector3(-1,0,0);
			CHAR_HEROKEY = 'a';

			//Sprite Animation
			hero.heroTileID += 0.2;
			if(hero.heroTileID < 4)
			{
				hero.heroTileID = 4;
			}

			if(hero.heroTileID > 7)
			{
				hero.heroTileID = 4;
			}
		}

		else if(Application::IsKeyPressed('D') && hero.transform == false)
		{
			hero.direction = Vector3(1,0,0);
			CHAR_HEROKEY = 'd';

			//Sprite Animation
			hero.heroTileID += 0.2;
			if(hero.heroTileID < 8)
			{
				hero.heroTileID = 8;
			}

			if(hero.heroTileID > 11)
			{
				hero.heroTileID = 8;
			}

			cout << hero.heroTileID << endl;
		}

		else if(Application::IsKeyPressed('W') && hero.transform == false)
		{
			hero.direction = Vector3(0,1,0);
			CHAR_HEROKEY = 'w';

			//Sprite Animation
			hero.heroTileID += 0.2;
			if(hero.heroTileID < 12)
			{
				hero.heroTileID = 12;
			}

			if(hero.heroTileID > 15)
			{
				hero.heroTileID = 12;
			}
		}

		else if(Application::IsKeyPressed('S') && hero.transform == false)
		{
			hero.direction = Vector3(0,-1,0);
			CHAR_HEROKEY = 's';

			//Sprite Animation
			hero.heroTileID += 0.2;
			if(hero.heroTileID < 0)
			{
				hero.heroTileID = 0;
			}

			if(hero.heroTileID > 3)
			{
				hero.heroTileID = 0;
			}
		}
	}

	//Limit hero's attak rate
	if(hero.GetAttackStatus() == true)
	{
		attackSpeed += dt;
		if(attackSpeed >= 0.5)
		{
			attackSpeed = 0;
			hero.SetAttackStatus(false);
		}
	}

	//Check if player is hiding
	if(CurrentMap->theScreenMap[hero.heroCurrTile.y][hero.heroCurrTile.x] == CMap::HAY || hero.invisibleStatus == true)
	{
		hero.hiding = true;
		RenderDim = true;
	}
	
	else
	{
		hero.hiding = false;
		RenderDim = false;
	}

	//Transformation to stealth
	if(hero.transform == true)
	{
		hero.heroTransformID += 0.1;
		if(hero.heroTransformID >= 8)
		{
			hero.heroTransformID = 0;
			hero.transform = false;

			if(Blue_Selected == true && hero.invisibleTimer < 15)
			{
				hero.invisibleStatus = true;
			}

			else if(Red_Selected == true && hero.invisibleTimer < 15)
			{
				hero.invisibleStatus = false;
				hero.invisibleTimer = 0;
			}

			if(hero.invisibleTimer >= 15)
			{
				hero.invisibleStatus = false;
				hero.invisibleTimer = 0;
				Red_Selected = true;
				Blue_Selected = false;
			}
		}
	}

	//Timer during invisibility
	if(hero.invisibleStatus == true)
	{
		hero.invisibleTimer += dt;
		if(hero.invisibleTimer >= 15)
		{
			hero.transform = true;
		}
	}

	if(!InShop)
	{
		hero.HeroUpdate(CurrentMap, BarrelList, enemyList, CHAR_HEROKEY, stage);
	}
	else
	{
		hero.HeroUpdate(CurrentMap, BarrelList, enemyList, CHAR_HEROKEY, 999);
	}
	CHAR_HEROKEY = NULL;
}

void SceneText::UpdateEnemies(double dt)
{
	for(std::vector<CEnemy *>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		CEnemy *go = (CEnemy *)*it;
		if(go->active)	
		{
			go->theStrategy->CurrentState;

			if(go->currentStrat != CEnemy::STRAT_KILL)
			{
				go->ChangeStrategy(new CStrategy_Kill());
				go->currentStrat = CEnemy::STRAT_KILL;
			}

			go->SetDestination(hero.gettheHeroPositionx() + CurrentMap->mapOffset_x, hero.gettheHeroPositiony());

			if(go->stunned && go->routeCounter == 0 && go->routeCounter2 == 0)
			{
			}
			
			else
			{
				go->Update(CurrentMap, hero.heroCurrTile, BarrelList, hero.invisibleStatus);
				
				int DistanceFromEnemyX = hero.gettheHeroPositionx() - go->GetPos_x() + CurrentMap->mapOffset_x;
				int DistanceFromEnemyY = hero.gettheHeroPositiony() - go->GetPos_y();
				CheckEnemiesInRange(go, hero, DistanceFromEnemyX, DistanceFromEnemyY);
			}

			//If enemy is stunned
			if(go->stunned)
			{
				go->stunTimer += dt;
				go->stunTileID += 0.2;
				if(go->stunTileID >= 4)
				{
					go->stunTileID = 0;
				}
			}

			if(go->stunTimer >= 3)
			{
				go->stunned = false;
				go->stunTimer = 0;
				go->stunTileID = 0;
				go->theStrategy->isAttacking = true;
			}

			if (go->isHit == true && go->routeCounter == 0 && go->routeCounter2 == 0)
			{
				go->theStrategy->isAttacking = true;
			}

			//Checking enemy attack status
			if(go->attackStatus == true && go->attackAnimation == false)
			{
				go->attackReactionTime += dt;
				if(go->attackReactionTime >= 0.2)
				{
					hero.health--;
					go->attackReactionTime = 0;
					go->attackStatus = false;
					go->attackAnimation = true;
				}
			}

			else
			{
				go->attackReactionTime = 0;
			}

			//Attacking animation for enemy
			if (go->attackAnimation == true)
			{
				go->attackAnimationTimer += dt;
				if (go->attackAnimationTimer >= 1)
				{
					go->attackAnimationTimer = 0;
					go->attackAnimation = false;
				}
			}

			for(std::vector<CGoodies *>::iterator it2 = BarrelList.begin(); it2!= BarrelList.end(); ++it2)
			{
				CGoodies *go2 = (CGoodies *)*it2;
				if(go2->active)	
				{
					if(go->eneCurrTile == go2->tilePos)
					{
						go->attackAnimation = true;
						go2->active = false;
					}
				}
			}

			//Movement Sprite Animation
			if(go->direction == Vector3(0, -1, 0))
			{
				//Sprite Animation
				go->enemyTileID += 0.2;
				if(go->enemyTileID < 0)
				{
					go->enemyTileID = 0;
				}

				else if(go->enemyTileID > 3)
				{
					go->enemyTileID = 0;
				}
			}

			else if(go->direction == Vector3(-1, 0, 0))
			{
				//Sprite Animation
				go->enemyTileID += 0.2;
				if(go->enemyTileID < 5)
				{
					go->enemyTileID = 5;
				}

				else if(go->enemyTileID > 8)
				{
					go->enemyTileID = 5;
				}
			}

			else if(go->direction == Vector3(1, 0, 0))
			{
				//Sprite Animation
				go->enemyTileID += 0.2;
				if(go->enemyTileID < 10)
				{
					go->enemyTileID = 10;
				}

				else if(go->enemyTileID > 13)
				{
					go->enemyTileID = 10;
				}
			}

			else if(go->direction == Vector3(0, 1, 0))
			{
				//Sprite Animation
				go->enemyTileID += 0.2;
				if(go->enemyTileID < 15)
				{
					go->enemyTileID = 15;
				}

				else if(go->enemyTileID > 18)
				{
					go->enemyTileID = 15;
				}
			}
		}
	}
}

void SceneText::UpdateGoodies()
{
	for(std::vector<CGoodies *>::iterator it = GoodiesList.begin(); it != GoodiesList.end(); ++it)
	{
		CGoodies *go = (CGoodies *)*it;
		if(go->active)	
		{
			if(go->GoodiesType == CGoodies::Goodies_Type::BARREL)
			{
				if(hero.GetAttackStatus() == true)
				{
					Vector3 tempheroTile = hero.heroCurrTile + Vector3(hero.direction.x,-hero.direction.y,0);

					if(tempheroTile == go->tilePos)
					{
						hero.SetDaggerAcquired(true);
						go->active = false;
					}
				}
			}

			else if(go->GoodiesType == CGoodies::Goodies_Type::CHEST)
			{
				if(hero.GetPickUpWeapon() == true && Application::IsKeyPressed(VK_SPACE))
				{
					Vector3 tempheroTile = hero.heroCurrTile + Vector3(hero.direction.x,-hero.direction.y,0);
					if(tempheroTile == go->tilePos)
					{
						hero.SetDaggerAcquired(true);
						go->active = false;
					}
				}
			}

			else
			{	
				if(go->CalculateDistance(hero.gettheHeroPositionx() + CurrentMap->mapOffset_x, hero.gettheHeroPositiony()) == true)
				{
					if(go->GoodiesType != CGoodies::Goodies_Type::DOOR)
					{
						if(go->GoodiesType == CGoodies::Goodies_Type::KEY)
						{
							hero.SetKeyAcquired(true);
							go->active = false;
							keyCount++;
						}
						
						else if(go->GoodiesType == CGoodies::Goodies_Type::JEWEL)
						{
							go->active = false;
							diamondCount++;
							PointSystem += 10;
						}
						
						else if(go->GoodiesType == CGoodies::Goodies_Type::HPPOT)
						{
							if(hero.heroCurrTile == go->tilePos && hero.health < hero.full_health)
							{
								if(diamondCount >= 3)
								{
									go->active = false;
									hero.health++;
									diamondCount -= 3;
								}
							}
						}
						
						else if(go->GoodiesType == CGoodies::Goodies_Type::MAXHP)
						{
							if(hero.heroCurrTile == go->tilePos)
							{
								if(hero.health == hero.full_health)
								{
									if(diamondCount >= 5)
									{
										go->active = false;
										hero.health++;
										hero.full_health++;
										diamondCount -= 5;
									}
								}
							}
						}
						
						else if(go->GoodiesType == CGoodies::Goodies_Type::SCROLL)
						{
							if(hero.heroCurrTile == go->tilePos)
							{
								if(diamondCount >= 3)
								{
									go->active = false;
									hero.NoOfScroll++;
									diamondCount -= 3;
								}
							}
						}
					}
				}
			}
		}
	}
}

void SceneText::UpdateBossLevel(int checkPosition_X, int checkPosition_Y)
{
	BossPointer->Set_BossDestination(BossPointer->Get_BossX(), BossPointer->Get_BossY());
	bossCounter += 0.01f;

	if(bossCounter < 2.0f)
	{
		BossTileID += 0.1f;
		if(BossTileID > 2)
		{
			BossTileID = 0;
			IsTurn = false;
		}
	}

	else if(bossCounter > 2.0f && bossCounter < 4.0f)
	{
		BossTileID += 0.1f;
		if(BossTileID > 5)
		{
			BossTileID = 3;
			IsTurn = true;
		}
	}

	else if(bossCounter > 4.0f)
	{
		bossCounter = 0;
	}

	if(hero.GetdoorOpened() == true)
	{
		derenderDoor = true;
	}

	if(stage == 7 && (CurrentMap->theScreenMap[checkPosition_Y][checkPosition_X + 1] == CMap::BOSS || CurrentMap->theScreenMap[checkPosition_Y + 1][checkPosition_X] == CMap::BOSS || CurrentMap->theScreenMap[checkPosition_Y - 1][checkPosition_X] == CMap::BOSS))
	{
		if(Application::IsKeyPressed(VK_SPACE))
		{
			if(GetKey == false)
			{
				keyCount++;
			}

			if(keyCount == 1)
			{
				hero.SetKeyAcquired(true);
				GetKey = true;
			}

			for(std::vector<CGoodies *>::iterator it = GoodiesList.begin(); it != GoodiesList.end(); ++it)
			{
				CGoodies *go = (CGoodies *)*it;
				if(go->active)
				{
					if(go->GoodiesType == CGoodies::Goodies_Type::DOOR)
					{
						go->active = false;
					}
				}
			}
		}
	}

	if(IsTurn == true)
	{
		for (int i = 0; i < CurrentMap->GetNumOfTiles_Height(); i++)
		{
			for (int k = 0; k < CurrentMap->GetNumOfTiles_Width() + 1; k++)
			{
				if (CurrentMap->theScreenMap[CurrentMap->GetNumOfTiles_Height() - (hero.gettheHeroPositiony() / 32)][hero.gettheHeroPositionx() / 32] == 0 || CurrentMap->theScreenMap[(CurrentMap->GetNumOfTiles_Height() - (hero.gettheHeroPositiony() / 32)) + 1][hero.gettheHeroPositionx() / 32] == 0 || CurrentMap->theScreenMap[CurrentMap->GetNumOfTiles_Height() - (hero.gettheHeroPositiony() / 32)][(hero.gettheHeroPositionx() / 32) + 1] == 0)
				{
					EnemiesRendered = true;
				}
			}
		}
	}

	if(stage == 7)
	{
		for (std::vector<CEnemy *>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
		{
			CEnemy *go = (CEnemy *)*it;
			if (EnemiesRendered == true && go->health > 0)
			{
				go->active = true;
			}
			else
			{
				go->active = false;
			}
		}
	}

	BossPointer->Set_SpawnGuards(IsTurn);
}

void SceneText::UpdateCustomisation(double dt)
{
	//Delay in closing and opening Menu
	if(CheckCustomMenu == true)
	{
		CustomMenuDelay += dt;
		if(CustomMenuDelay >= 0.2)
		{
			CustomMenuDelay = 0;
			CheckCustomMenu = false;

			if(CloseOpenCustomMenu == 1)
			{
				CloseOpenCustomMenu = 2;
			}

			else
			{
				CloseOpenCustomMenu = 1;
			}			
		}
	}

	//Open Menu
	if(Application::IsKeyPressed('T'))
	{
		if(CloseOpenCustomMenu == 1)
		{
			CustomMenuRendered = true;
			CustomMenuSelected = false;
		}

		else if(CloseOpenCustomMenu == 2)
		{
			CustomMenuRendered = false;
		}

		CheckCustomMenu = true;
	}

	//Set for starting
	if(CustomMenuRendered == false)
	{
		Temp_Red_Selected = true;
	}

	//If a choice is selected
	if((Red_Selected == true || Blue_Selected == true))
	{
		Temp_Red_Selected = false;
	}

	//If a choice is selected, menu close
	if(CustomMenuSelected == true)
	{
		CustomMenuRendered = false;
	}
}

void SceneText::UpdateGameOver()
{
	if(hero.health <= 0)
	{
		lose = true;
	}

	if(lose == true)
	{
		LoseTimer += 0.01f;
		if(LoseTimer >= 2.0f)
		{
			bReset = true;
		}
	}
}

void SceneText::UpdateMouse()
{
	// =================================== For Right Click Interaction ===================================
	
	if(CustomMenuRendered == false)
	{
		static bool bLButtonState = false;
		if(!bLButtonState && Application::IsMousePressed(0) && hero.invisibleStatus == false)
		{
			bLButtonState = true;
			//std::cout << "LBUTTON DOWN" << std::endl;

			double x, y;
			Application::GetCursorPos(&x, &y);
			int w = Application::GetWindowWidth();
			int h = Application::GetWindowHeight();
			float posX = static_cast<float>(x) / w * m_worldWidth;
			float posY = (h - static_cast<float>(y)) / h * m_worldHeight;
		}

		else if(bLButtonState && !Application::IsMousePressed(0) && hero.invisibleStatus == false)
		{
			bLButtonState = false;
			//std::cout << "LBUTTON UP" << std::endl;

			double x, y;
			Application::GetCursorPos(&x, &y);
			int w = Application::GetWindowWidth();
			int h = Application::GetWindowHeight();
			float posX = static_cast<float>(x) / w * m_worldWidth;
			float posY = (h - static_cast<float>(y)) / h * m_worldHeight;
		}

		static bool bRButtonState = false;
		if(!bRButtonState && Application::IsMousePressed(1) && hero.invisibleStatus == false)
		{
			bRButtonState = true;
			//std::cout << "RBUTTON DOWN" << std::endl;

			double x, y;
			Application::GetCursorPos(&x, &y);
			int w = Application::GetWindowWidth();
			int h = Application::GetWindowHeight();

			float posX = x / w * m_worldWidth;
			float posY = (h - y) / h * m_worldHeight;
			m_ghost->pos.Set(posX, posY, 0);

			int mouseX = (int)((CurrentMap->mapOffset_x + posX) / CurrentMap->GetTileSize());
			int mouseY = CurrentMap->GetNumOfTiles_Height() - (int)((posY + CurrentMap->GetTileSize()) / CurrentMap->GetTileSize());

			if(Vector3(mouseX, mouseY, 0) == hero.heroCurrTile && hero.ammo >= 1)
			{
				onHero = true;
				hero.rotation = hero.direction;

				for(int i = 0; i < 10; ++i)
				{
					GameObject *go = FetchGO();
					go->type = GameObject::GO_AIM;
					go->active = true;
					go->pos = Vector3(hero.gettheHeroPositionx() + 16,hero.gettheHeroPositiony() + 16,0);
					go->scale.Set(4, 4, 4);

					if(i == 0)
					{
						go->isSet = true;
					}
				}

				prevPos = Vector3(hero.gettheHeroPositionx() + 16,hero.gettheHeroPositiony() + 16,0);
				lockMovement = true;
			}

			else
			{
				onHero = false;
			}
		}

		else if(bRButtonState && !Application::IsMousePressed(1) && hero.invisibleStatus == false)
		{
			bRButtonState = false;
			//std::cout << "RBUTTON UP" << std::endl;

			if(onHero == true)
			{
				for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
				{
					GameObject *go = (GameObject *)*it;
					if(go->active == false)
					{
						go->active = true;
						go->type = GameObject::GO_BALL;
						double x, y;
						Application::GetCursorPos(&x, &y);
						int w = Application::GetWindowWidth();
						int h = Application::GetWindowHeight();
						float worldX = x * m_worldWidth / w;
						float worldY = (h - y) * m_worldHeight / h;

						go->pos = Vector3(hero.gettheHeroPositionx() + 16 + CurrentMap->mapOffset_x,hero.gettheHeroPositiony() + 16,0);
						go->vel = Vector3(hero.gettheHeroPositionx()+ 16, hero.gettheHeroPositiony() + 16, 0) - Vector3(worldX, worldY, 0);
						go->vel *= 2.5;
						go->scale.Set(6, 6, 6);

						if (go->vel.Length() > MAX_SPEED)
						{
							go->vel = go->vel.Normalize() * MAX_SPEED;
						}

						m_ghost->active = false;
						hero.ammo -= 1;
						break;
					}
				}

				for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
				{
					GameObject *go = (GameObject *)*it;
					if(go->active && go->type == GameObject::GO_AIM)
					{
						go->isSet = false;
						go->active = false;
					}
				}
			}

			lockMovement = false;
		}

		if(bRButtonState == true)
		{
			double x, y;
			Application::GetCursorPos(&x, &y);
			int w = Application::GetWindowWidth();
			int h = Application::GetWindowHeight();
			float posX = x / w * m_worldWidth;
			float posY = (h - y) / h * m_worldHeight;

			if(onHero == true)
			{
				Vector3 posXY (posX,posY,0);
				Vector3 mousePos = -Vector3(hero.gettheHeroPositionx(),hero.gettheHeroPositiony(),0) + posXY;

				float angle;

				angle = Math::RadianToDegree(atan2((hero.rotation.Cross(mousePos)).Length(),hero.rotation.Dot(mousePos)));

				Vector3 pointB = Vector3(hero.gettheHeroPositionx(),hero.gettheHeroPositiony(),0) + hero.rotation;

				if((pointB.x - hero.gettheHeroPositionx()) * (posY - hero.gettheHeroPositiony()) - 
					(pointB.y - hero.gettheHeroPositiony()) * (posX - hero.gettheHeroPositionx()) > 0)
				{
					Mtx44 rot;
					rot.SetToRotation(angle,0,0,1);
					hero.rotation = rot * hero.rotation;
				}
				
				else
				{
					Mtx44 rot;
					rot.SetToRotation(-angle,0,0,1);
					hero.rotation = rot * hero.rotation;
				}
			}

			for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
			{
				GameObject *go = (GameObject *)*it;
				if(go->active && go->type == GameObject::GO_AIM)
				{
					if(go->isSet == false)
					{
						if((Vector3(posX, posY, 0) - prevPos).Length() >= 20)
						{
							Vector3 dis = (Vector3(posX, posY, 0) - prevPos).Normalize() * 20;
							go->pos = prevPos + dis;
							go->isSet = true;
							prevPos = go->pos;
							break;
						}
					}

					else
					{
						Vector3 a = go->pos - Vector3(hero.gettheHeroPositionx() + 16,hero.gettheHeroPositiony() + 16,0);;

						if(a.IsZero())
						{
							continue;
						}

						float length = a.Length();
						Vector3 b = Vector3(posX, posY, 0) - Vector3(hero.gettheHeroPositionx() + 16,hero.gettheHeroPositiony() + 16,0);;

						if(a.Length() > b.Length())
						{
							go->render = false;
						}

						else
						{
							go->render = true;
						}

						if(!b.IsZero())
						{
							go->pos = Vector3(hero.gettheHeroPositionx() + 16,hero.gettheHeroPositiony() + 16,0) + ((a.Dot(b.Normalize())) * b.Normalize()).Normalize() * length;
						}
					}
				}
			}
		}
	}

	// =================================== For Left Click Interaction ===================================
	
	//Selecting options on menu
	else
	{
		static bool bLButtonState = false;
		if(!bLButtonState && Application::IsMousePressed(0))
		{
			bLButtonState = true;
			//std::cout << "LBUTTON DOWN" << std::endl;

			double x, y;
			Application::GetCursorPos(&x, &y);
			int w = Application::GetWindowWidth2();
			int h = Application::GetWindowHeight2();

			if(w <= 800 && h <= 600)
			{
				//For Red Hero
				if((x > 123 && x < 278) && (y < 404 && y > 203) && Red_Selected == false)
				{
					cout << "HELLO RED WORLD" << endl;
					
					Red_Selected = true;
					Blue_Selected = false;
					hero.transform = true;
				}
				
				//For Blue Hero
				else if((x > 524 && x < 675) && (y < 404 && y > 203) && Blue_Selected == false)
				{
					cout << "HELLO BLUE WORLD" << endl;
					
					Red_Selected = false;
					Blue_Selected = true;
					hero.transform = true;
				}
			}

			else
			{
				//For Red Hero
				if((x > 303 && x < 662) && (y < 684 && y > 349))
				{
					cout << "HELLO RED WORLD" << endl;

					Red_Selected = true;
					Blue_Selected = false;
				}
				
				//For Blue Hero
				else if((x > 1266 && x < 1622) && (y < 684 && y > 349))
				{
					cout << "HELLO BLUE WORLD" << endl;

					Red_Selected = false;
					Blue_Selected = true;
				}
			}

			CustomMenuSelected = true;
		}

		else if(bLButtonState && !Application::IsMousePressed(0))
		{
			bLButtonState = false;
			//std::cout << "LBUTTON UP" << std::endl;

			double x, y;
			Application::GetCursorPos(&x, &y);
			int w = Application::GetWindowWidth2();
			int h = Application::GetWindowHeight2();
		}

		//Hover over image to make it big
		else if((!bLButtonState && !Application::IsMousePressed(0) && CustomMenuRendered == true))
		{
			bLButtonState = true;
			//std::cout << "LBUTTON DOWN" << std::endl;

			double x, y;
			Application::GetCursorPos(&x, &y);
			int w = Application::GetWindowWidth2();
			int h = Application::GetWindowHeight2();

			if(w <= 800 && h <= 600)
			{
				// For Red Hero
				if ((x > 123 && x < 278) && (y < 404 && y > 203))
				{
					Custom_HeroSize_Red = 30;
				}

				// For BLUE Hero
				else if((x > 524 && x < 675) && (y < 404 && y > 203))
				{
					Custom_HeroSize_Blue = 30;
				}
				
				else
				{
					Custom_HeroSize_Red = 20;
					Custom_HeroSize_Blue = 20;
				}
			}
			
			else
			{
				//For Red Hero
				if((x > 301 && x < 661) && (y < 677 && y > 353))
				{
					Custom_HeroSize_Red = 30;
				}

				//For BLUE Hero
				else if((x > 1281 && x < 1618) && (y < 677 && y > 353))
				{
					Custom_HeroSize_Blue = 30;
				}
				
				else
				{
					Custom_HeroSize_Red = 20;
					Custom_HeroSize_Blue = 20;
				}
			}
		}
		
		else
		{
			bLButtonState = false;
		}
	}
}

void SceneText::UpdatePhysics(double dt)
{
	for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
	{
		GameObject *go = (GameObject *)*it;
		if(go->active)
		{
			if(go->type == GameObject::GO_BALL)
			{
				Vector3 friction = -go->vel * 0.2f;
				go->vel += friction * dt;
				go->pos += go->vel * dt;
				go->timer += dt;

				shurikenTileID += 1;
				if(shurikenTileID >= 5)
				{
					shurikenTileID = 0;
				}

				if(go->vel.Length() <= 2.f)
				{
					go->vel.SetZero();
				}

				for(std::vector<GameObject *>::iterator it2 = m_goList.begin(); it2 != m_goList.end(); ++it2)
				{
					GameObject *go2 = (GameObject *)*it2;
					if(go2->active)
					{
						if(checkCollision(go, go2, dt))
						{
							if(go2->ID == CMap::BARREL)
							{
								for(std::vector<CGoodies *>::iterator it3 = BarrelList.begin(); it3 != BarrelList.end(); ++it3)
								{
									CGoodies *go3 = (CGoodies *)*it3;

									if(go3->active && (go3->GetPos_x() == go2->pos.x - 16) && (go3->GetPos_y() == go2->pos.y - 16))
									{
										collisionResponse(go, go2);	

										if(go->timer < 3)
											go3->active = false;
									}
								}
							}

							else if(go2->ID >= CMap::ENEMY_50)
							{
								for(std::vector<CEnemy *>::iterator it4 = enemyList.begin(); it4 != enemyList.end(); ++it4)
								{
									CEnemy *go4 = (CEnemy *)*it4;

									if(go4->active && go4->ID == go2->ID)
									{
										collisionResponse(go, go2);	

										if(go->timer < 3 && go4->ID < 80 && go4->stunned == false)
										{
											go4->stunned = true;
											go4->isHit = true;
											go4->health--;
										}

										else if (go4->ID >= 80)
											go4->isHit = true;
									}
								}
							}

							else
								collisionResponse(go, go2);	
						}
					}
				}

				if(go->timer >= 3)
				{
					float combinedDist = (Vector3(hero.gettheHeroPositionx() + CurrentMap->mapOffset_x,hero.gettheHeroPositiony(),0) - go->pos).Length();
					float combinedRad = 32;

					if(combinedDist <= combinedRad)
					{
						go->active = false;
						hero.ammo++;
						go->timer = 0;
						shurikenTileID = 0;
					}					
				}
			}

			if(go->type == GameObject::GO_PILLAR)
			{
				for(std::vector<CEnemy *>::iterator it2 = enemyList.begin(); it2 != enemyList.end(); ++it2)
				{
					CEnemy *go2 = (CEnemy *)*it2;
					if(go2->active)
					{
						if(go2->ID == go->ID)
						{
							go->pos.x = go2->GetPos_x() + 16 /*+ CurrentMap->mapOffset_x*/;
							go->pos.y = go2->GetPos_y() + 16;
						}
					}
				}
			}
		}
	}
}

void SceneText::UpdateMiniMap(double dt)
{
	MiniMapDelay += dt;

	if(MiniMapDelay >= 1)
	{
		MiniMapDelay = 0;
	}

	//cout << MiniMapDelay << endl;

	if(Application::IsKeyPressed('G') && OpenCloseMiniMap == 0 && MiniMapDelay < 0.3)
	{
		MiniMapRendered = true;
		OpenCloseMiniMap = 1;
	}

	else if(Application::IsKeyPressed('G') && OpenCloseMiniMap == 1 && MiniMapDelay > 0.7)
	{
		MiniMapRendered = false;
		OpenCloseMiniMap = 0;
	}
}

void SceneText::MainUpdates(int checkPosition_X, int checkPosition_Y)
{
	//Moving from screen stage to scrollnig stage conditions
	if(CurrentMap->theScreenMap[checkPosition_Y][checkPosition_X + 1] == CMap::DOOR)
	{
		if(hero.GetKeyAcquired() == true)
		{
			if(hero.GetdoorOpened() == false)
			{
				if(Application::IsKeyPressed(VK_SPACE))
				{

					hero.SetdoorOpened(true);
					if(stage == 2)
					{
						cout << '1' << endl;
					}
					for(std::vector<CGoodies *>::iterator it = GoodiesList.begin(); it != GoodiesList.end(); ++it)
					{
						CGoodies *go = (CGoodies *)*it;
						if(go->active)	
						{	
							if(go->GoodiesType == CGoodies::Goodies_Type::DOOR)
							{
								go->active = false;
							}
						}
					}
				}
			}
		}
	}

	if(CurrentMap->theScreenMap[checkPosition_Y][checkPosition_X] == CMap::DOOR)
	{
		if(hero.GetdoorOpened() == true)
		{
			hero.moveToDown = hero.moveToLeft = hero.moveToRight = hero.moveToRight = false;
			if(!InShop)
			{
				if(stage == 1)
				{
					hero.SetdoorOpened(true);
					stage = 2;
					hero.settheHeroPositionx(32);
					hero.heroCurrTile.x = 1;
					enemyList.erase(enemyList.begin(), enemyList.end());
					GoodiesList.erase(GoodiesList.begin(), GoodiesList.end());
					GetKey = false;
					derenderDoor = false;
					for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
					{
						GameObject *go = (GameObject *)*it;
						if(go->active)
							go->active = false;
					}

					hero.ammo = 2;

					//Set new map
					map.InitScrollingMap(enemyList, GoodiesList, BarrelList, m_goList);
					CurrentMap = map.m_cScrollingMap;

					

					InitMiniMap_Level2();
				}

				else if(stage == 2)
				{
					hero.SetdoorOpened(true);
					InShop = true;
					hero.settheHeroPositionx(512);
					hero.heroCurrTile.x = hero.gettheHeroPositionx() / 32;
					hero.settheHeroPositiony(256);
					hero.heroCurrTile.y = 25 - (int) ceil ((float)(hero.gettheHeroPositiony() + 32) / 32);

					enemyList.erase(enemyList.begin(), enemyList.end());
					GoodiesList.erase(GoodiesList.begin(), GoodiesList.end());
					
					for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
					{
						GameObject *go = (GameObject *)*it;
						if(go->active)
							go->active = false;
					}
					hero.ammo = 2;

					//Set new map
					map.InitShopMap(enemyList, GoodiesList, BarrelList, m_goList);
					CurrentMap = map.m_cShopMap;

					


					//InitMiniMap_Level3();
				}

				else if (stage == 3)
				{
					
					
					hero.SetdoorOpened(true);
					stage = 4;
					hero.settheHeroPositionx(64);
					hero.settheHeroPositiony(128);
					hero.heroCurrTile.x = 2;
					hero.heroCurrTile.y = 20;
					enemyList.erase(enemyList.begin(), enemyList.end());
					GoodiesList.erase(GoodiesList.begin(), GoodiesList.end());

					for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
					{
						GameObject *go = (GameObject *)*it;
						if (go->active)
							go->active = false;
					}

					hero.ammo = 2;

					//Set new map
					map.InitScrollingMap2(enemyList, GoodiesList, BarrelList, m_goList);
					CurrentMap = map.m_cScrollingMap2;

					InitMiniMap_Level4();
				}

				else if (stage == 4)
				{
					hero.SetdoorOpened(true);
					InShop = true;
					hero.settheHeroPositionx(512);
					hero.heroCurrTile.x = hero.gettheHeroPositionx() / 32;
					hero.settheHeroPositiony(256);
					hero.heroCurrTile.y = 25 - (int) ceil ((float)(hero.gettheHeroPositiony() + 32) / 32);

					enemyList.erase(enemyList.begin(), enemyList.end());
					GoodiesList.erase(GoodiesList.begin(), GoodiesList.end());
					
					for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
					{
						GameObject *go = (GameObject *)*it;
						if(go->active)
							go->active = false;
					}
					hero.ammo = 2;

					//Set new map
					map.InitShopMap(enemyList, GoodiesList, BarrelList, m_goList);
					CurrentMap = map.m_cShopMap;
					InitMiniMap_Level5();
				}

				else if(stage == 5)
				{
					
					hero.SetdoorOpened(true);
					stage = 6;
					hero.settheHeroPositionx(32);
					hero.heroCurrTile.x = 1;
					enemyList.erase(enemyList.begin(), enemyList.end());
					GoodiesList.erase(GoodiesList.begin(), GoodiesList.end());

					for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
					{
						GameObject *go = (GameObject *)*it;
						if (go->active)
							go->active = false;
					}

					hero.ammo = 2;

					//Set new map
					map.InitScrollingMap3(enemyList, GoodiesList, BarrelList, m_goList);
					CurrentMap = map.m_cScrollingMap3;

					InitMiniMap_Level6();
				}

				else if(stage == 6)
				{
					
					hero.SetdoorOpened(true);
					InShop = true;
					hero.settheHeroPositionx(512);
					hero.heroCurrTile.x = hero.gettheHeroPositionx() / 32;
					hero.settheHeroPositiony(256);
					hero.heroCurrTile.y = 25 - (int) ceil ((float)(hero.gettheHeroPositiony() + 32) / 32);

					enemyList.erase(enemyList.begin(), enemyList.end());
					GoodiesList.erase(GoodiesList.begin(), GoodiesList.end());

					for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
					{
						GameObject *go = (GameObject *)*it;
						if(go->active)
							go->active = false;
					}

					hero.ammo = 2;

					//Set new map
					map.InitShopMap(enemyList, GoodiesList, BarrelList, m_goList);
					CurrentMap = map.m_cShopMap;
					InitMiniMap_Level7();
				}
			}
			else
			{
				hero.SetKeyAcquired(false);	
				hero.SetdoorOpened(false);
				InShop = false;
				stage++;
				enemyList.erase(enemyList.begin(), enemyList.end());
				GoodiesList.erase(GoodiesList.begin(), GoodiesList.end());

				for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
				{
					GameObject *go = (GameObject *)*it;
					if(go->active)
						go->active = false;
				}

				hero.ammo = 2;

				//Set new map
				if(stage == 3)
				{
					//hero position for map
					hero.settheHeroPositionx(896);
					hero.heroCurrTile.x = hero.gettheHeroPositionx() / 32;
					hero.settheHeroPositiony(640);
					hero.heroCurrTile.y = 25 - (int) ceil ((float)(hero.gettheHeroPositiony() + 32) / 32);

					//map for level 3
					map.InitScreenMap2(enemyList, GoodiesList, BarrelList, m_goList);
					CurrentMap = map.m_cScreenMap2;
					InitMiniMap_Level3();
				}	
				else if(stage == 5)
				{
					//hero position for map
					hero.settheHeroPositionx(896);
					hero.heroCurrTile.x = hero.gettheHeroPositionx() / 32;
					hero.settheHeroPositiony(640);
					hero.heroCurrTile.y = 25 - (int) ceil ((float)(hero.gettheHeroPositiony() + 32) / 32);

					//map for level 3
					map.InitScreenMap3(enemyList, GoodiesList, BarrelList, m_goList);
					CurrentMap = map.m_cScreenMap3;
					InitMiniMap_Level5();
				}
				else if(stage == 7)
				{
					//hero position for map
					hero.settheHeroPositionx(896);
					hero.heroCurrTile.x = hero.gettheHeroPositionx() / 32;
					hero.settheHeroPositiony(640);
					hero.heroCurrTile.y = 25 - (int) ceil ((float)(hero.gettheHeroPositiony() + 32) / 32);

					//map for level 3
					map.InitBossMap(enemyList, GoodiesList, BarrelList, HoleList, m_goList);
					CurrentMap = map.m_cBossMap;
					InitMiniMap_Level7();
				}

			}

				
		}
	}
}

// ================================== RENDERING APPLICATION FUNCTIONS ==================================

void SceneText::RenderText(Mesh* mesh, std::string text, Color color)
{
	if(!mesh || mesh->textureID <= 0)
		return;

	glDisable(GL_DEPTH_TEST);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	glEnable(GL_DEPTH_TEST);
}

void SceneText::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if(!mesh || mesh->textureID <= 0)
		return;

	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10);
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity();
	modelStack.PushMatrix();
	modelStack.LoadIdentity();
	modelStack.Translate(x, y, 0);
	modelStack.Scale(size, size, size);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 0.6f + 0.5f, 0.5f, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	modelStack.PopMatrix();
	viewStack.PopMatrix();
	projectionStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}

void SceneText::RenderMeshIn2D(Mesh *mesh, const bool enableLight, const float size, const float x, const float y, const bool rotate)
{
	Mtx44 ortho;
	ortho.SetToOrtho(-80, 80, -60, 60, -10, 10);
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity();
	modelStack.PushMatrix();
	modelStack.LoadIdentity();
	modelStack.Translate(x, y, 0);
	modelStack.Scale(size, size, size);

	if(rotate)
		modelStack.Rotate(rotateAngle, 0, 0, 1);

	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	if(mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}

	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}

	mesh->Render();

	if(mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	modelStack.PopMatrix();
	viewStack.PopMatrix();
	projectionStack.PopMatrix();
}

void SceneText::RenderMesh(Mesh *mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	if(enableLight && bLightEnabled)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView = viewStack.Top() * modelStack.Top();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}

	else
	{	
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}

	if(mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}

	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}

	mesh->Render();

	if(mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void SceneText::Render2DMesh(Mesh *mesh, bool enableLight, float size, float x, float y, bool rotate)
{
	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 1024, 0, 800, -10, 10);
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity();
	modelStack.PushMatrix();
	modelStack.LoadIdentity();
	modelStack.Translate(x, y, 0);
	modelStack.Scale(size, size, size);

	if(rotate)
	{
		//glDisable(GL_CULL_FACE);
		//modelStack.Rotate(180, 0, 1, 0);
	}

	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	if(mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}

	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}

	mesh->Render();

	if(mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	modelStack.PopMatrix();
	viewStack.PopMatrix();
	projectionStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}

void SceneText::RenderQuadOnScreen(Mesh* mesh, float sizeX, float sizeY, float x, float y, bool enableLight)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);

	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10);	//size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity();					//No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity();					//Reset modelStack
	modelStack.Translate(x, y, 0);
	modelStack.Scale(sizeX, sizeY, 0);


	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	if(enableLight)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView = viewStack.Top() * modelStack.Top();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}

	else
	{	
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}

	if(mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}

	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}

	mesh->Render();

	if(mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();

	glEnable(GL_DEPTH_TEST);
}

void SceneText::RenderSprites(Mesh* mesh, int id, const float size, const float x, const float y)
{
	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 1024, 0, 800, -10, 10);
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity();
	modelStack.PushMatrix();
	modelStack.LoadIdentity();
	modelStack.Translate(x, y, 0);
	modelStack.Scale(size, size, size);

	//if (!mesh || mesh->textureID <= 0)
	//	return;

	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	Mtx44 characterSpacing;
	characterSpacing.SetToTranslation(0.5f, 0.5f, 0); //1.0f is the spacing of each character, you may change this value
	Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	mesh->Render((unsigned)id * 6, 6);

	glBindTexture(GL_TEXTURE_2D, 0);

	modelStack.PopMatrix();
	viewStack.PopMatrix();
	projectionStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}

void SceneText::RenderTilesMap(Mesh* mesh, int ID, const float size, const float x, const float y)
{
	Mtx44 ortho;
	ortho.SetToOrtho(0, 1024, 0, 800, -10, 10);
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity();
	modelStack.PushMatrix();
	modelStack.LoadIdentity();
	modelStack.Translate(x, y, 0);
	modelStack.Scale(size, size, size);

	//if (!mesh || mesh->textureID <= 0)
	//	return;

	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	Mtx44 characterSpacing;
	characterSpacing.SetToTranslation(0.5f, 0.5f, 0); //1.0f is the spacing of each character, you may change this value
	Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	mesh->Render((unsigned)ID * 6, 6);

	glBindTexture(GL_TEXTURE_2D, 0);

	modelStack.PopMatrix();
	viewStack.PopMatrix();
	projectionStack.PopMatrix();
}

// ================================== RENDERING GAME PROJECT FUNCTIONS ==================================

void SceneText::RenderInit()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Mtx44 perspective;
	perspective.SetToPerspective(45.0f, 4.0f / 3.0f, 0.1f, 10000.0f);
	projectionStack.LoadMatrix(perspective);

	//Camera matrix
	viewStack.LoadIdentity();
	viewStack.LookAt(
		camera.position.x, camera.position.y, camera.position.z,
		camera.target.x, camera.target.y, camera.target.z,
		camera.up.x, camera.up.y, camera.up.z
		);

	//Model matrix : an identity matrix (model will be at the origin)
	modelStack.LoadIdentity();
}

void SceneText::RenderText()
{
	//On screen text
	std::ostringstream ss;
	ss.precision(4);
	ss << fps;
	RenderTextOnScreen(meshList[GEO_TEXT], ss.str(), Color(1, 0, 0), 2.3, 71, 0.5);

	if(Application::IsKeyPressed(VK_INSERT))
	{
		std::ostringstream ss1;
		ss1.precision(5);
		ss1 << "Position: " << hero.gettheHeroPositionx() << "," << hero.gettheHeroPositiony();
		RenderTextOnScreen(meshList[GEO_TEXT], ss1.str(), Color(1, 1, 0), 2.3, 2, 57);

		std::ostringstream ss2;
		ss2.precision(5);
		ss2 << "MapOffset_x: " << CurrentMap->mapOffset_x;
		RenderTextOnScreen(meshList[GEO_TEXT], ss2.str(), Color(1, 1, 0), 2.3, 2, 53);

		std::ostringstream ss3;
		ss3.precision(5);
		ss3 << "TileOffset_x:" << CurrentMap->tileOffset_x;
		RenderTextOnScreen(meshList[GEO_TEXT], ss3.str(), Color(1, 1, 0), 2.3, 2, 49);
	}
}

void SceneText::RenderHero()
{
	//Slingshot rotation angle
	float angle = Math::RadianToDegree(atan2(hero.rotation.y, hero.rotation.x));
	if(angle > 180)
	{
		angle -= 180;
	}
	
	else
	{
		angle += 180;
	}

	//For dislaying Hero's Health
	if(hero.transform == false)
	{
		for(int a = hero.health; a > 0; a--)
		{
			if(hero.health%2 == 1)
			{
				if(hero.health == 1)
					Render2DMesh(meshList[GEO_HUD_HEART], false, 20, hero.gettheHeroPositionx() + 6, hero.gettheHeroPositiony() + 33);
				else
					Render2DMesh(meshList[GEO_HUD_HEART], false, 20, hero.gettheHeroPositionx() - 15 + ((a - hero.health/2) * 21), hero.gettheHeroPositiony() + 33);
			}
			else
			{
				Render2DMesh(meshList[GEO_HUD_HEART], false, 20, hero.gettheHeroPositionx() - 15 + ((a - hero.health/2) * 21) + 11, hero.gettheHeroPositiony() + 33);
			}
		}
	}

	if(Red_Selected == true || Temp_Red_Selected == true || hero.invisibleTimer >= 10 && hero.invisibleTimer <= 11 || hero.invisibleTimer >= 13 && hero.invisibleTimer <= 14)
	{
		if(hero.transform == true)
		{
			RenderSprites(meshList[GEO_TRANSFORMATIONSHEET], hero.heroTransformID, 96, hero.gettheHeroPositionx() - 32, hero.gettheHeroPositiony() - 16);
		}

		else
		{
			//Attacking
			if(hero.GetAttackStatus() == true)
			{
				if(hero.heroTileID >= 0 && hero.heroTileID <= 2)
				{
					RenderSprites(meshList[GEO_TILEHEROSHEET], 3, 32, hero.gettheHeroPositionx(), hero.gettheHeroPositiony());
				}

				else if(hero.heroTileID >= 4 && hero.heroTileID <= 6)
				{
					RenderSprites(meshList[GEO_TILEHEROSHEET], 7, 32, hero.gettheHeroPositionx(), hero.gettheHeroPositiony());
				}

				else if(hero.heroTileID >= 8 && hero.heroTileID <= 10)
				{
					RenderSprites(meshList[GEO_TILEHEROSHEET], 11, 32, hero.gettheHeroPositionx(), hero.gettheHeroPositiony());
				}

				else
				{
					RenderSprites(meshList[GEO_TILEHEROSHEET], 15, 32, hero.gettheHeroPositionx(), hero.gettheHeroPositiony());
				}
			}

			//Walking
			else
			{
				RenderSprites(meshList[GEO_TILEHEROSHEET], hero.heroTileID, 32, hero.gettheHeroPositionx(), hero.gettheHeroPositiony());
			}
		}
	}

	else if(Blue_Selected == true)
	{
		if(hero.transform == true)
		{
			RenderSprites(meshList[GEO_TRANSFORMATIONSHEET], hero.heroTransformID, 96, hero.gettheHeroPositionx() - 32, hero.gettheHeroPositiony() - 16);
		}

		else
		{
			RenderSprites(meshList[GEO_TILEHEROSHEET2], hero.heroTileID, 32, hero.gettheHeroPositionx(), hero.gettheHeroPositiony());
		}
	}
}

void SceneText::RenderEnemies()
{
	//For displaying Enemy's Health
	for(int i = 0; i < enemyList.size(); ++i)
	{
		if(enemyList[i]->health >= 1)
		{
			Render2DMesh(meshList[GEO_HUD_HEART], false, 20, (enemyList[i]->GetPos_x() - 5) - CurrentMap->mapOffset_x, enemyList[i]->GetPos_y() - 20);

			if(enemyList[i]->health >= 2)
			{
				Render2DMesh(meshList[GEO_HUD_HEART], false, 20, (enemyList[i]->GetPos_x() + 15) - CurrentMap->mapOffset_x, enemyList[i]->GetPos_y() - 20);

				if(enemyList[i]->health == 3)
				{
					Render2DMesh(meshList[GEO_HUD_HEART], false, 20, (enemyList[i]->GetPos_x() + 35) - CurrentMap->mapOffset_x, enemyList[i]->GetPos_y() - 20);
				}
			}
		}
	}

	for(vector<CEnemy *>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		CEnemy *go = (CEnemy *)*it;
		int theEnemy_x = go->GetPos_x() - CurrentMap->mapOffset_x;
		int theEnemy_y = go->GetPos_y();
		Vector3 theEnemyPos (theEnemy_x,theEnemy_y,0);

		if(go->active)	
		{
			//Stunned
			if(go->stunned == true)
			{
				RenderSprites(meshList[GEO_STUNSHEET], go->stunTileID, 48, theEnemy_x - 8, theEnemy_y + 18);
			}

			//Detection radius
			for(vector<Vector3>::iterator it2 = go->detectionGrid.begin(); it2 != go->detectionGrid.end(); ++it2)
			{
				if(go->theStrategy->CurrentState == CStrategy::PATROL && go->stunned == false)
				{
					Vector3 go2 = (Vector3)*it2;
					Render2DMesh(meshList[GEO_TILEDETECTIONRADIUS], false, 1.0f, go2.x - CurrentMap->mapOffset_x, go2.y);
				}

				else if(go->theStrategy->CurrentState == CStrategy::ATTACK)
				{
					Render2DMesh(meshList[GEO_EXCLAMATIONMARK], false, 23, (go->GetPos_x() + 5) - CurrentMap->mapOffset_x, go->GetPos_y() + 35);
				}
			}

			//Attacking
			if(go->attackAnimation == true)
			{
				if(go->direction == Vector3(0, -1, 0))
				{
					if(go->ID >= 50 && go->ID < 80)
					{
						RenderSprites(meshList[GEO_TILEENEMYSHEET], 3, 32, theEnemy_x, theEnemy_y);
					}

					else if(go->ID >= 80)
					{
						RenderSprites(meshList[GEO_TILEENEMYSHEET2], 3, 32, theEnemy_x, theEnemy_y);
					}
				}

				else if(go->direction == Vector3(-1, 0, 0))
				{
					if(go->ID >= 50 && go->ID < 80)
					{
						RenderSprites(meshList[GEO_TILEENEMYSHEET], 8, 32, theEnemy_x, theEnemy_y);
					}

					else if(go->ID >= 80)
					{
						RenderSprites(meshList[GEO_TILEENEMYSHEET2], 8, 32, theEnemy_x, theEnemy_y);
					}
				}

				else if(go->direction == Vector3(1, 0, 0))
				{
					if(go->ID >= 50 && go->ID < 80)
					{
						RenderSprites(meshList[GEO_TILEENEMYSHEET], 13, 32, theEnemy_x, theEnemy_y);
					}

					else if(go->ID >= 80)
					{
						RenderSprites(meshList[GEO_TILEENEMYSHEET2], 13, 32, theEnemy_x, theEnemy_y);
					}
				}

				else
				{
					if(go->ID >= 50 && go->ID < 80)
					{
						RenderSprites(meshList[GEO_TILEENEMYSHEET], 18, 32, theEnemy_x, theEnemy_y);
					}

					else if(go->ID >= 80)
					{
						RenderSprites(meshList[GEO_TILEENEMYSHEET2], 18, 32, theEnemy_x, theEnemy_y);
					}
				}
			}

			//Walking
			else
			{
				if(go->ID >= 50 && go->ID < 80)
				{
					RenderSprites(meshList[GEO_TILEENEMYSHEET], go->enemyTileID, 32, theEnemy_x, theEnemy_y);
				}

				else if(go->ID >= 80)
				{
					RenderSprites(meshList[GEO_TILEENEMYSHEET2], go->enemyTileID, 32, theEnemy_x, theEnemy_y);
				}
			}
		}

		//Idling
		else if (stage == 7 && go->health > 0)
		{
			if (go->ID >= 50 && go->ID < 80)
			{
				RenderSprites(meshList[GEO_TILEENEMYSHEET], 5, 32, theEnemy_x, theEnemy_y);
			}

			else if (go->ID >= 80)
			{
				RenderSprites(meshList[GEO_TILEENEMYSHEET2], 5, 32, theEnemy_x, theEnemy_y);
			}
		}

		//Dead
		else
		{
			if(go->ID >= 50 && go->ID < 80)
			{
				RenderSprites(meshList[GEO_TILEENEMYSHEET], 19, 32, theEnemy_x, theEnemy_y);
			}

			else if(go->ID >= 80)
			{
				RenderSprites(meshList[GEO_TILEENEMYSHEET2], 19, 32, theEnemy_x, theEnemy_y);
			}
		}
	}
}

void SceneText::RenderTileMap()
{
	int m = 0;	
	CurrentMap->mapFineOffset_x = CurrentMap->mapOffset_x % CurrentMap->GetTileSize();

	for(int i = 0; i < CurrentMap->GetNumOfTiles_Height(); i++)
	{
		for(int k = 0; k < CurrentMap->GetNumOfTiles_Width() + 1; k++)
		{
			m = CurrentMap->tileOffset_x + k;

			//If we have reached the right side of the map, then do not display the extra column of tiles
			if(m >= CurrentMap->getNumOfTiles_MapWidth())
			{
				break;
			}

			if(stage == 1 || stage == 3 || stage == 5)
			{
				if(CurrentMap->theScreenMap[i][m] >= 20 && CurrentMap->theScreenMap[i][m] <= 49)
				{
					RenderTilesMap(meshList[GEO_TILESHEET_DESERT], CurrentMap->theScreenMap[i][m], 32.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
				}

				else if(CurrentMap->theScreenMap[i][m] == CMap::DOOR)
				{
					if(hero.GetdoorOpened() == false)
					{
						Render2DMesh(meshList[GEO_TILEDOOR], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
					}
					
					else
					{
						Render2DMesh(meshList[GEO_TILEBACKGROUND], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
					}
				}

				else
				{
					Render2DMesh(meshList[GEO_TILEBACKGROUND], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
				}
			}

			else if(stage == 2 || stage == 4 || stage == 6)
			{
				if (CurrentMap->theScreenMap[i][m] >= 20 && CurrentMap->theScreenMap[i][m] <= 49)
				{
					RenderTilesMap(meshList[GEO_TILESHEET_DESERT], CurrentMap->theScreenMap[i][m], 32.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
				}

				else if(CurrentMap->theScreenMap[i][m] == CMap::DOOR)
				{
					if(hero.GetdoorOpened() == false)
					{
						Render2DMesh(meshList[GEO_TILEDOOR], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());				
					}
					else
					{
						Render2DMesh(meshList[GEO_TILEBACKGROUND], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
					}
				}

				else
				{
					Render2DMesh(meshList[GEO_TILEBACKGROUND], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
				}
			}

			else if(stage == 7)
			{
				if (CurrentMap->theScreenMap[i][m] >= 20 && CurrentMap->theScreenMap[i][m] <= 49)
				{
					RenderTilesMap(meshList[GEO_TILESHEET_DESERT], CurrentMap->theScreenMap[i][m], 32.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
				}

				else
				{
					Render2DMesh(meshList[GEO_TILEBACKGROUND], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
				}

				if (CurrentMap->theScreenMap[i][m] == 17)
				{
					a = i;
					b = k;
				}
			}
			else
			{
				if (CurrentMap->theScreenMap[i][m] >= 20 && CurrentMap->theScreenMap[i][m] <= 49)
				{
					RenderTilesMap(meshList[GEO_TILESHEET_DESERT], CurrentMap->theScreenMap[i][m], 32.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
				}

				else if(CurrentMap->theScreenMap[i][m] == CMap::DOOR)
				{
					if(hero.GetdoorOpened() == false)
					{
						Render2DMesh(meshList[GEO_TILEDOOR], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());				
					}
					else
					{
						Render2DMesh(meshList[GEO_TILEBACKGROUND], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
					}
				}

				else
				{
					Render2DMesh(meshList[GEO_TILEBACKGROUND], false, 1.0f, k * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - i * CurrentMap->GetTileSize());
				}
			}
		}
	}
}

void SceneText::RenderGoodies()
{
	//Render the goodies
	for (vector<CGoodies *>::iterator it = GoodiesList.begin(); it != GoodiesList.end(); ++it)
	{
		CGoodies *go = (CGoodies *)*it;
		int theGoodies_x = go->GetPos_x() - map.mapOffset_x;
		int theGoodies_y = go->GetPos_y();

		if(go->GoodiesType == CGoodies::Goodies_Type::JEWEL)
		{
			if(go->active == true)
			{
				Render2DMesh(meshList[GEO_DIAMOND], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
			}
		}
		
		else if(go->GoodiesType == CGoodies::Goodies_Type::KEY)
		{
			if(go->active == true)
			{
				Render2DMesh(meshList[GEO_KEY], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
			}
		}
		
		else if(go->GoodiesType == CGoodies::Goodies_Type::CHEST)
		{
			if(go->active == true)
			{
				Render2DMesh(meshList[GEO_CHEST], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
			}
			
			else
			{
				Render2DMesh(meshList[GEO_CHEST_OPENED], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
			}
		}
		
		else if(go->GoodiesType == CGoodies::Goodies_Type::BARREL)
		{
			if(go->active)
			{
				Render2DMesh(meshList[GEO_BARREL], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
			}
			
			else
			{
				Render2DMesh(meshList[GEO_BARREL_BROKEN], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
			}

		}

		else if(go->GoodiesType == CGoodies::Goodies_Type::HAY)
		{
			Render2DMesh(meshList[GEO_HAY], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
		}

		else if(go->GoodiesType == CGoodies::Goodies_Type::HOLE)
		{
			Render2DMesh(meshList[GEO_HOLE], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
		}
		
		else if(go->GoodiesType == CGoodies::Goodies_Type::HPPOT)
		{
			if(go->active)
				Render2DMesh(meshList[GEO_HPPOT], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
		}
		
		else if(go->GoodiesType == CGoodies::Goodies_Type::MAXHP)
		{
			if(go->active)
				Render2DMesh(meshList[GEO_MAXHP], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
		}
		
		else if(go->GoodiesType == CGoodies::Goodies_Type::SCROLL)
		{
			if(go->active)
				Render2DMesh(meshList[GEO_SCROLL], false, 1.0f, theGoodies_x - CurrentMap->mapOffset_x, theGoodies_y);
		}
	}
}

void SceneText::RenderBoss()
{
	RenderSprites(meshList[GEO_TILEBOSS_FRAME0], BossTileID, 64, b * CurrentMap->GetTileSize() - CurrentMap->mapFineOffset_x, 768 - a * CurrentMap->GetTileSize());
}

void SceneText::RenderHUD()
{
	//For indicating number of diamonds collected
	RenderQuadOnScreen(meshList[GEO_HUD_DIAMOND], 3.4, 3, 1, 56.5, false);
	std::ostringstream ss1;
	ss1 << "x " << diamondCount;
	RenderTextOnScreen(meshList[GEO_TEXT], ss1.str(), Color(0, 0, 1), 2.3, 5, 57);

	//For indicating number of keys collected
	RenderQuadOnScreen(meshList[GEO_HUD_KEY], 3.4, 3, 12, 56.5, false);
	std::ostringstream ss2;
	ss2 << "x " << keyCount;
	RenderTextOnScreen(meshList[GEO_TEXT], ss2.str(), Color(0.5, 0.5, 0.5), 2.3, 16, 57);

	//For Point System
	std::ostringstream ss3;
	ss3.precision(5);
	ss3 << "Points: " << PointSystem;
	RenderTextOnScreen(meshList[GEO_TEXT], ss3.str(), Color(1, 0, 0), 2.3, 65, 57);

	//For indicating number of shurikens left
	RenderQuadOnScreen(meshList[GEO_HUD_SHURIKEN], 3.9, 3, 22, 56.6, false);
	std::ostringstream ss4;
	ss4 << "x " << hero.ammo;
	RenderTextOnScreen(meshList[GEO_TEXT], ss4.str(), Color(0, 0, 0), 2.3, 26.5, 57);

	//Detection status
	if(hero.hiding == false)
	{
		RenderQuadOnScreen(meshList[GEO_DETECTIONEYE], 4.7, 4.9, 35, 55.5, false);
	}

	else
	{
		RenderQuadOnScreen(meshList[GEO_DETECTIONEYE2], 4.7, 4.9, 35, 55.5, false);
	}

	//Render grey screen
	if(RenderDim == true)
	{
		Render2DMesh(meshList[GEO_DIM], false, 500.0f, 0, 0);
	}
}

void SceneText::RenderMinimap()
{
	if(MiniMapRendered == true)
	{
		if(CustomMenuRendered == false)
		{
			Render2DMesh(meshList[GEO_DIM], false, 500.0f, 0, 0);
			Render2DMesh(meshList[GEO_DIM], false, 500.0f, 0, 0);

			// For Representing Player on Minimap
			RenderQuadOnScreen(CurrentMiniMap->GetBackground(), 50, 33, 40, 30, false);
			RenderQuadOnScreen(CurrentMiniMap->GetAvatar(), 1, 1, (hero.gettheHeroPositionx() / 20) + 15.3, (hero.gettheHeroPositiony() / 24) + 14.5, false);

			if (stage == 7)
			{
				// For Representing Boss On Minimap
				RenderQuadOnScreen(CurrentMiniMap->GetBossAvatar(), 1, 1, (BossPointer->Get_BossX() / 20) + 18.5, (BossPointer->Get_BossY() / 24) + 31.5, false);
			}

			for(int i = 0; i < enemyList.size(); ++i)
			{
				// For Representing Enemy on Minimap
				RenderQuadOnScreen(CurrentMiniMap->GetEnemyAvatar(), 1, 1, (enemyList[i]->GetPos_x() / 20) + 15.3, (enemyList[i]->GetPos_y() / 24) + 14.5, false);
			}

			for(vector<CGoodies *>::iterator it = GoodiesList.begin(); it != GoodiesList.end(); ++it)
			{
				CGoodies *go = (CGoodies *)*it;
				int theGoodies_x = go->GetPos_x() - map.mapOffset_x;
				int theGoodies_y = go->GetPos_y();

				if(go->GoodiesType == CGoodies::Goodies_Type::JEWEL)
				{
					if(go->active == true)
					{
						RenderQuadOnScreen(CurrentMiniMap->GetDiamondAvatar(), 1, 1, ((theGoodies_x - CurrentMap->mapOffset_x) / 20) + 15.3, (theGoodies_y / 24) + 14.5, false);
					}
				}

				else if(go->GoodiesType == CGoodies::Goodies_Type::KEY)
				{
					if(go->active == true)
					{
						RenderQuadOnScreen(CurrentMiniMap->GetKeyAvatar(), 2, 2, ((theGoodies_x - CurrentMap->mapOffset_x) / 20) + 16, (theGoodies_y / 24) + 14, false);
					}
				}

				else if(go->GoodiesType == CGoodies::Goodies_Type::BARREL)
				{
					if(go->active == true)
					{
						RenderQuadOnScreen(CurrentMiniMap->GetBarrelAvater(), 1, 1, ((theGoodies_x - CurrentMap->mapOffset_x) / 20) + 15.3, (theGoodies_y / 24) + 14.5, false);
					}
				}
			}
		}
	}
}

// ================================== RENDERING MENUS ==================================

void SceneText::RenderMenu(int &InteractHighLight, int max, int min)
{
	if(Application::IsKeyPressed(VK_DOWN) && delay == 0 && InteractHighLight < max)
	{
		InteractHighLight += 1;
		delay = 15;
	}

	if(Application::IsKeyPressed(VK_UP) && delay == 0 && InteractHighLight > min)
	{
		InteractHighLight -= 1;
		delay = 15;
	}

	if(delay > 0)
	{
		--delay;
	}

	if(InteractHighLight == 0 && Application::IsKeyPressed(VK_RETURN))
	{
		menu = false;
	}

	if(InteractHighLight == 1 && Application::IsKeyPressed(VK_RETURN))
	{
		menu = false;
	}

	//Menu
	int a = 0;
	if(menu == true)
	{
		for(int text = 0; text < 2; text++)
		{
			float TextSize = 5;
			int y = 60 / TextSize / 2 - 5 - (text * TextSize);

			if(InteractHighLight == text)
			{
				a = 1;
			}

			RenderTextOnScreen(meshList[GEO_TEXT], Text[text], Color(1, a, a), TextSize, 40, y + 30);

			if(InteractHighLight == text)
			{
				a = 0;
			}
		}
	}
}

void SceneText::RenderGameOver()
{
	RenderQuadOnScreen(meshList[GEO_LOSE], 82, 62, 40, 30, false);
}

void SceneText::RenderCustomMenu()
{
	if(CustomMenuRendered == true)
	{
		RenderQuadOnScreen(meshList[GEO_CUSTOM_MENU], 80, 60, 40, 30, false);

		RenderQuadOnScreen(meshList[GEO_HERO_RED], Custom_HeroSize_Red, Custom_HeroSize_Red, 20, 30, false);
		RenderQuadOnScreen(meshList[GEO_HERO_BLUE], Custom_HeroSize_Blue, Custom_HeroSize_Blue, 60, 30, false);

		if (Custom_HeroSize_Blue == 30)
		{
			std::ostringstream ss1;
			ss1.precision(5);
			ss1 << "STEALTH";
			RenderTextOnScreen(meshList[GEO_TEXT], ss1.str(), Color(1, 1, 0), 2.3, 55, 11);
		}

		else if (Custom_HeroSize_Red == 30)
		{
			std::ostringstream ss2;
			ss2.precision(5);
			ss2 << "UNSTEALTH";
			RenderTextOnScreen(meshList[GEO_TEXT], ss2.str(), Color(1, 1, 0), 2.3, 13, 11);
		}
	}
}

// ================================== RENDER & EXIT ==================================

void SceneText::Render()
{
	/*if(menu == true)
	{
		RenderQuadOnScreen(meshList[GEO_MENU], 82, 62, 40, 30, false);
		RenderMenu(InteractHighLight, 1, 0);
	}*/

	RenderInit();
	RenderTileMap();
	RenderBoss();
	RenderEnemies();
	RenderText();

	if(m_ghost->active)
	{
		RenderGO(m_ghost);
	}

	for(std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
	{
		GameObject *go = (GameObject *)*it;
		if(go->active)
		{
			RenderGO(go);
		}
	}

	RenderHero();
	RenderGoodies();
	RenderHUD();
	RenderCustomMenu();
	RenderMinimap();

	if(lose == true)
	{
		RenderGameOver();
	}
}

void SceneText::Exit()
{
	// Cleanup VBO
	for(int i = 0; i < NUM_GEOMETRY; ++i)
	{
		if(meshList[i])
			delete meshList[i];
	}

	glDeleteProgram(m_programID);
	glDeleteVertexArrays(1, &m_vertexArrayID);
}