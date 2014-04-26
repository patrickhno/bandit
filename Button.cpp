
#include <posix/stdlib.h>
#include <Interface/String.h>
#include <Interface/Bitmap32.h>
#include "Button.h"

Button::Button(const char *name, Rect &rect) : View(rect){

	anim = new Bitmap32(String(name),Bitmap32::cARGB);
	SetClearState(false);
	Apply(anim);
}

Button::~Button(){
	delete anim;
}
