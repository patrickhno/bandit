
#include <posix/stdlib.h>
#include <posix/stdio.h>
#include <posix/string.h>
#include <Interface/Rect.h>
#include <Interface/DynamicArray.h>
#include <Devices/Input/PhoneDevice.h>
#include <math.h>
#include "PlayField.h"
#include "Player.h"

//#define SINGLE_LINE_TEST
#define NEWSCALE

PlayField::PlayField(Hiscore *h, View *parent, ScrollText *st) : View(Rect(0,0,1,1)), Message(){ //-.25f,-.25f,1.25f,1.25f)){

//	Listen("/Devices/Input/Dialogic");
	SetClearState(false);

	#ifdef NEWSCALE

	parent->Apply(this);
	players  = new DynamicArray();
	channels = new DynamicArray();
	int dir = 0;
	int x = 1;
	int y = 1;
	int xr = 2;
	int yb = 2;
	int xl = 0;
	int yt = 0;
	int n = 1;
	for(int _x=0; _x<4; _x++){
		for(int _y=0; _y<4; _y++){
			Player *pl = new Player(h,Rect((float(x)/4.0f),(float(y)/4.0f),(float(x+1)/4.0f),(float(y+1)/4.0f)),st,n++);
			Apply(pl);
			players->Add(pl);
			channels->Add(0);
			switch(dir){
			case 0: if(++x==xr){ dir++; xr++; } break;
			case 1: if(++y==yb){ dir++; yb++; } break;
			case 2: if(--x==xl){ dir++; xl--; } break;
			case 3: if(--y==yt){ dir=0; yt--; } break;
			}
		}
	}

	#else

	parent->Apply(this);
	players  = new DynamicArray();
	channels = new DynamicArray();
	int dir = 0;
	int x = 1;
	int y = 1;
	int xr = 2;
	int yb = 2;
	int xl = 1;
	int yt = 1;
	int n = 1;
	for(int _x=0; _x<4; _x++){
		for(int _y=0; _y<4; _y++){
			Player *pl = new Player(h,Rect((float(x)/4.0f),(float(y)/4.0f),(float(x+1)/4.0f),(float(y+1)/4.0f)),st,n++);
			Apply(pl);
			players->Add(pl);
			channels->Add(0);
			switch(dir){
			case 0: if(++x==xr){ dir++; xr++; } break;
			case 1: if(++y==yb){ dir++; yb++; } break;
			case 2: if(--x==xl){ dir++; xl--; } break;
			case 3: if(--y==yt){ dir=0; yt--; x--; y--; } break;
			}
		}
	}
	#endif
	foo = 0;
	player_count=0;

	zoom = .5f;
	xz = yz = 0;

	Listen("/Devices/Input/Dialogic");
}

PlayField::~PlayField(){
	int cnt = players->GetCount();
	for(int n=0; n<cnt; n++){
		Player *pl = (Player*)players->GetItem(n);
		delete pl;
	}
	delete players;
}

void PlayField::Tick(float pulse){

	#ifdef NEWSCALE

	int zstate = 0;
	int cnt = players->GetCount();
	for(int n=4; n<9; n++){
		Player *pl = (Player*)players->GetItem(n);
		if(pl->IsActive()) zstate = 1;
	}
	for(n=9; n<cnt; n++){
		Player *pl = (Player*)players->GetItem(n);
		if(pl->IsActive()) zstate = 2;
	}

	float wzoom,wxz,wyz;
	switch(zstate){
	case 0:
		wzoom = 1.0f;
		wxz = wyz = 0;
	break;
	case 1:
		wzoom = .65f;
		wxz = .175f;
		wyz = .175f;
	break;
	case 2:
		wzoom = .5f;
		wxz = wyz = 0;
	break;
	}

	float _zoom = wzoom-zoom;
	if(_zoom>0) zoom += ((_zoom)/8.0f)*(pulse>1.0f?1.0f:pulse);
	else        zoom += ((_zoom)/4.0f)*(pulse>1.0f?1.0f:pulse);
	float _xz = wxz-xz;
	if(_xz>0)   xz   += ((  _xz)/8.0f)*(pulse>1.0f?1.0f:pulse);
	else        xz   += ((  _xz)/4.0f)*(pulse>1.0f?1.0f:pulse);
	float _yz = wyz-yz;
	if(_yz>0)   yz   += ((  _yz)/8.0f)*(pulse>1.0f?1.0f:pulse);
	else        yz   += ((  _yz)/4.0f)*(pulse>1.0f?1.0f:pulse);

	Set(Rect(-zoom+.5f+xz,-zoom+.5f+yz,zoom+.5f+xz,zoom+.5f+yz));

	#else

	float wzoom = 1.0f;

	int cnt = players->GetCount();
	for(int n=4; n<cnt; n++){				// why not 3????????
		Player *pl = (Player*)players->GetItem(n);
		if(pl->IsActive()) wzoom = .5f;
	}

//	float zoom = player_count>4 ? .5f : 1.0f;

	float _zoom = wzoom-zoom;
	if(_zoom>0) zoom += ((_zoom)/10.0f)*(pulse>1.0f?1.0f:pulse);
	else        zoom += ((_zoom)/ 5.0f)*(pulse>1.0f?1.0f:pulse);

//	foo+=pulse;
//	Set(Rect(-sin(foo)*.2f-.21f,-sin(foo)*.2f-.21f,.21f+1+sin(foo)*.2f,.21f+1+sin(foo)*.2f));

	Set(Rect(-zoom+.5f,-zoom+.5f,zoom+.5f,zoom+.5f));

	#endif

	cnt = players->GetCount();
	for(n=0; n<cnt; n++){
		Player *pl = (Player*)players->GetItem(n);
		pl->Tick(pulse);
	}
}

void PlayField::Input(int chan, int val){
	Player *pl = (Player*)players->GetItem(chan);
	switch(val){
	case 0: pl->Lock(0);  break;
	case 1: pl->Lock(1);  break;
	case 2: pl->Lock(2);  break;
	case 3: pl->Lock(3);  break;
	case 4: pl->Spinn();  break;
	case 5: pl->Logon();  break;
	case 6: pl->Logout(); break;
	}
}

void PlayField::MessageReceived(void){
	int cnt = GetReceivedCount();
	char *buf = (char*)GetReceivedBuffer();
	for(int n=0; n<cnt; n++){
		switch(GetReceivedCommand(n)){
		case INPUT_DIGITAL_DOWN:{
			if(!buf){
				printf("PlayField::MessageReceived: No buffer!\n");
				break;
			}
			int len = *(int16*)buf;
			buf+=sizeof(int16);
			char *str = new char[len+1];
			for(int n=0; n<len; n++) str[n]=*buf++;
			str[len]='\0';
//			printf("%s down\n",str);

			char *key = &str[1];
			int chan = 0;
			bool done = false;
			do{
				switch(*key++){
				case '0': chan*=10; break;
				case '1': chan*=10; chan+=1; break;
				case '2': chan*=10; chan+=2; break;
				case '3': chan*=10; chan+=3; break;
				case '4': chan*=10; chan+=4; break;
				case '5': chan*=10; chan+=5; break;
				case '6': chan*=10; chan+=6; break;
				case '7': chan*=10; chan+=7; break;
				case '8': chan*=10; chan+=8; break;
				case '9': chan*=10; chan+=9; break;
				default: done=true;
				}
			}while(!done);

if(chan>=channels->GetCount()){
//	printf("PlayField::MessageReceived(): Channel overflow!\n");
	delete str;
	return;
}

//			printf("%s(%d) down\n",key,chan);

			if(!strcmp(key,"!Hook")){
//printf("PlayField: hookof %d\n",chan);
				#ifndef SINGLE_LINE_TEST
				if(GetChannel(chan)) printf("PlayField: Channel allready active (%d)!\n",chan);
				else{
				#endif
					//((Player*)players->GetItem(0))->Logon();
					Player *player = AllocateChannel(chan);
					player->Logon();
				#ifndef SINGLE_LINE_TEST
				}
				#endif
			}
			else if(!strcmp(key,"1")){ if(GetChannel(chan)) ((Player*)GetChannel(chan))->Lock(0); }
			else if(!strcmp(key,"2")){ if(GetChannel(chan)) ((Player*)GetChannel(chan))->Lock(1); }
			else if(!strcmp(key,"3")){ if(GetChannel(chan)) ((Player*)GetChannel(chan))->Lock(2); }
			else if(!strcmp(key,"4")){ if(GetChannel(chan)) ((Player*)GetChannel(chan))->Lock(3); }
			else if(!strcmp(key,"5")){ if(GetChannel(chan)) ((Player*)GetChannel(chan))->Spinn(); }
			if(GetChannel(chan)) ((Player*)GetChannel(chan))->DigitDown(key);

/*
			if(!strcmp(key,"!Hook")) state[chan] = '!';
			if(!strcmp(key,"0"))     state[chan] = '0';
			if(!strcmp(key,"1"))     state[chan] = '1';
			if(!strcmp(key,"2"))     state[chan] = '2';
			if(!strcmp(key,"3"))     state[chan] = '3';
			if(!strcmp(key,"4"))     state[chan] = '4';
			if(!strcmp(key,"5"))     state[chan] = '5';
			if(!strcmp(key,"6"))     state[chan] = '6';
			if(!strcmp(key,"7"))     state[chan] = '7';
			if(!strcmp(key,"8"))     state[chan] = '8';
			if(!strcmp(key,"9"))     state[chan] = '9';
			if(!strcmp(key,"#"))     state[chan] = '#';
			if(!strcmp(key,"*"))     state[chan] = '*';
*/
			delete str;

		}break;
		case INPUT_DIGITAL_UP:{
			if(!buf){
				printf("PlayField::MessageReceived: No buffer!\n");
				break;
			}
			int len = *(int16*)buf;
			buf+=sizeof(int16);
			char *str = new char[len+1];
			for(int n=0; n<len; n++) str[n]=*buf++;
			str[len]='\0';
//			printf("%s up\n",str);

			char *key = &str[1];
			int chan = 0;
			bool done = false;
			do{
				switch(*key++){
				case '0': chan*=10; break;
				case '1': chan*=10; chan+=1; break;
				case '2': chan*=10; chan+=2; break;
				case '3': chan*=10; chan+=3; break;
				case '4': chan*=10; chan+=4; break;
				case '5': chan*=10; chan+=5; break;
				case '6': chan*=10; chan+=6; break;
				case '7': chan*=10; chan+=7; break;
				case '8': chan*=10; chan+=8; break;
				case '9': chan*=10; chan+=9; break;
				default: done=true;
				}
			}while(!done);

if(chan>=channels->GetCount()){
//	printf("PlayField::MessageReceived(): Channel overflow!\n");
	delete str;
	return;
}

//			printf("%s(%d) up\n",key,chan);

//			if(!strcmp(key,"!Hook")) ((Player*)players->GetItem(0))->Logout();
			if(GetChannel(chan)) ((Player*)GetChannel(chan))->DigitUp(key);

			#ifndef SINGLE_LINE_TEST
			if(!strcmp(key,"!Hook")){
//printf("PlayField: hookon %d\n",chan);
				Player *player = GetChannel(chan);
				if(player){
					player->Logout();
					FreeChannel(chan);
				}else printf("PlayField: No player in channel %d!\n",chan);
			}
			#endif

/*
			if(!strcmp(key,"!Hook")) state[chan] = '-';
			else
			if(!strcmp(key,"0"))     state[chan] = '!';
			if(!strcmp(key,"1"))     state[chan] = '!';
			if(!strcmp(key,"2"))     state[chan] = '!';
			if(!strcmp(key,"3"))     state[chan] = '!';
			if(!strcmp(key,"4"))     state[chan] = '!';
			if(!strcmp(key,"5"))     state[chan] = '!';
			if(!strcmp(key,"6"))     state[chan] = '!';
			if(!strcmp(key,"7"))     state[chan] = '!';
			if(!strcmp(key,"8"))     state[chan] = '!';
			if(!strcmp(key,"9"))     state[chan] = '!';
			if(!strcmp(key,"#"))     state[chan] = '!';
			if(!strcmp(key,"*"))     state[chan] = '!';
*/
			delete str;
		}break;
		}
	}
}

Player *PlayField::AllocateChannel(const int chan){
//printf("%d: Alloc()\n",chan);
#if 0
	Player *player;
	int cnt = players->GetCount();
	for(int n=0; n<cnt; n++){
		player = (Player*)players->GetItem(n);
		if(!player->IsActive()) break;
	}
#else
	Player *player = (Player*)players->GetItem(chan);
	if(player->IsActive()) printf("PlayField::AllocateChannel: Fatal: Player allready active!\n");
#endif
	channels->SetItem(chan,player);
	player_count++;
	return player;
}

void PlayField::FreeChannel(const int chan){
//printf("%d: Free()\n",chan);
	channels->SetItem(chan,0);
	player_count--;
}

Player *PlayField::GetChannel(const int chan){
//printf("%d: Get()\n",chan);
	return (Player*)channels->GetItem(chan);
}

