
#include <posix/stdlib.h>
#include <posix/stdio.h>
#include <Interface/ARGB.h>
#include <Interface/Rect.h>
#include <Interface/View.h>
#include <Interface/Font.h>
#include "MovieScroller.h"

MovieScroller::MovieScroller(View *_parent) : View(Rect(0,0,1,1)){

	SetClip(false);

	parent = _parent;
//parent->SetClip(false);
	SetClearState(false);
	SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
	parent->Apply(this);
	offset = 0;
}

MovieScroller::~MovieScroller(){
}

void MovieScroller::Tick(float pulse){
	offset+=pulse*.5f;
	while(offset>27.0f) offset -= 27.0f;
	Set(Rect(0,1.0f-(offset*.05f/parent->GetAbsolute()->Height),1,2.0f-(offset*.05f/parent->GetAbsolute()->Height)));
}

