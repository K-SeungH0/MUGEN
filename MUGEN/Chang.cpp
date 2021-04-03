#include "Mugen.h"
#include "Chang.h"
#include "Image.h"

Chang::Chang()
{
}

Chang::~Chang()
{
}

void Chang::Init()
{

	dir = DIRECTION::LEFT;
	state = CHARACTER_STATE::IDLE;
	hp = 100;
	pos = { -300,  300 };
	name = "Chang Koehan";

	frame = 0;
	elapsedTime = 0;
	lpImage = new Image();
	auto del_RGB = RGB(140, 206, 156);
}