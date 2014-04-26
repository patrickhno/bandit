
#include <string.h>
#include <posix/stdlib.h>
#include <posix/stdio.h>
#include <posix/string.h>
#include <Interface/ARGB.h>
#include <Interface/Rect.h>
#include <Interface/String.h>
#include <Interface/Bitmap32.h>
#include <Interface/DynamicArray.h>
#include "Player.h"
#include "Roll.h"
#include "Arm.h"
#include "Button.h"
#include "Coin.h"
#include <Interface/Font.h>
#include "ScrollText.h"
#include "Hiscore.h"
#include <assert.h>

//#define NOGFX
//#define ENGLISH

Player::Player(Hiscore *h, Rect &rect, ScrollText *_st, int _nr) : View(rect){

	SetClip(false);

	nr = _nr;
	st = _st;

	hiscore = h;

	baseframe  = new Bitmap32("baseframe",Bitmap32::cARGB);

	freeanim   = new Bitmap32("phoneopt/phone",Bitmap32::cARGB);
	logonanim  = new Bitmap32("ledigopt/caller/caller",Bitmap32::cARGB);
	logoutanim = new Bitmap32("ledigopt/ledig/ledig",Bitmap32::cARGB);
	flashanim  = new Bitmap32("win1opt/flash",Bitmap32::cARGB);

	freeview = new View(Rect(0,0,1,1));
	freeview->SetClearState(false);
	freeview->Apply(freeanim);

	SetClearState(false);

//	anim = new Bitmap32(String("test_alpha"),Bitmap32::cARGB);
//	Apply(anim);

//	roll1   = new Roll("normalopt/symbols/symbolroll/1/symbolroll","normalopt/symbols/symbolstillframe/1",Rect( 25.0f/256.0f,27.0f/192.0f,( 25.0f+47.0f)/256.0f,(27.0f+67.0f)/192.0f));
//	roll2   = new Roll("normalopt/symbols/symbolroll/2/symbolroll","normalopt/symbols/symbolstillframe/2",Rect( 75.0f/256.0f,27.0f/192.0f,( 75.0f+47.0f)/256.0f,(27.0f+67.0f)/192.0f));
//	roll3   = new Roll("normalopt/symbols/symbolroll/3/symbolroll","normalopt/symbols/symbolstillframe/3",Rect(124.0f/256.0f,27.0f/192.0f,(124.0f+47.0f)/256.0f,(27.0f+67.0f)/192.0f));
//	roll4   = new Roll("normalopt/symbols/symbolroll/4/symbolroll","normalopt/symbols/symbolstillframe/4",Rect(174.0f/256.0f,27.0f/192.0f,(174.0f+47.0f)/256.0f,(27.0f+67.0f)/192.0f));
	roll1   = new Roll("symbolroll/symbols/1/1","symbolstill/1/1","symbolselect/1/symbolselect",Rect( 25.0f/256.0f,27.0f/192.0f,( 25.0f+47.0f)/256.0f,(27.0f+67.0f)/192.0f));
	roll2   = new Roll("symbolroll/symbols/2/2","symbolstill/2/2","symbolselect/2/symbolselect",Rect( 75.0f/256.0f,27.0f/192.0f,( 75.0f+47.0f)/256.0f,(27.0f+67.0f)/192.0f));
	roll3   = new Roll("symbolroll/symbols/3/3","symbolstill/3/3","symbolselect/3/symbolselect",Rect(124.0f/256.0f,27.0f/192.0f,(124.0f+47.0f)/256.0f,(27.0f+67.0f)/192.0f));
	roll4   = new Roll("symbolroll/symbols/4/4","symbolstill/4/4","symbolselect/4/symbolselect",Rect(174.0f/256.0f,27.0f/192.0f,(174.0f+47.0f)/256.0f,(27.0f+67.0f)/192.0f));
	arm     = new Arm(Rect(229.0f/256.0f,46.0f/192.0f,(229.0f+27.0f)/256.0f,(46.0f+69.0f)/192.0f));
	button1 = new Button("normalopt/buttonselect/button1select",Rect( 18.0f/256.0f,100.0f/192.0f,( 18.0f+51.0f)/256.0f,(100.0f+30.0f)/192.0f));
	button2 = new Button("normalopt/buttonselect/button2select",Rect( 71.0f/256.0f,100.0f/192.0f,( 71.0f+51.0f)/256.0f,(100.0f+30.0f)/192.0f));
	button3 = new Button("normalopt/buttonselect/button3select",Rect(123.0f/256.0f,100.0f/192.0f,(123.0f+51.0f)/256.0f,(100.0f+30.0f)/192.0f));
	button4 = new Button("normalopt/buttonselect/button4select",Rect(173.0f/256.0f,100.0f/192.0f,(173.0f+51.0f)/256.0f,(100.0f+30.0f)/192.0f));
#ifndef NOGFX
	bandit     = new Bitmap32("jack/Jack",Bitmap32::cARGB);
	crazyanim  = new Bitmap32("win4opt/bigwin",Bitmap32::cARGB);
	wowanim    = new Bitmap32("win3opt/bigwin",Bitmap32::cARGB);
#endif
	leftbm	  = new Bitmap32("arrows/notselected/4",Bitmap32::cARGB);
	rightbm	  = new Bitmap32("arrows/notselected/6",Bitmap32::cARGB);
	upbm	  = new Bitmap32("arrows/notselected/2",Bitmap32::cARGB);
	downbm	  = new Bitmap32("arrows/notselected/8",Bitmap32::cARGB);
	centerbm  = new Bitmap32("arrows/notselected/center",Bitmap32::cARGB);
	sleftbm	  = new Bitmap32("arrows/selected/4",Bitmap32::cARGB);
	srightbm  = new Bitmap32("arrows/selected/6",Bitmap32::cARGB);
	supbm	  = new Bitmap32("arrows/selected/2",Bitmap32::cARGB);
	sdownbm	  = new Bitmap32("arrows/selected/8",Bitmap32::cARGB);
	sleftcbm  = new Bitmap32("arrows/selected/4center",Bitmap32::cARGB);
	srightcbm = new Bitmap32("arrows/selected/6center",Bitmap32::cARGB);
	supcbm	  = new Bitmap32("arrows/selected/2center",Bitmap32::cARGB);
	sdowncbm  = new Bitmap32("arrows/selected/8center",Bitmap32::cARGB);
	left    = new View(Rect(.3f*1.1f,.5f*1.5f-.061f,.4f*1.1f,.6f*1.5f-.061f));
	right   = new View(Rect(.5f*1.1f,.5f*1.5f-.061f,.6f*1.1f,.6f*1.5f-.061f));
	up      = new View(Rect(.4f*1.1f,.4f*1.5f-.061f,.5f*1.1f,.5f*1.5f-.061f));
	down    = new View(Rect(.4f*1.1f,.6f*1.5f-.061f,.5f*1.1f,.7f*1.5f-.061f));
	center  = new View(Rect(.4f*1.1f,.5f*1.5f-.061f,.5f*1.1f,.6f*1.5f-.061f));
	sleft   = new View(Rect(.3f*1.1f,.5f*1.5f-.061f,.4f*1.1f,.6f*1.5f-.061f));
	sright  = new View(Rect(.5f*1.1f,.5f*1.5f-.061f,.6f*1.1f,.6f*1.5f-.061f));
	sup     = new View(Rect(.4f*1.1f,.4f*1.5f-.061f,.5f*1.1f,.5f*1.5f-.061f));
	sdown   = new View(Rect(.4f*1.1f,.6f*1.5f-.061f,.5f*1.1f,.7f*1.5f-.061f));
	sleftc  = new View(Rect(.4f*1.1f,.5f*1.5f-.061f,.5f*1.1f,.6f*1.5f-.061f));
	srightc = new View(Rect(.4f*1.1f,.5f*1.5f-.061f,.5f*1.1f,.6f*1.5f-.061f));
	supc    = new View(Rect(.4f*1.1f,.5f*1.5f-.061f,.5f*1.1f,.6f*1.5f-.061f));
	sdownc  = new View(Rect(.4f*1.1f,.5f*1.5f-.061f,.5f*1.1f,.6f*1.5f-.061f));
	left   ->SetClearState(false);
	right  ->SetClearState(false);
	up     ->SetClearState(false);
	down   ->SetClearState(false);
	center ->SetClearState(false);
	sleft  ->SetClearState(false);
	sright ->SetClearState(false);
	sup    ->SetClearState(false);
	sdown  ->SetClearState(false);
	sleftc ->SetClearState(false);
	srightc->SetClearState(false);
	supc   ->SetClearState(false);
	sdownc ->SetClearState(false);
	left   ->Apply(leftbm);
	right  ->Apply(rightbm);
	up     ->Apply(upbm);
	down   ->Apply(downbm);
	center ->Apply(centerbm);
	sleft  ->Apply(sleftbm);
	sright ->Apply(srightbm);
	sup    ->Apply(supbm);
	sdown  ->Apply(sdownbm);
	sleftc ->Apply(sleftcbm);
	srightc->Apply(srightcbm);
	supc   ->Apply(supcbm);
	sdownc ->Apply(sdowncbm);
	#ifdef OPENGL
	#else
	left   ->SetTransparency(.5f);
	right  ->SetTransparency(.5f);
	up     ->SetTransparency(.5f);
	down   ->SetTransparency(.5f);
	center ->SetTransparency(.5f);
	sleft  ->SetTransparency(1);
	sright ->SetTransparency(1);
	sup    ->SetTransparency(1);
	sdown  ->SetTransparency(1);
	sleftc ->SetTransparency(1);
	srightc->SetTransparency(1);
	supc   ->SetTransparency(1);
	sdownc ->SetTransparency(1);
	#endif

	flash = new View(Rect(88.0f/256.0f,0,(88+67)/256.0f,26.0f/192.0f));
	flash->Apply(flashanim);
	flash->SetClearState(false);

	nameframe = new View(Rect(.1f,/*.68f*/0,1,1));
	nameview = new View(Rect(0,0,1,1)); //.1f,.68f,1,1));//.1f,.6f,1,1));
//	nameview->SetColor(ARGB(1,1,1));
	nameview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
	nameview->SetClearState(false);
	nameframe->Apply(nameview);
nameframe->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
nameframe->SetClearState(false);
nameframe->SetClip(false);
nameview->SetClip(false);
	infoview = new View(Rect(.1f,.7f,1,1));//.1f,.6f,1,1));
	infoview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
	infoview->SetClearState(false);
	infoview->Print("Infoview");

	scorev1000 = new View(Rect(.64f,.7f,.69f+.1f,1));
	scorev0100 = new View(Rect(.69f,.7f,.74f+.1f,1));
	scorev0010 = new View(Rect(.74f,.7f,.79f+.1f,1));
	scorev0001 = new View(Rect(.79f,.7f,.84f+.1f,1));
	scorev1000->SetColor(ARGB(0,1,1));
	scorev0100->SetColor(ARGB(1,0,1));
	scorev0010->SetColor(ARGB(1,1,0));
	scorev0001->SetColor(ARGB(0,0,1));
	scorev1000->SetClearState(false);
	scorev0100->SetClearState(false);
	scorev0010->SetClearState(false);
	scorev0001->SetClearState(false);

//	Apply(nameview);
	font = new Font("Fonts/swed");//Humnst777_BT_40");
//	font->SetSize(.05f);
	font->SetSize(.49f);
//	name = new ScrollText(nameview);
//	name->Apply(font);
//	#ifdef OPENGL
//	#else
//	name->Print("");
//	#endif
//	nameview->Apply(name);
	infoview->Apply(font);

nameview->Apply(font);
nameframe->Apply(font);

	scorev1000->Apply(font);
	scorev0100->Apply(font);
	scorev0010->Apply(font);
	scorev0001->Apply(font);

//	int framecount = anim->GetFrameCount();
//	frame = rand()%(framecount*2);

	brainstate = BS_FREE;
	frame = 0;

	locked1 = false;
	locked2 = false;
	locked3 = false;
	locked4 = false;

	lock1 = false;
	lock2 = false;
	lock3 = false;
	lock4 = false;

	spinn = false;

	score = 0;
//logout = 0;
	active = false;
	checkwin = false;
	logon = false;
	simulate = false;

	key_2=
	key_4=key_5=key_6=
	key_8=false;

	coins = new DynamicArray();
	for(int n=0; n<20; n++){
		Coin *coin = new Coin();
		coins->Add(coin);
//		Apply(coin);
	}

	logout = false;
}

Player::~Player(){
	delete bandit;
	delete roll1;
	delete roll2;
	delete roll3;
	delete roll4;
	delete button1;
	delete button2;
	delete button3;
	delete button4;
	delete logonanim;
	delete logoutanim;
	delete arm;
	delete flashanim;
	delete crazyanim;
	delete wowanim;
	delete flash;
	delete nameview;
	delete nameframe;
	delete infoview;
//	delete name;
	delete freeanim;
	delete leftbm;
	delete rightbm;
	delete upbm;
	delete downbm;
	delete centerbm;
	delete sleftbm;
	delete srightbm;
	delete supbm;
	delete sdownbm;
	delete sleftcbm;
	delete srightcbm;
	delete supcbm;
	delete sdowncbm;
	delete left;
	delete right;
	delete up;
	delete down;
	delete center;
	delete sleft;
	delete sright;
	delete sup;
	delete sdown;
	delete sleftc;
	delete srightc;
	delete supc;
	delete sdownc;
	delete font;
	delete baseframe;
	delete freeview;
	delete scorev1000;
	delete scorev0100;
	delete scorev0010;
	delete scorev0001;

	while(coins->GetCount()){
		delete (Coin*)coins->GetItem(0);
		coins->Remove(0);
	}
	delete coins;
}

void Player::DigitDown(char *str){
	if(!strcmp(str,"2")) key_2 = true;
	if(!strcmp(str,"4")) key_4 = true;
	if(!strcmp(str,"5")) key_5 = true;
	if(!strcmp(str,"6")) key_6 = true;
	if(!strcmp(str,"8")) key_8 = true;
}
void Player::DigitUp(char *str){
//	if(!strcmp(str,"2")) key_2 = false;
//	if(!strcmp(str,"4")) key_4 = false;
//	if(!strcmp(str,"5")) key_5 = false;
//	if(!strcmp(str,"6")) key_6 = false;
//	if(!strcmp(str,"8")) key_8 = false;
}

void Player::Tick(float pulse){

//	char *str;

//return;

//	printf("Player: %f,%f,%f,%f\n",GetAbsolute()->x,GetAbsolute()->y,GetAbsolute()->rx,GetAbsolute()->ly);

	arm->Tick(pulse);

	bool retick = true;
	while(retick){
		retick = false;
		switch(brainstate){


		case BS_FREE:
//logout = 0;
			Apply(logonanim);
			Apply(freeview); //anim);
			brainstate = BS_FREE_TICK;
			think = 0;
			logonanim->SetFrame(0);
			#ifdef OPENGL
			#else
			freeview->SetTransparency(0);
			#endif

			simulate = false;

		case BS_FREE_TICK:
			#ifdef SIMULATE
			if(think<10.0f){
				frame = int(think*25.0f)%freeanim->GetFrameCount();
				freeanim->SetFrame(frame);
				break;
			}
			#else
			#ifdef OPENGL
			#else
			if(think<4.0f) freeview->SetTransparency(1.0f-think/4.0f);
			else freeview->SetTransparency(0);
			#endif
			frame = int(think*25.0f)%(freeanim->GetFrameCount()*4);
			assert(frame>=0);
			//assert(frame<freeanim->GetFrameCount());
			if(frame<freeanim->GetFrameCount()) freeanim->SetFrame(frame);
			else freeanim->SetFrame(freeanim->GetFrameCount()-1);
//printf("%d,%d\n",frame,freeanim->GetFrameCount());

			if(think>60.0f) simulate = true;
			if((!active)&&(!simulate)) break;
			#endif
		case BS_FREE_DEINITIALIZE:
//printf("!!!!!!\n");
			Detatch(freeview); //anim);
			Detatch(logonanim);


		case BS_INTRO: //NAME:
//			sprintf(name_str,"Aaaaaaaa");
#ifndef NOGFX
			Apply(bandit);
#endif
			brainstate = BS_INTRO_TICK; //NAME_TICK;
//			name->ConsoleStream::Clear();
//			name->Print(name_str);
//			Apply(nameview);
			think = 0;
			key_2 = false;
			key_4 = false;
			key_5 = false;
			key_6 = false;
			key_8 = false;
//			cn=0;

//			Apply(left);
//			Apply(right);
//			Apply(up);
//			Apply(down);

//			nameview->Set(Rect(.5,.65f,1,1));

//			locked1 = false;
//			locked2 = false;
//			locked3 = false;
//			locked4 = false;

			locked1 = false;
			locked2 = false;
			locked3 = false;
			locked4 = false;

			lock1 = false;
			lock2 = false;
			lock3 = false;
			lock4 = false;

			score = 0;

		case BS_INTRO_TICK:{
			bool falltrough = false;
			if((active&&simulate)||((!active)&&(!simulate))||logout){
				brainstate = BS_LOGOUT;
				falltrough = true;
			}
			frame = int(think*13.0f);
#ifdef NOGFX
		falltrough = true;
#else
			if(frame>=bandit->GetFrameCount()){
falltrough = true;
			}else{
				bandit->SetFrame(frame);
			}
#endif
//			name->ConsoleStream::Clear();
//			if(key_2){
//				// Norway
//				     if(name_str[cn]=='Z') name_str[cn]='Æ';
//				else if(name_str[cn]=='z') name_str[cn]='æ';
//				else if(name_str[cn]=='Æ') name_str[cn]='Ø';
//				else if(name_str[cn]=='æ') name_str[cn]='ø';
//				else if(name_str[cn]=='Ø') name_str[cn]='Å';
//				else if(name_str[cn]=='ø') name_str[cn]='å';
//				else if(name_str[cn]=='Å') name_str[cn]='A';
//				else if(name_str[cn]=='å') name_str[cn]='a';
//				else name_str[cn]++;
//				key_2 = false;
//			}
//			if(key_4){ if(cn) cn--; key_4 = false; }
//			if(key_5){ falltrough = true; }
//			if(key_6){ if(name_str[cn+1]) cn++; key_6 = false; }
//			if(key_8){
//				// Norway
//				     if(name_str[cn]=='A') name_str[cn]='Å';
//				else if(name_str[cn]=='a') name_str[cn]='å';
//				else if(name_str[cn]=='Å') name_str[cn]='Ø';
//				else if(name_str[cn]=='å') name_str[cn]='ø';
//				else if(name_str[cn]=='Ø') name_str[cn]='Æ';
//				else if(name_str[cn]=='ø') name_str[cn]='æ';
//				else if(name_str[cn]=='Æ') name_str[cn]='Z';
//				else if(name_str[cn]=='æ') name_str[cn]='z';
//				else name_str[cn]--;
//				key_8 = false;
//			}
//			name->Print(name_str);
//			char c = name_str[cn];
//			name_str[cn]='\0';
//			float w = font->GetWidth(name_str);
//			name_str[cn]=c;
//			nameview->Set(Rect(.46f-w*.21f,.65f,1,1));
			if(!falltrough) break;
		}
		case BS_INTRO_DEINITIALIZE: //NAME_DEINITIALIZE:
#ifndef NOGFX
			Detatch(bandit);
#endif
//			Detatch(nameview);
//			nameview->Set(Rect(.1,.65f,1,1));
//			Detatch(left);
//			Detatch(right);
//			Detatch(up);
//			Detatch(down);


		case BS_LOGON:
			brainstate = BS_LOGON_TICK;
			think = 0.0f;
			frame = 0;
			Apply(logonanim);
			logon = true;
		case BS_LOGON_TICK:{
			bool falltrough = false;
			if((active&&simulate)||((!active)&&(!simulate))||logout){
				brainstate = BS_LOGOUT;
				falltrough = true;
			}
			frame = int(think*25.0f);
			if(frame>=logonanim->GetFrameCount()){
				falltrough = true;
			}else{
				logonanim->SetFrame(frame);
			}
			if(!falltrough) break;
		}
		case BS_LOGON_DEINITIALIZE:
			Detatch(logonanim);


		case BS_NAME:
			sprintf(name_str,"A       ");
			brainstate = BS_NAME_INFO_TICK;
//			#ifdef OPENGL
//			#else
			nameview->ConsoleStream::Clear();
			nameview->Print(name_str);
//			#endif
			Apply(infoview);
			//infoview->SetColor(ARGB(1,1,1));
			//name->SetColor(ARGB(1,1,1));
			nameview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
			infoview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
			think = 0;
			key_2 = false;
			key_4 = false;
			key_5 = false;
			key_6 = false;
			key_8 = false;
			cn=0;

			nameview->Set(Rect(.5f,.7f,1,1));

			Apply(arm);
			Apply(baseframe);

			t_left = t_right = t_up = t_down = 0;

			infoview->ConsoleStream::Clear();
//			infoview->Print("Spillerfelt %d",nr);
			#ifdef ENGLISH
			infoview->Print("Playfield %d",nr);
			#else
			infoview->Print("Spillefelt %d",nr);
			#endif
			think = 0;

			left  ->Set(Rect(.3f*1.1f,.5f*1.5f-.061f,.4f*1.1f,.6f*1.5f-.061f));
			right ->Set(Rect(.5f*1.1f,.5f*1.5f-.061f,.6f*1.1f,.6f*1.5f-.061f));
			up    ->Set(Rect(.4f*1.1f,.4f*1.5f-.061f,.5f*1.1f,.5f*1.5f-.061f));
			down  ->Set(Rect(.4f*1.1f,.6f*1.5f-.061f,.5f*1.1f,.7f*1.5f-.061f));
			center->Set(Rect(.4f*1.1f,.5f*1.5f-.061f,.5f*1.1f,.6f*1.5f-.061f));
			sleft ->Set(Rect(.3f*1.1f,.5f*1.5f-.061f,.4f*1.1f,.6f*1.5f-.061f));
			sright->Set(Rect(.5f*1.1f,.5f*1.5f-.061f,.6f*1.1f,.6f*1.5f-.061f));
			sup   ->Set(Rect(.4f*1.1f,.4f*1.5f-.061f,.5f*1.1f,.5f*1.5f-.061f));
			sdown ->Set(Rect(.4f*1.1f,.6f*1.5f-.061f,.5f*1.1f,.7f*1.5f-.061f));

		case BS_NAME_INFO_TICK:{

			bool falltrough = false;

			if((active&&simulate)||((!active)&&(!simulate))||logout){
				brainstate = BS_LOGOUT;
				falltrough = true;
			}

			if(simulate) key_5 = true;

			if(think>20){
				infoview->ConsoleStream::Clear();
//				infoview->Print("Spillerfelt %d",nr);
				#ifdef ENGLISH
				infoview->Print("Playfield %d",nr);
				#else
				infoview->Print("Spillefelt %d",nr);
				#endif
				think -= 20;
			}else if(think>15){
				infoview->ConsoleStream::Clear();
//				infoview->Print("avslutt med 5");
				#ifdef ENGLISH
				infoview->Print("end with 5");
				#else
				infoview->Print("avslutt med 5");
				#endif
			}else if(think>10){
				infoview->ConsoleStream::Clear();
//				infoview->Print("med 2,4,6 og 8");
				#ifdef ENGLISH
				infoview->Print("with 2,4,6 and 8");
				#else
				infoview->Print("med 2,4,6 og 8");
				#endif
			}else if(think>5){
				infoview->ConsoleStream::Clear();
//				infoview->Print("Skriv inn navn");
				#ifdef ENGLISH
				infoview->Print("Type your name");
				#else
				infoview->Print("Skriv inn navn");
				#endif
			}
			think += pulse;

			if(key_2||key_4||key_5||key_6||key_8) falltrough = true;
			if(!falltrough) break;

//			Apply(nameview);
Apply(nameframe);
			Apply(left);   Apply(right);   Apply(up);   Apply(down);
			Apply(center);
			Apply(sleft);  Apply(sright);  Apply(sup);  Apply(sdown);
			Apply(sleftc); Apply(srightc); Apply(supc); Apply(sdownc);

			Detatch(infoview);
			brainstate = BS_NAME_TICK;
		}
		case BS_NAME_TICK:{
			bool falltrough = false;

			if((active&&simulate)||((!active)&&(!simulate))||logout){
				brainstate = BS_LOGOUT;
				falltrough = true;
			}

//			if(simulate) falltrough = true;

//			#ifdef OPENGL
//			#else
//			name->ConsoleStream::Clear();
//			#endif
nameview->ConsoleStream::Clear();
			if(key_2){
				t_up = 0;
				#ifdef ENGLISH
				     if(name_str[cn]=='Z') name_str[cn]=' ';
				else if(name_str[cn]=='z') name_str[cn]='A';
				else if(name_str[cn]==' ') name_str[cn]='a';
				#else
				
				// Norway
				     if(name_str[cn]=='Z') name_str[cn]='Æ';
				else if(name_str[cn]=='z') name_str[cn]='æ';
				else if(name_str[cn]=='Æ') name_str[cn]='Ø';
				else if(name_str[cn]=='æ') name_str[cn]='ø';
				else if(name_str[cn]=='Ø') name_str[cn]='Å';
				else if(name_str[cn]=='ø') name_str[cn]='å';
				else if(name_str[cn]=='å') name_str[cn]='A';
				else if(name_str[cn]=='Å') name_str[cn]=' ';
				else if(name_str[cn]==' ') name_str[cn]='a';
				/*
				// Sweden
				     if(name_str[cn]=='Z') name_str[cn]='Å';
				else if(name_str[cn]=='z') name_str[cn]='å';
				else if(name_str[cn]=='Å') name_str[cn]='Ä';
				else if(name_str[cn]=='å') name_str[cn]='ä';
				else if(name_str[cn]=='Ä') name_str[cn]='Ö';
				else if(name_str[cn]=='ä') name_str[cn]='ö';
				else if(name_str[cn]=='ö') name_str[cn]='A';
				else if(name_str[cn]=='Ö') name_str[cn]=' ';
				else if(name_str[cn]==' ') name_str[cn]='a';
				*/
				#endif
				else name_str[cn]++;
				key_2 = false;
			}
			if(key_4){ t_left = 0; if(cn) cn--; key_4 = false; }
			if(key_5){ falltrough = true; }
			if(key_6){ t_right = 0; if(name_str[cn+1]) cn++; key_6 = false; }
			if(key_8){
				t_down = 0;
				#ifdef ENGLISH
				     if(name_str[cn]=='a') name_str[cn]=' ';
				else if(name_str[cn]==' ') name_str[cn]='Z';
				else if(name_str[cn]=='A') name_str[cn]='z';
				#else
				
				// Norway
				     if(name_str[cn]=='a') name_str[cn]=' ';
				else if(name_str[cn]==' ') name_str[cn]='Å';
				else if(name_str[cn]=='A') name_str[cn]='å';
				else if(name_str[cn]=='Å') name_str[cn]='Ø';
				else if(name_str[cn]=='å') name_str[cn]='ø';
				else if(name_str[cn]=='Ø') name_str[cn]='Æ';
				else if(name_str[cn]=='ø') name_str[cn]='æ';
				else if(name_str[cn]=='Æ') name_str[cn]='Z';
				else if(name_str[cn]=='æ') name_str[cn]='z';
				/*
				// Sweden
				     if(name_str[cn]=='a') name_str[cn]=' ';
				else if(name_str[cn]==' ') name_str[cn]='Ö';
				else if(name_str[cn]=='A') name_str[cn]='ö';
				else if(name_str[cn]=='Ö') name_str[cn]='Ä';
				else if(name_str[cn]=='ö') name_str[cn]='ä';
				else if(name_str[cn]=='Ä') name_str[cn]='Å';
				else if(name_str[cn]=='ä') name_str[cn]='å';
				else if(name_str[cn]=='Å') name_str[cn]='Z';
				else if(name_str[cn]=='å') name_str[cn]='z';
				*/
				#endif
				else name_str[cn]--;
				key_8 = false;
			}
//			#ifdef OPENGL
//			#else
//			name->Print(name_str);
nameview->Print(name_str);
//			#endif
			char c = name_str[cn];
			name_str[cn]='\0';
			float w = font->GetWidth(name_str);
			name_str[cn]=c;
//			nameview->Set(Rect(.46f-w*.21f,.68f,1,1));
			float v = .196f-(w*.048f);
			nameview->Set(Rect(v,.7f,1,1));
nameframe->Set(Rect(.1f,/*.68f*/0,1,1));

//printf("%f,%d,(%f)\n",w,cn,v);

			left   ->Set(Rect((.3f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f,(.4f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f));
			right  ->Set(Rect((.5f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f,(.6f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f));
			up     ->Set(Rect((.4f-.2f)*1.1f*.9f+w*.149f+.06f,.4f*1.5f*.95f-.061f+.05f,(.5f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f));
			down   ->Set(Rect((.4f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f,(.5f-.2f)*1.1f*.9f+w*.149f+.06f,.7f*1.5f*.95f-.061f+.05f));
			center ->Set(Rect((.4f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f,(.5f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f));
			sleft  ->Set(Rect((.3f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f,(.4f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f));
			sright ->Set(Rect((.5f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f,(.6f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f));
			sup    ->Set(Rect((.4f-.2f)*1.1f*.9f+w*.149f+.06f,.4f*1.5f*.95f-.061f+.05f,(.5f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f));
			sdown  ->Set(Rect((.4f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f,(.5f-.2f)*1.1f*.9f+w*.149f+.06f,.7f*1.5f*.95f-.061f+.05f));
			sleftc ->Set(Rect((.4f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f,(.5f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f));
			srightc->Set(Rect((.4f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f,(.5f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f));
			supc   ->Set(Rect((.4f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f,(.5f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f));
			sdownc ->Set(Rect((.4f-.2f)*1.1f*.9f+w*.149f+.06f,.5f*1.5f*.95f-.061f+.05f,(.5f-.2f)*1.1f*.9f+w*.149f+.06f,.6f*1.5f*.95f-.061f+.05f));
/*
			#ifdef OPENGL
			#else
			if(t_left<.5f){   left->SetTransparency(1.0f-t_left);   sleft->SetTransparency(.48f+t_left); }
			else{  left->SetTransparency(.5f);  sleft->SetTransparency(1.0f); }
			if(t_right<.5f){ right->SetTransparency(1.0f-t_right); sright->SetTransparency(.48f+t_right); }
			else{ right->SetTransparency(.5f); sright->SetTransparency(1.0f); }
			if(t_up<.5f){       up->SetTransparency(1.0f-t_up);       sup->SetTransparency(.48f+t_up); }
			else{    up->SetTransparency(.5f);    sup->SetTransparency(1.0f); }
			if(t_down<.5f){   down->SetTransparency(1.0f-t_down);   sdown->SetTransparency(.48f+t_down); }
			else{  down->SetTransparency(.5f);  sdown->SetTransparency(1.0f); }
			#endif
*/
			if(t_left<.5f){   sleft ->SetTransparency( t_left*2.0f); sleftc  ->SetTransparency( t_left*2.0f); }
			else{             sleft ->SetTransparency(1.0f);         sleftc  ->SetTransparency(1.0f);         }
			if(t_right<.5f){  sright->SetTransparency(t_right*2.0f); srightc->SetTransparency(t_right*2.0f);  }
			else{             sright->SetTransparency(1.0f);         srightc->SetTransparency(1.0f);          }
			if(t_up<.5f){     sup   ->SetTransparency(   t_up*2.0f); supc   ->SetTransparency(   t_up*2.0f);  }
			else{             sup   ->SetTransparency(1.0f);         supc   ->SetTransparency(1.0f);          }
			if(t_down<.5f){   sdown ->SetTransparency( t_down*2.0f); sdownc ->SetTransparency( t_down*2.0f);  }
			else{             sdown ->SetTransparency(1.0f);         sdownc ->SetTransparency(1.0f);          }

			t_left  += pulse;
			t_right += pulse;
			t_up    += pulse;
			t_down  += pulse;

			if(!falltrough) break;
		}case BS_NAME_DEINITIALIZE:
			{
			int l = strlen(name_str);
			int rl = 0;
			for(int n=0; n<l; n++) if(name_str[n]==' ') rl++;
			#ifdef ENGLISH
			if(rl==l-1) sprintf(name_str,"Ano.");
			#else
			if(rl==l-1) sprintf(name_str,"Anonym");
			#endif
			}

			// sensur
			     if(!stricmp(name_str,"knulle"))	sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"pule"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"fitte"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"forpulte"))	sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"hore"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"kukk"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"pikk"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"pik"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"kuk"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"dritt"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"drit"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"bæsj"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"rashull"))	sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"rasshull"))	sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"rashul"))	sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"rasshul"))	sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"penis"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"balle"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"knull"))		sprintf(name_str,"Sensur");

			else if(!stricmp(name_str,"fuck"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"pussy"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"dick"))		sprintf(name_str,"Sensur");
			else if(!stricmp(name_str,"fucker"))	sprintf(name_str,"Sensur");

			nameview->ConsoleStream::Clear();
			nameview->Print(name_str);

			Detatch(arm);
			Detatch(baseframe);

//			Detatch(nameview);
Detatch(nameframe);
			nameview->Set(Rect(.1f,.7f,1,1));
			Detatch(left);
			Detatch(right);
			Detatch(up);
			Detatch(down);
			Detatch(center);
			Detatch(sleft);
			Detatch(sright);
			Detatch(sup);
			Detatch(sdown);
			Detatch(sleftc);
			Detatch(srightc);
			Detatch(supc);
			Detatch(sdownc);

			// pre play
			locked1=locked2=locked3=locked4=lock1=lock2=lock3=lock4=false;
			startplay = 0.0f;
			//lastlocked = false;
			holdstate = HOLD_SIX; //ALL;


		case BS_PLAYING:
			// BUG
//			printf("%d,%d,%d,%d\n",locked1,locked2,locked3,locked4);

//			locked1=locked2=locked3=locked4/*=lock1=lock2=lock3=lock4*/ = false;

			brainstate = BS_PLAYING_TICK;
			think = 0.0f;
			Apply(nameview);
			Apply(infoview);

Apply(scorev1000);
Apply(scorev0100);
Apply(scorev0010);
Apply(scorev0001);
/*
			nameview->SetColor(ARGB(0,0,0));
			scorev1000->SetColor(ARGB(0,0,0));
			scorev0100->SetColor(ARGB(0,0,0));
			scorev0010->SetColor(ARGB(0,0,0));
			scorev0001->SetColor(ARGB(0,0,0));
//			infoview->SetColor(ARGB(1,1,1));
			infoview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
*/
			Apply(roll1);
			Apply(roll2);
			Apply(roll3);
			Apply(roll4);
			if(locked1) Apply(button1);
			if(locked2) Apply(button2);
			if(locked3) Apply(button3);
			if(locked4) Apply(button4);
			Apply(baseframe);
			Apply(arm);
			//Apply(logonanim);
			//logonanim->SetFrame(logonanim->GetFrameCount()-1);

			// spinn
			if(logon){
				Spinn();
				logon = false;
			}
			#ifdef SIMULATE
			{
			int r = rand();
			if(r&1) Lock(0);
			if(r&2) Lock(1);
			if(r&4) Lock(2);
			if(r&8) Lock(3);
			}
			#endif

			nameview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
			scorev1000->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
			scorev0100->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
			scorev0010->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
			scorev0001->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
			infoview->SetColor(ARGB(0,0,0));
AddScore(0);

		case BS_PLAYING_TICK:{
//printf("BS_PLAYING_TICK\n");
			bool falltrough = false;

			#ifndef SIMULATE
			if((active&&simulate)||((!active)&&(!simulate))||logout){
				brainstate = BS_LOGOUT;
				falltrough = true;
			}
			#endif

			if(simulate){
				if(startplay>30.0f){
					brainstate = BS_LOGOUT;
					falltrough = true;
				}else{
					Spinn();
				}
				startplay+=pulse;
			}

			if(roll1->GetStatus()!=-1&&
			   roll2->GetStatus()!=-1&&
			   roll3->GetStatus()!=-1&&
			   roll4->GetStatus()!=-1){

				// check if we won last roll
				if(checkwin){

					checkwin = false;
					if( (roll1->GetStatus()==-1)||
						(roll2->GetStatus()==-1)||
						(roll3->GetStatus()==-1)||
						(roll4->GetStatus()==-1)){
						// We are in a roll, so break this tick

					}else{
/*
						switch(holdstate){
						case HOLD_ALL:
							if(locked1||locked2||locked3||locked4) holdstate = HOLD_TWO; //lastlocked=true;
							break;
						case HOLD_TWO:
							if(locked1||locked2||locked3||locked4) holdstate = HOLD_NONE;
							else holdstate = HOLD_ALL;
							break;
						case HOLD_NONE:
							holdstate = HOLD_ALL;
							break;
						}
*/

						if((roll1->GetStatus()==roll2->GetStatus())&&
								 (roll1->GetStatus()==roll3->GetStatus())&&
								 (roll1->GetStatus()==roll4->GetStatus())){
							// four of a kind
							if(roll1->GetStatus()){
								win = roll1->GetStatus()-1;
								switch(win){
								case 0: AddScore( 300); break;
								case 1: AddScore( 500); break;
								case 2: AddScore(1000); break;
								}
								if(!win) win++;
								brainstate = BS_WINN;
								falltrough = true;
							}
						}else if(roll1->GetStatus()||roll2->GetStatus()||roll3->GetStatus()||roll4->GetStatus()){
							// One or more of a kind
							switch(roll1->GetStatus()-1){
							case 0: AddScore(10); break;
							case 1: AddScore(25); break;
							case 2: AddScore(50); break;
							}
							switch(roll2->GetStatus()-1){
							case 0: AddScore(10); break;
							case 1: AddScore(25); break;
							case 2: AddScore(50); break;
							}
							switch(roll3->GetStatus()-1){
							case 0: AddScore(10); break;
							case 1: AddScore(25); break;
							case 2: AddScore(50); break;
							}
							switch(roll4->GetStatus()-1){
							case 0: AddScore(10); break;
							case 1: AddScore(25); break;
							case 2: AddScore(50); break;
							}
//if(!simulate) printf("one or more!\n");
							win = 0;
							brainstate = BS_WINN;
							falltrough = true;
							//retick = true;
						}
					}
				}else{
					//if(/*!lastlocked*/holdstate==HOLD_ALL){
/*
					switch(holdstate){
					case HOLD_ALL:
						if(lock1){
							lock1=false;
							locked1=!locked1;
							if(locked1) Apply(button1);
							else Detatch(button1);
						}
						if(lock2){
							lock2=false;
							locked2=!locked2;
							if(locked2) Apply(button2);
							else Detatch(button2);
						}
						if(lock3){
							lock3=false;
							locked3=!locked3;
							if(locked3) Apply(button3);
							else Detatch(button3);
						}
						if(lock4){
							lock4=false;
							locked4=!locked4;
							if(locked4) Apply(button4);
							else Detatch(button4);
						}
						break;
					case HOLD_TWO:
						int n = 0;
						if(locked1) n++;
						if(locked2) n++;
						if(locked3) n++;
						if(locked4) n++;
						if(n<2){
							if(lock1){
								lock1=false;
								locked1=!locked1;
								if(locked1) Apply(button1);
								else Detatch(button1);
							}
							if(lock2){
								lock2=false;
								locked2=!locked2;
								if(locked2) Apply(button2);
								else Detatch(button2);
							}
							if(lock3){
								lock3=false;
								locked3=!locked3;
								if(locked3) Apply(button3);
								else Detatch(button3);
							}
							if(lock4){
								lock4=false;
								locked4=!locked4;
								if(locked4) Apply(button4);
								else Detatch(button4);
							}
						}else{
							if(lock1){
								lock1=false;
								if(locked1){
									locked1=!locked1;
									Detatch(button1);
								}
							}
							if(lock2){
								lock2=false;
								if(locked2){
									locked2=!locked2;
									Detatch(button2);
								}
							}
							if(lock3){
								lock3=false;
								if(locked3){
									locked3=!locked3;
									Detatch(button3);
								}
							}
							if(lock4){
								lock4=false;
								if(locked4){
									locked4=!locked4;
									Detatch(button4);
								}
							}
						}
						break;
					}
*/
					#if 1
					int cnt = 0;
					switch(holdstate){
					case HOLD_SIX:  cnt = 6; break;
					case HOLD_FIVE: cnt = 5; break;
					case HOLD_FOUR: cnt = 4; break;
					case HOLD_TREE: cnt = 3; break;
					case HOLD_TWO:  cnt = 2; break;
					case HOLD_ONE:  cnt = 1; break;
					}
					int n = 0;
					if(locked1) n++;
					if(locked2) n++;
					if(locked3) n++;
					if(locked4) n++;
					if(n<cnt){
						if(lock1){
							lock1=false;
							locked1=!locked1;
							if(locked1) Apply(button1);
							else Detatch(button1);
						}
						if(lock2){
							lock2=false;
							locked2=!locked2;
							if(locked2) Apply(button2);
							else Detatch(button2);
						}
						if(lock3){
							lock3=false;
							locked3=!locked3;
							if(locked3) Apply(button3);
							else Detatch(button3);
						}
						if(lock4){
							lock4=false;
							locked4=!locked4;
							if(locked4) Apply(button4);
							else Detatch(button4);
						}
					}else{
						if(lock1){
							lock1=false;
							if(locked1){
								locked1=!locked1;
								Detatch(button1);
							}
						}
						if(lock2){
							lock2=false;
							if(locked2){
								locked2=!locked2;
								Detatch(button2);
							}
						}
						if(lock3){
							lock3=false;
							if(locked3){
								locked3=!locked3;
								Detatch(button3);
							}
						}
						if(lock4){
							lock4=false;
							if(locked4){
								locked4=!locked4;
								Detatch(button4);
							}
						}
					}
					#endif

					if(spinn){

						if(!locked1) roll1->Spinn();
						else roll1->Delay();
						if(!locked2) roll2->Spinn();
						else roll2->Delay();
						if(!locked3) roll3->Spinn();
						else roll3->Delay();
						if(!locked4) roll4->Spinn();
						else roll4->Delay();
						arm->Spinn();

						int holds = 0;
						if(locked1) holds++;
						if(locked2) holds++;
						if(locked3) holds++;
						if(locked4) holds++;
						switch(holdstate){
						case HOLD_SIX:
							switch(holds){
							case 0: holdstate = HOLD_SIX; break;
							case 1: holdstate = HOLD_FIVE; break;
							case 2: holdstate = HOLD_FOUR; break;
							case 3: holdstate = HOLD_TREE; break;
							case 4: holdstate = HOLD_TWO; break;
							}
							break;
						case HOLD_FIVE:
							switch(holds){
							case 0: holdstate = HOLD_SIX; break;
							case 1: holdstate = HOLD_FOUR; break;
							case 2: holdstate = HOLD_TREE; break;
							case 3: holdstate = HOLD_TWO; break;
							case 4: holdstate = HOLD_ONE; break;
							}
							break;
						case HOLD_FOUR:
							switch(holds){
							case 0: holdstate = HOLD_SIX; break;
							case 1: holdstate = HOLD_TREE; break;
							case 2: holdstate = HOLD_TWO; break;
							case 3: holdstate = HOLD_ONE; break;
							case 4: holdstate = HOLD_NONE; break;
							}
							break;
						case HOLD_TREE:
							switch(holds){
							case 0: holdstate = HOLD_SIX; break;
							case 1: holdstate = HOLD_TWO; break;
							case 2: holdstate = HOLD_ONE; break;
							case 3: holdstate = HOLD_NONE; break;
							case 4: holdstate = HOLD_NONE; break;
							}
							break;
						case HOLD_TWO:
							switch(holds){
							case 0: holdstate = HOLD_SIX; break;
							case 1: holdstate = HOLD_ONE; break;
							case 2: holdstate = HOLD_NONE; break;
							case 3: holdstate = HOLD_NONE; break;
							case 4: holdstate = HOLD_NONE; break;
							}
							break;
						case HOLD_ONE:
							switch(holds){
							case 0: holdstate = HOLD_SIX; break;
							case 1: holdstate = HOLD_NONE; break;
							case 2: holdstate = HOLD_NONE; break;
							case 3: holdstate = HOLD_NONE; break;
							case 4: holdstate = HOLD_NONE; break;
							}
							break;
						case HOLD_NONE:
							holdstate = HOLD_SIX;
							break;
						}

						if(locked1) Detatch(button1);
						if(locked2) Detatch(button2);
						if(locked3) Detatch(button3);
						if(locked4) Detatch(button4);
						locked1=locked2=locked3=locked4=lock1=lock2=lock3=lock4 = false;

						//if(locked1) lock1 = true;
						//if(locked2) lock2 = true;
						//if(locked3) lock3 = true;
						//if(locked4) lock4 = true;
						spinn = false;
						checkwin = true;
					//	think = 0;
					}else{
						// waiting for input

						if(think>5){
//							name->SetColor(ARGB(0,0,0));
nameview->SetColor(ARGB(0,0,0));
							scorev1000->SetColor(ARGB(0,0,0));
							scorev0100->SetColor(ARGB(0,0,0));
							scorev0010->SetColor(ARGB(0,0,0));
							scorev0001->SetColor(ARGB(0,0,0));
							//infoview->SetColor(ARGB(1,1,1));
							infoview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
							if(think>15) think -= 15;
							else if(think>10){
								infoview->ConsoleStream::Clear();
								#ifdef ENGLISH
								infoview->Print("Spinn with 5");
								#else
								infoview->Print("Spinn med 5");
								#endif
							}else{
							/*
								switch(holdstate){
								case HOLD_ALL:
									infoview->ConsoleStream::Clear();
									infoview->Print("Fire hold");
									break;
								case HOLD_TWO:
									infoview->ConsoleStream::Clear();
									infoview->Print("To hold");
									break;
								case HOLD_NONE:
									infoview->ConsoleStream::Clear();
									infoview->Print("Ingen hold");
									break;
								}
							*/
								#if 1
								switch(holdstate){
								case HOLD_SIX:
									infoview->ConsoleStream::Clear();
//									infoview->Print("Seks hold");
									#ifdef ENGLISH
									infoview->Print("Six holds");
									#else
									infoview->Print("Seks hold");
									#endif
									break;
								case HOLD_FIVE:
									infoview->ConsoleStream::Clear();
//									infoview->Print("Fem hold");
									#ifdef ENGLISH
									infoview->Print("Five holds");
									#else
									infoview->Print("Fem hold");
									#endif
									break;
								case HOLD_FOUR:
									infoview->ConsoleStream::Clear();
//									infoview->Print("Fire hold");
									#ifdef ENGLISH
									infoview->Print("Four holds");
									#else
									infoview->Print("Fire hold");
									#endif
									break;
								case HOLD_TREE:
									infoview->ConsoleStream::Clear();
//									infoview->Print("Tre hold");
									#ifdef ENGLISH
									infoview->Print("Three holds");
									#else
									infoview->Print("Tre hold");
									#endif
									break;
								case HOLD_TWO:
									infoview->ConsoleStream::Clear();
//									infoview->Print("To hold");
									#ifdef ENGLISH
									infoview->Print("Two holds");
									#else
									infoview->Print("To hold");
									#endif
									break;
								case HOLD_ONE:
									infoview->ConsoleStream::Clear();
									#ifdef ENGLISH
									infoview->Print("One hold");
									#else
									infoview->Print("Ett hold");
									#endif
									break;
								case HOLD_NONE:
									infoview->ConsoleStream::Clear();
									#ifdef ENGLISH
									infoview->Print("No holds");
									#else
									infoview->Print("Ingen hold");
									#endif
									break;
								}
								#endif
							}
						}else{
							//name->SetColor(ARGB(1,1,1));
							//scorev1000->SetColor(ARGB(1,1,1));
							//scorev0100->SetColor(ARGB(1,1,1));
							//scorev0010->SetColor(ARGB(1,1,1));
							//scorev0001->SetColor(ARGB(1,1,1));
//							name->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
nameview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
							scorev1000->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
							scorev0100->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
							scorev0010->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
							scorev0001->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
							infoview->SetColor(ARGB(0,0,0));
						}

						think += pulse;
					}
				}

			}else{
				think = 0; //+= pulse;
				spinn = false;

				// we are in a spinn
//				name->SetColor(ARGB(1,1,1));
//				scorev1000->SetColor(ARGB(1,1,1));
//				scorev0100->SetColor(ARGB(1,1,1));
//				scorev0010->SetColor(ARGB(1,1,1));
//				scorev0001->SetColor(ARGB(1,1,1));
//				name->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
nameview->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
				scorev1000->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
				scorev0100->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
				scorev0010->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
				scorev0001->SetColor(ARGB(255.0f/255.0f,212.0f/255.0f,95.0f/255.0f));
				infoview->SetColor(ARGB(0,0,0));
			}
/*
			if(think>1){
				if(think>6){
					infoview->ConsoleStream::Clear();
					infoview->Print("Spinn med 5");
					if(think>11) think-=11;
				}else{
					infoview->ConsoleStream::Clear();
					infoview->Print("Hold med 1,2,3,4");
				}
			}
*/
			roll1->Tick(pulse);
			roll2->Tick(pulse);
			roll3->Tick(pulse);
			roll4->Tick(pulse);
//			arm->Tick(pulse);

			//if(brainstate==BS_PLAYING_TICK) break;
			if(!falltrough) break;
		}
		case BS_PLAYING_DEINITIALIZE:
//printf("BS_PLAYING_DEINITIALIZE\n");
			Detatch(roll1);
			Detatch(roll2);
			Detatch(roll3);
			Detatch(roll4);
			Detatch(nameview);
			Detatch(infoview);
Detatch(scorev1000);
Detatch(scorev0100);
Detatch(scorev0010);
Detatch(scorev0001);
			if(locked1) Detatch(button1);
			if(locked2) Detatch(button2);
			if(locked3) Detatch(button3);
			if(locked4) Detatch(button4);
			//if(locked1||locked2||locked3||locked4) holdstate=HOLD_NONE; //lastlocked=true;
			//else holdstate=HOLD_ALL; //lastlocked=false;
/*
			switch(holdstate){
			case HOLD_ALL:
				if(locked1||locked2||locked3||locked4) holdstate = HOLD_TWO; //lastlocked=true;
				break;
			case HOLD_TWO:
				if(locked1||locked2||locked3||locked4) holdstate = HOLD_NONE;
				else holdstate = HOLD_ALL;
				break;
			case HOLD_NONE:
				holdstate = HOLD_ALL;
				break;
			}
*/
			Detatch(arm);
			//Detatch(logonanim);
			Detatch(baseframe);
			retick = true;
		break;

		case BS_LOGOUT:
//printf("BS_LOGOUT\n");
			brainstate = BS_LOGOUT_TICK;
			think = 0.0f;
			frame = 0;
			Apply(logoutanim);
		case BS_LOGOUT_TICK:
//printf("BS_LOGOUT_TICK\n");
			frame = int(think*25.0f);
			if(frame>=logoutanim->GetFrameCount()){
				// fall trough
			}else{
				logoutanim->SetFrame(frame);
				break;
			}
		case BS_LOGOUT_DEINITIALIZE:
//printf("BS_LOGOUT_DEINITIALIZE\n");
			Detatch(logoutanim);
			brainstate = BS_FREE;
			retick = true;

			if(score) hiscore->Add(name_str,score);
			score = 0;

			logout = false;
		break;

		case BS_WINN:
//printf("BS_WINN\n");
	//printf("%x, Winn!\n",this);
			brainstate = BS_WINN_TICK;
			think = 0.0f;
			//frame = 0;
			//Detatch(roll1);
			//Detatch(roll2);
			//Detatch(roll3);
			//Detatch(roll4);
			//Detatch(arm);
			//Detatch(calleranim);

			locked1=locked2=locked3=locked4=false;

			//win = roll1->GetStatus();
//if(!simulate) printf("Win %d\n",win);
			switch(win){
			case 0:
	//printf("%x\n",logonanim);
				Apply(flash);
				//Apply(logonanim);
				//logonanim->SetFrame(logonanim->GetFrameCount()-1);
				Apply(arm);
				Apply(baseframe);

				Apply(roll1);
				Apply(roll2);
				Apply(roll3);
				Apply(roll4);
				Apply(nameview);
				Apply(infoview);
				Apply(scorev1000);
				Apply(scorev0100);
				Apply(scorev0010);
				Apply(scorev0001);
				//if(locked1) Apply(button1);
				//if(locked2) Apply(button2);
				//if(locked3) Apply(button3);
				//if(locked4) Apply(button4);

				lock1=lock2=lock3=lock4=key_5= false;

				break;
			case 1:

//{
//char *str = new char[strlen("                                    ")+1];
//sprintf(str,"%s %d",name_str,score);
//st->Urgent(str);
//delete str;
//}
				//Apply(crazysym);
				Apply(crazyanim);
				holdstate = HOLD_NONE; //lastlocked = true;
				{
					for(int n=0; n<coins->GetCount(); n++){
						Coin *coin = (Coin*)coins->GetItem(n);
						coin->SetSize(1.0f);
						Apply(coin);
					}
				}

				break;
			case 2:
{
char *str = new char[strlen("                                    ")+1];
sprintf(str,"%s %d",name_str,score);
st->Urgent(str);
delete str;
}
				Apply(wowanim);
				holdstate = HOLD_NONE; //lastlocked = true;
				{
					for(int n=0; n<coins->GetCount(); n++){
						Coin *coin = (Coin*)coins->GetItem(n);
						coin->SetSize(1.5f);
						Apply(coin);
					}
				}
				break;
			};
		case BS_WINN_TICK:{
//printf("BS_WINN_TICK\n");
			bool falltrough = false;
			frame = int(think*25.0f);
			if(frame<0) frame = 0;		// 3/4-99 What on earth??
			Bitmap32 *an = 0;
			int n;
			switch(win){
			case 0:
				an = flashanim;
				roll1->Tick(pulse);
				roll2->Tick(pulse);
				roll3->Tick(pulse);
				roll4->Tick(pulse);
				if(frame>=an->GetFrameCount()){
					falltrough = true;
				}else{
					an->SetFrame(frame);
				}

				if(lock1||lock2||lock3||lock4||key_5) falltrough = true;
			break;
			case 1:
				an = crazyanim;
				if(frame>=(an->GetFrameCount()*3)){
					falltrough = true;
				}else{
					an->SetFrame(frame%an->GetFrameCount());
				}
				for(n=0; n<coins->GetCount(); n++) ((Coin*)coins->GetItem(n))->Tick(pulse);
			break;
			case 2:
				an = wowanim;
				if(frame>=(an->GetFrameCount()*4)){
					falltrough = true;
				}else{
					an->SetFrame(frame%an->GetFrameCount());
				}
				for(n=0; n<coins->GetCount(); n++) ((Coin*)coins->GetItem(n))->Tick(pulse);
			break;
			};
			if(!falltrough) break;
		}
		case BS_WINN_DEINITIALIZE:
//printf("BS_WINN_DEINITIALIZE\n");

	//printf("%x, ~Winn!\n",this);
			switch(win){
			case 0:
	//printf("%x\n",logonanim);
				//Detatch(logonanim);
				Detatch(flash);
				Detatch(arm);
				Detatch(baseframe);

				Detatch(roll1);
				Detatch(roll2);
				Detatch(roll3);
				Detatch(roll4);
				Detatch(nameview);
				Detatch(infoview);
				Detatch(scorev1000);
				Detatch(scorev0100);
				Detatch(scorev0010);
				Detatch(scorev0001);
				//if(locked1) Detatch(button1);
				//if(locked2) Detatch(button2);
				//if(locked3) Detatch(button3);
				//if(locked4) Detatch(button4);
				break;
			case 1:
				Detatch(crazyanim);
				//Detatch(crazysym);
				{
					for(int n=0; n<coins->GetCount(); n++){
						Detatch((Coin*)coins->GetItem(n));
					}
				}
				lock1=lock2=lock3=lock4 = false;
				break;
			case 2:
				Detatch(wowanim);
				{
					for(int n=0; n<coins->GetCount(); n++){
						Detatch((Coin*)coins->GetItem(n));
					}
				}
				lock1=lock2=lock3=lock4 = false;
				break;
			};
			brainstate = BS_PLAYING;
			retick = true;
		break;

	/*
		default:
			think = 0.0f;
			frame = 0;
			brainstate = BS_FREE;
	*/
		}
	}

	think+=pulse;

	if(!(win==0&&brainstate==BS_WINN))
		key_2=key_4=key_5=key_6=key_8 = false;
}

void Player::Spinn(void){
	spinn = true;
/*
	if(!locked1) roll1->Spinn();
	if(!locked2) roll2->Spinn();
	if(!locked3) roll3->Spinn();
	if(!locked4) roll4->Spinn();
	arm->Spinn();
*/
}

void Player::Lock(int n){
//printf("Lock %d\n",n);
	switch(n){
	case 0: lock1 = true; break; //locked1!=locked1; break;
	case 1: lock2 = true; break; //locked2!=locked2; break;
	case 2: lock3 = true; break; //locked3!=locked3; break;
	case 3: lock4 = true; break; //locked4!=locked4; break;
	}
}

void Player::AddScore(int n){
	score += n;
	char str[1024];
//	sprintf(str,"%s %d",name_str,score);
//	sprintf(str,"%s",name_str);
//	#ifdef OPENGL
//	#else
//	name->ConsoleStream::Clear();
//	name->Print(str);
//	#endif

	#ifdef OPENGL
	#else
	scorev1000->ConsoleStream::Clear();
	scorev0100->ConsoleStream::Clear();
	scorev0010->ConsoleStream::Clear();
	scorev0001->ConsoleStream::Clear();
	if(score>=1000){ sprintf(str,"%d",(score/1000)%10); scorev1000->Print(str); }
	if(score>= 100){ sprintf(str,"%d",(score/ 100)%10); scorev0100->Print(str); }
	if(score>=   1){ sprintf(str,"%d",(score/  10)%10); scorev0010->Print(str); }
	                 sprintf(str,"%d", score%10      ); scorev0001->Print(str);
	#endif

	//printf("%s\n",str);
}
/*
void Player::Key(const char c){
	printf("Key %c\n",c);
}
*/


