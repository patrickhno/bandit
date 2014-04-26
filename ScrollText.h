
#include <Interface/View.h>
#include <3DAPI/Network/Message.h>

class ScrollText : public View{//, Message{
public:					ScrollText(View *);
						~ScrollText();
		void			Tick(float);
		void			Urgent(const char *);
private:
//		void			MessageReceived(void);
		float			offset,t;
class	DynamicArray	*urgent;
		enum States{
		SCROLL_TICK,
		SCROLL_TO_URGENT_TICK,
		URGENT_TICK,
		URGENT_TO_SCROLL,
		URGENT_TO_SCROLL_TICK
		};
		States			state;
		char			*ustr,*sstr;
		View			*uview;
};

