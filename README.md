# MMA-Komponist
Eine kleine HilfsAnwendung für MMA https://www.mellowood.ca/mma/

Hier findet ihr jetzt die ungefähre / grobe GUI für mein Programm.
Solltest du das Programm ausprobieren wollen:
1.) Du musst wxWidgets Installiert haben.
2.) Und g++. ( Was in der Regel in Linux schon istalliert ist )
3.) Der Compile Befehl lautet:
     g++ test.cpp TrackControl.cpp TrackParameter.cpp `wx-config --libs --cxxflags` -std=c++11 -o Test2
