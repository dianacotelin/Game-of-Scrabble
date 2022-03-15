// 311CD COTELIN MARIA-DIANA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/print_board.h"
#include "util/scrabble.h"


int main(){
    char board[15][15];
    int i, j, t=0;
    char task[10];

    fgets(task, 10, stdin);
    t=atoi(task);

    for(i=0; i<15; i++)
        for(j=0; j<15; j++)
            board[i][j] = '.';
    
    
    if(t==0){
    print_board(board);
    }

    if(t==1){

        int nr;
        char N[30];
        fgets(N,30,stdin);
        nr = atoi(N);
        
        
        while(nr>0){
            int col, lin, dir;
            long unsigned int k;
            char cuv[40], cop[40];
            char *token;
            fgets(cuv, 40, stdin);
            token = strtok(cuv, " "); 
            lin = atoi(token);

            token = strtok(NULL, " ");
            col = atoi(token);

            token = strtok(NULL, " ");
            dir = atoi(token);

            token = strtok(NULL, "\n");
            strcpy(cop, token);
            strtok(cop, " ");
            strtok(cop, "\n");
        
            if (dir==0){
                for(k=0; k<=strlen(cop)-1; k++){
                    board[lin][col] = cop[k];
                    col++;
                }
            }
        
            if(dir==1){ 
                for(k=0; k<=strlen(cop)-1; k++){
                    board[lin][col] = cop[k];
                    lin++;
                }
            }

        nr--;
        } 
        print_board(board);
        }

        if (t==2){
        int alfabet1[26];
        for(i=0; i<26; i++){
            if ((i==0)||(i==4)||(i==8)||(i==11)||(i==13)||(i==14)||(i==17))
                alfabet1[i]=1;
            if ((i==18)||(i==19)||(i==20))
                alfabet1[i]=1;
            if ((i==3)||(i==6))
                alfabet1[i]=2;
            if ((i==1)||(i==2)||(i==12)||(i==15))
                alfabet1[i]=3;
            if (((i==7)||(i==5)||(i==21)||(i==22)||(i==24)))
                alfabet1[i]=4;
            if(i==10)
                alfabet1[i]=5;
            if((i==9)||(i==23))
                alfabet1[i]=8;
            if((i==16)||(i==25))
                alfabet1[i]=10;
        }

        int n, play=0, sc_p1=0, sc_p2=0, sc;
        char Nr[30];
        fgets(Nr,30,stdin);
        n = atoi(Nr);

        while(n>0){
            int auxiliar;
            long unsigned int contor;
            char cuvant[40], copie[40];
            char *tok;
            sc = 0;
            fgets(cuvant, 40, stdin);
            tok = strtok(cuvant, " ");
        
            tok= strtok(NULL, " ");
            tok = strtok(NULL, " ");
            tok = strtok(NULL, "\n");
            strcpy(copie, tok);
            strtok(copie, " ");
            strtok(copie, "\n");

            for(contor=0; contor<=strlen(copie); contor++){
                auxiliar = copie[contor] - 65;
                sc = sc + alfabet1[auxiliar];
            }

            if (play%2==0)
                sc_p1 = sc_p1+sc;
            else
                sc_p2 = sc_p2+sc;

            play++;
            n--;
       
        }
        printf("Player 1: %d Points\n", sc_p1);
        printf("Player 2: %d Points\n", sc_p2);
        }

    if(t==3){
        int alfabet[26];
        for(i=0; i<26; i++){
            if ((i==0)||(i==4)||(i==8)||(i==11)||(i==13)||(i==14)||(i==17))
                alfabet[i]=1;
            if ((i==18)||(i==19)||(i==20))
                alfabet[i]=1;
            if ((i==3)||(i==6))
                alfabet[i]=2;
            if ((i==1)||(i==2)||(i==12)||(i==15))
                alfabet[i]=3;
            if (((i==7)||(i==5)||(i==21)||(i==22)||(i==24)))
            alfabet[i]=4;
                if(i==10)
            alfabet[i]=5;
                if((i==9)||(i==23))
            alfabet[i]=8;
                if((i==16)||(i==25))
            alfabet[i]=10;
        }

        int nr, player=0, scor_p1=0, scor_p2=0, scor;
        char N[30], B1[10], B2[10];
        fgets(B1,10,stdin);
        fgets(B2,10,stdin);
        fgets(N,30,stdin);
        nr = atoi(N);

        while(nr>0){
            int col, lin, dir, aux, p=1;
            long unsigned int k;
            char cuv[40], cop[40], cop2[40];
            char *token;
            scor=0;
            fgets(cuv, 40, stdin);
            token = strtok(cuv, " "); 
            lin = atoi(token);

            token = strtok(NULL, " ");
            col = atoi(token);

            token = strtok(NULL, " ");
            dir = atoi(token);

            
            token = strtok(NULL, "\n");
            strcpy(cop, token);
            strcpy(cop2, token);
            strtok(cop, " ");
            strtok(cop, "\n");
        
            for(k=0; k<=strlen(cop); k++){
                aux = cop[k] - 65;
                scor = scor + alfabet[aux];
            }

            for(k=0; k<=strlen(cop); k++)
                if ((cop[k]==B1[0])&&(cop[k+1]==B1[1])){
                    if (dir==0){
                        for(k=col; k<col+strlen(cop); k++){
                           if (bonus_board[lin][k]==1){
                                p = p*2;
                           }
                        }
                    }
                    if (dir==1) 
                        for(k=lin; k<lin+strlen(cop); k++)
                            if (bonus_board[k][col]==1)
                                p = p*2;
                    
                } 
            
            
            if((cop[strlen(cop)-2]==B2[0])&&(cop[strlen(cop)-1]==B2[1])){
                if (dir==0){
                    for(k=col; k<col+strlen(cop); k++){
                        if (bonus_board[lin][k]==2){
                           p = p*3;
                        }
                    } 
                }       
                if (dir==1){ 
                    for(k=lin; k<lin+strlen(cop); k++){
                        if (bonus_board[k][col]==2){
                           p = p*3;
                        }
                    }
                }    
            } 
            
            
            if (player%2==0)
                scor_p1=scor_p1+scor*p;
            else
                scor_p2=scor_p2+scor*p;

            player++;
            nr--;  
        }

    printf("Player 1: %d Points\n", scor_p1);
    printf("Player 2: %d Points\n", scor_p2);    
    }

    if(t==4){
        int nr, n;
        char N[30], B1[10], B2[10], cuvinte[100][100];
        fgets(B1,10,stdin);
        fgets(B2,10,stdin);
        fgets(N,30,stdin);
        nr = atoi(N);
        n = nr;

        int index=0;
        int col, lin, dir;
        long unsigned int k;
        char cuv[40], cop[40];
        char *token;

        while(nr>0){
        
            fgets(cuv, 40, stdin);
            token = strtok(cuv, " "); 
            lin = atoi(token);

            token = strtok(NULL, " ");
            col = atoi(token);

            token = strtok(NULL, " ");
            dir = atoi(token);

            token = strtok(NULL, "\n");
            strcpy(cop, token);
            strtok(cop, " ");
            strtok(cop, "\n");
            strcpy(cuvinte[index], cop);

            if (dir==0){
                for(k=0; k<=strlen(cop)-1; k++){
                    board[lin][col] = cop[k];
                    col++;
                }
            }

            if(dir==1){ 
                for(k=0; k<=strlen(cop)-1; k++){
                    board[lin][col] = cop[k];
                    lin++;
                }
            }
            index++;    
            nr--;  
        }

        int stop=1, ok=1, linie, coloana, merge, lit, stop2=1;
        int linie2, coloana2;
        char aux[100];
        index = 0;

        while (stop!=0){
            ok = 1;
            strcpy(aux,words[index]);

            for (i=0; i<n; i++){
                // verifiv daca nu e folosit cuvantul
                if((strcmp(cuvinte[i],aux))==0){ 
                   ok=0;
                }  
            }
            
            if(ok==1){
                for(linie=0; ((linie<15)&&(stop2==1)); linie++)
                    for(coloana=0; ((coloana<15)&&(stop2==1)); coloana++){
                        stop2 = 1;
                        if(board[linie][coloana]==words[index][0]){
                             // verific daca prima litera e pe tabla
                            merge = 1;
                            if(strlen(aux)+coloana<=15){ 
                                // verific daca nu iese din tabla pe orizontala
                                for(coloana2=coloana+1; coloana2<coloana+(int)strlen(aux); coloana2++){ 
                                    // verific daca se intersecteaza cu ceva
                                    if(board[linie][coloana2]!='.'){
                                        merge = 0;
                                            }
                                    }    
                                    if(merge==1){
                                        lit = 1;
                                        for(coloana2=coloana+1; coloana2<coloana+(int)strlen(aux); coloana2++){ 
                                            //pun cuvantul
                                            board[linie][coloana2]=words[index][lit];
                                            lit++;
                                        } 
                                        stop2 = 0;  
                                        stop = 0;     
                                    }  
                                    }

                            merge=1;
                            if(stop2==1){    
                                if(strlen(aux)+linie<=15){ 
                                    // verific daca nu iese din tabla pe verticala
                                    for(linie2=linie+1; linie2<linie+(int)strlen(aux); linie2++){
                                        // verific daca se intersecteaza cu ceva
                                        if(board[linie2][coloana]!='.'){
                                            merge = 0;
                                        }
                                    }    
                                    if(merge==1){
                                        lit = 1;
                                        for(linie2=linie+1; linie2<linie+(int)strlen(aux); linie2++){ 
                                            //pun cuvantul
                                            board[linie2][coloana]=words[index][lit];
                                            lit++;
                                        } 
                                        stop2 = 0; 
                                        stop = 0;      
                                    }  
                                }
                            }
                                
                        }
                    }    
                }     
        index++;
        }
        print_board(board);
    }
   
    if (t==5){

        int alfabet[26];
        for(i=0; i<26; i++){
            if ((i==0)||(i==4)||(i==8)||(i==11)||(i==13)||(i==14)||(i==17))
                alfabet[i]=1;
            if ((i==18)||(i==19)||(i==20))
                alfabet[i]=1;
            if ((i==3)||(i==6))
                alfabet[i]=2;
            if ((i==1)||(i==2)||(i==12)||(i==15))
                alfabet[i]=3;
            if (((i==7)||(i==5)||(i==21)||(i==22)||(i==24)))
                alfabet[i]=4;
            if(i==10)
                alfabet[i]=5;
            if((i==9)||(i==23))
                alfabet[i]=8;
            if((i==16)||(i==25))
                alfabet[i]=10;
        }

        int nr, n, player=0, scor_p1=0, scor_p2=0, scor, col2, lin2;
        char N[30], B1[10], B2[10], cuvinte[100][100];
        fgets(B1,10,stdin);
        fgets(B2,10,stdin);
        fgets(N,30,stdin);
        nr = atoi(N);
        n = nr;

        int index=0;
        
        while(nr>0){

            long unsigned int k;
            int col, lin, dir, auxiliar, p=1;
            
            char cuv[40], cop[40];
            char *token;
            scor = 0;

            fgets(cuv, 40, stdin);
            token = strtok(cuv, " "); 
            lin = atoi(token);

            token = strtok(NULL, " ");
            col = atoi(token);

            token = strtok(NULL, " ");
            dir = atoi(token);

            token = strtok(NULL, "\n");
            strcpy(cop, token);
            strtok(cop, " ");
            strtok(cop, "\n");
            strcpy(cuvinte[index], cop);
            
            col2 = col;
            lin2 = lin;

            if (dir==0){ 
                //pun cuvantul pe tabla pe orizontala
                for(k=0; k<=strlen(cop)-1; k++){
                    board[lin2][col2]=cop[k];
                    col2++;
                }
            }

            if(dir==1){
                //pun cuvantul pe tabla pe verticala
                for(k=0; k<=strlen(cop)-1; k++){
                    board[lin2][col2]=cop[k];
                    lin2++;
                }
            }

            for(k=0; k<=strlen(cop); k++){
                auxiliar = cop[k]- 65;
                scor = scor + alfabet[auxiliar];
            }

            for(k=0; k<=strlen(cop); k++)
                if ((cop[k]==B1[0])&&(cop[k+1]==B1[1])){
                    //calculez bonusurile pentru primul sir

                    if (dir==0){
                        for(k=col; k<col+strlen(cop); k++){
                            if (bonus_board[lin][k]==1){
                                p = p*2;
                            }
                        }
                    }

                    if (dir==1){ 
                        for(k=lin; k<lin+strlen(cop); k++){
                            if (bonus_board[k][col]==1){
                               p = p*2;
                            }
                        }
                    }
                    
                } 
            
            
            if((cop[strlen(cop)-2]==B2[0])&&(cop[strlen(cop)-1]==B2[1])){
                //calculez bonusurile pentru al doilea sir

                if (dir==0){
                    for(k=col; k<col+strlen(cop); k++){
                        if (bonus_board[lin][k]==2){
                            p = p*3;
                        }
                    }
                } 

                if (dir==1){ 
                    for(k=lin; k<lin+strlen(cop); k++){
                        if (bonus_board[k][col]==2){
                            p = p*3;
                        }
                    }
                }
                
            } 
            
            
            if (player%2==0)
                scor_p1=scor_p1+scor*p;
            else
                scor_p2=scor_p2+scor*p;

            index++;
            player++;
            nr--;     
        }  
        int ok=1, linie, coloana, merge, lit, p, auxiliar;
        int linie_f, coloana_f, directie_f=2, scor_max=0, index_f;
        int linie2, coloana2;
        long unsigned int k;
        char aux[100], final[100];
        index = 0;
        while (index<100){ 
            ok = 1;
            strcpy(aux,words[index]);
            for (i=0; i<n; i++){
                if((strcmp(cuvinte[i],aux))==0){ 
                    // verifiv daca nu e folosit
                ok = 0;
                }  
            }

            if(ok==1){    
                for(linie=0; linie<15; linie++){
                    for(coloana=0; coloana<15; coloana++){
                        if(board[linie][coloana]==words[index][0]){ 
                            // verific daca prima litera e pe tabla
                            merge = 1;
                            if(strlen(aux)+coloana<=15){
                                // verific daca nu iese din tabla pe orizontala
                                p = 1;
                                scor = 0;
                                for(coloana2=coloana+1; coloana2<coloana+(int)strlen(aux); coloana2++){ 
                                    // verific daca se intersecteaza cu ceva
                                    if(board[linie][coloana2]!='.'){
                                            merge = 0;
                                    }  
                                } 
                                for(k=0; k<=strlen(aux); k++){ 
                                    //calculez scorul
                                    auxiliar = aux[k] - 65;
                                    scor = scor + alfabet[auxiliar];
                                }
                                for(k=0; k<=strlen(aux); k++)
                                    if ((aux[k]==B1[0])&&(aux[k+1]==B1[1])){
                                        //calculez punctajul bonus 1
                                        for(k=coloana; k<coloana+strlen(aux); k++){
                                            if (bonus_board[linie][k]==1){
                                                p = p*2;
                                            }
                                        }
                                    }

                                if((aux[strlen(aux)-2]==B2[0])&&(aux[strlen(aux)-1]==B2[1])){
                                    //calculez punctajul bonus 2
                                    for(k=coloana; k<coloana+strlen(aux); k++){
                                        if (bonus_board[linie][k]==2){
                                            p = p*3;
                                        }
                                    } 
                                }
                                scor = scor*p;   
                                if( scor_p2+scor*p < scor_p1)
                                    merge = 0;
                                if(scor_max>scor)
                                    merge = 0;
                                if((scor_max==scor)&&(directie_f==0))
                                    merge = 0;
                                if((scor_max==scor)&&(directie_f==1)){
                                    if((coloana_f>coloana)&&(linie_f>=linie))
                                        merge = 1;
                                    if((linie_f<linie)&&(coloana_f>coloana))
                                        merge = 0;
                                    if((coloana_f<coloana)&&(linie_f<linie))
                                        merge = 0;
                                }

                                if(merge==1){
                                    coloana_f = coloana + 1;
                                    linie_f = linie;
                                    directie_f = 0;
                                    strcpy(final, aux);
                                    scor_max = scor;
                                    index_f = index;     
                                }  
                            }
                            merge = 1;
                                
                            if(strlen(aux)+linie<=15){
                                // verific daca nu iese din tabla pe verticala 
                                p = 1;
                                scor = 0;
                                for(linie2=linie+1; linie2<linie+(int)strlen(aux); linie2++){ 
                                    // verific daca se intersecteaza cu ceva
                                    if(board[linie2][coloana]!='.'){
                                        merge = 0;
                                    }
                                }
                                 for(k=0; k<=strlen(aux); k++){ 
                                    //calculez scorul
                                    auxiliar = aux[k] - 65;
                                    scor = scor + alfabet[auxiliar];
                                }
                                for(k=0; k<=strlen(aux); k++)
                                    if ((aux[k]==B1[0])&&(aux[k+1]==B1[1])){
                                        //calculez punctajul bonus 1
                                        for(k=linie; k<linie+strlen(aux); k++){
                                            if (bonus_board[k][coloana]==1){
                                                p = p*2;
                                            }
                                        }
                                    }        
                                        

                                if((aux[strlen(aux)-2]==B2[0])&&(aux[strlen(aux)-1]==B2[1])){
                                    // calculez punctajul bonus 2
                                    for(k=linie; k<linie+strlen(aux); k++){
                                        if (bonus_board[k][coloana]==2){
                                            p = p*3;
                                        }
                                    } 
                                }

                                scor=scor*p;
                                if( scor_p2 + scor < scor_p1 )
                                    merge = 0;
                                if(scor_max>scor)
                                    merge = 0;
                                if((scor_max==scor)&&(directie_f==0))
                                    merge = 0;
                                if((scor==scor_max)&&(directie_f==1)){
                                    if((coloana_f>coloana)&&(linie_f>=linie))
                                        merge = 1;
                                    if((coloana_f<coloana)&&(linie_f<linie))
                                        merge = 0;
                                }

                                if(merge==1){
                                    coloana_f = coloana;
                                    linie_f = linie + 1;
                                    directie_f = 1;
                                    strcpy(final, aux);
                                    scor_max = scor;
                                    index_f = index;       
                                }  
                            }          
                        }
                    }
                }
            }             
        index++;
        }

        lit = 1;
    
        if (directie_f==0){
                for(coloana2=coloana_f; coloana2<coloana_f+(int)strlen(final)-1; coloana2++){ 
                    //pun cuvantul pe orizontala
                    board[linie_f][coloana2] = words[index_f][lit];
                    lit++;
                }
        }

        if (directie_f==1){
                for(linie2=linie_f; linie2<linie_f+(int)strlen(final)-1; linie2++){ 
                    //pun cuvantul pe verticala
                    board[linie2][coloana_f] = words[index_f][lit];
                    lit++;
                    }
        }
        
        scor_p2 = scor_p2 + scor_max;
        if(scor_p2>=scor_p1)
            print_board(board);
        if(scor_p2<scor_p1)
            printf("Fail!");
    }
    
    return 0;
}
