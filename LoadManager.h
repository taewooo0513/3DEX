#pragma once
#include "singleton.h"
struct Texture
{
public:
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;
public:
	Texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
		:texturePtr(texturePtr), info(info)
	{
	}
	~Texture()
	{
	}
};
struct MultiTexture
{
public:
	list<Texture*> l_Texture;
	
public:
	MultiTexture(Texture * texturePtr)
	{
		l_Texture.push_back(texturePtr);
	}

	~MultiTexture()
	{
	}
};
struct Mesh
{
public:
	LPD3DXMESH pMesh;
	vector<Material*> v_Matrial;
public:
	Mesh() {}
	~Mesh()
	{
		SAFE_DELETE(pMesh);
		v_Matrial.clear();
	}

};
class LoadManager :public singleton<LoadManager>
{
private:
	map <string, Texture*>m_Texture;
	map <string, MultiTexture*> m_MultiTexture;
	map <string,Mesh*> m_Mesh;
public:
	LoadManager();
	~LoadManager();
public:
	Texture* AddImage(const string& key, const string& path);
	MultiTexture* AddImages(const string& key, const string& path, int count = 0);

	Texture* FindImage(const string& key);
	MultiTexture* FindImages(const string& key,int count = 0);

	Mesh* AddMesh(const string& key, const wstring& strFilename);
	Mesh* FindMesh(const string & key);
};

#define LOADER LoadManager::GetInstance()
