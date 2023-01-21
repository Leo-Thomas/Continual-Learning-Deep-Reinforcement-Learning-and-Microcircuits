//--------------------------------------
//   LEARN TO PLAY O
//
//---------------------------------------





//------------------------------------&&&-----------------
void print_inputs_story(void)     //      AQUI SE IMPRIMEN LAS ENTRADAS DE LA RED                                  
{
 int  i,j;
    
              cout << endl; 
              cout << " inputs from story" ;  
              cout << endl; 
              j=0;
              for(i=0;i<N_IN;i++)
                 {
                  cout << Entrada[i];   //              OJO  VECTOR
                  j++;
                  if(j>2) {j=0; cout <<" ";} 
                 }
              cout << endl;       
} 
//-----------------------------------------------
void flash(int pointer)                   //       ---------------->      FLASH   
{
 int i;   
            for(i=0;i<20;i++)   
              {  
               board[pointer]='O';
               plot_game_graphics(); 
               delay(100);               //  100
               board[pointer]='-';
               plot_game_graphics();    
               delay(200);               //  200
               i++;   
              } 
}
//----------------------------------------------

void macro_print(void)
{
      plot_game_graphics();  
      print_game_story();
      print_inputs_story();    
      print_play_order();        
      print_future_targets();   
      print_capa_salida();     
}

//-------------------------------
void busca_neuron_ganador(void)              //                                                                               BUSCA WINNER  !!
{
  int i;
  float max;
               
    net_winner=0;
    //winner_y=0;
    peak_value=0.0;
    max=c_salida.out[0];
    for (i=0; i<N_OUT; i++) counselor_out[i]=0.0;   
    
    for (i=0; i<N_OUT; i++)
        { 
         if (c_salida.out[i]>=max)
           {
            max  = c_salida.out[i];
            net_winner= i;
            peak_value=max;   
           }        
        } 
    
 
         // flash(net_winner); 
    
}
//---------------------------------------
void load_inputs_story(void)                                                                  //  ROI
{
 int   i;
 
    for(i=0;i<N_IN;i++)
          {    
           Entrada[i]=story[story_pointer][i]; //   se carga a la red con una de los muchos tableros guardados en i
          }
} 
//------------------------------------------------------------
void fill_inputs_X(void)   //   convierte ASCII en tablero a sparse en la entrada dela red
{
 int i,j;

 // k=image_in_use;
    //{        
     for(j=0;j<9;j++)
        {
        i=3*j;  
        if(board[j]=='O') {Entrada[i]=0;Entrada[i+1]=0;Entrada[i+2]=1;} // 1 a la derecha para O 
        if(board[j]=='-') {Entrada[i]=0;Entrada[i+1]=1;Entrada[i+2]=0;} // 1 al centro par -  
        if(board[j]=='X') {Entrada[i]=1;Entrada[i+1]=0;Entrada[i+2]=0;} // 1 a la izquierda para X 
        }
    //}    
}  
//--------------------------------------------------------------
void fill_inputs(void) //CARGA TABLERO EN ENTRADA DE RED
{
 int i,j;

 // k=image_in_use;
    //{        
     for(j=0;j<9;j++)
        {
        i=3*j;  
        if(board[j]=='O') {Entrada[i]=0;Entrada[i+1]=0;Entrada[i+2]=1;} // 1 a la derecha para O 
        if(board[j]=='-') {Entrada[i]=0;Entrada[i+1]=1;Entrada[i+2]=0;} // 1 al centro par -  
        if(board[j]=='X') {Entrada[i]=1;Entrada[i+1]=0;Entrada[i+2]=0;} // 1 a la izquierda para X 
        }
    //}    
}
//--------------------------------------------------------------
void set_targets_noise(void)                                  //  ROI
{
 int i;
    
  for(i=0;i<N_OUT;i++) Target[i]=0.0;
  //Target[0]=1.0;   
  //Target[1]=0.0; 
  
} 
//--------------------------------------------------------------
void feed_forward(void)             //LA RED PROCESA 
{
    Gain=0.5;                            //       GAIN HIDDEN  0.5                                                                                                 //    GAIN   SETTING
    calcular_capa_escondida();
    Gain=1.5;                            //       Use to be 1.5
    calcular_capa_salida(); 
    
       
    if(b_flag){
        corregir_pesos_all();
        backpro_count++;
        }
}
//--------------------------------------
void print_console(void)                                    
{
  plot_game_graphics();  
  print_game_story();   
  print_inputs_story();  
  print_play_order_c();       
  print_capa_salida();   
  print_games_won();  
} 
//-------------------------------------
void fill_noise_pattern(void)                                    
{
   int i,j;
   for (i=0; i<9;i++) 
   {
    j=random(4); 
    if(j==0) board[i]='-';
    if(j==1) board[i]='-';
    if(j==2) board[i]='O';       //  O
    if(j==3) board[i]='X';       // X
   }  
   for(i=0;i<N_OUT;i++) Target[i]=0.1;   
} 
//--------------------------------------

void print_console_stuff(void)                                    
{
   system("cls"); 
   print_future_targets();       
   //print_game_story();  
   print_rotative_key(); 
   print_play_order_c();       
   print_capa_salida();      
   print_games_won(); 
   print_inputs_story();
} 
//-----------------------------------------------
void X_fill_square(void)
{
 int i;       
  do
    { 
     i=random(9);        
     if(board[i]=='-') {
                        board[i]='X';
                        play_order[moves_counter]=i;
                        break;
                       }   
    }   
    while(1);
}
//-------------------------------------------------------------------------
void O_fill_square(void)
{
 int i;       
 
  do
    { 
     i=random(9);        
     if(board[i]=='-') {
                        board[i]='O';
                        play_order[moves_counter]=i;
                        break;
                       }   
    }   
    while(1);
 
}
//-----------------------------------------------
void X_plays(void)            
{
 X_fill_square();
 fill_inputs();
 if(!b_flag) feed_forward();  
}
//---------------------------------------------------------------------------------------
void O_plays(void)            
{
  float femp1,femp2;   
  //system("cls");
    
  //game_open_case=random(4);  
    
  O_fill_square();
  fill_inputs(); 
    
       if(!b_flag) feed_forward();  
           
   //getch();    
  //explore_from_here();
  
   //busca_neuron_ganador();

  femp1= games_won_O;
  femp2= games_played;
    
  winner_record_O= femp1/femp2;  
  
}
//--------------------------------------
/*










*/

