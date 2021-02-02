#include "DXUT.h"
#include "NormalEnemy.h"

NormalEnemy::NormalEnemy(Vec3 pos)
	: pos(pos)
{
	ts.timer = new CDXUTTimer;
	ts.timer->Start();
	CollKind = "박스";
	ObjTag = "NormalEnemy";
	
	mesh = LOADER->FindMesh("Enemy");
	ts.SetRot(Vec3(0,0,0));
	ts.SetScale(Vec3(0.4,0.4,0.4));
	ts.GetMesh = mesh;
	GravityOn = true;
}

NormalEnemy::~NormalEnemy()
{
}

void NormalEnemy::Update()
{
	ts.SetPos(pos);

}

void NormalEnemy::Render()
{
	ts.SetWorldMatrix();
	RENDER3D->Render(mesh,ts);
}

void NormalEnemy::UIRender()
{
}

void NormalEnemy::Collision(Object* obj)
{
	if (obj->ObjTag == "Player")
	{
		cout << "황진영섹스";
	}
}
