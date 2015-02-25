#ifndef COLLISION_VOLUME_H
#define COLLISION_VOLUME_H

#include "Vector3.h"

class collisionVolume
{
public:
	collisionVolume(Vector3 cC, float Mass, float Velocity, bool Elastic);
	collisionVolume();
	~collisionVolume();

	Vector3 getCentre(void)const;
	void setCentre(Vector3 cC);

	std::string getText(void)const;
	void setText(std::string txt);

	float getMass(void)const;
	void setMass(float m);

	float getVelocity(void)const;
	void setVelocity(float v);

	float getCOORD(int Axis)const;
	void setCOORD(float X, float Y, float Z);


	int getCollisionType(void)const;
	void setCollisionType(int cT);

private:
	Vector3 collisionCentre;
	std::string text;
	float mass;
	float velocity;
	int collisionType;
	//bool isElastic;
	bool collisionTriggered;
};

#endif COLLISION_VOLUME_H