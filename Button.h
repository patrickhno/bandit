
#include <Interface/View.h>

class Button : public View{
public:				Button(const char *, class Rect &);
					~Button();
private:
class	Bitmap32	*anim;
};


