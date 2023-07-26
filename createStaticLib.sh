g++ -std=c++17 -c Constants.h -o Constants.o
g++ -std=c++17 -c InputProcessing.h -o InputProcessing.o
g++ -std=c++17 -c TableWinners.cpp -o TableWinners.o
ar rc libGames.a Constants.o InputProcessing.o TableWinners.o
rm Constants.o InputProcessing.o TableWinners.o
