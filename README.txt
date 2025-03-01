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


get_next_line(fd) <-- przekazuje tutaj file descriptor i na koncu funkcja zwraca linijke tekstu
{
	char *line; <-- to bedzie mi na koncu zwracalo linije tekstu
	static char *left_data <-- to bedzie mi zapisywalo od kiedy zaczynac sprawdzanie linijki;

	line = line_grabber(fd, left_data) <-- to bedzie mi pobieralo linijke tekstu i ja zapisywalo do stringa;
	left_data = left_str(fd) <-- to bedzie mi przechowywalo pozostala czesc linijki kiedy buff bedzie za duzy 

}

aktualnie mam kod ktory nastepująco
 -> mam BUFFER_SIZE = 4
 -> odpalam funkcje i 4 razy ma mi zdodbyc linijke
 -> *w funkcji get_next_line*
	-> alokacja pamieci dla 4 + 1
	-> jednorazowe sprawdzenie czy buffor != NULL
	-> jednorazowe sprawdzenie czy bytesread <= 0
	-> jednorazowe sprawdzenie left_str
	-> jednorazowe sprawdzenie new_position
	-> jednorazowe ustawienie new_position

gdzie w funkcji get_next_line podpunkt 3 - 4 powinno byc zapetlone zeby poprawnie
przypisywac elementy do nowo stworzonej tablicy, np wlasnie
jak mam BUFFER_SIZE = 4 a w linijce mam 16 znakow, tak to jednorazowo to mi sie ustawi
a za pomoca petli bede mogl dodawac do line nowe elementy az nie trafie na \n

xddd
popierdoli mnie fest z tym zara chyba xddd


dobra, tera na koncu po wpisaniu wszystkiego w left_str moge teoretycznie zrobic cos takiego
ze if ft_strchr left_str \n != 
	to wtedy line = ft_strdup ft_strchr \n left_str

ale tez i pewnie nie xddd po robocie se sprawdze lol
 
