#pragma once
//============================ include section ===============================
#include <map>
#include <typeinfo>
#include <typeindex>
#include "GameObject.h"
#include "Player.h"
//#include "Exterminator.h"
//#include "OldWoman.h"
//#include "Scooter.h"
#include "Road.h"
#include "Trash.h"
#include "SpecialFood.h"
//#include "ToxicFood.h"
//#include "RegularFood.h"

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
    //void playerExterminator(GameObject& object1, GameObject& object2)
    //{

    //}
    //void exterminatorPlayer(GameObject& object1, GameObject& object2)
    //{
    //    playerExterminator(object2, object1);
    //}

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

    void playerSpecialFood(GameObject& object1, GameObject& object2)
    {
        SpecialFood& food = static_cast<SpecialFood&>(object2);
        food.collect();
    }
    void specialFoodPlayer(GameObject& object1, GameObject& object2)
    {
        playerSpecialFood(object2, object1);
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
}
