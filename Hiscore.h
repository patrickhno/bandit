
#include "MovieScroller.h"

class Hiscore : public MovieScroller{
public:			Hiscore(View *parent);
				~Hiscore();
		void	Add(const char *, const int);
private:
class	Font	*font;
		int		scores[30];
		char	names[30][20];
};

