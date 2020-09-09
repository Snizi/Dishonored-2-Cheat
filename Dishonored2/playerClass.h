#include <cstdint>

struct Vector3
{
	float x, y, z;
}vec3;



// Created with ReClass.NET 1.2 by KN4CK3R

class ent
{
public:
	char pad_0000[8]; //0x0000
	class callBackBindMem* callBackBindMemPtr; //0x0008
}; //Size: 0x0010

class callBackBindMem
{
public:
	char pad_0000[8]; //0x0000
	class playerController* playerControllerPtr; //0x0008
	char pad_0010[60]; //0x0010
}; //Size: 0x004C

class playerController
{
public:
	char pad_0000[536]; //0x0000
	class playerState* playerStatePtr; //0x0218
}; //Size: 0x0220

class playerState
{
public:
	char pad_0000[40]; //0x0000
	class playerStateMachine* playerStateMachinePtr; //0x0028
	char pad_0030[728]; //0x0030
	class playerPhysics* playerPhysicsPtr; //0x0308
	char pad_0310[56]; //0x0310
	class status* statusPtr; //0x0348
	class playerBreath* playerBreathPtr; //0x0350
	char pad_0358[240]; //0x0358
}; //Size: 0x0448

class status
{
public:
	char pad_0000[32]; //0x0000
	float health; //0x0020
	char pad_0024[76]; //0x0024
	class manaClass* manaPtr; //0x0070
	char pad_0078[272]; //0x0078
}; //Size: 0x0188

class manaClass
{
public:
	char pad_0000[32]; //0x0000
	float mana; //0x0020
	char pad_0024[228]; //0x0024
}; //Size: 0x0108

class playerBreath
{
public:
	char pad_0000[64]; //0x0000
	float oxygen; //0x0040
	char pad_0044[196]; //0x0044
}; //Size: 0x0108

class playerStateMachine
{
public:
	void* N000002EC; //0x0000
	char pad_0008[336]; //0x0008
	class playerStateChoke* playerStateChokePtr; //0x0158
	char pad_0160[176]; //0x0160
	class playerStateEquipChange* playerStateEquipChangePtr; //0x0210
	char pad_0218[496]; //0x0218
}; //Size: 0x0408

class playerStateEquipChange
{
public:
	char pad_0000[80]; //0x0000
	class inventory* inventoryPtr; //0x0050
}; //Size: 0x0058

class inventory
{
public:
	char pad_0000[32]; //0x0000
	int32_t ammo; //0x0020
	char pad_0024[7]; //0x0024
}; //Size: 0x002B

class playerPhysics
{
public:
	char pad_0000[72]; //0x0000
	class playerBody* playerBodyPointer; //0x0048
	char pad_0050[184]; //0x0050
}; //Size: 0x0108

class playerBody
{
public:
	char pad_0000[328]; //0x0000
	class characterProxy* CharacterProxyPointer; //0x0148
}; //Size: 0x0150

class characterProxy
{
public:
	char pad_0000[128]; //0x0000
	Vector3 playerPosition; //0x0080
	char pad_008C[145]; //0x008C
}; //Size: 0x011D

class playerStateChoke
{
public:
	char pad_0000[212]; //0x0000
	float choke; //0x00D4
	char pad_00D8[51]; //0x00D8
}; //Size: 0x010B