
#include <Interface/View.h>

class MovieScroller : public View{
public:			MovieScroller(View *parent);
				~MovieScroller();
		void	Tick(const float pulse);
private:
		View	*parent;
		float	offset;
};

