
#include <stdlib.h>

void bug_fix(){	// windows memory bug patch
	char *buf = (char*)malloc(1024*1024*32);
	for(int n=0; n<1024*1024*32; n++) buf[n]++;
	free(buf);
}

#include <windows.h>
#include <posix/stdlib.h>
#include <posix/stdio.h>
#include <posix/unistd.h>
#include <posix/time.h>
#include <Interface/WindowScreen.h>
#include <Interface/View.h>
#include <Interface/Bitmap32.h>
#include <Interface/DynamicArray.h>
#include <Interface/String.h>
#include <Interface/Font.h>
#include <Interface/Rect.h>
//#include "MovieScroller.h"
#include <Devices/Input/PhoneDevice.h>
#include "ScrollText.h"
#include "PlayField.h"
#include "Phone.h"
#include "Hiscore.h"
#include "Images.h"

//#define _DISABLED

#ifdef DLL

extern bool Initialized;

#include <Gameserver/Gameserver.h>

class Banditt : Message{
public:				Banditt();
					~Banditt();
//		void		InitLevels(int);
//		void		NextLevel(int);
		void		MessageLoop(void);
//		void		MessageReceived(double time, int Cmd, void *);
		void		MessageReceived(void);
//private:
		void		WarnShutDown();
		void		Refresh(class WindowScreen *);
//		int			AttatchHook,
//					DetatchHook,
//					ShutDownHook;
/*
class	DynamicArray
					*Rocks,
					*Rocks_sub,
					*Rocks_sub_sub,
					*AI_Rocks,
					*PlayerGeometries,
					*InfoViews,
					*ViewBunch,
					*BitmapBunch;
		int			Rocks_item,
					Rocks_sub_item,
					Rocks_sub_sub_item;
		int			RockCount;
*/
class	View		*View1;
/*
					*View2,
					*View4; //,*ScoreView;
class	Bitmap		*MeteoritesBitmap;
class	Geometry	*null,
					*Back;
class	PlayerAI	*AI_Player1,
					*AI_Player2,
					*AI_Player3,
					*AI_Player4;
class	Camera		*cam;
class	CameraAI	*camAI;
*/
		bool		quit,allowquit;
/*
class	Font		*font;
//struct	RefreshArgs *rfargs;
*/
		bool		bailout;
/*
class	Bitmap		*Info1,*Info2,*Info3;
class	ScoreViews	*Scores;
class	Scene		*scene;
*/
class	WindowScreen *scr;
/*		#ifdef	TV2
		View		*tv2v;
		Bitmap		*tv2bm;
		#endif
		#ifdef	SCHIBSTED
		View		*tv2v;
		Bitmap		*tv2bm;
		#endif
class	PhoneNumber	*pnum;
//class	Message		*msg;
*/
class	Message		*msg;

		Bitmap32		*picture;
		PhoneNumber		*phone;
		Images			*im;
		Hiscore			*hiscore;
		ScrollText		*st;
		PlayField		*pf;
		bool			sdwarn;
};

Banditt::Banditt() : Message(){

	msg = new Message();
	scr = 0;

//	ViewBunch = new DynamicArray();
//	BitmapBunch = new DynamicArray();

	SetName("BandittGame");

	printf("------------------------------------------------------------------------\n");
	printf(" Jack The Bandit, Copyright (C) 1998-1999 RealityMakers Entertainment as\n");
	printf("------------------------------------------------------------------------\n");

	#ifdef _DISABLED
	printf("Banditt is disabled!!!\n");
	#endif

	View1 = new View(Rect(0,0,1,1));
	View1->SetClearState(false);

	#ifndef _DISABLED
	View *back = new View(Rect(-40/800.0f,63.0f/600.0f,1+40/800.0f,1.0f-60.0f/600.0f));
	picture = new Bitmap32("Background/Background",Bitmap32::cRGB);
	back->Apply(picture);
	back->SetClearState(false);
	View1->Apply(back);

	View *scr = new View(Rect(0,.105f,1,.9f));
	scr->SetClearState(false);
	View1->Apply(scr);

//	View *top = new View(Rect(.03f,0,1,.09f));

	View *top = new View(Rect(0,0,1,63.0f/600.0f));
	View *topv = new View(Rect(-40.0f/800.0f,-(30.0f)/600.0f,1.0f+40.0f/800.0f,63.0f/600.0f/*1.0f+(90.0f-60.0f)/800.0f*/));
	Bitmap32 *topbm = new Bitmap32("Background/top",Bitmap32::cRGB);
	topv->Apply(topbm);
	//top->SetColor(ARGB(0,0,.1f));
	topv->SetClearState(false);
	top ->SetClearState(false);
	View1->Apply(topv);
	View1->Apply(top);

	View *view2 = new View(Rect(0,.9f,1,1));
	view2->SetClearState(true); //Color(ARGB(0,0,.1f));
	View1->Apply(view2);

//	View *bottom = new View(Rect(0,.9f,1,1));

	View *bottom = new View(Rect(-40.0f/800.0f,1.0f-60.0f/600.0f,1.0f+40.0f/800.0f,1.0f+(90.0f-60.0f)/800.0f));
	Bitmap32 *bottombm = new Bitmap32("Background/bottom",Bitmap32::cRGB);
	bottom->Apply(bottombm);
	//bottom->SetColor(ARGB(0,0,.1f));
	bottom->SetClearState(false);
	View1->Apply(bottom);

	View *view = new View(Rect(.73f,.23f,.99f,.85f));
	view->SetClearState(false); //Color(ARGB(0,0,.1f));
	top->Apply(view);
	hiscore = new Hiscore(view);

	phone = new PhoneNumber(Rect(.3f,0,.7f,1));
	top->Apply(phone);

	im = new Images(Rect(.03f,.19f,.3f,.84f));
	top->Apply(im);

	Font *font = new Font("Fonts/swed"); //Humnst777_BT_40");
	font->SetSize(.5f);

	View *view3 = new View(Rect(0,.15f,1,1));
	view2->Apply(view3);
	st = new ScrollText(view3);
	st->Apply(font);
//	st->Print("Scroll text............. abcdefghijklmnopqrstuvwxyz");

	pf = new PlayField(hiscore,View1,st);
	scr->Apply(pf);

	#endif
	printf("------------------------------------------------------------------------\n");
	printf("                      Jack The Bandit initalized\n");
	printf("------------------------------------------------------------------------\n");

	bug_fix();

	Initialized = true;

	sdwarn = false;
}

Banditt::~Banditt(){
	delete picture;
	delete phone;
	delete im;

	delete msg;
	delete View1;
}

void Banditt::MessageLoop(void){
	quit = false;
	while(!quit||!allowquit) sleep(1);
	printf("Leaving message loop. %d,%d\n",quit,allowquit);
}

void Banditt::WarnShutDown(){
	sdwarn = true;
}

#include <math.h>
#include <Interface/globals.h>

void Banditt::Refresh(WindowScreen *scr){
	//int t=int(float(clock())*(1.0f/CLOCKS_PER_SEC)*256.0f);

	static double otime = -1;
//	static double stime = -1;

	if(otime<0) otime = float(clock())*(1.0f/CLOCKS_PER_SEC);
//	if(stime<0) stime = otime;

//if(otime-stime>10.0f){
//__globals::SetSpeed(.01);
//stime += 1000.0f;
//}

	double time = float(clock())*(1.0f/CLOCKS_PER_SEC);
	#ifndef _DISABLED
	if(sdwarn){
		st->Urgent("Spelet blir avslutad om 5 minuter.");
		sdwarn = false;
	}
	hiscore->Tick(float(time-otime));
	st->Tick(float(time-otime));
	pf->Tick(float(time-otime));			// ???
	phone->Tick(float(time-otime));			// OK1
	im->Tick(float(time-otime));			// OK2
	#endif
	otime = time;

	scr->Refresh();
//scr->SetScale(sin(time)/2.0f+.5f);
}

struct RefreshArgs{
	WindowScreen	*scr;
	Banditt			*game;
	bool			bailout;
};

#include <Interface/Thread.h>

class RefreshThread : Thread{
public:		RefreshThread(WindowScreen *scr, Banditt *game);
			~RefreshThread();
void		main(void);
private:
	WindowScreen	*scr;
	Banditt			*game;
};

RefreshThread::RefreshThread(WindowScreen *_scr, Banditt *_game) : Thread(){
	scr = _scr;
	game = _game;
}

RefreshThread::~RefreshThread(){
}

/*
#ifndef _DEBUG
#define FIREMAN
#ifdef FIREMAN
#include <Fireman/Fireman.h>
#include <3dapi/Network/Socket.h>
//bool ping_fireman = false;
#endif
#endif
*/

#include <Watchdog.h>

void RefreshThread::main(void){
	printf("RefreshThread:a\n");
/*
	#ifdef FIREMAN
	int proc = GetCurrentProcessId();
	Socket *socket = new Socket();
	while(!socket->Connect("localhost:50001"));
	Message *msg = new Message(socket);
	msg->AddPacket(Fireman::SAVE_ME);
	msg->Add((int32)proc);
	msg->Send();
	//ping_fireman = true;
	double ping_time = Kernel::Time();
	#endif
*/
	Watchdog *wd = new Watchdog();

	printf("Banditt: Entering game loop!\n");
//printf("a\n");
	while(!game->bailout){

/*		//printf("b\n");
#if 1 // reboot test
//printf("c\n");
		#ifdef FIREMAN
//printf("d\n");
		//if(ping_fireman){
			double ping = Kernel::Time();
//printf("%f\n",ping-ping_time);
			if(ping-ping_time>10.0f){
				ping_time = ping;
				msg->AddPacket(Fireman::PULSE);
				msg->Add((int32)proc);
				msg->Send();
//				printf("ping (%f)!\n",ping);
//volatile int *adr;
//adr = (int*)4;
//*adr += 10;
			}
			//ping_fireman = false;
		//}
		#endif
#endif
*/
		wd->Touch();
		game->Refresh(scr);
	}
	printf("Leaving game loop!\n");
/*
	#ifdef FIREMAN
	msg->AddPacket(Fireman::LEAVE_ME);
	msg->Add((int32)proc);
	msg->Send();
	delete msg;
	delete socket;
	#endif
*/
	delete wd;
	game->bailout = false;
}

#include <Interface/Garbage.h>
#include <Interface/globals.h>

void Banditt::MessageReceived(void){
	int cnt = GetReceivedCount();
	char *buf = (char*)GetReceivedBuffer();
	for(int n=0; n<cnt; n++){
		switch(GetReceivedCommand(n)){
		case GAME_INITIALIZE:
			printf("GAME_INITIALIZE\n");
		break;
		case GAME_SHUTDOWN:
			printf("GAME_SHUTDOWN\n");
			quit=true;
		break;
		case GAME_START:{
//__globals::SetSpeed(.1);
			allowquit=false;
			printf("GAME_START:a\n");
			float scale;
			float maxtime;//,zoom;
			int32 maxplayers,s,_st,_pn;
			char *scrolltext,*phonenr;
//printf("a!\n");
			Get(s);
			Get(maxtime);
			Get(maxplayers);
			Get(scale);
			Get(_st);
			Get(_pn);
			float ConnectionCharge,ChargePerMin;
			Get(ConnectionCharge);
			Get(ChargePerMin);
			scrolltext = (char*)_st;
			phonenr = (char*)_pn;
/*
printf("b!\n");
printf("screen = %x\n",s);
printf("maxtime = %f\n",maxtime);
printf("maxplayers = %d\n",maxplayers);
printf("scale = %f\n",scale);
printf("scrolltext = %s\n",scrolltext);
printf("phonenr = %s\n",phonenr);
*/
	#ifndef _DISABLED
	#ifdef OPENGL
	#else
	st->ConsoleStream::Clear();
	if(scrolltext) st->Print(scrolltext);
	#endif
	phone->SetNumber(phonenr);
	phone->SetConnectionCharge(ConnectionCharge);
	phone->SetCharge(ChargePerMin);
	#endif
//extern float dialogic_max_time;
//extern int dialogic_max_players;
//dialogic_max_time = maxtime;
if(maxplayers>30) maxplayers = 30;
if(maxplayers<0) maxplayers = 0;
//dialogic_max_players = maxplayers;

	msg->AddPacket(Phone::OPEN);
	msg->Add(maxplayers);
	msg->Add(maxtime);
	msg->SendTo("/Devices/Input/Dialogic");
//printf("c!\n");

//			Get(zoom);
//printf("%f,%d,%f\n",maxtime,maxplayers,zoom);

//			Add(zoom);
//			SendTo("/Devices/Glide");
//			msg->Add(zoom);
//			msg->SendTo("/Devices/Glide");

			printf("GAME_START:b\n");
//			if(!scr) scr = new WindowScreen();
			scr = (WindowScreen*)s;
//printf("1\n");
			scr->SetScale(scale);
//printf("2\n");
			scr->SetClearState(false);
//printf("3\n");
			scr->Apply(View1);
//printf("4\n");
//printf("d!\n");

			printf("GAME_START:c\n");
			//rfargs = new RefreshArgs;
			bailout = false;
/*
			rfargs->scr = scr;
			rfargs->game = this;

			DWORD dwThreadID;
			CreateThread(
				NULL,
				0,
				(LPTHREAD_START_ROUTINE)RefreshThread,
				rfargs,
				0,
				&dwThreadID);
*/
			Leftover(new RefreshThread(scr,this));
			printf("GAME_START:d(%x)\n",scr);
		}break;
		case GAME_BREAK:
			printf("GAME_BREAK\n");
			msg->AddPacket(Phone::CLOSE);
			msg->SendTo("/Devices/Input/Dialogic");
			WarnShutDown();
		break;
		case GAME_STOP:

			printf("GAME_STOP\n");

			msg->AddPacket(Phone::CLOSE);
			msg->SendTo("/Devices/Input/Dialogic");

//printf("GAME_STOP:a (%x)\n",scr);
			scr->Detatch(View1);	// fixme: Crashes in GameServer
//printf("GAME_STOP:b\n");
			bailout = true;
//printf("GAME_STOP:c\n");
//			while(bailout) sleep(100);
//printf("GAME_STOP:d\n");
//			if(scr) delete scr;
//			scr = 0;
			//delete rfargs;
//printf("GAME_STOP:e\n");
			allowquit=true;
printf("GAME_STOP:f\n");
		break;
		//case PROPERTIES;
		//	Get(buf,len);
		//break;
		}
	}
}

void main(int,char**){
	printf("main!\n");
	Message *msg = new Message();
	Banditt *game = new Banditt();
	#ifndef _DEBUG
	msg->AddPacket(1);
	msg->SendTo("LogCollector");
	#endif
	game->MessageLoop();
	printf("Deleting game\n");
	delete game;
	printf("Leaving\n");
	delete msg;
}


#else

class Screen : public WindowScreen{
public:				Screen();
					~Screen();
private:
		void			MessageReceived(void);
		bool			quit;
		Bitmap32		*picture;
		PhoneNumber		*phone;
		Images			*im;
};

Screen::Screen() : WindowScreen(){
View *back = new View(Rect(0,63.0f/600.0f,1,1.0f-60.0f/600.0f));
	picture = new Bitmap32("Background/Background",Bitmap32::cRGB);
	back->Apply(picture);
	back->SetClearState(false);
	Apply(back);

//	View *v = new View(Rect(0,.9f,.5f,1));
//	v->SetClearState(false);
//	Apply(v);
//	Bitmap32 *scrollfront = new Bitmap32("Background/Textbackground",Bitmap32::cARGB);
//	v->Apply(scrollfront);

View *scr = new View(Rect(0,.105f,1,.9f));
scr->SetClearState(false);
	Apply(scr);

//	View *top = new View(Rect(.03f,0,1,.09f));
	View *top = new View(Rect(0,0,1,63.0f/600.0f));
Bitmap32 *topbm = new Bitmap32("Background/top",Bitmap32::cRGB);
top->Apply(topbm);
	//top->SetColor(ARGB(0,0,.1f));
	top->SetClearState(false);
	Apply(top);

	View *view2 = new View(Rect(0,.92f,1,1));
	view2->SetClearState(false); //Color(ARGB(0,0,.1f));
	Apply(view2);

//	View *bottom = new View(Rect(0,.9f,1,1));
	View *bottom = new View(Rect(-40.0f/800.0f,1.0f-60.0f/600.0f,1.0f+40.0f/800.0f,1.0f+(90.0f-60.0f)/800.0f));
Bitmap32 *bottombm = new Bitmap32("Background/textbackground",Bitmap32::cRGB);
bottom->Apply(bottombm);
	//bottom->SetColor(ARGB(0,0,.1f));
	bottom->SetClearState(false);
	Apply(bottom);

	View *view = new View(Rect(.74f,.20f,.9f,.88f));
	view->SetClearState(false); //Color(ARGB(0,0,.1f));
	top->Apply(view);

	phone = new PhoneNumber(Rect(.3f,0,.7f,1));
	top->Apply(phone);

	im = new Images(Rect(.01f,.19f,.076f,.84f));
	top->Apply(im);
/*
	View *view2 = new View(Rect(0,.2f,1,1));
	view2->SetClearState(false); //Color(ARGB(0,0,.1f));
	bottom->Apply(view2);
*/
	Font *font = new Font("Fonts/swed"); //Humnst777_BT_40");
	font->SetSize(.5f);

	Hiscore *hiscore = new Hiscore(view);
	PlayField *pf = new PlayField(hiscore,this);
	scr->Apply(pf);

/*
	MovieScroller *scroll = new MovieScroller(view);
	scroll->Apply(font);
	scroll->Print(
		"1.  Player 1\n"
		"2.  Player 2\n"
		"3.  Player 3\n"
		"4.  Player 4\n"
		"5.  Player 5\n"
		"6.  Player 6\n"
		"7.  Player 7\n"
		"8.  Player 8\n"
		"9.  Player 9\n"
		"10. Player 10");
*/

	ScrollText *st = new ScrollText(view2);
	st->Apply(font);
	st->Print("Scroll text............. abcdefghijklmnopqrstuvwxyz");
/*
//	View *bottom2 = new View(Rect(-40.0f/800.0f,1.0f-60.0f/600.0f,1.0f+40.0f/800.0f,1.0f+(90.0f-60.0f)/800.0f));
	View *bottom2 = new View(Rect(0,0,1,1));
//Bitmap32 *bottombm = new Bitmap32("Background/textbackground",Bitmap32::cRGB);
bottom2->Apply(bottombm);
	//bottom->SetColor(ARGB(0,0,.1f));
	bottom2->SetClearState(false);
	st->Apply(bottom2);
*/
/*
	Bitmap32 *leftbm = new Bitmap32("Background/Left",Bitmap32::cRGB);
	View *left = new View(Rect(-40.0f/880.0f,0,(-40.0f+102.0f)/880.0f,1));
	left->SetClearState(false);
	left->Apply(leftbm);
	view2->Apply(left);

	Bitmap32 *rightbm = new Bitmap32("Background/Right",Bitmap32::cRGB);
	View *right = new View(Rect(1-(99.0f-40.0f)/880.0f,0,1+40.0f/880.0f,1));
	right->SetClearState(false);
	right->Apply(rightbm);
	view2->Apply(right);
*/

	quit = false;
	double otime = Time();
	while(!quit){
		double time = Time();
		//scroll->Tick(float(time-otime));
		hiscore->Tick(float(time-otime));
//		st->Tick(float(time-otime));
		pf->Tick(float(time-otime));
		phone->Tick(float(time-otime));
		im->Tick(float(time-otime));
		otime = time;

		Refresh();
//if(time>30.0f) quit = true;
	}
}

Screen::~Screen(){
	delete picture;
	delete phone;
	delete im;
}

void Screen::MessageReceived(void){
	quit = true;
}

void main(int,char**){
	Phone *phone = new Phone();
	phone->CreateVirtual("/Devices/Input/Dialogic");
	delete new Screen();
	delete phone;
}

#endif

