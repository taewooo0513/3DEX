#pragma once
#include "Object.h"
class NormalEnemy :public Object
{
private :

public:
	NormalEnemy();
	virtual ~NormalEnemy();
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(Object* obj) override;
};

