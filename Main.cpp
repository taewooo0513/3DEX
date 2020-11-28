#include "DXUT.h"
#include "Main.h"

Main::Main()
{
}

Main::~Main()
{
}

void Main::Init()
{
	mesh = LOADER->AddMesh("Gun",L"media\\cup.obj");
}

void Main::Update()
{
}

void Main::Render()
{
	RENDER3D->Render(mesh,Vec3(0,0,0));
}

void Main::Release()
{
}

void Main::ResetDevice()
{
}

void Main::LostDevice()
{
}
