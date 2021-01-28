#pragma once
class cBoundSphere
{
public:
	D3DXVECTOR3 localCenter;
	float radius;
	D3DXVECTOR3 halfSize;

public:
	cBoundSphere();
	~cBoundSphere();

	//���� ������ ���Ϳ� �������� ��´�.
	void GetWorldCenterRadius(const Transform& cTrans, D3DXVECTOR3* center, float* radius);

	//���� ������ �׷�����.
	virtual void RenderGizmo(const Transform& trans);
};
class BoundingBox: public cBoundSphere
{
public:
	Vec3 LocalMinPos;
	Vec3 LocalMaxPos;
public:
	BoundingBox();
	~BoundingBox();
	void GetWorldBox(const Transform& cTrans, D3DXVECTOR3* outBoxPos);
	void GetWorldAABBMinMax(const Transform& cTrans, D3DXVECTOR3* min, D3DXVECTOR3* max);

	//���� ������ �׷��ش�.
	virtual void RenderGizmo(const Transform& trans) override;

};

#define GIZMO_MGR GizmoManager::GetInstance()