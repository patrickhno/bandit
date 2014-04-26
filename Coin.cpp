
#include <Interface/Bitmap32.h>
#include "Coin.h"
#include <posix/stdlib.h>
#include <math.h>

Coin::Coin() : View(Rect(0,0,.1f,.13f)){
	SetClearState(false);
	bm = new Bitmap32("spinning coin/coin",Bitmap32::cARGB);
	Apply(bm);
	ft = double(rand()%10000)/100.0f;
	mt = double(rand()%5000)/1000.0f;

	xo = .5f + ((rand()%1000)-500)/3000.0f;
	yo = .9f;

	float a = float((rand()%100)-50)/200.0f;
	yv = -cos(a);
	xv =  sin(a);
	size = 1.0f;
}

Coin::~Coin(){
	delete bm;
}

void Coin::Tick(float pulse){
	bm->SetFrame(int(ft*25)%bm->GetFrameCount());

	while(mt>(3.5f*size)) mt-=(3.5f*size);

//	float yv = -.1f;
	float yg = .3f;

	float x = xo + xv*mt * size;
	float y = yo + yv*mt + yg*mt*mt;
	Set(Rect(x-.05f,y-.065f,x+.05f,y+.065f));

	ft += pulse;
	mt += pulse;
}

