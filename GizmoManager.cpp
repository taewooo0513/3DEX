#include "DXUT.h"
#include "GizmoManager.h"

GizmoManager::GizmoManager()
{
}

GizmoManager::~GizmoManager()
{
}

HRESULT GizmoManager::Init(LPDIRECT3DDEVICE9 pDevice)
{
    m_pDevice = pDevice;
    float intervalAngle = (D3DX_PI * 2.0f) / CIRCLEGIZMO_SEGMENTS;
    for (int i = 0; i <= CIRCLEGIZMO_SEGMENTS; i++)
    {
        float angle = i * intervalAngle;
        pCirclePos[i] = Vec3(cos(angle), sin(angle), 0.0f);
    }
    return S_OK;
}

void GizmoManager::Release()
{
}

void GizmoManager::Line(const Vec3& startpos, const Vec3& endpos, DWORD color) const
{
    D3DXMATRIXA16 matPrevWorld;
    m_pDevice->GetTransform(D3DTS_WORLD, &matPrevWorld);

    D3DXMATRIXA16 matIdentity;
    D3DXMatrixIdentity(&matIdentity);
    m_pDevice->SetTransform(D3DTS_WORLD, &matIdentity);

    DWORD prevLight = 0;
    m_pDevice->GetRenderState(D3DRS_LIGHTING, &prevLight);

    m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

    GIZMOVERTEX vertices[2];
    vertices[0].pos = startpos;
    vertices[0].color = color;
    vertices[1].pos = endpos;
    vertices[1].color = color;

    m_pDevice->SetFVF(GIZMOVERTEX::FVF);
    m_pDevice->DrawPrimitiveUP(D3DPT_LINELIST, 1, vertices, sizeof(GIZMOVERTEX));
    m_pDevice->SetTransform(D3DTS_WORLD, &matPrevWorld);
    m_pDevice->SetRenderState(D3DRS_LIGHTING, prevLight);
}

void GizmoManager::Circle(const Vec3& centerpos, float radius, DWORD color) const
{
	D3DXMATRIXA16 matPrevWorld;
	m_pDevice->GetTransform(D3DTS_WORLD, &matPrevWorld);

	//���� ������ ��带 ���
	DWORD prevLight = 0;
	m_pDevice->GetRenderState(D3DRS_LIGHTING, &prevLight);

	//�������� ����.
	m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//�ӽ� ���� �迭 
	GIZMOVERTEX vertices[CIRCLEGIZMO_SEGMENTS + 1];
	for (int i = 0; i < CIRCLEGIZMO_SEGMENTS + 1; i++)
	{
		//vertices[i].pos = m_pCirclePos[i];
		vertices[i].color = color;
	}

	//Circle �� ���� ��� �غ�

	//ȸ���غ�
	D3DXVECTOR3 forward ;
	D3DXVECTOR3 right;
	D3DXVECTOR3 up(0, 1, 0);
	if (forward == up)
		up = D3DXVECTOR3(0, 0, -1);
	else if (forward == D3DXVECTOR3(0, -1, 0))
		up = D3DXVECTOR3(0, 0, 1);

	D3DXVec3Cross(&right, &up, &forward);
	D3DXVec3Cross(&up, &forward, &right);

	//�� ����ȭ
	D3DXVec3Normalize(&forward, &forward);
	D3DXVec3Normalize(&right, &right);
	D3DXVec3Normalize(&up, &up);

	//�� ������
	forward = forward * radius;
	right = right * radius;
	up = up * radius;

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	memcpy(&matWorld._11, right, sizeof(D3DXVECTOR3));
	memcpy(&matWorld._21, up, sizeof(D3DXVECTOR3));
	memcpy(&matWorld._31, forward, sizeof(D3DXVECTOR3));
	memcpy(&matWorld._41, centerpos, sizeof(D3DXVECTOR3));

	m_pDevice->SetTransform(D3DTS_WORLD, &matWorld);

	//�׸���.
	m_pDevice->SetFVF(GIZMOVERTEX::FVF);
	m_pDevice->DrawPrimitiveUP(
		D3DPT_LINESTRIP,			//D3DPT_LINESTRIP �� �ϸ� ������ ���� �Ѻױ׸���� Line �� �׷� �糤��.
		CIRCLEGIZMO_SEGMENTS,
		vertices,
		sizeof(GIZMOVERTEX));

	//�ٽ� ���� ���´�.
	m_pDevice->SetTransform(D3DTS_WORLD, &matPrevWorld);

	//������ ��� ���� ���´�
	m_pDevice->SetRenderState(D3DRS_LIGHTING, prevLight);
}

void GizmoManager::AABBBox(const Vec3& minpos, const Vec3& maxpos, DWORD color) const
{
	this->Line(D3DXVECTOR3(minpos.x, minpos.y, minpos.z), D3DXVECTOR3(maxpos.x, minpos.y, minpos.z), color);
	this->Line(D3DXVECTOR3(maxpos.x, minpos.y, minpos.z), D3DXVECTOR3(maxpos.x, maxpos.y, minpos.z), color);
	this->Line(D3DXVECTOR3(maxpos.x, maxpos.y, minpos.z), D3DXVECTOR3(minpos.x, maxpos.y, minpos.z), color);
	this->Line(D3DXVECTOR3(minpos.x, maxpos.y, minpos.z), D3DXVECTOR3(minpos.x, minpos.y, minpos.z), color);
	this->Line(D3DXVECTOR3(minpos.x, minpos.y, maxpos.z), D3DXVECTOR3(maxpos.x, minpos.y, maxpos.z), color);
	this->Line(D3DXVECTOR3(maxpos.x, minpos.y, maxpos.z), D3DXVECTOR3(maxpos.x, maxpos.y, maxpos.z), color);
	this->Line(D3DXVECTOR3(maxpos.x, maxpos.y, maxpos.z), D3DXVECTOR3(minpos.x, maxpos.y, maxpos.z), color);
	this->Line(D3DXVECTOR3(minpos.x, maxpos.y, maxpos.z), D3DXVECTOR3(minpos.x, minpos.y, maxpos.z), color);
	this->Line(D3DXVECTOR3(minpos.x, minpos.y, minpos.z), D3DXVECTOR3(minpos.x, minpos.y, maxpos.z), color);
	this->Line(D3DXVECTOR3(maxpos.x, minpos.y, minpos.z), D3DXVECTOR3(maxpos.x, minpos.y, maxpos.z), color);
	this->Line(D3DXVECTOR3(maxpos.x, maxpos.y, minpos.z), D3DXVECTOR3(maxpos.x, maxpos.y, maxpos.z), color);
	this->Line(D3DXVECTOR3(minpos.x, maxpos.y, minpos.z), D3DXVECTOR3(minpos.x, maxpos.y, maxpos.z), color);
}
