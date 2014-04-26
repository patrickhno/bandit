
#include <Interface/View.h>

class Coin : public View{
public:				Coin();
					~Coin();
		void		SetSize(float s){ size = s; }
		void		Tick(float);
private:
class	Bitmap32	*bm;
		double		ft,mt;
		float		xo,yo,xv,yv,size;
};

