#include "Object.h"


Object::Object(void)
{
}


Object::~Object(void)
{
}

void Object::setContainer(std::shared_ptr<Container> c) {
	this->container = c;
}