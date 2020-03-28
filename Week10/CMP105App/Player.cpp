#include "Player.h"
Player::Player()
{
	scale = 200;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	texture.loadFromFile("gfx/Mushroom.png");
	setTexture(&texture);
	setSize(sf::Vector2f(64, 64));
	setCollisionBox(0, 0, 64, 64);
	setPosition(100, 100);
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		move(200 * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		move(-200 * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		input->setKeyUp(sf::Keyboard::Up);
		velocity.y = 1000;
	}	
}

void Player::update(float dt)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut+ 1/2at^2
	stepVelocity += gravity * dt; // v = u + at  note the += is not =
	setPosition(getPosition() + pos);
}

void Player::collisionResponse(GameObject* collider)
{
	velocity.y = 0;
	setPosition(getPosition().x, collider->getPosition().y - getSize().y);
}
