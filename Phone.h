
#ifndef PHONE_H
#define PHONE_H

#include <Interface/View.h>

class PhoneNumber : public View{
public:				PhoneNumber(class Rect &);
					~PhoneNumber();
		void		Tick(float);
		void		SetNumber(const char *);
		void		SetConnectionCharge(const float);
		void		SetCharge(const float);
private:
		View		*view,*cview,*pnview1,*pnview2,*pnview3,*jview,*tbview;
		float		ccharge,charge;
class	Bitmap32	*anim,*pnbm1,*pnbm2,*pnbm3,*jbm,*tbbm;
		float		think;
};

#endif
