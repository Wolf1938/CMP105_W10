#pragma once
#include "Framework/TileMap.h"
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
class Map
{
public:
	Map();
	~Map();

	void checkCollision(GameObject* player);
	void render(sf::RenderWindow* hwnd);

private:
	TileMap tileMap;
};

