#include "DXUT.h"
#include "Player.h"

Player::Player()
{
	ts.timer = new CDXUTTimer;
	ts.timer->Start();
	CollKind = "¹Ú½º";
	mes = LOADER->FindMesh("Block");
	mesh = LOADER->FindMeshs("Player");
	ObjTag = "Player";
	ts.SetPos(Vec3(0, 10, 0));
	pos = Vec3(0, 0, 0);
	CamPos = Vec3(0, 10, -10);
	radius = 0;
	CamR.y = 0;
	CamAt.y = -10;
	GravityOn = false;
	ShowCursor(false);
	GravityOn = true;
	for (auto iter : mesh->v_mesh)
	{
		ts.GetMesh = iter;
	}
}

	
Player::~Player()
{
}

void Player::Update()
{
	for (auto iter : mesh->v_mesh)
	{
		ts.GetMesh=iter;
	}
	GetCursorPos(&ptf);
	if (DXUTIsKeyDown(VK_SPACE))
	{
		ts.GravityPower += 1;
	}
	if (ptf.x - WINSIZEX / 2 < 0)
	{
		radius -= 0.03;

	}
	if (ptf.x - WINSIZEX / 2 > 0)
	{
		radius += 0.03;

	}

	for (auto iter : mesh->v_mesh)
	{
		ts.Radius = abs(iter->maxVec.x - iter->minVec.x);
	}
	if (DXUTIsKeyDown(0x57))
	{
		Dir = Vec2( cosf(-radius),sinf(-radius));
		pos.x += Dir.x * 10 * DXUTGetElapsedTime();
		pos.z += Dir.y * 10 * DXUTGetElapsedTime();
	}
	if (DXUTIsKeyDown(0x41))
	{
		Dir = Vec2(cosf(-radius+1.57), sinf(-radius +1.57));
		pos.x += Dir.x * 5 * DXUTGetElapsedTime();
		pos.z += Dir.y * 5 * DXUTGetElapsedTime();
	}
	if (DXUTIsKeyDown(0x53))
	{
		Dir = Vec2(cosf(-radius-3.14), sinf(-radius-3.14));
		pos.x += Dir.x * 5 * DXUTGetElapsedTime();
		pos.z += Dir.y * 5 * DXUTGetElapsedTime();
	}
	if (DXUTIsKeyDown(0x44))
	{
		Dir = Vec2(cosf(-radius - 1.57), sinf(-radius-1.57));
		pos.x += Dir.x * 5 * DXUTGetElapsedTime();
		pos.z += Dir.y * 5 * DXUTGetElapsedTime();
	}

	CamR.x = pos.x - 10 * cos(radius);
	CamR.z = pos.z + 10 * sin(radius);
	CamPos =  CamR * 1;
	CamAt.x = pos.x + 10 * cos(radius);
	CamAt.z = pos.z - 10 * sin(radius);
	CamPos.y = pos.y + 6;

	SetCursorPos(WINSIZEX / 2, WINSIZEY / 2);


}

void Player::Render()
{
	CAM->SetCamPos(Vec3(CamPos));
	CAM->SetCamLook(Vec3(CamAt.x, -1, CamAt.z));
	//ts.Pos = Vec3(0, 0, 0);
	ts.SetPos(pos);
	ts.SetScale(Vec3(15, 15, 15));

	ts.SetRot(Vec3(D3DXToDegree(radius + 1.55), 0, 0));
	ts.SetScale(Vec3(300, 300, 300));
	ts.SetWorldMatrix();
	mesh->Render(0.03, ts);
	ts.SetScale(Vec3(15, 15, 15));


}

void Player::UIRender()
{
}

void Player::Collision(Object* obj)
{
	if (obj->ObjTag == "Block")
	{
	}
}
