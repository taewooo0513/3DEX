#pragma once
class Main
{
private:
	Mesh* mesh;
public:
	Main();
	~Main();
public:
	void Init();
	void Update();
	void Render();
	void Release();
	void ResetDevice();
	void LostDevice();
};

