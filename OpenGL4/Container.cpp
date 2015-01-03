#include "Container.h"
#include "LightManager.h"
#include "World.h"


Container::Container(void)
{
}


Container::~Container(void)
{
}

void Container::setLightManager(std::shared_ptr<LightManager> lm) {
	this->lLightManager = lm;
}
void Container::setWorld(std::shared_ptr<World> w) {
	this->wWorld = w;
}
std::shared_ptr<LightManager> Container::getLightManager() {
	return this->lLightManager;
}
std::shared_ptr<World> Container::getWorld() {
	return this->wWorld;
}