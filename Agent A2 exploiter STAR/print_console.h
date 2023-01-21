//---------------------------------
//         PRINT CONSOLE

//-------------------------------------------------------------



//-----------------------------------------
void print_game_story(void)           //             GAME STORY                        
{
 int  i,j,k;
              system("cls");  
              cout << endl;
           
              cout << "game story";  
              cout << endl; 
              k=0;
              for(j=0;j<max_moves;j++)
               { 
                 cout <<" ";  
                 for(i=0;i<N_IN;i++)
                 {
                  cout << story[j][i]; 
                  k++;
                  if(k>2) {k=0; cout <<" ";}  
              
                 }
                if(j==2)  cout << endl;   
                if(j==4)  cout << endl;      
                cout << endl;  
               }
} 
//---------------------------------------
void print_future_targets(void)                                   
{
 int  i;
    
              cout << endl;   
              cout << "Targets " << "= " ;  
              for(i=0;i<N_OUT;i++)
                 {
                  cout << Target[i];
                  cout << "  ";   
                 }
              cout << endl;       
              cout << endl;  
} 
//---------------------------------------
void print_capa_salida(void)                                   
{
 int  i;
 float femp;   
      cout << "capa de salida Net  ";  
      for(i=0;i<N_OUT;i++)
         {
          femp= c_salida.out[i];
          if(femp<0.01) femp=0.01;             
          cout << setprecision(2)<<femp <<" ";     
         }
     cout << endl;      
} 

///----------------------------------------------··****
using namespace std;
void print_games_won(void)                                    
{
    
 //int  i;
   cout << endl;  
   cout << "games_won_O="<<games_won_O<<"   games_won_X="<<games_won_X<< "   games played="<< games_played;     
   cout << endl;
  
} 
//----------------------------------------------------------
void print_rotative_key(void)                                    
{
 int  i;
   cout << endl;  
   cout << "rotavive key  ";
    
    for(i=0;i<8;i++)
                {
                 //cout << rotative_key[i]<<" ";  
                }  
     
   cout << endl;
   cout << endl;             
} 
//-------------------------------------------------------------
void print_history(void)     //      AQUI SE IMPRIME EL HISTORIAL DEL JUEGO                                  
{
 int  i,j,k;
    
    for(k=0;k<5;k++)
        {        
              cout << "Sparse Input "<< k << "= " ;  
              j=0;
              for(i=0;i<N_IN;i++)
                 {
                  //
                  cout << Entrada[i];   //              OJO  MATRIZ A VECTOR
                
                  j++;
                  if(j>2) {j=0; cout <<" ";} 
                 }
             // cout << "  f_winner=" << f_winner;     
              cout << endl;       
             
        } 

} 
//---------------------------------------------------
void print_play_order_c(void)                                    
{
 int  i;
   cout << endl;  
   cout << "winners sequence=";
    
    for(i=0;i<9;i++)
                {
                 cout << play_order[i]<<" ";  
                }  
     
   cout << endl;
   cout <<"Eta--"<< Eta;   
   cout << endl;
   cout <<"winner_record_O  "<< winner_record_O;   
   cout << endl;
   cout <<"winner_record_X  "<< winner_record_X;     //         winner_record_X
   cout << endl;             
    
} 
//---------------------------------------------------
void print_play_order(void)                                    
{
 int  i;
   cout << endl;  
   cout << "play order = ";
    
    for(i=0;i<moves_counter;i++)
                {
                 cout << play_order[i]<<" ";  
                }  
     
   cout << endl;
   cout <<"moves_count  "<< moves_counter<< endl;              
                
    
} 
//-----------------------------------------------------

//-----------------------------------------------------
void print_console_aux(void)                                    
{
  plot_game_graphics();    
  system("cls");  
  //plot_game_graphics();  
  print_game_story();   
  //print_inputs_copy();  
  print_play_order_c();       
  print_capa_salida();   
  print_games_won();  
} 
//----------------------------------------

