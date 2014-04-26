
#include <Interface/View.h>
#include <3dapi/Network/Message.h>

class PlayField : public View, public Message{
public:					PlayField(class Hiscore *, View *parent, class ScrollText *st);
						~PlayField();
		void			Tick(float);
		void			Input(int,int);
private:
		void			MessageReceived(void);
class	Player			*AllocateChannel(const int);
		void			FreeChannel(const int);
class	Player			*GetChannel(const int);
class	DynamicArray	*players;
class	DynamicArray	*channels;
		float			foo;
class	Bitmap32		*picture;
		int				player_count;
		float			zoom,xz,yz;
};

