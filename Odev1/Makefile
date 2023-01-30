hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/NodeSatir.o -c ./src/NodeSatir.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/NodeYonetici.o -c ./src/NodeYonetici.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/NodeSatir.o ./lib/SatirListesi.o ./lib/NodeYonetici.o ./lib/YoneticiListesi.o ./src/Test.cpp
	
calistir:
	./bin/Test