#pragma once

#include "Container.h"
#include <memory>

class Object
{
public:
	Object(void);
	virtual ~Object(void);

	void setContainer(std::shared_ptr<Container>);

protected:
	std::shared_ptr<Container> container;
};

