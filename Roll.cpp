
#include <posix/stdlib.h>
#include <posix/stdio.h>
#include <Interface/String.h>
#include <Interface/Bitmap32.h>
#include <assert.h>
#include "Roll.h"
#include <math.h>

Roll::Roll(const char *name, const char *folder, const char *sname, Rect &rect) : View(rect){
	anim = new Bitmap32(String(name),Bitmap32::cARGB);
	SetClearState(false);

//	char str[1024];
//	sprintf(str,"%s/symbolstillframe",folder);
	frames = new Bitmap32(/*str*/folder,Bitmap32::cARGB);
	Apply(frames);

	selectbm   = new Bitmap32(sname,Bitmap32::cARGB);
	sview = new View(Rect(0,0,1,1));
	sview->SetClearState(false);
	sview->Apply(selectbm);
	Apply(sview);

	status = (rand()%800)/100;
	frames->SetFrame(status);

	brainstate = BS_FREE;
}

Roll::~Roll(){
	delete anim;
	delete frames;
	delete selectbm;
	delete sview;
}

void Roll::Tick(float pulse){

//pulse *= .1f;

	bool falltrough = false;
	switch(brainstate){
	case BS_FREE:
		think = 0;
		sview->SetTransparency(1);
		selectbm->SetFrame((status-1)%8);
		brainstate = BS_FREE_TICK;
	case BS_FREE_TICK:
		{
		float i;
		switch(status){
		case 2:
		case 1:
		case 8:
			i = float(sin(think*10)*5);
			if(i<=0) i=0;
			if(i>=1) i=1;
			sview->SetTransparency(i);
		break;
		}
		}
		think += pulse;
	break;
	case BS_DELAY:
		think = 0;
		brainstate = BS_DELAY_TICK;
		sview->SetTransparency(1);
	case BS_DELAY_TICK:
		if(think>2) brainstate = BS_FREE;
		think += pulse;
	break;
	case BS_SPINN:{
		sview->SetTransparency(1);

		brainstate = BS_SPINN_TICK;
		think = 0.0f;
		time = 1.5f; //float(anim->GetFrameCount())/50.0f;
		int frame = (int(float(status)*float(anim->GetFrameCount())/9.0f)+int(time*50.0f))%anim->GetFrameCount();
/*
		     if(r>950){ time+=float(22-frame)/50.0f; nextstatus = 2;	} // 7      (wow)
		else if(r>750){ time+=float(11-frame)/50.0f; nextstatus = 1;	} // Bell   (crazy)
		else if(r>600){ time+=float(89-frame)/50.0f; nextstatus = 8;	} // Cherry	(flash)
		else if(r>450){ time+=float(45-frame)/50.0f; nextstatus = 4;	} // 5
		else if(r>360){ time+=float(56-frame)/50.0f; nextstatus = 5;	} // Pære
		else if(r>270){ time+=float(67-frame)/50.0f; nextstatus = 6;	} // Apple
		else if(r>180){ time+=float(78-frame)/50.0f; nextstatus = 7;	} // Lemon
		else if(r> 90){ time+=float(33-frame)/50.0f; nextstatus = 3;	} // Banana
*/
#if 0
		     if(r>900-340){ time+=float((22-11)-frame)/50.0f; nextstatus = 2; r = 900-340; } // 7      (wow)
		else if(r>700-340){ time+=float((11-11)-frame)/50.0f; nextstatus = 1; r = 700-340; } // Bell   (crazy)
		else if(r>400-340){ time+=float((89-11)-frame)/50.0f; nextstatus = 8; r = 400-340; } // Cherry	(flash)
		else if(r> 50){ time+=float((45-11)-frame)/50.0f; nextstatus = 4; r =  50; } // 5
		else if(r> 40){ time+=float((56-11)-frame)/50.0f; nextstatus = 5; r =  40; } // Pære
		else if(r> 30){ time+=float((67-11)-frame)/50.0f; nextstatus = 6; r =  30; } // Apple
		else if(r> 20){ time+=float((78-11)-frame)/50.0f; nextstatus = 7; r =  20; } // Lemon
		else /*if(r> 10)*/{ time+=float((33-11)-frame)/50.0f; nextstatus = 3; r =  10; } // Banana
		//else{ time+=float(-frame)/50.0f; nextstatus = 0; }
#endif

//printf("%d\n",r);
//r = 90;
#if 0
		do{
			int r = (rand()%9700)/100;
				 if(r>89){ time+=float((22-11)-frame)/50.0f; nextstatus = 2; r = 89; } // 7      (wow)
			else if(r>70){ time+=float((11-11)-frame)/50.0f; nextstatus = 1; r = 70; } // Bell   (crazy)
			else if(r>50){ time+=float((89-11)-frame)/50.0f; nextstatus = 8; r = 50; } // Cherry (flash)
			else if(r>40){ time+=float((45-11)-frame)/50.0f; nextstatus = 4; r = 40; } // 5
			else if(r>30){ time+=float((56-11)-frame)/50.0f; nextstatus = 5; r = 30; } // Pære
			else if(r>20){ time+=float((67-11)-frame)/50.0f; nextstatus = 6; r = 20; } // Apple
			else if(r>10){ time+=float((78-11)-frame)/50.0f; nextstatus = 7; r = 10; } // Lemon
			else{          time+=float((33-11)-frame)/50.0f; nextstatus = 3; r =  0; } // Banana
		}while(status==nextstatus);
#else
		do{
			int r = (rand()%9700)/10;
				 if(r>890-5){ time+=float((22-11)-frame)/50.0f; nextstatus = 2; r = 890-5; } // 7      (wow)
			else if(r>700-5){ time+=float((11-11)-frame)/50.0f; nextstatus = 1; r = 700-5; } // Bell   (crazy)
			else if(r>500-5){ time+=float((89-11)-frame)/50.0f; nextstatus = 8; r = 500-5; } // Cherry (flash)
			else if(r>400-5){ time+=float((45-11)-frame)/50.0f; nextstatus = 4; r = 400-5; } // 5
			else if(r>300-5){ time+=float((56-11)-frame)/50.0f; nextstatus = 5; r = 300-5; } // Pære
			else if(r>200-5){ time+=float((67-11)-frame)/50.0f; nextstatus = 6; r = 200-5; } // Apple
			else if(r>100-5){ time+=float((78-11)-frame)/50.0f; nextstatus = 7; r = 100-5; } // Lemon
			else{             time+=float((33-11)-frame)/50.0f; nextstatus = 3; r =     0; } // Banana
		}while(status==nextstatus);
#endif

/*
		time = float(rand()%200)/200.0f+2.0f;
		int frame = (int(float(status)*float(anim->GetFrameCount())/9.0f)+int(time*50.0f))%anim->GetFrameCount();
		     if(frame<11){ time+=float(11-frame)/50.0f; nextstatus = 1; }
		else if(frame<22){ time+=float(22-frame)/50.0f; nextstatus = 2; }
		else if(frame<33){ time+=float(33-frame)/50.0f; nextstatus = 3; }
		else if(frame<45){ time+=float(45-frame)/50.0f; nextstatus = 4; }
		else if(frame<56){ time+=float(56-frame)/50.0f; nextstatus = 5; }
		else if(frame<67){ time+=float(67-frame)/50.0f; nextstatus = 6; }
		else if(frame<78){ time+=float(78-frame)/50.0f; nextstatus = 7; }
		else if(frame<89){ time+=float(89-frame)/50.0f; nextstatus = 8; }
		else{ time+=float(anim->GetFrameCount()-frame)/50.0f; nextstatus = 0; }
		//nextstatus = int(time*50.0f/(anim->GetFrameCount()/9.0f))%9;
*/
		Detatch(frames);
		Apply(anim);
	}

//	7777
//	BBBB
//	CCCC

	case BS_SPINN_TICK:{
		int frame = int(think*50.0f);
//frame = 11;	// Bell
//frame = 22;	// 7
//frame = 33;	// banana
//frame = 44;	// 5
//frame = 56;	// Pære
//frame = 67;	// Apple
//frame = 78;	// Lemon
//frame = 89;	// Cherry
//printf("%d,%f,%f\n",frame,think,pulse);
		if(think<time){
			anim->SetFrame((int(float(status)*float(anim->GetFrameCount())/8.0f)+frame)%anim->GetFrameCount());
			think+=pulse;
			break;
		}else{
			// fall trough
		}
	}
	case BS_SPINN_DEINITIALIZE:
		status = nextstatus;
		Detatch(anim);
		brainstate = BS_FREE;
		Apply(frames);
		frames->SetFrame(status-1);
	break;
	}
}

void Roll::Spinn(void){
	assert(brainstate!=BS_SPINN);
	brainstate = BS_SPINN;
}

void Roll::Delay(void){
	brainstate = BS_DELAY;
}

int Roll::GetStatus(void) const{
	if((brainstate!=BS_FREE)&&(brainstate!=BS_FREE_TICK)) return -1;
	switch(status){
	case 8: return 1; break;
	case 1: return 2; break;
	case 2: return 3; break;
	}
	return 0;
}

