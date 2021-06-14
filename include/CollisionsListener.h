 #pragma once
#include <box2d/box2d.h>

class CollisionsListener : public b2ContactListener {
public:
	CollisionsListener()=default;
	//void BeginContact(const b2Contact* contact);
};