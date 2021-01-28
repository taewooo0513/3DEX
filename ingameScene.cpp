#include "DXUT.h"
#include "ingameScene.h"
#include "Player.h"
#include "DirtBlock.h"
ingameScene::ingameScene()
{
}

ingameScene::~ingameScene()
{
}

void ingameScene::init()
{
	mesh = LOADER->FindMesh("BackGround");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			OBJMANAGER->AddObject(new DirtBlock(Vec3(i * 10, -10,j* 10)), 1);
			OBJMANAGER->AddObject(new DirtBlock(Vec3(-i * 10, -10, -j*10)), 1);
		}
	}

	OBJMANAGER->AddObject(new Player,1);
}

void ingameScene::Update()
{
}

void ingameScene::Render()
{
	ts.SetPos(Vec3(0, 0, 0));
	ts.SetScale(Vec3(10000, 10000, 10000));
	ts.SetRot(Vec3(0, 0, -90));
	ts.SetWorldMatrix();
	RENDER3D->Render(mesh,ts);
}

void ingameScene::UIRender()
{
}

void ingameScene::Release()
{
}
