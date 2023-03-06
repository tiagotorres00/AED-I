EXERCÍCIO: Determine se dois eventos têm conflito  

Você recebe dois arrays de strings que representam dois eventos que aconteceram no mesmo dia, evento1 e evento2, onde:  
evento1 = [começo1, fim1] e evento2 = [começo2, fim2].

Os horários dos eventos são válidos no formato de 24 horas no formato HH:MM.
Um conflito ocorre quando dois eventos têm alguma interseção não vazia (ou seja, algum momento é comum
a ambos os eventos).

Faça a função que retorna verdadeiro se houver um conflito entre dois eventos. Caso contrário, retorne falso.  
 bool haveConflict(char ** evento1, int evento1Tamanho, char ** evento2, int evento2Tamanho)

Restrições:  
 evento1Tamanho == evento2Tamanho == 2.  
 strlen(evento1[i]) == strlen(evento2[i]) == 5  
 começo1 <= fim1  
 começo2 <= fim2  
 Todos os horários dos eventos seguem o formato HH:MM.  
