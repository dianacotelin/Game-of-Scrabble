 COTELIN MARIA-DIANA
 Decembrie 2020
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   Toata rezolvarea este in main, nu am folosit functii suplimentare.
    Am folosit fgets si stdin pentru a citi fiecare linie de la fiecare task,
 iar cu atoi am transformat in int task-ul, indicii cuvantului si directia.
     --->fgets(variabila_de_tip_char, dimensiunea ei, stdin);
     ---> alta_variabila_de_tip_int = atoi(variabila de tip char)
    Am construit de la inceput tabla de joc si am folosit-o la taskurile
 la care era nevoie.
    Variabilele i si j le-am folosit de fiecare data cand am parcurs tabla de
 joc, iar variabila t pentru numarul task-ului.


 ~~~~~~~~~~~~~~~~~~~~Task 0~~~~~~~~~~~~~~~~~~~~~~~

   Am afisat tabla folosind functia print_board.
  

 ~~~~~~~~~~~~~~~~~~~~Task 1~~~~~~~~~~~~~~~~~~~~~~~

    Am citit intr-un while fiecare linie, cu fgets, iar apoi am folosit strtok 
 pentru a desparti in cuvinte fiecare informatie. Cu atoi am transformat 
 coordonatele cuvantului si le-am retinut in variabile. 
     In functie de directie am pus cuvantul pe orizontala sau verticala.
     Am afisat tabla.


 ~~~~~~~~~~~~~~~~~~~~Task 2~~~~~~~~~~~~~~~~~~~~~~~~

    (Initial am avut aceleasi denumiri pentru variabilele de la task-urile 2 si 
  3,  dar la un moment dat n-am mai primit punctaj pe task-ul 2, asa ca le-am 
  schimbat numele, de aici vine 'alfabet1')
    Am creat un vector pentru fiecare litera din alfabet in care am stocat
  cate puncte au literele:
    De exemplu, pentru cele cu un punct aveam;
    A, E, I,  L,   N,   O,  R,  S,   T,  U  -literele
     0, 4, 8, 11, 13, 14, 17, 18, 19, 20  -pozitia in vector
    Am folosit aceeasi metoda ca la task-ul 1 pentru citirea liniilor. 
    Am parcurs literele fiecarui cuvant cu un for, iar din fiecare litera 
  am scazut codul Ascii al lui 'A' pentru a afla pozitia literei in vectorul
  meu 'alfabet1'. 
     ---->auxiliar = copie[contor] - 65;
    Am adunat scorul fiecarei litere in sc.
    Am folosit variabila play pentru a verifica jucatorul, daca este para
  ultimul cuvant a fost pus de player 1, iar daca e impara, de player 2.
    In functie de play am adunat mai departe scorul la player 1 sau player 2.
    La final am afisat scorul pentru ambii jucatori.


  ~~~~~~~~~~~~~~~~~~~~~~Task 3~~~~~~~~~~~~~~~~~~~~~~~~~

    Am initializat acelasi vector pentru literele din alfabet, stiu ca era mai 
  simplu sa il pun la inceput o singura data, dar n-am mai primit punctaj
  pe Task-uri cand am incerat.
    Am folosit aceeasi metoda pentru citirea liniilor si calcularea scorului.
    Am verificat cu un for daca substring-ul pentru bonusul marcat cu 1
  se gaseste in cuvant. B1[0] este prima litera a lui XX, iar B1[1] a 2-a.
    Am verificat asa deoarece nu am reusit cu strstr. 
    Daca se gaseste, in functie de directia pe care este pus, verific tabla 
  bonus cu un alt for.
    De exemplu, daca un cuvant e pus pe orizontala (directia e 0), verific
 tabla bonus incepand de la indicii cuvantului, crescand coloana, daca
 pe tabla este vreun 1 inmultesc produsul cu 2. Dupa ce parcurg for-ul pentru
 tabla bonus, cel initial se opreste.
    Analog daca directia este 1. 
    Am facut acelasi lucru si pentru bonusul marcat cu 2, doar ca de data asta
 am verificat daca se afla la final.
 In functie de valoarea lui player adaug scorul inmultit cu bonusul lui 
 Player 1 sau Player 2.


   ~~~~~~~~~~~~~~~~~~~~~~Task 4~~~~~~~~~~~~~~~~~~~~~~~~~

     Am creat un vector numit cuvinte in care stochez toate cuvintele puse pe 
  tabla.
     Aceeasi metoda pentru citirea liniilor si punerea cuvintelor pe tabla ca 
 la celelalte Task-uri.
     Am adaugat variabila index pe care o cresc dupa fiecare cuvant citit si o 
 folosesc pentru a stoca cuvantul in vectorul de cuvinte 
           ---> strcpy(cuvinte[index],cop);
      In while testez fiecare cuvant din vectorul words pentru a-l gasi pe cel 
  care se potriveste. 
      Prima data verific daca cuvantul a fost folosit, comparandu-l cu toate
  din vectorul de cuvinte.
      Daca nu se afla in vectorul de cuvinte, parcurg tabla de joc. In cele 2 
  for-uri am adaugat si conditia (stop2==1), deoarece voi folosi variabila
  'stop' sa le opresc cand gasesc un cuvant. 
      Verific initial daca prima litera se afla pe tabla, daca da 'merge' primeste 
   1 si pot continua.
     Verific apoi daca il pot pune pe orizontala, adica daca nu iese din tabla, 
  daca il pot pune, parcurg linia pe care vreau sa il pun si verific daca se 
  afla altceva inafara de punct, daca da, variabila 'merge' primeste 0.
      Daca variabila 'merge' este inca 1, pun cuvantul pe tabla si opresc 
  for-urile cu care parcurg tabla si while ul cu care parcurg vectorul words.
      Daca nu am pus cuvantul pe tabla, fac aceleasi verificari pe verticala.

 
  ~~~~~~~~~~~~~~~~~~~~~~Task 5~~~~~~~~~~~~~~~~~~~~~~~~~

    Am facut acelasi vector alfabet, iar apoi cu while am citit cuvintele si 
 le-am pus pe tabla, le-am calculat scorul si punctajul bonus (ca la Task 3) si 
 am format iar vectorul cuvinte  
       ---> strcpy(cuvinte[index],cop);
    Cu un while am parcurs toate cuvintele din words, am verificat daca 
cuvantul la care am ajuns este folosit. Daca nu este folosit, am verificat daca 
 prima litera este pe tabla. Daca este pe tabla, verific daca as putea pune 
 cuvantul pe tabla, initial pe orizontala. Cu scor si p calculez scorul si 
 punctajul bonus pentru fiecare cuvant (care nu se intersecteaza cu nimic daca
 este pus pe tabla). Pentru scor si punctajul bonus am folosit aceeasi metoda
 ca la Task-ul 3. Dupa ce calculez scorul cu tot cu bonusuri, fac mai multe 
 verificari pentru a vedea daca acel cuvant merita sa fie pus pe tabla:
 -->daca adunat la scorul pe care player 2 il are deja, este mai mare decat
 scorul lui player 1, 
 -->daca este mai mare decat scorul maxim retinut anterior.
   In cazul in care scorul curent este egal cu scorul maxim, verific intai 
 daca cuvantul anterior a fost pe orizontala sau verticala, daca a fost pe 
 orizontala, nu are rost sa retin cuvantul curent.
   Daca scorul este egal cu scorul maxim, iar ultimul cuvant a fost pe 
 verticala, verific daca ultimele coordonate sunt mai mari decat cele curente, 
 daca da, pot retine noul cuvant. In cazul in care ultimele coordonate sunt 
 mai mici sau daca doar ultima linie retinuta e mai mica, inseamna ca nu 
 voi retine datele despre cuvantul la care am ajuns.
  In urma acestor verificari, daca variabila 'merge' a ramas 1, inseamna ca pot
 retine datele cuvantului: coloana si linia de la care incepe, directia pe care
 vreau sa il pun (in primul caz pe orizontala), cuvantul in sine, scorul si
 pozitia sa in vectorul words. 
    Variabila merge primeste valoarea 1, deoarece urmeaza sa vad daca cuvantul
  poate fi pus si pe verticala. Metoda de verificare este simetrica cu ce am 
  descris mai sus: verific daca cuvantul nu iese din tabla pe verticala, daca
  in locul in care vreau sa il pun exista altceva pe tabla inafara de '.', ii 
  calculez scorul si punctajul bonus. Daca scorul obtinut adaugat la scorul lui
  Player 2 nu imi da un scor mai mare decat cel al lui Player 1 sau daca scorul
  curent este mai mic decat scorul maxim, nu retin datele despre cuvant. Daca
  scorul curent este egal cu cel maxim, verific daca ultimul cuvant a fost pus 
  pe orizontala, daca da, nu trec mai departe. In cazul in care ultimul cuvant
  a fost pus pe verticala, verific daca ultimele coordonate sunt mai mari decat 
  cele curente, daca da, 'merge' primeste 1, daca nu, 'merge' primeste 0.
     Daca 'merge' a ramas 1, pot retine datele cuvantului.
     Dupa ce am parcurs toate cuvintele, urmeaza sa il pun pe cel optim pe 
  tabla.
    Variabila directie_f a primit 2 la inceput, deci daca nu a fost gasit niciun 
  cuvant optim, nu voi intra pe if-urile in cadrul carora pun cuvantul. Daca
  totusi a fost un cuvant optim, il pun pe tabla in functie de directia pe care
  am memorat-o. 'lit' a primit 1 la inceput, deoarece o sa folosesc aceasta 
  variabila pentru a parcurge literele cuvantului pe care vreau sa il pun:
           ----> words[index_f][lit];
    Cu acel for parcurg tabla incepand de la coordonatele pe care le-am memorat
  pentru a pune cuvantul.
    La final, daca scorul lui Player 2 adunat cu scor_maxim nu imi da un scor 
 mai mare decat cel al lui Player 1, inseamna ca nu a fost gasit un cuvant optim, 
 deci afisez "Fail!", altfel afisez tabla.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   



  
 


 
 
 


