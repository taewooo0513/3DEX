#pragma once
#include "Object.h"
class NormalEnemy :public Object
{
private :

public:
	NormalEnemy();
	virtual ~NormalEnemy();
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(Object* obj) override;
};

