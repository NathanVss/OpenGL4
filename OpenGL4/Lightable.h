#pragma once

#include <memory>
#include <vector>
#include "LightManager.h"

class Lightable
{
public:
	Lightable(void);
	~Lightable(void);
	virtual void setLightManager(std::shared_ptr<LightManager>);
	virtual std::shared_ptr<LightManager> getLightManager();

protected:
	std::shared_ptr<LightManager> lLighManager;

};

