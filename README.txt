mam teskt, np

Linijka 1
Linijka 2
Linijka 3

get_next_line ma dzialac tak ze przy kazdym wywolaniu funkcji wypisuje kolejną linijke z podanego tekstu
czyli np, 
get_next_line(fd) -> Linijka 1
get_next_line(fd) -> Linijka 2
get_next_line(fd) -> Linijka 3


za kazdym wywolaniem funkcji, zapamietuje swoją pozycje, aby wypisywac kolejne elementy linijki
czyli jezeli mam "Linijka 1\n" to zapamietuje ostanią pozycję za znakiem \n aby rozpocząc od nowej linijki w 
nastepnym wywolaniu funkcji
czyli 
get_next_line(fd) -> Linijka 1  static int miejsce 10
get_next_line(fd) -> Linijka 2  static int miejsce 20
get_next_line(fd) -> Linijka 3  static int miejsce 30    ---> bo \n sie wlicza

nie moge od razu zczytac wszystkiego i iterowac sobie po prostu po tablicy, tylko zapamietywac linijke w danym momencie
https://medium.com/@lannur-s/gnl-c3cff1ee552b <-- stronka ktora pomoze w zrozumieniu tematu xdddd
(odchodze od zmysłów) 
