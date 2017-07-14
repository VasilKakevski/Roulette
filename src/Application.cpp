#include "Application.h"

Application::Application()
{

	intro = NULL;
	for (unsigned int i = 0; i < 5; i++)
	{
		introButtons[i] = NULL;
	}
	rouletteBorder=NULL;
	ball = NULL;
	info = NULL;
	infoBackToIntro = NULL;
	gameBoard = NULL;
	roulette = NULL; // spin roulette
	outro = NULL; // Animation who backs to Intro 10 sec;
	win = NULL; // anima
	initIntro();
}

Application::~Application()
{

	for (unsigned int i = 0; i < 5; i++)
	{
		delete introButtons[i];
	}
	delete intro;
	Free();

	// TODO Auto-generated destructor stub
}

void Application::initIntro()
{
	MenuState = INTRO_MENU;
	intro = new Background("INTROSCREEN", SCREEN_W, SCREEN_H,
			"INTRO SCREEN.jpg");
	for (int i = 0; i < 5; i++)
	{
		introButtons[i] = new Button(SCREEN_W / 2 - INTRO_BUTTON_W / 2,
				SCREEN_H / 5 - INTRO_BUTTON_H / 2 + i * (INTRO_BUTTON_H + 10));
		introButtons[i]->loadFromFile(Background::gRenderer, "Pools.png");
		introButtons[i]->setHeight(INTRO_BUTTON_H);
		introButtons[i]->setWidth(INTRO_BUTTON_W);
		SDL_Rect rectButton = { 1, 1, 118, 111 };
		introButtons[i]->render(Background::gRenderer, &rectButton);

	}

}

void Application::initInfo()
{
	MenuState = INFO;
	info = new Background("INFOSCREEN", SCREEN_W, SCREEN_H,
			"rouletterules.jpg");
	infoBackToIntro = new Button(10, 10);
	infoBackToIntro->loadFromFile(Background::gRenderer, "BackButton.png");
	infoBackToIntro->setHeight(INTRO_BUTTON_H);
	infoBackToIntro->setWidth(INTRO_BUTTON_W);
	infoBackToIntro->render(Background::gRenderer, NULL);
}

void Application::initGameBoard()
{
	MenuState = GAME_BOARD;
	gameBoard = new Background("GameBoard", SCREEN_BOARD_W, SCREEN_BOARD_H,
			"tap_resized.jpg");
	cashOut = new Button(SCREEN_BOARD_W - BUTTON_W,
			SCREEN_BOARD_H - BUTTON_H - 10);
	cashOut->loadFromFile(Background::gRenderer, "Cash OUT.png");
	cashOut->setHeight(BUTTON_W);
	cashOut->setWidth(BUTTON_W);
	cashOut->render(Background::gRenderer, NULL);

	//this will be spin button need picture ;
	spin = new Button(800, 200);
	spin->loadFromFile(Background::gRenderer, "Buttons.png");
	spin->setHeight(BUTTON_W);
	spin->setWidth(BUTTON_W);
	spin->render(Background::gRenderer, NULL);

	//draw 5 Pulls
	//TODO: Each Poll needs different credit value.
	Credits cr;
	for (int i = 0; i < 5; i++)
	{
		gameBoardPools[i] = new Pools(cr, 100 * i, SCREEN_BOARD_H - 60, 1);
		gameBoardPools[i]->loadFromFile(Background::gRenderer, "Pools.png");
		gameBoardPools[i]->setHeight(PULLS_W);
		gameBoardPools[i]->setWidth(PULLS_H);
		SDL_Rect rectButton = { 113 * i, 1, 118, 111 };
		gameBoardPools[i]->render(Background::gRenderer, &rectButton);
	}

}

void Application::initRoulette()
{
}

void Application::initOutro()
{

}

void Application::initWin()
{
	MenuState=WIN;
	win= new Background("Win",SCREEN_ROULETTE_W,SCREEN_ROULETTE_H,"CoinBag.png");
	for(int i=0 ; i<COIN_COUNT ; i++){
		coin[i] =new LTexture(rand()%200+100,rand()%SCREEN_ROULETTE_W);
		coin[i]->loadFromFile(Background::gRenderer,"coin.png");
		coin[i]->setWidth(COIN_W);
		coin[i]->setHeight(COIN_H);
	}
		WinAnimation();

}

void Application::initSpin()
{
	MenuState = SPIN;
	rouletteBorder = new Background("spin", SCREEN_ROULETTE_W, SCREEN_ROULETTE_H,
			"RouletteBoard.png");
	wheel = new RouletteWheel(110, 110);
	wheel->loadFromFile(Background::gRenderer, "wheel.png");
	wheel->setWidth(580);
	wheel->setHeight(580);


	ball = new Ball(SCREEN_ROULETTE_W, SCREEN_ROULETTE_H,5);
	ball->loadFromFile(Background::gRenderer, "BALL.png");
	ball->setWidth(BALL_W);
	ball->setHeight(BALL_H);
	ball->spin();
	wheel->Spin();






}

void Application::GamePlay()
{

	bool close = false;
	while (!close)
	{

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{

			switch (MenuState)
			{
			case INTRO_MENU:
				if (introButtons[0]->isClicked(&e))
				{
					Free();
					MenuState = INFO;
					initInfo();
				}
				if (introButtons[3]->isClicked(&e))
				{
					Free();
					MenuState = GAME_BOARD;
					initGameBoard();
				}

				break;
			case INFO:
				if (infoBackToIntro->isClicked(&e))
				{
					Free();
					initIntro();
				}
				break;
			case GAME_BOARD:
				if (spin->isClicked(&e))
				{
					Free();
					initSpin();
				}
				if (cashOut->isClicked(&e))
				{
					Free();
					initWin();
				}

				if (gameBoardPools[0]->isClicked(&e))
				{

				}

				if (gameBoardPools[1]->isClicked(&e))
				{

				}

				if (gameBoardPools[2]->isClicked(&e))
				{

				}

				if (gameBoardPools[3]->isClicked(&e))
				{

				}

				if (gameBoardPools[4]->isClicked(&e))
				{
				}
				break;

			case SPIN:


				break;
			case WIN:


				break;
			default:
				break;
			}

			if (e.type == SDL_QUIT)
			{
				close = true;
			}

		}

		//separate function that traverse vector with Bets and display polls

	}

}

void Application::Free()
{
	if (MenuState == INTRO_MENU)
	{
		intro->Clear();
		introButtons[0]->Free();
		introButtons[1]->Free();
		introButtons[2]->Free();
		introButtons[3]->Free();
		introButtons[4]->Free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if (MenuState == INFO)
	{
		info->Clear();
		infoBackToIntro->Free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if (MenuState == GAME_BOARD)
	{
		gameBoard->Clear();
		gameBoardPools[0]->Free();
		gameBoardPools[1]->Free();
		gameBoardPools[2]->Free();
		gameBoardPools[3]->Free();
		gameBoardPools[4]->Free();
		spin->Free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if(MenuState == SPIN)
	{
		roulette->Clear();
		wheel->Free();
		ball->Free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if(MenuState== WIN)
	{
		win->Clear();
		for(int i =0 ; i <COIN_COUNT; i++){

		coin[i]->Free();
		}
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
}



GameState Application::getMenuState() const
{
	return MenuState;
}

bool Application::WinAnimation()

{
	cout<<"START"<<endl;
	short int timeout=6000;
	int speedOfMove=10;
	SDL_Rect goldCoin ={0,0,COIN_W,COIN_H} ;
	SDL_Rect goldCoin1 ={110,0,COIN_W,COIN_H} ;
	SDL_Rect goldCoin2 ={220,0,COIN_W,COIN_H} ;
	SDL_Rect goldCoin3 ={330,0,COIN_W,COIN_H} ;
	SDL_Rect goldCoin4 ={440,0,COIN_W,COIN_H} ;
	SDL_Rect goldCoin5 ={550,0,COIN_W,COIN_H} ;
	SDL_Rect goldCoin6 ={660,0,COIN_W,COIN_H} ;
	SDL_Rect goldCoin7 ={770,0,COIN_W,COIN_H} ;
	SDL_Rect goldCoin8 ={880,0,COIN_W,COIN_H} ;

while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
	  {

		  	for(int i =0 ; i<COIN_COUNT; i++){
//		  	win->Show();
			coin[i]->setX(rand()%370+90);
			coin[i]->setY(rand()%100+0);

			speedOfMove+=4;
			if(speedOfMove>=0)
				{
					coin[i]->render(Background::gRenderer,&goldCoin,0);
				}
				if(speedOfMove>=50)
				{
					coin[i]->render(Background::gRenderer,&goldCoin1);
				}
				if(speedOfMove>=100)
				{
					coin[i]->render(Background::gRenderer,&goldCoin2);
				}
				if(speedOfMove>=150)
				{
					coin[i]->render(Background::gRenderer,&goldCoin3);
				}
				if(speedOfMove>=200)
				{
					coin[i]->render(Background::gRenderer,&goldCoin4);
				}
				if(speedOfMove>=250)
				{
					coin[i]->render(Background::gRenderer,&goldCoin5);
				}
				if(speedOfMove>=300)
				{
					coin[i]->render(Background::gRenderer,&goldCoin6);
				}
				if(speedOfMove>=350)
				{
					coin[i]->render(Background::gRenderer,&goldCoin7);
				}
				if(speedOfMove>=400)
				{
					coin[i]->render(Background::gRenderer,&goldCoin8);
				}


			cout<<"Speed of move"<<speedOfMove<<endl;
			SDL_Delay(80);
}
	  }
return true;
}
