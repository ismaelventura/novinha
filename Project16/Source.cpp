#include <stdio.h>
#include <stdlib.h>

using namespace System;
using namespace System::Text;
using namespace Threading;

int main()
{
	int jogadorX = 30;
	int inimigoX = 0;
	int inimigoY = 1;
	
	const int ESTADO_JOGO_MENU = 0;
	const int ESTADO_JOGO_GAMEPLAY = 1;
	const int ESTADO_JOGO_VENCEU = 2;
	const int ESTADO_JOGO_PERDEU = 3;
	int estadoDoJogo= ESTADO_JOGO_MENU;
	
	do {
		switch (estadoDoJogo)
		{
		case ESTADO_JOGO_MENU:
			 Console::BackgroundColor = ConsoleColor::DarkCyan;
			Console::Clear();
			 Console::SetCursorPosition(0, 0);
			Console::Write("_   _             _       _           ");
			 Console::SetCursorPosition(0, 1);
			Console::Write("| \\ | |           (_)     | |          ");
			 Console::SetCursorPosition(0, 2);
			Console::Write("|  \\| | __ ___   ___ _ __ | |__   __ _ ");
			 Console::SetCursorPosition(0, 3);
			Console::Write("| . ` |/ _` \ \ / / | '_ \\| '_ \\ / _` |");
			 Console::SetCursorPosition(0, 4);
			Console::Write("| |\\  | (_| |\\ V /| | | | | | | | (_| |");
			 Console::SetCursorPosition(0, 5);
			Console::Write("\\_| \\_/\\__,_| \\_/ |_|_| |_|_| |_|\\__,_|");
			 Console::SetCursorPosition(20, 10);
			Console::Write("Pressione ENTER para iniciar");

			if (Console::KeyAvailable)
			{
				ConsoleKeyInfo tecla;
				tecla = Console::ReadKey(true);
				if (tecla.Key == ConsoleKey::Enter)
				{
					estadoDoJogo = ESTADO_JOGO_GAMEPLAY;
				}
			}

				break;
		case (ESTADO_JOGO_GAMEPLAY):
			Console::BackgroundColor = ConsoleColor::Red;
			Console::Clear();

			Console::SetCursorPosition(jogadorX, 19);
			Console::Write("U");
			
			if (Console::KeyAvailable)
			{
				ConsoleKeyInfo tecla;
				tecla = Console::ReadKey(true);
				if (tecla.Key == ConsoleKey::LeftArrow)
				{
					jogadorX = jogadorX - 1;
					if (jogadorX == -1)
						jogadorX = 0;
				}

				else if
					(tecla.Key == ConsoleKey::RightArrow)
				{
					jogadorX = jogadorX + 1;
					if (jogadorX == 80)
						jogadorX = 79;
				}


				Console::BackgroundColor = ConsoleColor::Red;
				Console::Clear();

				Console::SetCursorPosition(jogadorX, 19);
				Console::Write("U");

				Console::SetCursorPosition(inimigoX, inimigoX);
				Console::Write("======");

			}
			 break;


		}
				
		Thread::Sleep(16);

	} while (true);



	return 0;

}