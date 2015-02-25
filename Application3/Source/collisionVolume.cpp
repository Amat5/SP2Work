#include "collisionVolume.h"
#include <math.h>

collisionVolume::collisionVolume(Vector3 cC, float Mass, float Velocity, bool Elastic)
{
	collisionTriggered = false;
	collisionType = 0;
	setCentre(cC);
	if (Mass > 0)
		mass = Mass;
	velocity = Velocity;
}

collisionVolume::collisionVolume()
{
	collisionType = 0;
	collisionCentre.SetZero();
	collisionTriggered = false;
	mass = 1;
	velocity = 0;
}

collisionVolume::~collisionVolume()
{

}

Vector3 collisionVolume::getCentre(void)const
{
	return collisionCentre;
}
void collisionVolume::setCentre(Vector3 cC)
{
	collisionCentre = cC;
}

std::string collisionVolume::getText(void)const
{
	return text;
}

void collisionVolume::setText(std::string txt)
{
	text = txt;
}

float collisionVolume::getMass(void)const
{
	return mass;
}
void collisionVolume::setMass(float m)
{
	if (m > 0)
		mass = m;
}

float collisionVolume::getVelocity(void)const
{
	return velocity;
}
void collisionVolume::setVelocity(float v)
{
	velocity = v;
}

float collisionVolume::getCOORD(int Axis)const
{
	if (Axis == 0)
		return collisionCentre.x;
	else if (Axis == 1)
		return collisionCentre.y;
	else
		return collisionCentre.z;
}
void collisionVolume::setCOORD(float X, float Y, float Z)
{
	collisionCentre.x = X;
	collisionCentre.y = Y;
	collisionCentre.z = Z;
}

int collisionVolume::getCollisionType(void)const
{
	return collisionType;
}
void collisionVolume::setCollisionType(int cT)
{
	collisionType = cT;
}

