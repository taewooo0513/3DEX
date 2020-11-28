#pragma once
#include "singleton.h"
class Render3DManager : public singleton<Render3DManager>
{
private:
public:
	Render3DManager();
	~Render3DManager();
public:
	void Render(Mesh * mesh,Vec3 pos, Vec3 rot = Vec3(0, 0, 0),Vec3 size = Vec3(1,1,1) ,D3DXCOLOR color = D3DCOLOR_XRGB(255,255,255));
};

#define RENDER3D Render3DManager::GetInstance()