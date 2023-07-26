source createStaticLib.sh
g++ -std=c++17 -L. -I. -L/usr/include -o Game main.cpp Card.cpp Constants.h Display.cpp Dealer.cpp GameTable.cpp Menu.cpp Player.cpp TwentyOnePoints.cpp -lGames -lsqlite3
rm libGames.a
