//============================================================================
//    Constantes  
//============================================================================
void dummy_fill_inputs(void)                                                                  //  ROI
{
 int   i,temp;
 float femp;
  
    for(i=0;i<N_IN;i++)
          {    
          temp= random(100);
          femp=temp/100.0;
          Entrada[i]=femp;
          }
} 
//------------------------------------------------
  
//----------------------------------------------------
void fill_random_board(void)
{
 int i,j;
  
     for(j=0;j<9;j++)
       {   
        i=random(3);
        if(i==0) board[j]='-';               
        if(i==1) board[j]='X';  
        if(i==2) board[j]='O';    
       } 
    
} 
//------------------------------------------------------------
void fill_game_story(void)                                                                  //  ROI
{
 int   i;
   
    for(i=0;i<N_IN;i++)
          {    
           story[moves_counter][i]=Entrada[i];
          }
} 