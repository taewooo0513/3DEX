#include "DXUT.h"
#include "Main.h"
#include "ingameScene.h"
Main::Main()
{

}

Main::~Main()
{

}

void Main::Init()
{
	//Run_000001
	//씬
	SCENE->AddScene("ingame",new ingameScene);
	//3D오브젝트
	LOADER->AddMesh("BackGround","./Resource/BG1.obj");
	LOADER->AddMesh("BacksGround", "./Resource/Run/Run_000001.obj");
	LOADER->AddMesh("Block","./Resource/DirtBlock.obj");
	//3D 애니메이션
	LOADER->AddMeshs("Player","./Resource/Run/Run_0000",34);

	//2D 이미지
	LOADER->AddImage("fdas","./media/cup.jpg");
	
	SCENE->ChangeScene("ingame");
	ts.SetPos(Vec3(0,-10,0));
	ts.SetRot(Vec3(0, 0, 0));
	ts.SetScale(Vec3(10,10,10));
	
}

void Main::Update()
{
	OBJMANAGER->Update();
	SCENE->Update();
}

void Main::Render()
{
	

	SCENE->Render();
	OBJMANAGER->Render();
	
	RENDER2D->Begin();
	SCENE->UIRender();
	OBJMANAGER->UIRender();
	RENDER2D->End();

	
}

void Main::Release()
{
	SceneManager::ReleaseIntacne();
	cMeshLoader::ReleaseIntacne();
	CamManager::ReleaseIntacne();
	LoadManager::ReleaseIntacne();
	Render2DManager::ReleaseIntacne();
	Render3DManager::ReleaseIntacne();
	ObjectManager::ReleaseIntacne();
}

void Main::ResetDevice()
{
	RENDER2D->ResetDevice();
}

void Main::LostDevice()
{
	RENDER2D->LostDevice();
}
