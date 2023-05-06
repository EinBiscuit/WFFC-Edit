#pragma once
#include <vector>
#include <map>
#include <d3d11.h>
#include <SimpleMath.h>

#include "DisplayObject.h"

class DisplayObject;

struct Command
{
	std::vector<DisplayObject>* DisplayListReference;
	Command(std::vector<DisplayObject>* dl) { DisplayListReference = dl; };

	virtual void Do();
	virtual void Undo();
	virtual ~Command();
};

struct Paste : Command
{
	int PastedCount;
	Paste(std::vector<DisplayObject>* dl) : Command(dl) { PastedCount = 0; };
	void Do(std::vector<DisplayObject>* Copies)
	{
		DisplayListReference->insert(DisplayListReference->end(), Copies->begin(), Copies->end());
		PastedCount = Copies->size();
	};
	void Undo()
	{
		DisplayListReference->erase(DisplayListReference->end()-PastedCount,DisplayListReference->end());
	}
	~Paste();
};

struct Move : Command
{
	const std::map<int,DirectX::SimpleMath::Vector3> MovedPositions;
	Move(std::vector<DisplayObject>* dl,const std::map<int, DirectX::SimpleMath::Vector3>& NewRelativePositions) : Command(dl) { MovedPositions = NewRelativePositions; };
	void Do()
	{
		for (auto& i : MovedPositions)
			DisplayListReference->at(i.first).m_position += i.second;
	};
	void Undo()
	{
		for (auto& i : MovedPositions)
			DisplayListReference->at(i.first).m_position -= i.second;
	};
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