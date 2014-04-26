
#include <Interface/View.h>

class Images : public View{
public:				Images(class Rect &);
					~Images();
		void		Tick(float);
private:
class	Image		*apple1,
					*apple2,
					*apple3,
					*apple4,
					*banana1,
					*banana2,
					*banana3,
					*banana4,
					*bell1,
					*bell2,
					*bell3,
					*bell4,
					*cherry1,
					*cherry2,
					*cherry3,
					*cherry4,
					*lemon1,
					*lemon2,
					*lemon3,
					*lemon4,
					*pear1,
					*pear2,
					*pear3,
					*pear4,
					*five1,
					*five2,
					*five3,
					*five4,
					*seven1,
					*seven2,
					*seven3,
					*seven4;
		View		*view1,
					*view2,
					*view3,
					*view4,
					*applev1,
					*applev2,
					*bananav1,
					*bananav2,
					*bellv1,
					*bellv2,
					*cherryv1,
					*cherryv2,
					*lemonv1,
					*lemonv2,
					*pearv1,
					*pearv2,
					*fivev1,
					*fivev2,
					*sevenv1,
					*sevenv2;
		Bitmap32	*p10bm,
					*p25bm,
					*p50bm,
					*p300bm,
					*p500bm,
					*p1000bm;
		float		t;
};

