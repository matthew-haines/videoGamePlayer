void ReadDb(FILE * Source, char *Name, struct node * Head){
  Source = fopen(Name, "rb+");
  user temp;
  while(!feof(Source)){
    fread(&temp, sizeof(user), 1, Source);
    if(temp.usrnm[0] != 0 && search(Head, temp) == (struct node *)-1) //make sure it is a user (sometimes things get left over for some reason)
    insert(Head, temp, compare_usrnm);
  }
  fclose(Source);
}

void WriteDb(FILE * Source, char *Name, struct node * Head){
   if(Source == NULL) Source = fopen(Name, "wb");
   
   fwrite(&Head->value, sizeof(user), 1, Source);

   if(Head->lc) WriteDb(Source,Name,Head->lc); //traverse BST
   if(Head->rc) WriteDb(Source,Name,Head->rc); //traverse BST

}
