#pragma once
#include "Object.h"
class Player : public Object
{
private :
	PCURSORINFO* info;
	HWND hand;
	Vec3 CamPos,CamR , CamAt;
	float x=0, y=0;
	float radius=0;
	Mesh* mes;
	MOUSEINPUT* ms;
	POINT ptf;
	DIMOUSESTATE2* m;
	Vec2 Dir;
	DIDATAFORMAT* mat;
	Vec3 pos;
	LPCDIDATAFORMAT maat;
	HINSTANCE hInst;
	MultiMesh* mesh;
	IDirectInput8 * pt;
	IDirectInputDevice8* InputDevice;

public:
	Player();
	virtual ~Player();
public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(Object* obj) override;
};

