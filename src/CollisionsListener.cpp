#include "CollisionsListener.h"
#include "GameObject.h"
#include <vector>
void CollisionsListener::BeginContact(const b2Contact* contact) {
	Fixture f1 = cp.FixtureA();
	Fixture f2 = cp.FixtureB();

	Body b1 = f1.getBody();
	Body b2 = f2.getBody();

	GameObject o1 = b1.getUserData();
	GameObject o2 = b2.getUserData();

	std::vector<GameObject*> objCollided;
	objCollided.push_back(&o1);
	objCollided.push_back(&o2);
}