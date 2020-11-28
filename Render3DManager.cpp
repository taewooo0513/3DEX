#include "DXUT.h"
#include "Render3DManager.h"

Render3DManager::Render3DManager()
{
	
}

Render3DManager::~Render3DManager()
{
	
}

void Render3DManager::Render(Mesh* mesh, Vec3 pos, Vec3 rot, Vec3 size, D3DXCOLOR color)
{
	D3DXMATRIX matP, matS, matR, matW,RotX,RotY,RotZ;
	D3DXMatrixTranslation(&matP, pos.x,pos.y,pos.z);
	D3DXMatrixScaling(&matS,size.x,size.y,size.z);
	D3DXMatrixRotationX(&RotX,rot.x);
	D3DXMatrixRotationY(&RotY,rot.y);
	D3DXMatrixRotationZ(&RotY, rot.z);
	matR = RotX * RotY * RotZ;
	matW = matR * matP * matS;
	Device->SetTransform(D3DTS_WORLD,&matW);
	int i = 0;
	for (auto iter : mesh->v_Matrial)
	{
		iter->material.Emissive = color;
		Device->SetTexture(0, iter->pTexture);
		Device->SetMaterial(&iter->material);
		mesh->pMesh->DrawSubset(i);
		i++;
	}
	D3DXMATRIX mat;
	D3DXMatrixIdentity(&mat);
	Device->SetTransform(D3DTS_WORLD,&mat);
}
