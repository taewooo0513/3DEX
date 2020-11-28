#include "DXUT.h"
#include "LoadManager.h"

LoadManager::LoadManager()
{
}

LoadManager::~LoadManager()
{
}

Texture* LoadManager::AddImage(const string& key, const string& path)
{
	auto find = m_Texture.find(key);
	if (find == m_Texture.end())
	{
		D3DXIMAGE_INFO info;
		LPDIRECT3DTEXTURE9 texturePtr;
		if (D3DXCreateTextureFromFileExA(Device, path.c_str(), -2, -2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			Texture* text = new Texture(texturePtr, info);
			m_Texture[key] = text;
			return text;
		}
		return nullptr;
	}
	return find->second;
}

MultiTexture* LoadManager::AddImages(const string& key, const string& Folder, int count)
{

	auto find = m_MultiTexture.find(key);
	if (find == m_MultiTexture.end())
	{
		D3DXIMAGE_INFO info;
		LPDIRECT3DTEXTURE9 texturePtr;
		for (int i = 0; i > count; i++)
		{
			char a;
			sprintf(&a,"./Resouce/image/",Folder,"/",count,".png");
			if (D3DXCreateTextureFromFileExA(Device, to_string(a).c_str(), -2, -2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
			{
				Texture* text = new Texture(texturePtr, info);
				MultiTexture* Multi = new MultiTexture(text);
				m_MultiTexture[key] = Multi;
				if (i == count)
				{
					return Multi;
				}
			}
		}
		return nullptr;
	}
	return find->second;
}

Texture* LoadManager::FindImage(const string& key)
{
	auto find = m_Texture.find(key);
	if (find == m_Texture.end())
	{
		return nullptr;
	}
	return find->second;
}

MultiTexture* LoadManager::FindImages(const string& key, int count)
{
	auto find = m_MultiTexture.find(key);
	if (find == m_MultiTexture.end())
	{
		return nullptr;
	}
	return find->second;
}


Mesh* LoadManager::AddMesh(const string& key, const wstring& strFilename)
{
	auto find = m_Mesh.find(key);
	if (find != m_Mesh.end())
	{
		return find->second;
	}
	CMeshLoader* pMeshLoader = new CMeshLoader();
	pMeshLoader->Create(Device, strFilename);
	if (pMeshLoader->GetMesh() == nullptr)
	{
		SAFE_DELETE(pMeshLoader);
		return nullptr;
	}
	Mesh* mesh = new Mesh();
	mesh->pMesh = pMeshLoader->GetMesh();
	for (int i = 0; i < pMeshLoader->GetNumMaterials(); i++)
	{
		mesh->v_Matrial.push_back(pMeshLoader->GetMaterial(i));
	}
	m_Mesh[key.c_str()] = mesh;
	SAFE_DELETE(pMeshLoader);
	return mesh;
}

Mesh* LoadManager::FindMesh(const string& key)
{
	auto find = m_Mesh.find(key);
	if (find == m_Mesh.end())
	{
	return nullptr;
	}
		return find->second;
}

