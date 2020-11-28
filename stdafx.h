#pragma once
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
#include <istream>
#include <ostream>
#include <string>
using namespace std;
static float TimeScale = 1;

#define Device DXUTGetD3D9Device()
#define Vec2 D3DXVECTOR2
#define Vec3 D3DXVECTOR3
#define DTime DXUTGetElapsedTime() * TimeScale
inline const int WINSIZEX = 1920;
inline const int WINSIZEY = 1080;
#include "MeshLoader.h"
#include "LoadManager.h"
#include "Render2DManager.h"
#include "Render3DManager.h"