#Prosta gra w c++

Gra nazywa się Bulls&CowsGame została ona napisana w C++ na podstawie kursu "The Unreal Engine Dev Course - Learn To Code By Making Games". Gra polega na zgadnięciu ukrytego słowa. Po wpisaniu naszego słowa na ekranie wyświetlają się dwie zmienne:

- Bulls - ta zmienne odpowiada liczbie trafionych liter(są na odpowiednim miejscu).
- Cows. - ta zmienna odpowiada liczbie nie trafionych liter (są w ukrytym słowie ale na złym miejscu)

Do implementacji został wykorzystany standard z Unreal Engine 4.

Ukryte słowo znajduje się w pliku FBullsAndCows.cpp w lini 16 pod zmienną "const FString HIDDEN_WORD" i musi one być isogramem czyli żadna litera w słowie nie może wystąpić dwa razy .

Program nie jest ostateczną wersją, przewidziane są jeszcze usprawnienia które ułatwia rozgrywkę.

Przyszłe usprawnienia:

+ automatyczne wybieranie słowa. 
+ dostosowanie ilości prób do trudności(długości) wybranego słowa.
+ różne rodzaje podpowiedzi jeżeli słowo okaże się  za trudne 
+ możliwość wybrania poziomu trudności 

