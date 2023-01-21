
//==================================================================================
//                    Rutinas pop   push pesos  
//-------------------------------------------------------
void pop_pesos_net1(void)  //  de la matriz net_1_hif[] []    a la red
{
 int i,k;
    		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
			  c_escondida.pesos[k][i]=net_1_hid[k][i];
            }
            
            
      		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
			  c_salida.pesos[k][i]= net_1_out[k][i];
            }
}
//-----------------------------------------------------------
void push_pesos_net1(void)  //  de la red a la matriz net_1_hif[] []   
{
 int i,k;
    		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
			  net_1_hid[k][i] = c_escondida.pesos[k][i];
            }
            
            
      		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
			  net_1_out[k][i] = c_salida.pesos[k][i];            
            }
}

//-------------------------------------------------------
void pop_pesos_net2(void)  //  de la matriz net_2_hif[] []    a la red
{
 int i,k;
    		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
			  c_escondida.pesos[k][i]=net_2_hid[k][i];
            }
            
            
      		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
			  c_salida.pesos[k][i]= net_2_out[k][i];
            }
}
//-----------------------------------------------------------
void push_pesos_net2(void)  //  de la red a la matriz net_2_hif[] []   
{
 int i,k;
    		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
			  net_2_hid[k][i] = c_escondida.pesos[k][i];
            }
            
            
      		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
			  net_2_out[k][i] = c_salida.pesos[k][i];            
            }
}
//-----------------------------------------------------------
//--------------------------------------
void count_peak_values(void)                                    
{
 int i;   
  peak_count=0;
  for (i=0; i<9;i++) 
   {
    if(c_salida.out[i]>0.45) peak_count++; 
   }  
} 
//---------------------------------------
//-----------------------------------------------------------
void fire_net_2(void)
{
    pop_pesos_net2();    
    
    fill_inputs();
    feed_forward();                         
    busca_neuron_ganador();  
    push_pesos_net2();
} 
//----------------------------------------------------------
void check_TG1_energy(void)
{
    pop_pesos_net1();        //   Knowledge of TG1 
    fill_inputs();
    feed_forward_soft(); 
    busca_neuron_ganador();  
    count_peak_values();
    
    //if(peak_count>1) TG1_flag=1; 
    //else TG1_flag=0;    
}
//-----------------------------------------------------------
void test_net_2(void)
{
    cout << "test net_2  -- "<<endl;
    fire_net_2(); 
    plot_game_graphics();  
    delay(100); 
} 
//-------------------------------------------------------