#include "Collisions.h"

Collisions::Collisions(){}

HitMap Collisions::initializeCollisionMap()
{
    HitMap map;

    map[Key(typeid(Player), typeid(Exterminator))] = &playerExterminator;
    map[Key(typeid(Exterminator), typeid(Player))] = &exterminatorPlayer;

    /*map[Key(typeid(Player), typeid(Scooter))] = &playerScooter;
    map[Key(typeid(Scooter), typeid(Player))] = &scooterPlayer;

    map[Key(typeid(Player), typeid(OldWoman))] = &playerOldWoman;
    map[Key(typeid(OldWoman), typeid(Player))] = &oldWomanPlayer;*/

    map[Key(typeid(Player), typeid(SpecialFood))] = &playerSpecialFood;
    map[Key(typeid(SpecialFood), typeid(Player))] = &specialFoodPlayer;

    map[Key(typeid(Exterminator), typeid(Trash))] = &exterminatorTrash;
    map[Key(typeid(Trash), typeid(Exterminator))] = &trashExterminator;

    /*map[Key(typeid(Player), typeid(RegularFood))] = &playerRegulerFood;
    map[Key(typeid(RegularFood), typeid(Player))] = &regulerFoodPlayer;

    map[Key(typeid(Player), typeid(ToxicFood))] = &playerToxicFood;
    map[Key(typeid(ToxicFood), typeid(Player))] = &toxicFoodPlayer;*/

    return map;
}

HitFunctionPtr Collisions::findHandler(const std::type_index& class1, const std::type_index& class2)
{
    static HitMap collisionMap = initializeCollisionMap();

    //try to find the proper pointer for the pair of objects
    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));

    //pointer not found
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }

    return mapEntry->second;
}

void Collisions::HandleCollision(GameObject& object1, GameObject& object2)
{
    //phf is a pointer to hit function
    auto phf = findHandler(typeid(object1), typeid(object2));

    //there is not handler function for these objects
    if (!phf)
    {
        return;
    }
    //handle the collision for these objects 
    phf(object1, object2);
}
