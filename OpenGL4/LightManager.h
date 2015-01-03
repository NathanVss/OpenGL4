#pragma once

#include <memory>
#include <vector>
#include "EasyBMP\EasyBMP.h"

#include "Light.h"
#include "Object.h"
#include "ShadowMap.h"
#include "NRectangle.h"
#include "CircleLight.h"
#include "DDAHelper.h"
#include "LightNeon.h"

class World;

struct mapPoint {
	int x;
	int y;
	unsigned char scale;
};

struct LightBag {
	ShadowMap* shadowMap;
};
struct LightBagRaycasting : LightBag {
	ShadowMap* shadowMapRaycasting;
};
struct CircleLightBag : LightBagRaycasting {

	std::vector<mapPoint> interpFromRaycastingPts;
	std::vector<mapPoint> lightMiniRadiusPts;
	CircleLight* cCircleLight;
};
struct LightNeonBag : LightBagRaycasting {
	std::vector<mapPoint> interFromRaycastingPts;
	LightNeon* lLightNeon;
};


class LightManager : public Object
{
public:
	LightManager(void);
	~LightManager(void);
	
	void addCircleLight(CircleLight*);
	void addLightNeon(LightNeon*);

	void mapWorld();

	void copyMapWorld(LightBag*);
	void assignShadowMapRaycasting(LightBagRaycasting*);
	void doRaycastingCircleLight(CircleLightBag*);
	void doOneRaycastingCircleLight(CircleLightBag*, coords);

	void lightRadius(CircleLightBag*);
	void lightMiniRadius(CircleLightBag*);
	void mixRaycastingRadius(CircleLightBag*);

	void checkLighting();

	void convertToBMP(ShadowMap*, std::string);

	void enableFinalShadowMap();
	ShadowMap* getFinalShadowMap();

	void doRaycastingNeonLight(LightNeonBag*);
	void doOneRaycastingNeonLight(LightNeonBag*, coords, coords);
	void mixRaycastingNeonLight(LightNeonBag*);


	void clearPointers();
	void clearLightBagPointer(LightBag*);
	void clearLightBagRaycastingPointer(LightBagRaycasting*);

private:
	ShadowMap* baseShadowMap;
	ShadowMap* finalShadowMap;

	std::vector<LightNeon*> LightNeons;
	std::vector<LightNeonBag*> LightNeonsBags;

	std::vector<CircleLight*> CircleLights;
	std::vector<CircleLightBag*> CircleLightsBags;
	

};

