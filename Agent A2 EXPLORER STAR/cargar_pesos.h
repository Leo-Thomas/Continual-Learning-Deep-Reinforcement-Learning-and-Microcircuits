
//==================================================================================
//                    Rutinas de cargar pesos  
//-------------------------------------------------------
int CargarPesos(void)
{
	int k, i, aux;
	float numero;
	FILE *in_file;
	aux=0;
	if ((in_file = fopen ("net_hid_weights.dat", "rt")) == NULL)
		aux=1;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_escondida.pesos[k][i]=numero;
			}
	}
	fclose(in_file);
	if ((in_file = fopen ("net_out_weights.dat", "rt")) == NULL)
		aux=aux+2;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_salida.pesos[k][i]=numero;
			}
	}
	fclose (in_file);
	
    moveto(420,445);
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    outtext("Pesos Cargados");
    return(aux);
}
//-----------------------------------------------		  }
int CargarPesos_net1(void)
{
	int k, i, aux;
	float numero;
	FILE *in_file;
	aux=0;
	if ((in_file = fopen ("net_1_hid.dat", "rt")) == NULL)
		aux=1;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_escondida.pesos[k][i]=numero;
                net_1_hid[k][i] = numero;
			}
	}
	fclose(in_file);
	if ((in_file = fopen ("net_1_out.dat", "rt")) == NULL)
		aux=aux+2;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_salida.pesos[k][i]=numero;
                net_1_out[k][i]=numero;
			}
	}
	fclose (in_file);
	
    moveto(300,400);
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    outtext("Pesos net_1 Cargados");
    return(aux);
}
//------------------------------------------------------------------
int CargarPesos_net2(void)     ///                     HERE   Important  * !
{
	int k, i, aux;
	float numero;
	FILE *in_file;
	aux=0;
	if ((in_file = fopen ("net_2_hid.dat", "rt")) == NULL)
		aux=1;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
				fscanf(in_file, "%f", &numero);
                c_escondida.pesos[k][i]=numero;
                net_2_hid[k][i]=numero; 
  			}
	}
	fclose(in_file);
	if ((in_file = fopen ("net_2_out.dat", "rt")) == NULL)
		aux=aux+2;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_salida.pesos[k][i]=numero;
                net_2_out[k][i]=numero;
            }
	}
	fclose (in_file);
	
    moveto(300,430);
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    outtext("Pesos net_2 Cargados");
    return(aux);
}
//----------------------------------------
int CargarPesos_dou(void)
{
	int k, i, aux;
	float numero;
	FILE *in_file;
	aux=0;
	if ((in_file = fopen ("net_hid_dou.dat", "rt")) == NULL)
		aux=1;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_escondida.pesos[k][i]=numero;
			}
	}
	fclose(in_file);
	if ((in_file = fopen ("net_out_dou.dat", "rt")) == NULL)
		aux=aux+2;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_salida.pesos[k][i]=numero;
			}
	}
	fclose (in_file);
	
    moveto(420,450);
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    outtext("Pesos dou Cargados");
    return(aux);
}
//--------------------------------------------
int CargarPesos_dia(void)
{
	int k, i, aux;
	float numero;
	FILE *in_file;
	aux=0;
	if ((in_file = fopen ("net_hid_dia.dat", "rt")) == NULL)
		aux=1;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_escondida.pesos[k][i]=numero;
			}
	}
	fclose(in_file);
	if ((in_file = fopen ("net_out_dia.dat", "rt")) == NULL)
		aux=aux+2;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_salida.pesos[k][i]=numero;
			}
	}
	fclose (in_file);
	
    moveto(420,445);
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    outtext("Pesos dia Cargados");
    return(aux);
}
//-----------------------------------------------------------
int CargarPesos_cro(void)
{
	int k, i, aux;
	float numero;
	FILE *in_file;
	aux=0;
	if ((in_file = fopen ("net_hid_cro.dat", "rt")) == NULL)
		aux=1;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_escondida.pesos[k][i]=numero;
			}
	}
	fclose(in_file);
	if ((in_file = fopen ("net_out_cro.dat", "rt")) == NULL)
		aux=aux+2;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_salida.pesos[k][i]=numero;
			}
	}
	fclose (in_file);
	
    moveto(420,445);
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    outtext("Pesos cro Cargados");
    return(aux);
}
//------------------------------------------------------------
int CargarPesos_center(void)
{
	int k, i, aux;
	float numero;
	FILE *in_file;
	aux=0;
	if ((in_file = fopen ("net_hid_center.dat", "rt")) == NULL)
		aux=1;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_escondida.pesos[k][i]=numero;
			}
	}
	fclose(in_file);
	if ((in_file = fopen ("net_out_center.dat", "rt")) == NULL)
		aux=aux+2;
	else
	{
		fseek(in_file, 0, SEEK_SET);
		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
				fscanf(in_file, "%f", &numero);
				c_salida.pesos[k][i]=numero;
			}
	}
	fclose (in_file);
	
    moveto(420,445);
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    outtext("Pesos center Cargados");
    return(aux);
}

