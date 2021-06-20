#pragma once
//============================ include section ===============================
#include <map>
#include <typeinfo>
#include <typeindex>

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Exterminator.h"
#include "Scooter.h"
#include "Road.h"
#include "Trash.h"
#include "Food.h"
#include "SpecialFood.h"
#include "ToxicFood.h"
#include "RegularFood.h"
#include <iostream> //for debug
//============================== using section ===============================
using HitFunctionPtr = void (*)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;
//===========================================================================
class Collisions
{
public:

    Collisions();

    void HandleCollision(GameObject& object1, GameObject& object2);
    HitFunctionPtr findHandler(const std::type_index& class1, const std::type_index& class2);
    HitMap initializeCollisionMap();
};
//===========================================================================
namespace
{
    void playerEnemy(GameObject& object1, GameObject& object2)
    {
        Player& player = static_cast<Player&>(object1);
        player.setState(DIE, PLAYER_BOX_HEIGHT, PLAYER_BOX_WIDTH);
    }
    void enemyPlayer(GameObject& object1, GameObject& object2)
    {
        playerEnemy(object2, object1);
    }
    //-------------------------------------------------------------------------

    void exterminatorTrash(GameObject& object1, GameObject& object2)
    {
        Exterminator& enemy = static_cast<Exterminator&>(object1);
        enemy.setCollision();
    }
    void trashExterminator(GameObject& object1, GameObject& object2)
    {
        exterminatorTrash(object2, object1);
    }

    //-------------------------------------------------------------------------

    void scooterTrash(GameObject& object1, GameObject& object2)
    {
        b2Vec2 dirFromKey = b2Vec2(0, 0);
        Scooter& enemy = static_cast<Scooter&>(object1);
        if (enemy.getDirection() == RIGHT) 
            enemy.setDirection(LEFT);
        else 
            enemy.setDirection(RIGHT);
        
        enemy.flipSprite(sf::Vector2f(-1.f, 1.f));
    }
    void trashScooter(GameObject& object1, GameObject& object2)
    {
        scooterTrash(object2, object1);
    }

     ////-------------------------------------------------------------------------

    void playerFood(GameObject& object1, GameObject& object2)
    {
        Food& food = static_cast<Food&>(object2);
        food.collect();
    }
    void foodPlayer(GameObject& object1, GameObject& object2)
    {
        playerFood(object2, object1);
    }
}
