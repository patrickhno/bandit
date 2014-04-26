
#include <Interface/View.h>

class Roll : public View{
public:				Roll(const char *, const char *, const char *, class Rect &);
					~Roll();
		void		Tick(float pulse);
		void		Spinn(void);
		void		Delay(void);
		int			GetStatus(void) const;
private:
class	Bitmap32	*anim,
					*frames,
					*selectbm;
		View		*sview;
		enum{
			BS_FREE,
			BS_FREE_TICK,
			BS_DELAY,
			BS_DELAY_TICK,
			BS_SPINN,
			BS_SPINN_TICK,
			BS_SPINN_DEINITIALIZE
		}			brainstate;
		float		think;
		int			status,nextstatus;
		float		time;
};

