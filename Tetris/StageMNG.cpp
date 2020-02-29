#include "StageMNG.h"
#include "Stage.h"
StageMNG* StageMNG::instance = nullptr;
bool StageMNG::Init()
{
	currentstage = new Stage();
	if (!currentstage->Init())
		return false;
	return true;
}

void StageMNG::Run()
{
	currentstage->Render();
}

StageMNG::StageMNG() : currentstage(nullptr)
{

}

StageMNG::~StageMNG()
{
}
