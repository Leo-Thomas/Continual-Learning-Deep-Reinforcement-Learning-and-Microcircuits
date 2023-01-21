/*********************** top_eye_flop.cpp **********************************       
Good learner stage 2
Prof  oscar  chang  
September 22, 2022 
Student name:     ---------------     ------------------
/*********************************************************************/               
//----------------------------------------------
// GLOBALS
// GLOBALS
#define f_dimension     9   //   tamaño del agente, cuantos comportamientos participan 
long int cycles=0;    
int b_flag;
int stop;
char dummy[1];
//--
float f_k_heat;
int f_winner;
int f_cycle_count;
float f_k_increment;
float f_threshold=0.7;                      //  Umbral de i_agent
int f_winner_count[f_dimension];
int f_fractal_count[f_dimension];

int flip[f_dimension];  
float femp; 

char board[9];
char board_temp[9];
int  moves_counter;
//int  turn_to_play_O;

int end_game_flag;

int master_brake;

float sparse_input[27];    
int win_O_bell;
int win_X_bell;

int games_played;
int games_won_O;
int games_won_X;

float auto_seal_weight=-0.05;  // -0.05;   cantidad CRITICA que autosella a los ganadores del flop para que no repitan

int image_in_use;
int play_order[9];

int play_ok_flag_O;

int learn_input_pointer;

int image_pointer;
int p_flag;

int player_selector;


int bars_scale =50; int x_print, y_print=10;
int net_winner=0;
int winner_y=0;

int winner_net;
float story[9][27];  // 9 jugadas (plays)  27 entradas,  primer indice es jugada,  segundo es valor de neurona segun tablero   
int story_pointer;

int q_flag;
int backpro_count;
float winner_record_O;
float winner_record_X;
char key, color;

int game_open_case;
int zone_pointer;

int max_moves=8;
int target_timer;
float peak_value;
int net_advice;

int target_pointer;
//----------------------------------------)))
//    end globals
//----------------------------------------)))
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip.h>
#include <windows.h>



#include "neural_lib_mmt.h"
#include "plot_net_items.h"
#include "print_console.h"
#include "handle_net_items.h"
#include "check_game_win.h"


#include "cargar_pesos.h"
#include "O_learns.h"

//#include "f_fire_flop.h"
//#include "f_print_items.h"

/******************* variables globales *********************/
using namespace std;
//usging namespace std;

//-------------------------------------
//    inicia el modo grafico             
//-------------------------------------    
void grafico(void)
{
    int    GraphDriver;  /* The Graphics device driver */
    int    GraphMode;    /* The Graphics mode value */
    int    ErrorCode;    /* Reports any graphics errors */
   
    initgraph(&GraphDriver, &GraphMode, "");

    ErrorCode = graphresult();            /* Read result of initialization*/
    if( ErrorCode != grOk )              /* Error occured during init    */
    {
       printf(" Graphics System Error: %s", grapherrormsg( ErrorCode ) );
       exit( 1 );
    }
}
//----&&---------------------------------------------
void clean_board(void)
{ 
  int i;
  for (i=0; i<9;i++)   board[i]='-';     

}
//-------------------------------------  
void erase_screen(void)
{
   setcolor(LIGHTGRAY);  
   setfillstyle(SOLID_FILL,LIGHTGRAY);     
   bar(150,100,350,300) ;         //  200   150   303   253
   floodfill(255,205,BLACK);    
}
//------------------------------------                                                    //////                           PUT EXAMPLE !!!
void init_game(void)            //                              $$$$$$$$$$$$$   INIT GAME
{
 int i; 
 win_O_bell=0; 
 win_X_bell=0;   
 clean_board();
 player_selector=0;        // O es mano
    
 //player_selector=random(2);
    
 moves_counter=0;  
 fill_inputs();   
    
 print_graph_parameters();
}
//-----------------------------------------------------------
void end_game(void)                   //       ---------------->       END GAME
{
 games_played++;   
 init_game();    
}
//-----------------------------------------------------------
void explore_future(void)            
{
 int i,j;
    
  for(i=0;i<9;i++)        //    explora todos los cuadros
  {
    if(board[i]=='-')     //  se buscan cuadros vacios
         {
          board[i]='O';   //  se coloca una O para explorar
          plot_game_graphics(); 
          check_game_winner(); //  se chequea para ver si con la O puesta se gana
          if(win_O_bell)       //  si se gana se debe memorizar la posicion
            {
              board[i]='-';      //  se limpia el tablero de la jugada adelantada
                                 //   aqui se debe activar el proceso de memorizar    
              for (j=0;j<N_OUT;j++) Target[j]=0.0;
              Target[i]=1.0;
              //print_graph_parameters();
              plot_targets();
              delay(10);
              fill_inputs();
              feed_forward();
              flash(i);          //  indica la posicion ganadora 
              Target[i]=0.0;   
              //getch();              
              plot_targets();      
            }     
          delay(500);    
          board[i]='-';
          plot_game_graphics();
          
        }    
  }    
}
//-----------------------------------------------------------
void train(void)  //                                                                          TRAIN  !!                        &&&/&&/&&/////
{
   while(1)
    {  
     player_selector=player_selector^1;   // se alternan los jugadores      
             
     if(player_selector)  {
                           if(moves_counter>0) explore_future();
                           O_plays();
                           
                          }  
                    
     if(!player_selector) {
                            X_plays();
                          }                                   
    
     check_game_winner();  
    
     busca_neuron_ganador();                      
                          
     print_graph_parameters();                     
     plot_game_graphics();
                          
     //delay(500);          //ojo con quitar para procesamiento rapido           

     moves_counter++;      
     
     if (moves_counter>max_moves)  end_game();  //    >5     O_learns();        
    
     if(win_O_bell) end_game();
     if(win_X_bell) end_game();
         
     if(stop)break;
     if(kbhit()) break;    
    }
    
}    
//------------------------------------------------------
//===================================================================================================
void main(void)
{ 
 int i;  
 
    for(i=0;i<N_OUT;i++) Target[i]=0.0;
    clean_board();    
    clrscr();                   // limpia la pantalla
    grafico();                  // prepara modo grafico   
    cleardevice();              // limpia la pantalla windows
    
    
    setcolor(LIGHTGRAY);
    bar(0,0,1400,900);       //    limpia pantalla
 
    //srand(10);
    init_game(); 
    plot_game_graphics();   
    plot_board_map();    
    //CargarPesos();
    inicializar_pesos();
    games_played=1;
    stop=0;
    b_flag=1;
    q_flag=0;
    train();
    
    do {
       //play_flag=0; 
       key=getch();
       switch (key) {
           case '1':         {
                             
                             }
           break;                    
           case '2':          {
                                   
                            
					          }
	       break;
              
                 
           case ',':           { 
               
         
							   }
	       break;                              
           case '.':           { 
               
                         
							   }
	       break;                        
                                
           case 'b': case 'B':  {
                                   b_flag=b_flag^1;
                                    //icon_flag=1;
                                    //stop=0;
                                    train();
                                }
           break;  
                                
                         
            case ' ':             {                     //-------    HERE  ! !!!!!!!!!!!!!!!!         !!!!!!!!!!!!1
                                    
                                   stop=stop^1;
                                   train();
                                  }                                     
                                  
                                  
            break; 
            case 'R': case 'r':  {
                                   inicializar_pesos();
                                   //limpiar_pesos(); 
                                   backpro_count=0; 
                                   train();
                                 }
            break;                     
                                
                                
            case 's': case 'S': {
                                //trim_pesos();   
                                SalvarPesos();
                                train(); 
                                }
	       break;                                                  
           case 'c': case 'C': {
                                CargarPesos();
                                train(); 
                               }
	       break;    
          
           case 'p': case 'P': {
                                stop=1;  
                                fill_inputs(); 
                                feed_forward();
                                busca_neuron_ganador();
                                macro_print();         
                                if(win_O_bell) end_game();;
                                train();                              
                               }
	       break;    
           case 'q': case 'Q': {
                                q_flag=1;
                                key='$';
                                //Sleep(100);   
                                train();                            
                               }
	       break;  
                 
                               
         }
   } while ((key!='x')&&(key!='X'));

   closegraph();
   clrscr();
}

//---------------------------------------
/*
BLACK        ³  0  ³ Yes ³ Yes
BLUE         ³  1  ³ Yes ³ Yes
GREEN        ³  2  ³ Yes ³ Yes
CYAN         ³  3  ³ Yes ³ Yes
RED          ³  4  ³ Yes ³ Yes
MAGENTA      ³  5  ³ Yes ³ Yes
BROWN        ³  6  ³ Yes ³ Yes
LIGHTGRAY    ³  7  ³ Yes ³ Yes
DARKGRAY     ³  8  ³ No  ³ Yes
LIGHTBLUE    ³  9  ³ No  ³ Yes
LIGHTGREEN   ³ 10  ³ No  ³ Yes
LIGHTCYAN    ³ 11  ³ No  ³ Yes
LIGHTRED     ³ 12  ³ No  ³ Yes
LIGHTMAGENTA ³ 13  ³ No  ³ Yes
YELLOW       ³ 14  ³ No  ³ Yes
WHITE        ³ 15  ³ No  ³ Yes

----------------------------------------------------------------
     if(x<0)    { x=0; if( heat<100) heat++;}     
     if(y<35)    { y=35; if( heat<100) heat++;}  
     if(x>640) { x=640; if( heat<100) heat++;}  //  x>1200 : full pantalla 
     if(y>470) { y=470; if( heat<100) heat++;}   // y>720 : full pantalla 
         
//--------------------------------------------------

************************ basic_robot.cpp ***************************
desarrollado usando Dev-C++ IDE V4.9.8.4 GNU / MinGW / GNU gcc
                    Sc1 IDE / BCC5.5
                    version orginal por Oscar Chang
*********************************************************************/

