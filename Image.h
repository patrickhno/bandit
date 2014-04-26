
#include "Interface/View.h"

class Image : public View{
public:				Image(const char *);
					~Image();
		void		Tick(float);
private:
		double		t;
class	Bitmap32	*bm;
};

