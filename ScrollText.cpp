
#include <posix/stdlib.h>
#include <posix/stdio.h>
#include <posix/string.h>
#include <Interface/ARGB.h>
#include <Interface/Rect.h>
#include <Interface/View.h>
#include <Interface/Font.h>
#include <Interface/DynamicArray.h>
#include "ScrollText.h"
#include <math.h>

ScrollText::ScrollText(View *parent) : View(Rect(0,0,1,1)){//, Message(){
	SetClearState(false);
	SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
	parent->Apply(this);
	offset = 0;
//	SetName("ScrollText");
	#ifdef OPENGL
	#else
	Print("Error!");
	#endif

	urgent = new DynamicArray();
	state = SCROLL_TICK;

	uview = new View(Rect(.4f,0,1,1));
	uview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
	uview->SetClearState(false);
	parent->Apply(uview);

	Font *font = new Font("Fonts/swed");//Humnst777_BT_40");
	font->SetSize(.5f);
	uview->Apply(font);
}

ScrollText::~ScrollText(){
	delete urgent;
	delete uview;
}

void ScrollText::Tick(float pulse){

	char *foo;
	float v;

	switch(state){
	case SCROLL_TICK:
		foo = ConsoleStream::GetString();	// fixme: Follow the "creator destructs" roule
		offset+=pulse;
		Set(Rect(1-(offset*.05f),0,1,1));
		if((offset*.05f)>((GetFont()->GetWidth(foo)/10.0f)+1.0f)) offset -= ((GetFont()->GetWidth(foo)/10.0f)+1.0f)/.05f;
		delete foo;

		if(urgent->GetCount()==0) break;

//	case SCROLL_TO_URGENT:
		t = 0;
		ustr = (char*)urgent->GetItem(0);
		urgent->Remove(0);
		state = SCROLL_TO_URGENT_TICK;
		uview->ConsoleStream::Clear();
//printf("ustr = %s",ustr);
		uview->ConsoleStream::Print(ustr);
		delete ustr;

	case SCROLL_TO_URGENT_TICK:
		foo = ConsoleStream::GetString();	// fixme: Follow the "creator destructs" roule
		offset+=pulse;
		Set(Rect(1-(offset*.05f),0,1,1));
		if((offset*.05f)>((GetFont()->GetWidth(foo)/10.0f)+1.0f)) offset -= ((GetFont()->GetWidth(foo)/10.0f)+1.0f)/.05f;
		delete foo;
		t += pulse;
		v = t>1?1:t;
//		SetColor(ARGB(1-v,1-v,1-v));
//		uview->SetColor(ARGB(v,v,v));
//255.0f/255.0f,212.0f/255.0f,95.0f/255.0f
		SetColor(ARGB((255.0f/255.0f)*(1-v),(212.0f/255.0f)*(1-v),(95.0f/255.0f)*(1-v)));
		uview->SetColor(ARGB(v*(255.0f/255.0f),v*(212.0f/255.0f),v*(95.0f/255.0f)));
		if(t<1) break;

		t = 0;
		state = URGENT_TICK;
		//sstr = new char[strlen(ConsoleStream::GetString())+1];
		//sprintf(sstr,"%s",ConsoleStream::GetString());
		//ConsoleStream::Clear();
		//ConsoleStream::Print(ustr);

	case URGENT_TICK:
		t += pulse;

		v = sin(t*25)*.5f+.5f;
		uview->SetColor(ARGB(v*(255.0f/255.0f),v*(212.0f/255.0f),v*(95.0f/255.0f)));

		if(t<5) break;

	case URGENT_TO_SCROLL:
		t = 0;
		state = URGENT_TO_SCROLL_TICK;

		//ConsoleStream::Clear();
		//ConsoleStream::Print(sstr);
		//delete sstr;

	case URGENT_TO_SCROLL_TICK:
		foo = ConsoleStream::GetString();	// fixme: Follow the "creator destructs" roule
		offset+=pulse;
		Set(Rect(1-(offset*.05f),0,1,1));
		if((offset*.05f)>((GetFont()->GetWidth(foo)/10.0f)+1.0f)) offset -= ((GetFont()->GetWidth(foo)/10.0f)+1.0f)/.05f;
		delete foo;
		t += pulse;
		//SetTransparency(((4-t)/4)>0?0:((4-t)/4));
		v = t>1?1:t;
		SetColor(ARGB(v*(255.0f/255.0f),v*(212.0f/255.0f),v*(95.0f/255.0f)));
		uview->SetColor(ARGB((255.0f/255.0f)*(1-v),(212.0f/255.0f)*(1-v),(95.0f/255.0f)*(1-v)));
		if(t<1) break;

		//delete ustr;
		state = SCROLL_TICK;
	}
}

/*
void ScrollText::MessageReceived(void){
printf("ScrollText::MessageReceived(): %x\n",this);
	char *buf = (char*)GetReceivedBuffer();
	int len = *(int16*)buf; buf = (char*)(int(buf)+sizeof(int16));
	char *text = new char[len+1];
	for(int n=0; n<len; n++) text[n] = *buf++;
	text[len]=0;
printf("%s\n",text);
	ConsoleStream::Clear();
	ConsoleStream::Print(text);
	delete text;

	offset = 0;
}
*/

void ScrollText::Urgent(const char *str){

	if(urgent->GetCount()<100){
		char *nstr = new char[strlen(str)+1];
		sprintf(nstr,"%s",str);
		urgent->Add((void*)nstr);
	}

}

