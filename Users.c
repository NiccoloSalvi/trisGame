#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define O 79
#define X 88
int main () {
    char matrice[3][3];
    int i,a,n,mossa,n_mosse=0,tris=0,p=9,errore=0;
    srand(time(NULL));
    printf("\t\tTRIS GAME\n");
    printf("\nPlayer 1: O\n");
    printf("Player 2: X\n\n");
    //Numero casuale tra 1 e 2, per stabilire casualmente a chi spetta la prima mossa
    mossa=rand()%2+1;
    //Riempimento della matrice, per vedere le posizioni
    for (i=0;i<3;i++) {
        for (a=2;a>=0;a--) {
            matrice[a][i]=p;
            p--;
        }
    }
    //Stampa della prima matrice dove vengono indicate le posizioni
    for (i=0;i<3;i++) {
        for (a=0;a<3;a++) printf("%d | ",matrice[a][i]);
        printf("\n");
    }
    //Azzeramento della matrice
    for (i=0;i<3;i++) for (a=0;a<3;a++) matrice[a][i]=0;
    while (tris==0) {
        if (mossa==1) printf("\nTurno: Player 1\n");
        else printf("\nTurno: Player: 2\n");
        do {
          printf("Inserisci n (1...9): ");
          scanf("%d",&n);
        } while (n<=0 || n>=10);
        errore=0;
        do {
          if (errore==1) {
            printf("Posizione occupata! Reinserisci n (1...9): ");
            scanf("%d",&n);
          }
          switch (n) {
            case 1: if (matrice[0][2]==0) {
                            if (mossa==1) matrice[0][2]=O;
                            else matrice[0][2]=X;
                            errore=0;
                    } else errore=1;
                    break;
            case 2: if (matrice[1][2]==0) {
                            if (mossa==1) matrice[1][2]=O;
                            else matrice[1][2]=X;
                            errore=0;
                    } else errore=1;
                    break;
            case 3: if (matrice[2][2]==0) {
                            if (mossa==1) matrice[2][2]=O;
                            else matrice[2][2]=X;
                            errore=0;
                    } else errore=1;
                    break;
            case 4: if (matrice[0][1]==0) {
                            if (mossa==1) matrice[0][1]=O;
                            else matrice[0][1]=X;
                            errore=0;
                    } else errore=1;
                    break;
            case 5: if (matrice[1][1]==0) {
                            if (mossa==1) matrice[1][1]=O;
                            else matrice[1][1]=X;
                            errore=0;
                    } else errore=1;
                    break;
            case 6: if (matrice[2][1]==0) {
                            if (mossa==1) matrice[2][1]=O;
                            else matrice[2][1]=X;
                            errore=0;
                    } else errore=1;
                    break;
            case 7: if (matrice[0][0]==0) {
                            if (mossa==1) matrice[0][0]=O;
                            else matrice[0][0]=X;
                            errore=0;
                    } else errore=1;
                    break;
            case 8: if (matrice[1][0]==0) {
                            if (mossa==1) matrice[1][0]=O;
                            else matrice[1][0]=X;
                            errore=0;
                    } else errore=1;
                    break;
            case 9: if (matrice[2][0]==0) {
                            if (mossa==1) matrice[2][0]=O;
                            else matrice[2][0]=X;
                            errore=0;
                    } else errore=1;
                    break;
          }
        } while (errore==1);
        //Cambio dell'utente a cui spetta la prossima mossa
        if (errore==0) {
          if (mossa==1) mossa=2;
          else mossa=1;
        //Stampa della tabella con situazione aggiornata all'ultima mossa
        printf("\n");
        for (i=0;i<3;i++) {
            for (a=0;a<3;a++) printf("%c | ",matrice[a][i]);
            printf("\n");
        }
        //Controllo tris verticale
        for (i=0;i<3;i++) {
          a=0;
          if (matrice[i][a]==matrice[i][a+1] && matrice[i][a]==matrice[i][a+2]
              && matrice[i][a]!=0 && matrice[i][a+1]!=0 && matrice[i][a+2]!=0) tris=1;
        }
        //Controllo tris orizzontale
        for (i=0;i<3;i++) {
          a=0;
          if (matrice[a][i]==matrice[a+1][i] && matrice[a][i]==matrice[a+2][i]
              && matrice[a][i]!=0 && matrice[a+1][i]!=0 && matrice[a+2][i]!=0) tris=1;
        }
        //Controllo tris obliquo decrescente
        if (matrice[0][0]==matrice[1][1] && matrice[0][0]==matrice[2][2]
            && matrice[0][0]!=0 && matrice[1][1]!=0 && matrice[2][2]!=0) tris=1;
        //Controllo tris obliquo crescente
        if (matrice[2][0]==matrice[1][1] && matrice[2][0]==matrice[0][2]
            && matrice[2][0]!=0 && matrice[1][1]!=0 && matrice[0][2]!=0) tris=1;
        //Condizione di parità
        n_mosse++;
        if (n_mosse==9) tris=1;
        if (tris==1) {
          //Cambio dell'utente a cui spetta la prossima mossa
          if (mossa==1) mossa=2;
          else mossa=1;
        }
      }
    }
    if (n_mosse==9) printf("\nNessun vincitore, pari!!\n");
    else {
        if (mossa==1) printf("\nIl vincitore e' Player 1\n");
        else printf("\nIl vincitore e' Player 2\n");
    }
    printf("\n\tEND GAME\n");
    return 0;
}
