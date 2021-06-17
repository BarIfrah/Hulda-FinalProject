#pragma once
//============================ include section ===============================
#include <map>
#include <typeinfo>
#include <typeindex>

#include "GameObject.h"
#include "Player.h"
#include "Exterminator.h"
//#include "OldWoman.h"
//#include "Scooter.h"
#include "Road.h"
#include "Trash.h"
#include "SpecialFood.h"
//#include "ToxicFood.h"
//#include "RegularFood.h"
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
    void playerExterminator(GameObject& object1, GameObject& object2)
    {
        std::cout << "player & exterminator collided!\n";
        Player& player = static_cast<Player&>(object1);
        player.setState(DIE, PLAYER_BOX_HEIGHT, PLAYER_BOX_WIDTH);
    }
    void exterminatorPlayer(GameObject& object1, GameObject& object2)
    {
        playerExterminator(object2, object1);
    }
    ////-------------------------------------------------------------------------

    //void playerScooter(GameObject& object1, GameObject& object2)
    //{

    //}
    //void scooterPlayer(GameObject& object1, GameObject& object2)
    //{
    //    playerScooter(object2, object1);
    //}

    ////-------------------------------------------------------------------------

    //void playerOldWoman(GameObject& object1, GameObject& object2)
    //{

    //}
    //void oldWomanPlayer(GameObject& object1, GameObject& object2)
    //{
    //    playerOldWoman(object2, object1);
    //}

    //-------------------------------------------------------------------------

    void exterminatorTrash(GameObject& object1, GameObject& object2)
    {
        Exterminator& enemy = static_cast<Exterminator&>(object1);
        b2Vec2 dirFromKey = b2Vec2(0, 0);
        std::cout << "enemy & trash were collided!\n";
        if (enemy.getDirection() == LEFT) {
            dirFromKey = b2Vec2(EMLEFT.x, EMUP.y);
            enemy.setPhysicsObjectPos(sf::Vector2f(enemy.getLocation().x+dirFromKey.x,
                enemy.getLocation().y+dirFromKey.y), dirFromKey );
        }
        else {
            dirFromKey = b2Vec2(EMRIGHT.x, EMUP.y);
            enemy.setPhysicsObjectPos(sf::Vector2f(enemy.getLocation().x+dirFromKey.x,
                enemy.getLocation().y+dirFromKey.y),dirFromKey );
        }
        enemy.updateLoc();
    }
    void trashExterminator(GameObject& object1, GameObject& object2)
    {
        exterminatorTrash(object2, object1);
    }

    //-------------------------------------------------------------------------

    //void playerToxicFood(GameObject& object1, GameObject& object2)
    //{

    //}
    //void toxicFoodPlayer(GameObject& object1, GameObject& object2)
    //{
    //    playerToxicFood(object2, object1);
    //}

    ////-------------------------------------------------------------------------

    //void playerRegulerFood(GameObject& object1, GameObject& object2)
    //{
    //    
    //}
    //void regulerFoodPlayer(GameObject& object1, GameObject& object2)
    //{
    //    playerRegulerFood(object2, object1);
    //}

     ////-------------------------------------------------------------------------

    void playerSpecialFood(GameObject& object1, GameObject& object2)
    {
        Food& food = static_cast<Food&>(object2);
        food.collect();
    }
    void specialFoodPlayer(GameObject& object1, GameObject& object2)
    {
        playerSpecialFood(object2, object1);
    }
}
