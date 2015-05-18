#ifndef GSRUN_H
#define GSRUN_H
#include "GSIncludes.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlayer.h"
#include "GSEnemyFighter.h"
#include "GSAmmo.h"
#include "GSGameObjectManager.h"
#include "GSCLock.h"


namespace groundSupport
{
	class GSRun
	{
	public:
		GSRun();
		~GSRun();
		//startissa ladataan pelin objectit ja siirryt��n looppiin.
		static void start();
		//Renderwindowsin haku metodi.
		static sf::RenderWindow& GetWindow();
		//Ruudun lukittu resoluution.
		const static int Screen_Width = 1024;
		const static int screen_Heihgt = 786;
		//Pelin objektit sis�lt�v�n s�ili�n hakeminen.
		const static GSGameObjectManager& getGSGameObjectManager();

	private:
		//Booli pit�� while loopin p��ll� jonka sis�ll� peli py�rii.
		static bool isQuiting();
		//Pelin looppi.
		static void GSLooping();
		//metodit menun ja intron k�ynnistykseen.
		static void showGSIntro();
		static void showGSMenu();
		//Pelin eri tilat;
		enum GsState
		{
			g_uninitialized,
			g_showingBg,
			g_paused,
			g_menu,
			g_play,
			g_quit

		};

		static GsState _State;
		static sf::RenderWindow _mainWin;
		static groundSupport::GSGameObjectManager _gameObjectManager;

	};
}

#endif