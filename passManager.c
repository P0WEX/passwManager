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
  puts("sito del login: (no spazi)");
  scanf("%s", sito);
  puts("email or username: ");
  scanf("%s", email);
  puts("password: ");
  scanf("%s", passw);

  FILE *pt;
  pt = fopen("nomeDelFile.txt","a");
  fprintf(pt,"\n");
  fprintf(pt,"%s:%s:%s",sito , email, passw);
  fclose(pt);
  
  puts("Credenziali inserite correttamente!");
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
  puts("Nome del login da modificare? ");
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
            printf("Sito: %s, ",token);
            token = strtok(NULL, ":");
            printf("Email/Username: %s, ",token);
            token = strtok(NULL, ":");
            printf("Password: %s\n\n",token);
            puts("Vuoi modificarlo? 0=>SI, 1=>NO");
            scanf("%d", &sesso);
            risposta=sesso;
            if (risposta == 0)
                {
                  system("cls");
                  puts("Nuovo nome del Sito: ");
                  scanf("%s", newSito);
                  puts("Nuovo Email/Username: ");
                  scanf("%s", newEmail);
                  puts("Nuova Password: ");
                  scanf("%s", newPassw);
                  fprintf(ptemp, "%s:%s:%s\n", newSito,newEmail,newPassw);
                }
            else
                fprintf(ptemp, "%s",temp );
      }
      else 
        fprintf(ptemp, "%s",temp );      
      }
  if (trovato){
      puts("Credenziali sostituite Correttamente! \n\n\n");
  }
  else{
      puts("Credenziali NON trovate! \n\n\n");
  }
  puts("Qualsiasi tasto per tornare al menu principale...");
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


  puts("\t\tNome del login da visualizzare? ");
  scanf("%s", query);
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
          trovato=1;
          break;
      }
      
  }

  fclose(pt);
  system("cls");
  
  if (trovato){
 
  puts("Ecco le informazioni: ");
  printf("Sito:%s,  Email:%s, Password:%s\n\n", newSito,newEmail, newPassw);

}
  
  else
    puts("Nessuna credenziale trovata! \n\n");
    
  puts("Qualsiasi tasto per tornare al menu principale...");
  getch();
  system("cls");

}
  

int main () {
    size_t scelta;

    while (1)
    {
        
        puts ("\t\t -- BENVENUTO COGLIONE DI MERDA! -- \n");
        puts ("© Copyright 2020-20PERSEMPRE, Se mi zappi il programma ti spezzo le gambe\n");
        puts ("1- Aggiungere una credenziale\n2-Modificare una credenziale\n3-Visualizzare una credenziale\n4-Esci\n\t\t CHE VUO' ?");
        scanf("%d", &scelta);
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
          exit(EXIT_SUCCESS);
          break;
        
        default:
          system("cls");
          puts("AOOOOOOOOO\n MA SI SCEMUNIT? SCRIVI BUON\n\n");
          puts("Qualsiasi tasto per tornare al menu principale...");
          getch();
          break;
        }
    }

    return 0;
}
