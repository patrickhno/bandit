
#include <posix/stdlib.h>
#include <posix/stdio.h>
#include <Interface/ARGB.h>
#include <Interface/Rect.h>
#include <Interface/Font.h>
#include <Interface/Bitmap.h>
#include <Interface/Bitmap32.h>
#include "Phone.h"
#include <math.h>

PhoneNumber::PhoneNumber(class Rect &rect) : View(rect){
	SetClearState(false);
/*

	Font *font = new Font("Fonts/swed");//Humnst777_BT_40");
	font->SetSize(.7f);
Apply(font);
	Bitmap *mask = font->GetString("Call 801802803");
//	mask->Scale(Rect(mask->GetWidth()*.4f,mask->GetHeight()*.85f));
	delete font;
	anim = new Bitmap32("texteffect/textfx",Bitmap32::cRGB);

	int cnt = anim->GetFrameCount();
	for(int n=0; n<cnt; n++){
		anim->SetFrame(n);
		*anim *= *mask;
	}
anim->Invalidate();
	Apply(mask);//anim);
//	delete mask;

*/
	view = new View(Rect(.1f,.15f,1,1));
	Apply(view);
//	Font *font = new Font("Fonts/swed");//Humnst777_BT_40");
//	font->SetSize(.7f);
	view->SetClearState(false);
//	view->Apply(font);
//	#ifdef OPENGL
//	#else
//	view->Print("Error!");
//	#endif
	pnview1 = new View(Rect(.04f,.03f,1-.03f,1-.15f));
	pnview1->SetClearState(false);
	pnview2 = new View(Rect(.04f,.03f,1-.03f,1-.15f));
	pnview2->SetClearState(false);
	pnview3 = new View(Rect(.04f,.03f,1-.03f,1-.15f));
	pnview3->SetClearState(false);
//	Apply(pnview);
	pnbm1 = new Bitmap32("call/0714/0714",Bitmap32::cARGB);
	pnbm2 = new Bitmap32("call/mobil/mobil",Bitmap32::cARGB);
	pnbm3 = new Bitmap32("call/0724/0724",Bitmap32::cARGB);
	Apply(pnview1);
	Apply(pnview2);
	Apply(pnview3);
	pnview1->Apply(pnbm1);
	pnview2->Apply(pnbm2);
	pnview3->Apply(pnbm3);

	jview = new View(Rect(.04f,-.2f,1-.03f,1-.25f));
	jview->SetClearState(false);
	Apply(jview);
	jbm = new Bitmap32("jacklogo/jack/jack",Bitmap32::cARGB);
	Apply(jview);
	jview->Apply(jbm);

	tbview = new View(Rect(.04f,-.2f,1-.03f,1-.25f));
	tbview->SetClearState(false);
	Apply(tbview);
	tbbm = new Bitmap32("jacklogo/the bandit/thebandit",Bitmap32::cARGB);
	Apply(tbview);
	tbview->Apply(tbbm);

	Font *small = new Font("Fonts/swed");//Humnst777_BT_40");
	small->SetSize(.5f);
	cview = new View(Rect(0,.6f,1,1));
	cview->SetClearState(false);
	#ifdef OPENGL
	#else
	cview->Print("Error!");
	#endif
	cview->Apply(small);
	cview->SetColor(ARGB(.5f,1,.3f));
//	Apply(cview);

	think = 0;
}

PhoneNumber::~PhoneNumber(){
//	delete anim;
	delete pnview1;
	delete pnview2;
	delete pnview3;
	delete pnbm1;
	delete pnbm2;
	delete pnbm3;
	delete jview;
	delete jbm;
	delete tbview;
	delete tbbm;
	delete view;
	delete cview;
}

void PhoneNumber::Tick(float pulse){
/*
	int frame = int(think*25.0f);
	if(frame>=anim->GetFrameCount()) frame = 0;
	anim->SetFrame(frame);
	think += pulse;
	while(think>8.0f) think-=8.0f;
*/
/*
	view->SetColor(ARGB(
		 .15f*sin(think*1.0f)+.15f+.2f,
		 .25f*sin(think*1.1f)+.25f+.1f,
		 .5f *sin(think*1.2f)+.5f ));
*/
	if(think>18.0f){
		pnview1->SetTransparency(0);
		pnview2->SetTransparency(1);
		pnview3->SetTransparency(1);
		jview  ->SetTransparency(1);
		tbview ->SetTransparency(1);
		int frame = int((think-18)*25);
		if(frame>=pnbm1->GetFrameCount()) frame = pnbm1->GetFrameCount()-1;
		pnbm1->SetFrame(frame);
		if(think>24) think -= 24;
	}else if(think>12.0f){
		pnview1->SetTransparency(1);
		pnview2->SetTransparency(0);
		pnview3->SetTransparency(1);
		jview  ->SetTransparency(1);
		tbview ->SetTransparency(1);
		int frame = int((think-12)*25);
		if(frame>=pnbm2->GetFrameCount()) frame = pnbm2->GetFrameCount()-1;
		pnbm2->SetFrame(frame);
	}else if(think>6.0f){
		pnview1->SetTransparency(1);
		pnview2->SetTransparency(1);
		pnview3->SetTransparency(0);
		jview  ->SetTransparency(1);
		tbview ->SetTransparency(1);
		int frame = int((think-6)*25);
		if(frame>=pnbm3->GetFrameCount()) frame = pnbm3->GetFrameCount()-1;
		pnbm3->SetFrame(frame);
	}else if(think>3.0f){
		pnview1->SetTransparency(1);
		pnview2->SetTransparency(1);
		pnview3->SetTransparency(1);
		 jview->SetTransparency(1);
		tbview->SetTransparency(0);
		int frame = int((think-3)*25);
		if(frame>=tbbm->GetFrameCount()) frame = tbbm->GetFrameCount()-1;
		tbbm->SetFrame(frame);
	}else{
		pnview1->SetTransparency(1);
		pnview2->SetTransparency(1);
		pnview3->SetTransparency(1);
		 jview->SetTransparency(0);
		tbview->SetTransparency(1);
		int frame = int(think*25);
		//if(frame<0) frame = 0;
		if(frame>=jbm->GetFrameCount()) frame = jbm->GetFrameCount()-1;
		jbm->SetFrame(frame);
	}
	think += pulse;
}

enum Location{
	C_LOCATION_UNKNOWN,
	C_LOCATION_DENMARK,
	C_LOCATION_NORWAY,
	C_LOCATION_SWEDEN,
	C_LOCATION_SCANDINAVIA = (C_LOCATION_DENMARK|C_LOCATION_NORWAY|C_LOCATION_SWEDEN)
};


static Location GetLocation(void){
	return C_LOCATION_SCANDINAVIA;
}

void PhoneNumber::SetNumber(const char *nr){
	#ifdef OPENGL
	#else
	view->ConsoleStream::Clear();
	switch(GetLocation()){
	case C_LOCATION_SCANDINAVIA:
//		view->Print("Ring %s",nr);
	break;
	default:
		view->Print("Dial %s",nr);
	}
	#endif
}

void PhoneNumber::SetConnectionCharge(const float v){
	ccharge = v;
	#ifdef OPENGL
	#else
	cview->ConsoleStream::Clear();
	switch(GetLocation()){
	case C_LOCATION_SCANDINAVIA:
		//cview->Print("    Kr. %1.2f oppkobling. Kr. %1.2f pr. min.",ccharge,charge);
		cview->Print("                        Kr. %1.2f pr. min.",ccharge,charge);
	break;
	default:
		cview->Print("    $%1.2f + $%1.2f min.",ccharge,charge);
	}
	#endif
}

void PhoneNumber::SetCharge(const float v){
	charge = v;
	#ifdef OPENGL
	#else
	cview->ConsoleStream::Clear();
	switch(GetLocation()){
	case C_LOCATION_SCANDINAVIA:
		//cview->Print("    Kr. %1.2f oppkobling. Kr. %1.2f pr. min.",ccharge,charge);
		cview->Print("                        Kr. %1.2f pr. min.",ccharge,charge);
	break;
	default:
		cview->Print("    $%1.2f + $%1.2f min.",ccharge,charge);
	}
	#endif
}

