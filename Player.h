
#include <Interface/View.h>

class Player : public View{
public:					Player(class Hiscore *, class Rect &, class ScrollText *, int _nr);
						~Player();
		void			Tick(float pulse);
		void			Spinn(void);
		void			DigitDown(char *);
		void			DigitUp(char *);
		void			Lock(int);
		void			Logon(void){	active = true;  }
		void			Logout(void){	active = false; logout = true; }
		bool			IsActive(void){	return active;  }
private:
class	DynamicArray	*coins;
		int				nr;
		int				cn;
		char			name_str[1024];
		bool			key_2,
						key_4,key_5,key_6,
						key_8;
		bool			active,simulate,/*lastlocked,*/logout;
		enum{
			/*
			HOLD_ALL,
			HOLD_TWO,
			HOLD_NONE
			*/
			HOLD_SIX,
			HOLD_FIVE,
			HOLD_FOUR,
			HOLD_TREE,
			HOLD_TWO,
			HOLD_ONE,
			HOLD_NONE
		} holdstate;
class	Hiscore			*hiscore;
		int				frame;
class	Bitmap32		*freeanim,
						*bandit,
						*logonanim,
						*logoutanim,
						*flashanim,
						*crazyanim,
						*wowanim,
						*leftbm,
						*rightbm,
						*upbm,
						*downbm,
						*centerbm,
						*sleftbm,
						*srightbm,
						*supbm,
						*sdownbm,
						*sleftcbm,
						*srightcbm,
						*supcbm,
						*sdowncbm,
						*baseframe;
class	Roll			*roll1,
						*roll2,
						*roll3,
						*roll4;
class	Button			*button1,
						*button2,
						*button3,
						*button4;
		float			think,startplay,t_left,t_right,t_up,t_down;
		enum{
			BS_FREE,
			BS_FREE_TICK,
			BS_FREE_DEINITIALIZE,
			BS_PLAYING,
			BS_PLAYING_TICK,
			BS_PLAYING_DEINITIALIZE,
			BS_INTRO,
			BS_INTRO_TICK,
			BS_INTRO_DEINITIALIZE,
			BS_LOGON,
			BS_LOGON_TICK,
			BS_LOGON_DEINITIALIZE,
			BS_NAME,
			BS_NAME_INFO_TICK,
			BS_NAME_TICK,
			BS_NAME_DEINITIALIZE,
			BS_LOGOUT,
			BS_LOGOUT_TICK,
			BS_LOGOUT_DEINITIALIZE,
			BS_WINN,
			BS_WINN_TICK,
			BS_WINN_DEINITIALIZE
		}				brainstate;//,wantedstate;
class	Arm				*arm;
		int				win;
		bool			locked1,
						locked2,
						locked3,
						locked4;
		View			*flash,
						*nameview,
						*nameframe,
						*infoview,
						*left,
						*right,
						*up,
						*down,
						*center,
						*sleft,
						*sright,
						*sup,
						*sdown,
						*sleftc,
						*srightc,
						*supc,
						*sdownc,
						*freeview,
						*scorev1000,
						*scorev0100,
						*scorev0010,
						*scorev0001;
		bool			lock1,
						lock2,
						lock3,
						lock4,
						spinn;
		int				score;
//class	ScrollText		*name;
		void			AddScore(int);
//		int				logout;
		bool			checkwin;
		bool			logon;
class	Font			*font;
class	ScrollText		*st;
};

