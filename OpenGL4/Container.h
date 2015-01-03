#pragma once

#include <memory>

class LightManager;
class World;

class Container
{
public:
	Container(void);
	~Container(void);
	void setLightManager(std::shared_ptr<LightManager>);
	std::shared_ptr<LightManager> getLightManager();
	void setWorld(std::shared_ptr<World>);
	std::shared_ptr<World> getWorld();
private:
	std::shared_ptr<LightManager> lLightManager;
	std::shared_ptr<World> wWorld;



};

