
#include <Interface/Bitmap32.h>
#include <Interface/Rect.h>
#include "Image.h"

Image::Image(const char *name) : View(Rect(0,0,1,1)){
	SetClearState(false);
	bm = new Bitmap32(name,Bitmap32::cARGB);
	Apply(bm);
	t = 0;
}

Image::~Image(){
	delete bm;
}

void Image::Tick(float pulse){
	t += pulse;
	bm->SetFrame(int(t*25)%bm->GetFrameCount());
}

