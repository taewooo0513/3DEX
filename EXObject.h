#pragma once
class EXObject : public Object
{
public:
	MultiMesh* mesh;
	EXObject();
	virtual ~EXObject();
public:


	// Object��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;

	virtual void UIRender() override;

	virtual void Collision(Object* obj) override;

};

