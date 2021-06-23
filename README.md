# Ratata
Object-Oriented platform game by:\
Bar Ifrah\
Sharon Levi\
Oren Holtzman
## About
#### This is a story of 'Hulda', a Tel-Avivian sewer rat.
Being kicked out of her home due to Metro train construction in Tel Aviv, Hulda went out on the streets,\
looking for food to survive. But, there are mant dangers in the city, such as: getting run over by a scooter,\
eating poison and having the city exterminator on your tail.\
To survive- Hulda needs:\
Hulda needs to avoid all enemies:\
![Screen Shot 2021-06-24 at 0 44 52 (2)](https://user-images.githubusercontent.com/71547715/123172253-8d391780-d485-11eb-940f-cd2525a10e5a.png)

and avoid the poisonous apples:\
<img width="159" alt="Screen Shot 2021-06-21 at 22 30 23" src="https://user-images.githubusercontent.com/71547715/122817594-c5532580-d2e0-11eb-906f-e15e614d3660.png">\

to gain powers, Hulda needs to eat some burgers!:\
<img width="160" alt="Screen Shot 2021-06-21 at 22 31 01" src="https://user-images.githubusercontent.com/71547715/122817697-eb78c580-d2e0-11eb-8e98-fe195cf0cc34.png">

to gain some points, Hulda needs to eat pizza, watermelon and bananas:\
<img width="163" alt="Screen Shot 2021-06-21 at 22 45 48" src="https://user-images.githubusercontent.com/71547715/122818976-7c03d580-d2e2-11eb-80fd-2d0cd2b59922.png">
<img width="172" alt="Screen Shot 2021-06-21 at 22 44 02" src="https://user-images.githubusercontent.com/71547715/122818987-7f975c80-d2e2-11eb-8ab2-204013790784.png">
<img width="172" alt="Screen Shot 2021-06-21 at 22 44 42" src="https://user-images.githubusercontent.com/71547715/122818988-7f975c80-d2e2-11eb-97ed-62d9d566f9d6.png">\

To move to the next level, Hulda needs to go inside the 'teleport' trash can:\
https://user-images.githubusercontent.com/71547715/123173160-d8075f00-d486-11eb-88b8-25e6bdda1965.mov
![huldaTrash](https://user-images.githubusercontent.com/71547715/123173460-4ea45c80-d487-11eb-8b22-6390ee88953b.gif)



Hulda starts with 3 lives. Every 100 points collected- hulda gets an extra life.\
Hulda can gain lives from the 'special force' burgers. no more than 6 lives can be collected.

@Create levels:
creating new levels by editing the 'Levels.txt' file.





## Files and descriptions
Headers:

CPP's:\
To build a game object:\
PhysicsObject.cpp\
GameObject.cpp

Static Game Objects inherit from 'StaticObject.cpp':\
Adanit.cpp\
Food.cpp\
ToxicFood.cpp

Trash.cpp\
RegularFood.cpp\
SpecialFood.cpp\
Road.cpp

Dynamic Game Objects inherit from 'MovingObject.cpp'\
Enemy.cpp\
-Exterminator.cpp\
-Scooter.cpp\
Player.cpp\
DynamicFloor.cpp

Game controlling classes:\
Controller.cpp\
Stats.cpp\
Board.cpp\
DataReader.cpp\
Resources.cpp

Collision management:				
Collisions.cpp
Listener.cpp
Utilities.cpp
Menu.cpp
main.cpp
	

## Implementation:

a c++ code snippit:

```c++
std::cout << "Hello, world!\n";
```

## GitHub Repository

## Credits
Game design:\
[Shaked 'Keti' Zahor (instagram)](https://www.instagram.com/shaketi___/?hl=en)

Physics:\
[Box2D](https://box2d.org) Physical engine:\

Graphic implementation:
[SFML](https://www.sfml-dev.org)




## Game ScreenShots:
<img width="748" alt="Screen Shot 2021-06-20 at 18 32 30" src="https://user-images.githubusercontent.com/71547715/122680019-fc004180-d1f5-11eb-9425-8f5b9ab20e2b.png">


<img width="747" alt="Screen Shot 2021-06-20 at 18 37 49" src="https://user-images.githubusercontent.com/71547715/122680185-b85a0780-d1f6-11eb-9722-e53636b1f172.png">
