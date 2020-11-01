#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

void add () {

  char email[100];
  char  passw[100];
  char  sito[100];
  system("cls");
  printf("\033[1;33m");
  puts("Digitare il nome del sito/applicazione: ");
  printf("\033[0m");
  scanf("%s", sito);
  printf("\033[1;33m");
  puts("Email/Username: ");
  printf("\033[0m");
  scanf("%s", email);
  printf("\033[1;33m");
  puts("Password: ");
  printf("\033[0m");
  scanf("%s", passw);

  FILE *pt;
  pt = fopen("nomeDelFile.txt","a");
  fprintf(pt,"\n");
  fprintf(pt,"%s:%s:%s",sito , email, passw);
  fclose(pt);

  printf("\033[0;32m");
  puts("\n\nCredenziali aggiunte correttamente!");
  printf("\033[0m");
  puts("\n\n\nQualsiasi tasto per tornare al menu principale...");
  getch();
  system("cls");

}
void modify(){
  char query[100];
  char creds[250];
  char temp[250];
  char newSito[50];
  char newEmail[50];
  char newPassw[50];
  bool risposta;
  char *token;
  int sesso;
  int trovato=0;
  system("cls");
  printf("\033[1;33m");
  puts("Nome del login da modificare? ");
  printf("\033[0m");
  scanf("%s", query);
  puts("\n");
  FILE *pt, *ptemp;
  pt= fopen("nomeDelFile.txt", "r");
  ptemp= fopen("nomeDelFileTemporaneo.txt", "w");
  while ( (fgets(creds, sizeof(creds), pt) != NULL)){
      strcpy(temp,creds);
      token = strtok(creds, ":");
      if ( strcmp(token, query) == 0){
            trovato=1;
            strcpy(newSito, token);
            system("cls");
            printf("\033[1;32m");
            printf("Sito: ");
            printf("\033[0m");
            printf("%s  ",newSito);
            printf("\033[1;32m");
            token = strtok(NULL, ":");
            strcpy(newEmail, token);
            printf("Username/Email: ");
            printf("\033[0m");
            printf("%s  ",newEmail);
            printf("\033[1;32m");
            token = strtok(NULL, ":");
            strcpy(newPassw, token);
            printf("Password: ");
            printf("\033[0m");
            printf("%s \n\n",newPassw);
            printf("\033[1;31m");
            puts("Vuoi modificarlo? 0=>SI, 1=>NO");
            printf("\033[0m");
            scanf("%d", &sesso);
            risposta=sesso;
            if (risposta == 0)
                {
                  system("cls");
                  printf("\033[1;32m");
                  puts("Nuovo nome del Sito: ");
                  printf("\033[0m");
                  scanf("%s", newSito);
                  printf("\033[1;32m");
                  puts("Nuovo Email/Username: ");
                  printf("\033[0m");
                  scanf("%s", newEmail);
                  printf("\033[1;32m");
                  puts("Nuova Password: ");
                  printf("\033[0m");
                  scanf("%s", newPassw);
                  fprintf(ptemp, "%s:%s:%s\n", newSito,newEmail,newPassw);
                }
            else
                fprintf(ptemp, "%s",temp );
      }
      else
        fprintf(ptemp, "%s",temp );
      }
  if (trovato==1 && risposta == 0){
      printf("\033[0;32m");
      puts("\n\nCredenziali sostituite correttamente!");
      printf("\033[0m");
  }
  else if (trovato == 0){
      printf("\033[1;31m");
      puts("Nessuna credenziale trovata! ");
      printf("\033[0m");
  }
  puts("\n\nQualsiasi tasto per tornare al menu principale...");
  getch();
  fclose(pt);
  fclose(ptemp);
  remove("nomeDelFile.txt");
  rename("nomeDelFileTemporaneo.txt", "nomeDelFile.txt");



}
void search(){
  char query[100];
  char creds[250];
  char * token;
  int trovato=0;
  char newSito[50];
  char newEmail[50];
  char newPassw[50];

  printf("\033[01;33m");
  puts("\t\tNome del login da visualizzare? ");
  printf("\033[0m");
  scanf("%s", query);
  system("cls");
  FILE *pt;
  pt= fopen("nomeDelFile.txt", "r+");
  while ( (fgets(creds, sizeof(creds), pt) != NULL)){
      token=strtok(creds, ":");
      if ( strcmp(token, query) == 0){
          strcpy(newSito,token);
          token=strtok(NULL, ":");
          strcpy(newEmail,token);
          token=strtok(NULL, ":");
          strcpy(newPassw,token);
          printf("\033[1;32m");
          printf("Sito: ");
          printf("\033[0m");
          printf("%s  ",newSito);
          printf("\033[1;32m");
          printf("Username/Email: ");
          printf("\033[0m");
          printf("%s  ",newEmail);
          printf("\033[1;32m");
          printf("Password: ");
          printf("\033[0m");
          printf("%s",newPassw);
          trovato=1;
      }

  }
  puts("\n");
  fclose(pt);

  if (trovato == 0){
      printf("\033[1;31m");
      puts("Nessuna credenziale trovata! \n\n");
      printf("\033[0m");
     }
  puts("Qualsiasi tasto per tornare al menu principale...");
  getch();
  system("cls");

}


int main () {
    size_t scelta;
    char masterPasw[50];

    puts("\t\t\t   |                           |     ");
    puts("\t\t\t___|___________________________|_____");
    puts("\t\t\t|                                   |");
    puts("\t\t\t| + Inserisci la master password +  |");
    puts("\t\t\t|___________________________________|");
    scanf("%s",masterPasw);

    if (strcmp(masterPasw, "password")!= 0)
        {
          system("cls");
          printf("\033[1;31m");
          printf("\n\n\n\t\t\t Master Password Sbagliata! Error:912");
          printf("\033[0m");
          sleep(2);
          system("cls");

          printf("\n\n\n\t\t\tCC 2020 - P0WEX Creative Commons Lincenses ");
          sleep(1);
          system("cls");
          exit(EXIT_SUCCESS);
        }
    else{
    while (1)
    {
        do{
        system("cls");
        printf("\033[01;33m");
        puts("___  ____ ____ ____ _ _ _ ____ ____ ___     _  _ ____ _  _ ____ ____ ____ ____         ____     ");
        puts("|__] |__| [__  [__  | | | |  | |__/ |  \\    |\\/| |__| |\\ | |__| | __ |___ |__/     |   |  |     ");
        puts("|    |  | ___] ___] |_|_| |__| |  \\ |__/    |  | |  | | \\| |  | |__] |___ |  \\     | . |__|     ");
        puts("                                                                                               \n\n ");
        printf("\033[0m");

        printf("%c 1 - Aggiungere una credenziale\n", 201);
        printf("%c 2 - Modificare una credenziale\n", 204);
        printf("%c 3 - Visualizzare una credenziale\n", 204);
        printf("%c 4 - Esci\n\n? ", 200);
        scanf("%d", &scelta);
        }while (scelta < 0 || scelta > 5);
        switch (scelta)
        {
        case 1:
          system("cls");
          add();
          break;
        case 2:
          system("cls");
          modify();
          break;

        case 3:
          system("cls");
          search();
          break;
        case 4:
          system("cls");
          printf("\n\n\n\t\t\tCC 2020 - P0WEX Creative Commons Lincenses ");
          sleep(1);
          system("cls");
          exit(EXIT_SUCCESS);
          break;
        }
    }

    return 0;
}

/*
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKOxdollllloxk0XNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOl:kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxc'.            ..,cd0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0c. .dWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'  .';cloooolc;'.     .,dXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo.  .dXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'.:ONWMMMMMMMMWNXOdc'    'kWMMMMMMMMMMMMMMMMMMMMMMMMMMNk,  .lKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXKNMMMMMMMMMMMMMMMMWNk:.  .kMMMMMMMMMMMMMMMMMMMMMMMMW0:.  :0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWx.  cNMMMMMMMMMMMMWX0kxooooxkl.  'xNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNkloKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMMMMMMMMMMX;  ,KMMMMMMMMMW0d:..           cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMx. .xMMMMMMMMMMMWXOkKWMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0l,oNMMMMMMMMMM0'  :XMMMMMMWKd;.   .';::'      :KMMMMMMN0dlkNMMMMMMMMMMMMMMMMMMMMMMMW0:. ;XMMMMMMMMMMMMWXOkdoooxKWMMMMMk.  oWMMMMMMMWXx:.  :XMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMX;  ,KMMMMMMMMW0,  .kWMMMMWKo.   'lOXNWNx'  ..   ,0MMMMXl.  '0MMMMMMMMMMMMMMMMMMMMMMMNl   ;KMMMMMMMMWKxc,.       .dNMMMMK,  ,KMMMMMWKo.  ..,dNMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO.  cNMMMMMMWXo.  ,OWMMMMWx'   'dXMMMMKc. .:0Xl.  lNMMWx.  .lNMMMMMMMMMWXxlOWMMMMMMMMWo   oWMMMMMWKd;.  ..;cll:.  'OMMMMWo  .dWMMWKl.  .l0NWWMMMMMMMMMMMMMMMMMM
MMMMMWXNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNc  .kMMMMMNOl.  .lKMMMMMNo.  .oXMMMMNx'  .xNMMX;  ,0MM0,  ,d0MMMMMMMMMWx'  cNMMMMMMMMX;  '0MMMMMXo.  .;d0NWMMMNc  .kMMMMM0,  ;KMNd'  .oKWMMMMMMMMMMMMMMMMMMMMMM
MMMWk;.,oOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMWx.  lNWNKkl,.  .l0WMMMMMNo.  'OWMMMMKc.  :0WMMMNc  .OMNc  .xWWMMMMMMMMWk.  .xMMMMMMMMMk.  lNMMMWO,  .l0WMMMMMMXo.  cXMMMMMWo  .ok;  .c0WMMMMMMMMMMMMMMMMMMMMMMMM
MMMWd.    .;cdk0KNWWMMMMMMMMMMMMMMMMMMM0,  .:l;'.   'ckXWMMMMMMWx.  ;0MMMMWO,  .xNMMMMMK,  ,KWk.  cNMMMMMMMMMM0,   :XMMMMMMMMNc  .OMMMNx.  ,OWMMMMWNOo'  .lXMMMMMMMO.  .   ;OWMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMWOl,.      ...,;:cllooodddddooollc:.       .':oOXWMMMMMMMMWk.  :KMMMMXo.  ;0WMMMMMNl  .dWK,  ,0MMMMMMMMMMK;   .OMMMMMMMMMk.  cNMMWx.   'loddol:'   .cOWMMMMMMMMX;    ,xNMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMNKkdc;'..                          ':lxOKNWMMMMMMMMMMMM0'  ,0MMMWO;  .lXMMMMMMXl.  lNNo  .dWMMMMMMMMMNl    cNMMMMMMMMX:  .OMMMO'            .,lkXWMMMMMMMMMXd.   ;KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMWNXK0kxddoolllccccllloodd:   ;KMMMMMMMMMMMMMMMMMMNl  .xWMMNd.  ,OWMMMMMNk,  .dNM0'  ;XMMMMMMMMMNo.   .xMMMMMMMMWx.  lNMMX:  .lolccclodkKNMMMMMMMMMMMNk,     .OMMMMMMMMWXXWMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMX:  .OMMMMMMMMMMMMMMMMMMMK,  ;KMMKc  .lXMMMMMNk;   ;OWMWd. .dWMMMMMMMMNo.    ,KMMMMMMMMK,  ,0MMM0'  :XMMMMMMMMMMMMMMMMMMMMW0:.  ;c.  :KMMMMMWO:.:KMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd.  lNMMMMMMMMMMMMMMMMMMM0,  ;KNx'  .xNMMMNOo'   ;kNMMMX:  '0MMMMMMMMXl.     :NMMMMMMMX:  .xWMMMk.  lWMMMMMMMMMMMMMMMMMMMNd.  'xNNl   ,kNMMMX:  '0MMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0'  ,KMMMMMMMMMMMMMMMMMMMMNc   ;;.  :0WNKkl,   .cONMMMMMO.  cNMMMMMMXd'  .;.  :NMMMMMMK:  .dWMMMMO'  ;KMMMMMMMMMWX0XMMMMM0:  .lKMMMXc   .;okOo.  lNMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNl  .xWMMMMMMMMMMMMMMMMMMMMMK;      .:c;'.   'ckXWMMMMMMMk.  :XWWNX0d'  .c0K;  .xNMMMWk,  .xWMMMMMNl   cXMMMMMMW0l'.cNMMNx.  'kWMMMMMNx,         :KMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk.  cNMMMMMMMMMMMMMMMMMMMMMMM0'         .':oONWMMMMMMMMMMX:   ';,...  .cOWMWk.  .;oxd:.  ;0WMMMMMMMK:   'lxOOOd:.  'xWWK:. .cKMMMMMMMMMXkl:,',,cxXMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;  '0MMMMMMMMMMMMMMMMMMMMMMW0:  .:ooodxOKNMMMMMMMMMMMMMMMM0:.   ...,cdKWMMMMWk,       .,xNMMMMMMMMMMKc.         .,oKWNx'  'xNMMMMMMMMMMMMMMWNNWMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo  .dWMMMMMMMMMMMMMMMMMMMMMNx.  'kWMMMMMMMMMMMMMMMMMMMMMMMMMN0kkO0XNWMMMMMMMMMMXkl:::cd0NMMMMMMMMMMMMMW0o:,,,,:lx0NMWKc.  :KWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMk.  cXMMMMMMMMMMMMMMMMMMMMMXc.  cKMMMMMMWWNXK0OkkxdooollcccccccccccclllooooddxkkOO00KXXNNWWWMMMMMMMMMMMMMMWWWWWWMMMMNx'  .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXxlkNMMMMMMMMMMMMMMMMMMMMMMK;.'dNMMWKxl:;,....                                     ....'',,;::clooddxkOOO0KKXWMMMMMNo.  :0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXKXWMMM0,    ...',;:ccllooddddddddddddoooolllcc::;;,,'.....                  ....cKMMMMNd,,dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNkodkO0XNNWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWNNXKK00OOkxdolllc::;,,'...  ;0MMMMMWNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWNNXK00XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
*/
