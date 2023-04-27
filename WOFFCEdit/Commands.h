#pragma once
#include <vector>
#include <map>
#include <d3d11.h>
#include <SimpleMath.h>

class DisplayObject;

struct Command
{
	std::vector<DisplayObject>* DisplayListReference = nullptr;
	Command(std::vector<DisplayObject>* dl) { DisplayListReference = dl; };

	virtual void Do();
	virtual void Undo();
	virtual ~Command();
};

struct Paste : Command
{
	int PastedCount;
	Paste(std::vector<DisplayObject>* dl) : Command(dl) { PastedCount = 0; };
	void Do();
	void Undo();
	~Paste();
};

struct Move : Command
{
	std::map<int,DirectX::SimpleMath::Vector3> MovedPositions;
	Move(std::vector<DisplayObject>* dl) : Command(dl) { };
	void Do(){};
	void Undo(){};
	~Move(){};
};

struct Delete : Command
{
	Delete(std::vector<DisplayObject>* dl) : Command(dl) { };
	std::vector<DisplayObject> DeletedObjects;
	void Do(){};
	void Undo(){};
	~Delete(){};
};