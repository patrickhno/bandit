
#include <posix/stdio.h>
#include <posix/stdlib.h>
#include <Interface/String.h>
#include <Interface/Bitmap32.h>
#include "Arm.h"

Arm::Arm(Rect &rect) : View(rect){

	anim = new Bitmap32(String("normalopt/armanim/banditt"),Bitmap32::cARGB);
	SetClearState(false);
	Apply(anim);

	brainstate = BS_FREE;
}

Arm::~Arm(){
	delete anim;
}

void Arm::Tick(float pulse){
	switch(brainstate){
	case BS_FREE:
	break;
	case BS_SPINN:
		brainstate = BS_SPINN_TICK;
		think = 0.0f;
	case BS_SPINN_TICK:
		int frame = int(think*50.0f);
		if(frame<anim->GetFrameCount()){
			anim->SetFrame(frame);
		}else{
			anim->SetFrame(0);
			brainstate = BS_FREE;
			break;
		}
		think+=pulse;
	break;
	}
}

void Arm::Spinn(void){
	brainstate = BS_SPINN;
}

