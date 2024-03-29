# Treść zadania
Sołtys bardzo boleśnie przekonał się, że nie powinien był ciąć kosztów podczas rozstrzygania przetargów na wieże transmisyjne. Ich awarie stały się plamą na sołtysim honorze. Ekipy nie nadążały z naprawami, dlatego Sołtys wpadł na pomysł, by nadawać zgłaszanym awariom priorytety i w pierwszej kolejności przywracać do życia najważniejsze z wież (o najwyższym priorytecie), a z naprawy niektórych (mniej kluczowych) być może nawet zrezygnować. Sołtys zlecił więc jednemu z teamów Ady i Serweryna napisanie aplikacji, która pomoże w zarządzaniu ekipami naprawczymi.

### Wejście:
Na wejściu program otrzyma liczbę n zestawów danych, a następnie dane poszczególnych zestawów. Dane pojedynczego zestawu składają się z liczby m, a następnie m linii z opisami operacji, które należy wykonać. Opis pojedynczej operacji składa się z liczby całkowitej ze zbioru {0,1,2}.

0 oznacza operację dodania zgłoszenia konieczności naprawy wieży. Opis tej operacji składa się z trzech liczb. Opis 0 a b oznacza, że należy dodać zgłoszenie potrzeby naprawy wieży a o priorytecie b.
1 naprawa wieży o najwyższym priorytecie. Odpowiednie zgłoszenie naprawy powinno zostać usunięte z pamięci.
2 rezygnacja z naprawy o najmniejszym priorytecie. Odpowiednie zgłoszenie naprawy powinno zostać usunięte z pamięci.
Zakładamy, że w dowolnym momencie w bazie znajduje się co najwyżej jedno zgłoszenie naprawy wieży o danym priorytecie.
### Wyjście:
Program powinien wypisywać na standardowym wyjściu numery wież transmisyjnych, których zgłoszenia naprawy są usuwane z pamięci. Program powinien ignorować polecenia usunięcia zgłoszenia naprawy z pustej listy zgłoszeń. Wszystkie wczytywane wartości są ograniczone przez wartość 3000000.

### Przykład:
**Wejście:**
```
1
8
0 1 2
1
0 1 2
0 2 1
0 0 3
1
2
1
```
**Wyjście:**
```
1
0
2
1
```
**Rozwiązanie powinno zawierać samodzielną implementację kopców. W rozwiązaniu nie wolno używać STL-a.**