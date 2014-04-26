
#include <Interface/View.h>

class Arm : public View{
public:				Arm(class Rect &);
					~Arm();
		void		Tick(float pulse);
		void		Spinn(void);
private:
class	Bitmap32	*anim;
		enum{
			BS_FREE,
			BS_SPINN,
			BS_SPINN_TICK
		}			brainstate;
		float		think;
};

