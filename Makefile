prog:    liste_temp.o test_liste_temp.o
            g++ liste_temp.o test_liste_temp.o -o prog
liste_temp.o:    liste_temp.cc liste_temp.h
            g++ -c liste_temp.cc
test_liste_temp.o:    test_liste_temp.cc liste_temp.h
            g++ -c test_liste_temp.cc

clean    :
            rm −f ∗ ̃ ∗ . o
