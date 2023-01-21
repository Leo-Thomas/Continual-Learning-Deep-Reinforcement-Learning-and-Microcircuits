
//===============================================================================
//-----------------------------------------------
int SalvarPesos(void)
{
	int k, i, aux;
	float numero;
	FILE *out_file;
	aux=0;
	if ((out_file = fopen ("net_hid_weights.dat", "wt")) == NULL)
		aux=1;
	else
	{
		fseek(out_file, 0, SEEK_SET);
		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
				numero=c_escondida.pesos[k][i];
				fprintf(out_file, "%f %c", numero,'\n');
			}
		  }
	if ((out_file = fopen ("net_out_weights.dat", "wt")) == NULL)
		aux=aux+2;
	else
	{
		fseek(out_file, 0, SEEK_SET);
		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
              numero=c_salida.pesos[k][i];
              fprintf(out_file, "%f %c", numero, '\n');
			}
    }
	fclose(out_file);
    moveto(300,20);
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    outtext("Pesos Salvados ");
	return(aux);
}
//-----------------------------------------------
int SalvarPesos_net2(void)
{
	int k, i, aux;
	float numero;
	FILE *out_file;
	aux=0;
    //remove("net_2_hid.dat");
    //remove("net_2_out.dat");
	if ((out_file = fopen ("net_2_hid.dat", "w+")) == NULL)
		aux=1;
	else
	{
		fseek(out_file, 0, SEEK_SET);
		for (k=0; k<N_HID; k++)
			for (i=0; i<N_IN; i++)
			{
				numero=c_escondida.pesos[k][i];
				fprintf(out_file, "%f %c", numero,'\n');
			}
		  }
	if ((out_file = fopen ("net_2_out.dat", "w+")) == NULL)
		aux=aux+2;
	else
	{
		fseek(out_file, 0, SEEK_SET);
		for (k=0; k<N_OUT; k++)
			for (i=0; i<N_HID; i++)
			{
              numero=c_salida.pesos[k][i];
              fprintf(out_file, "%f %c", numero, '\n');
			}
    }
	fclose(out_file);
    
    moveto(340,20);
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 1);
    outtext("Pesos net_2 Salvados ");
    
    delay(500);
    moveto(340,20);
    outtext("____________________");
	return(aux);
}
//---------------------------------------------