//---------------------------------
//         RUTINA PLOT NET ITEMS    --    GRAFICA los parametros de LA RED APRENDIZ 

//-----------------------------------------


void plot_inputs(void)
{
 int y,x,i,temp,color
    ;
  x=10;
  y=120;//210              Step 110
    
    setcolor(LIGHTGRAY);
    //setcolor(LIGHTGREEN); 
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(x,y-1,x+140,y-bars_scale); 
    
    color=DARKGRAY; 
    setcolor(color);
    
    line(x,y-bars_scale/2,x+130,y-bars_scale/2);    
      //j=0;
      for(i=0;i<N_IN;i++) 
       {
        setfillstyle(SOLID_FILL,DARKGRAY);     //                                                                                        PLOT outputs  !!
        temp= Entrada[i]*bars_scale;              
         bar(x,y,x+3,y-temp) ;
         //if(i==3) x=x+20 ;  
         x=x+5; 
         //if(j>2) {j=0;color++;}         
         
       }   
    //setfillstyle(SOLID_FILL,CYAN);     //                                                                                      
    // temp= blue_column;              
    //bar(x,y,x+3,y-temp) ;   
}
//----------------------------------------------------------            
void plot_hidden_outputs(void)
{
 int y,x,i,temp;
  x=10;
  y=180; //210
    
    setcolor(LIGHTGRAY);
    //setcolor(LIGHTGREEN); 
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(x,y-1,x+200,y-bars_scale);  

  
   setcolor(DARKGRAY);
   line(x,y-bars_scale/2,x+130,y-bars_scale/2);   
   
      
      for(i=0;i<N_HID;i++) 
       
       {
         setfillstyle(SOLID_FILL,BROWN);     //                               PLOT  HIDDEN outputs  !!
         if(b_flag) setfillstyle(SOLID_FILL,RED); ;               
         temp= c_escondida.out[i]*bars_scale;              
         bar(x,y,x+2,y-temp) ;
         //if(i==10) x=x+20 ;  
         x=x+4;           
         
       }   
}
//----------------------------------------------------------            
void plot_outputs(void)
{
 int y,x,i,temp;
  x=10;
  y=240; //210
    
    setcolor(LIGHTGRAY);                   // borrar plot anterior
    //setcolor(LIGHTGREEN); 
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(x,y-1,x+200,y-bars_scale);  
 
     
    setcolor(DARKGRAY);
    line(x,y-bars_scale/2,x+130,y-bars_scale/2);  
      
      for(i=0;i<N_OUT;i++) 
       {
         setfillstyle(SOLID_FILL,RED);     //                                                                                        PLOT outputs  !!
         temp= c_salida.out[i]*bars_scale;              
         bar(x,y,x+3,y-temp) ;
         //if(i==3) x=x+20 ;  
         x=x+10;           
         
       }   
    //setfillstyle(SOLID_FILL,CYAN);     //                                                                                      
    // temp= blue_column;              
    //bar(x,y,x+3,y-temp) ;   
}
//---------------------------------------------------------------------------------------
void plot_targets(void)
{
 int y,x,i,temp;   //,x_target,y_target;
 //float femp; 
    
  x=10;
  y=300; 
    
  //x=x_target;
  //=y_target; 
    
    setcolor(LIGHTGRAY);                   // borrar plot anterior
    //setcolor(LIGHTGREEN); 
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(x,y-1,x+200,y-bars_scale);   

    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,0);   
    line(x,y-bars_scale/2,x+130,y-bars_scale/2);     
    
    for(i=0;i<N_OUT;i++) 
       {
         setcolor(BLUE);     //                                                       PLOT TARGETS  !!
         temp= Target[i]*bars_scale;              
         bar(x,y,x+3,y-temp) ;
         //if(i==10) x=x+20 ;   
        //if(i==2)x=x+5;           
         x=x+10;           
       } 
}
//-------------------------------------------------------------
void plot_couselor_out(void)
{
 int y,x,i,temp;   //,x_target,y_target;
 //float femp; 
    
  x=10;
  y=400; 
    
  //x=x_target;
  //=y_target; 
    
    setcolor(LIGHTGRAY);                   // borrar plot anterior
    //setcolor(LIGHTGREEN); 
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(x,y-1,x+200,y-bars_scale);   

    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,0);   
    line(x,y-bars_scale/2,x+130,y-bars_scale/2);     
    
    for(i=0;i<N_OUT;i++) 
       {
         setcolor(YELLOW);     //                                                       PLOT TARGETS  !!
         temp= counselor_out[i]*bars_scale;              
         bar(x,y,x+3,y-temp) ;
         //if(i==10) x=x+20 ;   
        //if(i==2)x=x+5;           
         x=x+10;           
       } 
   //getch();    
}
//---------------------------------------------------------------------------------------
void plot_hidden_weights(void)                           ////       PLOT HIDDEN WEIGHTS
{
int i,j,sx,sy,x,y,color,scale; 
float timp; 
    
//char str[10];   
    
x=10;
scale=4;
//sx=x_giant;    
   
   for(j=0;j<N_IN;j++)  // 
     { 
      y=10;   
      sx = x+j*scale;             //   pesos[N_HID_1][N_IN];
      //(i=0;i<N_HID;i++)
      for(i=0;i<11;i++)    //    ojo !!  plot limitado        
         {    
          sy = y+i*scale;
          timp=c_escondida.pesos[i][j];  
          
          //timp= Entrada[counter];  
          color=LIGHTGRAY; 
          if(timp<-0.001) color=BLUE;        // fROZEN
          if(timp>0.001) color=RED;          // HOT !     
          setcolor(color); 
          setfillstyle(SOLID_FILL,color); 
          bar(sx,sy,sx+scale,sy+scale) ;
          //putpixel(sx,sy, color);      
          y++;  
         }
       x++;  
     } 
 
}
//----------------------------------------------------------------------------------------
void print_board(void)                   //          PRINT BOARD
{
 int i;   
 using namespace std;   
 system("cls");

        cout << endl; 
        
        cout << " BOARD     "; 
    
        for(i=0;i<3;i++)
                {
                 cout << board[i]<<" ";  
                }  
                
        cout << endl; 
        cout << endl;         
                
        cout << "           ";  
        for(i=3;i<6;i++)
                {
                 cout << board[i]<<" ";  
                }   

        cout << endl; 
        cout << endl;  
                
        cout << "           ";  
        for(i=6;i<9;i++)
                {
                  cout << board[i]<<" ";  
                }        
                
        //Beep(5000,200);  
        cout << endl;        
        cout << endl;  
}
//-----------------------------------------------------------------------------------------
void plot_board(void)                   //          PRINT BOARD
{
 int i,x,y,x_board;   
 //char str[10];
    x_board=200;    
    y=10;
    x=x_board;
    
        setcolor(LIGHTGRAY);
        bar(x,y,x+100,y+100);
        
        //cout << " BOARD     "; 
    
        for(i=0;i<3;i++)
                {
                 if(board[i]=='-') outtextxy(x,y,"     ");   
                 if(board[i]=='O') outtextxy(x,y," O ");   
                 if(board[i]=='X') outtextxy(x,y," X "); 
                 x=x+30;    
                }  
        x=x_board;        
        y=y+30;         
        for(i=3;i<6;i++)
                {
                 if(board[i]=='-') outtextxy(x,y,"     ");   
                 if(board[i]=='O') outtextxy(x,y," O ");   
                 if(board[i]=='X') outtextxy(x,y," X "); 
                 x=x+30;    
                }          
        x=x_board;        
        y=y+30;         
        for(i=6;i<9;i++)
                {
                 if(board[i]=='-') outtextxy(x,y,"     ");   
                 if(board[i]=='O') outtextxy(x,y," O ");   
                 if(board[i]=='X') outtextxy(x,y," X "); 
                 x=x+30;    
                }                      
      
}


//------------------------------------------------------------
void plot_board_map(void)                   //          PRINT BOARD
{
 int i,x,y,x_board;   
 //char str[10];
    x_board=240;    
    y=130;
    x=x_board;
    
        setcolor(LIGHTGRAY);
        bar(x,y,x+100,y+100);
        
        //cout << " BOARD     "; 
    
        for(i=0;i<3;i++)
                {
                 if(i==0) outtextxy(x,y," 0 ");   
                 if(i==1) outtextxy(x,y," 1 ");   
                 if(i==2) outtextxy(x,y," 2 "); 
                 x=x+30;    
                }  
        x=x_board;        
        y=y+30;         
        for(i=3;i<6;i++)
                {
                 if(i==3) outtextxy(x,y," 3 ");   
                 if(i==4) outtextxy(x,y," 4 ");   
                 if(i==5) outtextxy(x,y," 5 ");  
                 x=x+30;    
                }          
        x=x_board;        
        y=y+30;         
        for(i=6;i<9;i++)
                {
                 if(i==6) outtextxy(x,y," 6 ");   
                 if(i==7) outtextxy(x,y," 7 ");   
                 if(i==8) outtextxy(x,y," 8 ");  
                 x=x+30;    
                }                      
      
}
//-------------------------------------------------------------


//-------------------------------------------------------------
void print_graph_parameters(void)
{
 int x,y,x_print,y_print, x_step,y_step;
 char str[10]; 
 //char[10] str;   
 //if(coder_flag) {x_print=380;y_print=220;}   
    
 x_print= 373;  // 400
 y_print=70;
    
 x_step=135;
 y_step=22;    
    
 x=x_print;  
 y=y_print;   

            setcolor(LIGHTGRAY);
            bar(x+x_step,y,x+x_step+90,y+170);   
    
            settextstyle(3, HORIZ_DIR, 1);
            outtextxy(x,y,"backpro count "); 
            x=x+x_step;
            outtextxy(x,y,gcvt(backpro_count,6,str)); 
         
 
            x=x_print; 
            y=y+y_step;
 
            outtextxy(x,y,"moves_coun:"); 
            x=x+x_step;
            outtextxy(x,y,gcvt(moves_counter,6,str)); 

            x=x_print; 
            y=y+y_step;   
            outtextxy(x,y,"games won O:"); 
            x=x+x_step;
            outtextxy(x,y,gcvt(games_won_O,6,str)); 
            
            x=x_print; 
            y=y+y_step;   
            outtextxy(x,y,"games won X:"); 
            x=x+x_step;
            outtextxy(x,y,gcvt(games_won_X,6,str)); 
       
            x=x_print; 
            y=y+y_step;   
            outtextxy(x,y,"peak value:"); 
            x=x+x_step;
            outtextxy(x,y,gcvt(peak_value,6,str));     


            x=x_print; 
            y=y+y_step;   
            outtextxy(x,y,"target_pointer:"); 
            x=x+x_step;
            outtextxy(x,y,gcvt(target_pointer,6,str));     
            
            x=x_print; 
            y=y+y_step;   
            outtextxy(x,y,"winner:"); 
            x=x+x_step;
            outtextxy(x,y,gcvt(net_winner,6,str));   
            

            
            
}  
/*
            x=x_print; 
            y=y+y_step;
            
            outtextxy(x,y,"last_date:"); 
            x=x+x_step;
            outtextxy(x,y,gcvt(day[stone_week],sig,str));
            x=x+25;
            outtextxy(x,y,gcvt(month[stone_week],sig,str));  
            x=x+25;
            outtextxy(x,y,gcvt(year[stone_week],sig,str));   
            
            x=x_print; 
            y=y+y_step;
            
            outtextxy(x,y,"status:"); 
            x=x+x_step;
            //borrar(x,y);
            outtextxy(x,y,gcvt(status,sig,str)); 
            */
   //--------------------------------------------------------

void plot_game_graphics(void)
{ 
      plot_hidden_weights();  
      plot_inputs();
      plot_hidden_outputs();
      plot_outputs();            
      plot_targets();            
      plot_board();   
      plot_couselor_out();    
      //print_net_parameters();
      //print_net_parameters();  
       //print_graph_parameters();
}
