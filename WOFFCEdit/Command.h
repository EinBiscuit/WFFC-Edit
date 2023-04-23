#pragma once
struct Command
{
	

	virtual void Do();
	virtual void Undo();
	virtual ~Command();
};

