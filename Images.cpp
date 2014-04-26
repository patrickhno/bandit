
#include <posix/stdlib.h>
#include <posix/stdio.h>
#include <Interface/ARGB.h>
#include <Interface/Rect.h>
#include <Interface/Font.h>
#include <Interface/Bitmap.h>
#include <Interface/Bitmap32.h>
#include "Images.h"
#include "Image.h"

Images::Images(class Rect &rect) : View(rect){
#if 1
	SetClearState(false);
/*
	apple  = new Bitmap32("images/apple" ,Bitmap32::cARGB);
	banana = new Bitmap32("images/banana",Bitmap32::cARGB);
	bell   = new Bitmap32("images/bell"  ,Bitmap32::cARGB);
	cherry = new Bitmap32("images/cherry",Bitmap32::cARGB);
	lemon  = new Bitmap32("images/lemon" ,Bitmap32::cARGB);
	pear   = new Bitmap32("images/pear"  ,Bitmap32::cARGB);
*/
	view1 = new View(Rect( .00f*2.0f,0,.12f*2.0f,1));
	view2 = new View(Rect( .03f*2.0f,0,.15f*2.0f,1));
	view3 = new View(Rect( .06f*2.0f,0,.18f*2.0f,1));
	view4 = new View(Rect( .09f*2.0f,0,.22f*2.0f,1));
	view1->SetClearState(false);
	view2->SetClearState(false);
	view3->SetClearState(false);
	view4->SetClearState(false);
	Apply(view1);
	Apply(view2);
	Apply(view3);
	Apply(view4);

//	apple1  = new Image("images/apple");
//	apple2  = new Image("images/apple");
//	apple3  = new Image("images/apple");
//	apple4  = new Image("images/apple");
//	banana1 = new Image("images/banana");
//	banana2 = new Image("images/banana");
//	banana3 = new Image("images/banana");
//	banana4 = new Image("images/banana");
	bell1   = new Image("scoresymbols/bell");
	bell2   = new Image("scoresymbols/bell");
	bell3   = new Image("scoresymbols/bell");
	bell4   = new Image("scoresymbols/bell");
	cherry1 = new Image("scoresymbols/cherry");
	cherry2 = new Image("scoresymbols/cherry");
	cherry3 = new Image("scoresymbols/cherry");
	cherry4 = new Image("scoresymbols/cherry");
//	lemon1  = new Image("images/lemon");
//	lemon2  = new Image("images/lemon");
//	lemon3  = new Image("images/lemon");
//	lemon4  = new Image("images/lemon");
//	pear1   = new Image("images/pear");
//	pear2   = new Image("images/pear");
//	pear3   = new Image("images/pear");
//	pear4   = new Image("images/pear");
//	five1   = new Image("images/fem");
//	five2   = new Image("images/fem");
//	five3   = new Image("images/fem");
//	five4   = new Image("images/fem");
	seven1  = new Image("scoresymbols/seven");
	seven2  = new Image("scoresymbols/seven");
	seven3  = new Image("scoresymbols/seven");
	seven4  = new Image("scoresymbols/seven");
//	view1->Apply(apple1);  view2->Apply(apple2);  view3->Apply(apple3);  view4->Apply(apple4);
//	view1->Apply(banana1); view2->Apply(banana2); view3->Apply(banana3); view4->Apply(banana4);
	view1->Apply(bell1);   view2->Apply(bell2);   view3->Apply(bell3);   view4->Apply(bell4);
	view1->Apply(cherry1); view2->Apply(cherry2); view3->Apply(cherry3); view4->Apply(cherry4);
//	view1->Apply(lemon1);  view2->Apply(lemon2);  view3->Apply(lemon3);  view4->Apply(lemon4);
//	view1->Apply(pear1);   view2->Apply(pear2);   view3->Apply(pear3);   view4->Apply(pear4);
//	view1->Apply(five1);   view2->Apply(five2);   view3->Apply(five3);   view4->Apply(five4);
	view1->Apply(seven1);  view2->Apply(seven2);  view3->Apply(seven3);  view4->Apply(seven4);
	t=0;

	p10bm   = new Bitmap32("scorevalues/10/10P",Bitmap32::cARGB);
	p25bm   = new Bitmap32("scorevalues/25/25P",Bitmap32::cARGB);
	p50bm   = new Bitmap32("scorevalues/50/50P",Bitmap32::cARGB);
	p300bm  = new Bitmap32("scorevalues/300/300P",Bitmap32::cARGB);
	p500bm  = new Bitmap32("scorevalues/500/500P",Bitmap32::cARGB);
	p1000bm = new Bitmap32("scorevalues/1000/1000P",Bitmap32::cARGB);

	Font *small = new Font("Fonts/swed");//Humnst777_BT_40");
	small->SetSize(1);
	bellv1 = new View(Rect(.2f,.05f,1,1));
	bellv1->SetClearState(false);
	bellv1->Apply(p25bm);
	Apply(bellv1);
	bellv2 = new View(Rect(.2f,.05f,1,1));
	bellv2->SetClearState(false);
	bellv2->Apply(p500bm);
	Apply(bellv2);
	cherryv1 = new View(Rect(.2f,.05f,1,1));
	cherryv1->SetClearState(false);
	cherryv1->Apply(p10bm);
	Apply(cherryv1);
	cherryv2 = new View(Rect(.2f,.05f,1,1));
	cherryv2->SetClearState(false);
	cherryv2->Apply(p300bm);
	Apply(cherryv2);
	sevenv1 = new View(Rect(.2f,.05f,1,1));
	sevenv1->SetClearState(false);
	sevenv1->Apply(p50bm);
	Apply(sevenv1);
	sevenv2 = new View(Rect(.2f,.05f,1,1));
	sevenv2->SetClearState(false);
	sevenv2->Apply(p1000bm);
	Apply(sevenv2);

	cherry1->Tick(.0f); cherry2->Tick(.03f); cherry3->Tick(.06f); cherry4->Tick(.09f);
	bell1  ->Tick(.0f); bell2  ->Tick(.03f); bell3  ->Tick(.06f); bell4  ->Tick(.09f);
	seven1 ->Tick(.0f); seven2 ->Tick(.03f); seven3 ->Tick(.06f); seven4 ->Tick(.09f);
#endif
}

Images::~Images(){
//	delete apple1;
//	delete apple2;
//	delete apple3;
//	delete apple4;
//	delete banana1;
//	delete banana2;
//	delete banana3;
//	delete banana4;
	delete bell1;
	delete bell2;
	delete bell3;
	delete bell4;
	delete cherry1;
	delete cherry2;
	delete cherry3;
	delete cherry4;
//	delete lemon1;
//	delete lemon2;
//	delete lemon3;
//	delete lemon4;
//	delete pear1;
//	delete pear2;
//	delete pear3;
//	delete pear4;
//	delete five1;
//	delete five2;
//	delete five3;
//	delete five4;
	delete seven1;
	delete seven2;
	delete seven3;
	delete seven4;
	delete bellv1;
	delete bellv2;
	delete cherryv1;
	delete cherryv2;
	delete sevenv1;
	delete sevenv2;
	delete p10bm;
	delete p25bm;
	delete p50bm;
	delete p300bm;
	delete p500bm;
	delete p1000bm;
}

#include <math.h>

void Images::Tick(float pulse){
#if 1
	t+=pulse;
	while(t>24.0f) t-=24.0f;
	//                               |stop   |start   |end of |in     |start of|    |out    |
	//                               |       |        |fade in|effect |fade out|    |effect |
	#define I01        1.0f-(         t< 5.0f?         t< 1.0f? 1.0f-t:t< 4.0f ?0.0f:t- 4.0f     :1.0f)
	#define I02        1.0f-(         t< 9.0f?t> 4.0f? t< 5.0f? 5.0f-t:t< 8.0f ?0.0f:t- 8.0f:1.0f:1.0f)
	#define I03        1.0f-(         t<13.0f?t> 8.0f? t< 9.0f? 9.0f-t:t<12.0f ?0.0f:t-12.0f:1.0f:1.0f)
	#define I04        1.0f-(         t<17.0f?t>12.0f? t<13.0f?13.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f)
	#define I05        1.0f-(         t<21.0f?t>16.0f? t<17.0f?17.0f-t:t<20.0f ?0.0f:t-20.0f:1.0f:1.0f)
	#define I06        1.0f-(t<1.0f?t:t<25.0f?t>20.0f? t<21.0f?21.0f-t:t<24.0f ?0.0f:t-24.0f:1.0f:1.0f)
	#define I07        1.0f-(         t<29.0f?t>24.0f? t<25.0f?25.0f-t:t<28.0f ?0.0f:t-28.0f:1.0f:1.0f)
	#define I08        1.0f-(         t<33.0f?t>28.0f? t<29.0f?29.0f-t:t<32.0f ?0.0f:t-32.0f:1.0f:1.0f)
	#define I09        1.0f-(         t<37.0f?t>32.0f? t<33.0f?33.0f-t:t<36.0f ?0.0f:t-36.0f:1.0f:1.0f)
	#define I10        1.0f-(         t<41.0f?t>36.0f? t<37.0f?37.0f-t:t<40.0f ?0.0f:t-40.0f:1.0f:1.0f)
	#define I11        1.0f-(         t<45.0f?t>40.0f? t<41.0f?41.0f-t:t<44.0f ?0.0f:t-44.0f:1.0f:1.0f)
	#define I12        1.0f-(         t<49.0f?t>44.0f? t<45.0f?45.0f-t:t<48.0f ?0.0f:t-48.0f:1.0f:1.0f)
	#define I13        1.0f-(         t<53.0f?t>48.0f? t<49.0f?49.0f-t:t<52.0f ?0.0f:t-52.0f:1.0f:1.0f)
	#define I14        1.0f-(         t<57.0f?t>52.0f? t<53.0f?53.0f-t:t<56.0f ?0.0f:t-56.0f:1.0f:1.0f)
	#define I15        1.0f-(t<1.0f?t:t<61.0f?t>56.0f? t<57.0f?57.0f-t:t<60.0f ?0.0f:t-60.0f:1.0f:1.0f)
	#define I16        1.0f-(t<1.0f?t:t<65.0f?t>60.0f? t<61.0f?61.0f-t:t<64.0f ?0.0f:t-64.0f:1.0f:1.0f)

//	apple1 ->SetTransparency(         t< 9.0f?         t< 1.0f? 1.0f-t:t< 8.0f ?0.0f:t- 8.0f     :1.0f);
//	apple2 ->SetTransparency(         t< 9.0f?t> 4.0f? t< 5.0f? 5.0f-t:t< 8.0f ?0.0f:t- 8.0f:1.0f:1.0f);
//	apple3 ->SetTransparency(         t< 9.0f?t> 4.0f? t< 5.0f? 5.0f-t:t< 8.0f ?0.0f:t- 8.0f:1.0f:1.0f);
//	apple4 ->SetTransparency(         t< 9.0f?t> 4.0f? t< 5.0f? 5.0f-t:t< 8.0f ?0.0f:t- 8.0f:1.0f:1.0f);
//	banana1->SetTransparency(         t<17.0f?t> 8.0f? t< 9.0f? 9.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f);
//	banana2->SetTransparency(         t<17.0f?t>12.0f? t<13.0f?13.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f);
//	banana3->SetTransparency(         t<17.0f?t>12.0f? t<13.0f?13.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f);
//	banana4->SetTransparency(         t<17.0f?t>12.0f? t<13.0f?13.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f);
/*
	bell1  ->SetTransparency(         t<25.0f?t>16.0f? t<17.0f?17.0f-t:t<24.0f ?0.0f:t-24.0f:1.0f:1.0f);
	bell2  ->SetTransparency(         t<25.0f?t>20.0f? t<21.0f?21.0f-t:t<24.0f ?0.0f:t-24.0f:1.0f:1.0f);
	bell3  ->SetTransparency(         t<25.0f?t>20.0f? t<21.0f?21.0f-t:t<24.0f ?0.0f:t-24.0f:1.0f:1.0f);
	bell4  ->SetTransparency(         t<25.0f?t>20.0f? t<21.0f?21.0f-t:t<24.0f ?0.0f:t-24.0f:1.0f:1.0f);
	cherry1->SetTransparency(         t<33.0f?t>24.0f? t<25.0f?25.0f-t:t<32.0f ?0.0f:t-32.0f:1.0f:1.0f);
	cherry2->SetTransparency(         t<33.0f?t>28.0f? t<29.0f?29.0f-t:t<32.0f ?0.0f:t-32.0f:1.0f:1.0f);
	cherry3->SetTransparency(         t<33.0f?t>28.0f? t<29.0f?29.0f-t:t<32.0f ?0.0f:t-32.0f:1.0f:1.0f);
	cherry4->SetTransparency(         t<33.0f?t>28.0f? t<29.0f?29.0f-t:t<32.0f ?0.0f:t-32.0f:1.0f:1.0f);
*/
	#ifdef OPENGL
	#else
	cherryv1->SetTransparency(         t< 5.0f?         t< 1.0f? 1.0f-t:t< 4.0f ?0.0f:t- 4.0f     :1.0f);
	cherry1 ->SetTransparency(         t< 9.0f?         t< 1.0f? 1.0f-t:t< 8.0f ?0.0f:t- 8.0f     :1.0f);
	cherryv2->SetTransparency(         t< 9.0f?t> 4.0f? t< 5.0f? 5.0f-t:t< 8.0f ?0.0f:t- 8.0f:1.0f:1.0f);
	cherry2 ->SetTransparency(         t< 9.0f?t> 4.0f? t< 5.0f? 5.0f-t:t< 8.0f ?0.0f:t- 8.0f:1.0f:1.0f);
	cherry3 ->SetTransparency(         t< 9.0f?t> 4.0f? t< 5.0f? 5.0f-t:t< 8.0f ?0.0f:t- 8.0f:1.0f:1.0f);
	cherry4 ->SetTransparency(         t< 9.0f?t> 4.0f? t< 5.0f? 5.0f-t:t< 8.0f ?0.0f:t- 8.0f:1.0f:1.0f);
	bellv1  ->SetTransparency(         t<13.0f?t> 8.0f? t< 9.0f? 9.0f-t:t<12.0f ?0.0f:t-12.0f:1.0f:1.0f);
	bell1   ->SetTransparency(         t<17.0f?t> 8.0f? t< 9.0f? 9.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f);
	bellv2  ->SetTransparency(         t<17.0f?t>12.0f? t<13.0f?13.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f);
	bell2   ->SetTransparency(         t<17.0f?t>12.0f? t<13.0f?13.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f);
	bell3   ->SetTransparency(         t<17.0f?t>12.0f? t<13.0f?13.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f);
	bell4   ->SetTransparency(         t<17.0f?t>12.0f? t<13.0f?13.0f-t:t<16.0f ?0.0f:t-16.0f:1.0f:1.0f);
//	lemon1 ->SetTransparency(         t<41.0f?t>32.0f? t<33.0f?33.0f-t:t<40.0f ?0.0f:t-40.0f:1.0f:1.0f);
//	lemon2 ->SetTransparency(         t<41.0f?t>36.0f? t<37.0f?37.0f-t:t<40.0f ?0.0f:t-40.0f:1.0f:1.0f);
//	lemon3 ->SetTransparency(         t<41.0f?t>36.0f? t<37.0f?37.0f-t:t<40.0f ?0.0f:t-40.0f:1.0f:1.0f);
//	lemon4 ->SetTransparency(         t<41.0f?t>36.0f? t<37.0f?37.0f-t:t<40.0f ?0.0f:t-40.0f:1.0f:1.0f);
//	pear1  ->SetTransparency(         t<49.0f?t>40.0f? t<41.0f?41.0f-t:t<48.0f ?0.0f:t-48.0f:1.0f:1.0f);
//	pear2  ->SetTransparency(         t<49.0f?t>44.0f? t<45.0f?45.0f-t:t<48.0f ?0.0f:t-48.0f:1.0f:1.0f);
//	pear3  ->SetTransparency(         t<49.0f?t>44.0f? t<45.0f?45.0f-t:t<48.0f ?0.0f:t-48.0f:1.0f:1.0f);
//	pear4  ->SetTransparency(         t<49.0f?t>44.0f? t<45.0f?45.0f-t:t<48.0f ?0.0f:t-48.0f:1.0f:1.0f);
//	five1  ->SetTransparency(         t<57.0f?t>48.0f? t<49.0f?49.0f-t:t<56.0f ?0.0f:t-56.0f:1.0f:1.0f);
//	five2  ->SetTransparency(         t<57.0f?t>52.0f? t<53.0f?53.0f-t:t<56.0f ?0.0f:t-56.0f:1.0f:1.0f);
//	five3  ->SetTransparency(         t<57.0f?t>52.0f? t<53.0f?53.0f-t:t<56.0f ?0.0f:t-56.0f:1.0f:1.0f);
//	five4  ->SetTransparency(         t<57.0f?t>52.0f? t<53.0f?53.0f-t:t<56.0f ?0.0f:t-56.0f:1.0f:1.0f);
/*
	seven1 ->SetTransparency(t<1.0f?t:t<65.0f?t>56.0f? t<57.0f?57.0f-t:t<64.0f ?0.0f:t-64.0f:1.0f:1.0f);
	seven2 ->SetTransparency(t<1.0f?t:t<65.0f?t>60.0f? t<61.0f?61.0f-t:t<64.0f ?0.0f:t-64.0f:1.0f:1.0f);
	seven3 ->SetTransparency(t<1.0f?t:t<65.0f?t>60.0f? t<61.0f?61.0f-t:t<64.0f ?0.0f:t-64.0f:1.0f:1.0f);
	seven4 ->SetTransparency(t<1.0f?t:t<65.0f?t>60.0f? t<61.0f?61.0f-t:t<64.0f ?0.0f:t-64.0f:1.0f:1.0f);
*/
	sevenv1 ->SetTransparency(t<1.0f?t:t<21.0f?t>16.0f? t<17.0f?17.0f-t:t<20.0f ?0.0f:t-20.0f:1.0f:1.0f);
	seven1  ->SetTransparency(t<1.0f?t:t<25.0f?t>16.0f? t<17.0f?17.0f-t:t<24.0f ?0.0f:t-24.0f:1.0f:1.0f);
//printf("i: %f\n",t<1.0f?t:t<25.0f?t>20.0f? t<21.0f?21.0f-t:t<24.0f ?0.1f:t-24.0f:1.0f:1.0f);
	sevenv2 ->SetTransparency(t<1.0f?t:t<25.0f?t>20.0f? t<21.0f?21.0f-t:t<24.0f ?0.1f:t-24.0f:1.0f:1.0f);
	seven2  ->SetTransparency(t<1.0f?t:t<25.0f?t>20.0f? t<21.0f?21.0f-t:t<24.0f ?0.0f:t-24.0f:1.0f:1.0f);
	seven3  ->SetTransparency(t<1.0f?t:t<25.0f?t>20.0f? t<21.0f?21.0f-t:t<24.0f ?0.0f:t-24.0f:1.0f:1.0f);
	seven4  ->SetTransparency(t<1.0f?t:t<25.0f?t>20.0f? t<21.0f?21.0f-t:t<24.0f ?0.0f:t-24.0f:1.0f:1.0f);
	#endif
/*
	cherryv1->SetColor(ARGB(I01,I01,I01));
	cherryv2->SetColor(ARGB(I02,I02,I02));
	bellv1  ->SetColor(ARGB(I03,I03,I03));
	bellv2  ->SetColor(ARGB(I04,I04,I04));
	sevenv1 ->SetColor(ARGB(I05,I05,I05));
	sevenv2 ->SetColor(ARGB(I06,I06,I06));
*/
	p10bm  ->SetFrame(int(t*25/2)%  p10bm->GetFrameCount());
	p25bm  ->SetFrame(int(t*25/2)%  p25bm->GetFrameCount());
	p50bm  ->SetFrame(int(t*25/2)%  p50bm->GetFrameCount());
	p300bm ->SetFrame(int(t*25/2)% p300bm->GetFrameCount());
	p500bm ->SetFrame(int(t*25/2)% p500bm->GetFrameCount());
	p1000bm->SetFrame(int(t*25/2)%p1000bm->GetFrameCount());

	cherry1->Tick(pulse);
	cherry2->Tick(pulse);
	cherry3->Tick(pulse);
	cherry4->Tick(pulse);
	bell1->Tick(pulse);
	bell2->Tick(pulse);
	bell3->Tick(pulse);
	bell4->Tick(pulse);
	seven1->Tick(pulse);
	seven2->Tick(pulse);
	seven3->Tick(pulse);
	seven4->Tick(pulse);
#endif
}

