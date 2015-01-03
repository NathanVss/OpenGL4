#include "Lightable.h"


Lightable::Lightable(void)
{
}


Lightable::~Lightable(void)
{
}

void Lightable::setLightManager(std::shared_ptr<LightManager> lm) {
	this->lLighManager = lm;
}

std::shared_ptr<LightManager> Lightable::getLightManager() {
	return this->lLighManager;
}