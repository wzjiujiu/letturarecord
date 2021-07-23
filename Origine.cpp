#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include <string>
#define N 80

int checkdata(std::string data, int count);
int checkdatap(std::string data, int count,char *nomefile);
void printdataconspazio(std::string data,int i, int numchar, char tipo[N]);
void printdatasenzaspazio(std::string data, int i, int numchar, char tipo[N]);

int main(int argc,char**argv)
{
	if (argc != 3)
	{
		printf("non ci sono abbastanza argomenti,esco\n");
		exit(0);
	}

	std::ifstream infile(argv[1]);
	std::string line;
	int count = 1;
	while (std::getline(infile, line))
	{

		std::string data = line;
		int ok = checkdatap(data, count,argv[2]);
		count++;
	}
	return 0;
}

int checkdatap(std::string data, int count,char *nomefile)
{
	int spazio;
	int i;
	int numchar;
	char tipo[N];
	FILE* fp;
	printf("record %d:\n", count);
	fp = fopen(nomefile, "r");
	while (fscanf(fp, "%d %d %d %s", &i, &numchar, &spazio,tipo) == 4)
	{
		if (spazio == 0)
		{
			
			printdatasenzaspazio(data, i, numchar, tipo);
		}
		else
		{ 
			printdataconspazio(data, i, numchar, tipo);
		}
	}
	return 1;
}

void printdataconspazio(std::string data,int i, int numchar, char tipo[N])
{
	int countinside = 0;
	int space = 0;
	int j;
	int x = i;
	for (j = i; j < x + numchar; j++)
	{
		countinside++;
		std::cout << data[j];
		if (data[j] == ' ')
			space++;
	}
	printf("endhere %s  ",tipo);
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	printf("\n");
	
}
void printdatasenzaspazio(std::string data, int i, int numchar, char tipo[N])
{
	int j;
	int x = i;
	int countinside = 0;
	int space = 0;
	for (j = i; j< x + numchar; j++)
	{
		countinside++;
		std::cout << data[j];

	}
	printf("endhere %s  ",tipo);
	printf("caratteri totali sono %d\n ", countinside);
	printf("\n");
}


int checkdata(std::string data, int count)
{
	int i;
	int space = 0;
	printf("record %d:\n", count);
	int countinside = 0;
	if (data[0] != '2')
		return 0;

	//CDR
	for (i = 1; i < 1 + 37; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere CDR  ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//tipo trafficodati
	countinside = 0;
	space = 0;
	for (i = 38; i < 38 + 4; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere tipotrafficodati  ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//code servizio associato
	countinside = 0;
	space = 0;
	for (i = 42; i < 42 + 2; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere code servizio associato  ");
	printf("caratteri totali sono %d\n ", countinside);
	//data inizio conversazione
	countinside = 0;
	space = 0;
	for (i = 44; i < 44 + 8; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere data inizio conversazione  ");
	printf("caratteri totali sono %d\n ", countinside);
	//ora inizio conversazione
	countinside = 0;
	space = 0;
	for (i = 52; i < 52 + 6; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere ora inizio conversazione  ");
	printf("caratteri totali sono %d\n ", countinside);
	//durata conversazione
	countinside = 0;
	space = 0;
	for (i = 58; i < 58 + 10; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere durata conversazione  ");
	printf("caratteri totali sono %d\n ", countinside);
	//data fine conversazione
	countinside = 0;
	space = 0;
	for (i = 68; i < 68 + 8; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere data fine conversazione  ");
	printf("caratteri totali sono %d\n ", countinside);
	//ora fine conversazione
	countinside = 0;
	space = 0;
	for (i = 76; i < 76 + 6; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere ora fine conversazione  ");
	printf("caratteri totali sono %d\n ", countinside);

	//codicetassazione
	countinside = 0;
	space = 0;
	for (i = 82; i < 82 + 4; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere codice tassazione  ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	// flag provenienza invio
	countinside = 0;
	space = 0;
	for (i = 86; i < 86 + 1; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere flag provenienza  ");
	printf("caratteri totali sono %d\n ", countinside);

	//Distretto fatturante
	countinside = 0;
	space = 0;
	for (i = 87; i < 87 + 5; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Distretto fatturante  ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//fatturante
	countinside = 0;
	space = 0;
	for (i = 92; i < 92 + 15; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere fatturante  ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//tipo fatturante
	countinside = 0;
	space = 0;
	for (i = 107; i < 107 + 1; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere tipo fatturante ");
	printf("caratteri totali sono %d\n ", countinside);

	//code gestore fatt num

	countinside = 0;
	space = 0;
	for (i = 108; i < 108 + 5; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere code_gestore_fatt_num ");
	printf("caratteri totali sono %d\n ", countinside);

	//Code gestore fatt alf
	countinside = 0;
	space = 0;
	for (i = 113; i < 113 + 5; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Code gestore fatt alf");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Tipo indicativo chiamante
	countinside = 0;
	space = 0;
	for (i = 118; i < 118 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Tipo indicativo chiamante");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Distretto numero chiamante
	countinside = 0;
	space = 0;
	for (i = 119; i < 119 + 5; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Distretto numero chiamante");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//numero chiamante
	countinside = 0;
	space = 0;
	for (i = 124; i < 124 + 15; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere numero chiamante ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Code forte area code chiamante

	countinside = 0;
	space = 0;
	for (i = 139; i < 139 + 9; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere Code forte area code chiamante");
	printf("caratteri totali sono %d\n ", countinside);

	//Code gestore chiamante num
	countinside = 0;
	space = 0;
	for (i = 148; i < 148 + 5; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere Code gestore chiamante num");
	printf("caratteri totali sono %d\n ", countinside);

	//Code gestore chiamante alf
	countinside = 0;
	space = 0;
	for (i = 153; i < 153 + 5; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Code gestore chiamante alf ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Flag TP chiamante
	countinside = 0;
	space = 0;
	for (i = 158; i < 158 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Flag TP chiamante ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Info prefisso destinazione

	countinside = 0;
	space = 0;
	for (i = 159; i < 159 + 12; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Info prefisso destinazione ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//numero destinazione

	countinside = 0;
	space = 0;
	for (i = 171; i < 171 + 32; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere numero destinazione ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Tipo indicativo dest
	countinside = 0;
	space = 0;
	for (i = 203; i < 203 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Tipo indicativo dest ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Code forte area code dest
	countinside = 0;
	space = 0;
	for (i = 204; i < 204 + 9; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere Code forte area code dest ");
	printf("caratteri totali sono %d\n ", countinside);

	//Code gestore dest num
	countinside = 0;
	space = 0;
	for (i = 213; i < 213 + 5; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere Code gestore dest num");
	printf("caratteri totali sono %d\n ", countinside);

	//Code gestore dest alf
	countinside = 0;
	space = 0;
	for (i = 218; i < 218 + 5; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Code gestore dest alf ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Cifre selezionate
	countinside = 0;
	space = 0;
	for (i = 223; i < 223 + 21; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Cifre selezionate ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Servizio fittizio SDR
	countinside = 0;
	space = 0;
	for (i = 244; i < 244 + 11; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Servizio fittizio SDR ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Descrizione chiamato
	countinside = 0;
	space = 0;
	for (i = 255; i < 255 + 30; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Descrizione chiamato ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Flag Call completion

	countinside = 0;
	space = 0;
	for (i = 285; i < 285 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Flag Call completion ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Flag ISP chiamato
	countinside = 0;
	space = 0;
	for (i = 286; i < 286 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Flag ISP chiamato ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Flag on-off net
	countinside = 0;
	space = 0;
	for (i = 287; i < 287 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Flag on-off net ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Codice Autocommutatore
	countinside = 0;
	space = 0;
	for (i = 288; i < 288 + 30; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Codice Autocommutatore ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Inizio Cifratura  cifre selezionate

	countinside = 0;
	space = 0;
	for (i = 318; i < 318 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Inizio Cifratura  cifre selezionate ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Inizio Cifratura Numero destinazione
	countinside = 0;
	space = 0;
	for (i = 319; i < 319 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Inizio Cifratura Numero destinazione ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//DR
	countinside = 0;
	space = 0;
	for (i = 320; i < 320 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere DR ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Agenzia
	countinside = 0;
	space = 0;
	for (i = 322; i < 322 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Agenzia ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Data espletamento
	countinside = 0;
	space = 0;
	for (i = 324; i < 324 + 8; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Data espletamento ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Distretto addebito
	countinside = 0;
	space = 0;
	for (i = 332; i < 332 + 4; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Distretto addebito ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Numero addebito

	countinside = 0;
	space = 0;
	for (i = 336; i < 336 + 9; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Numero addebito ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//data inserimento
	countinside = 0;
	space = 0;
	for (i = 345; i < 345 + 8; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere data inserimento ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Codice univoco linea
	countinside = 0;
	space = 0;
	for (i = 353; i < 353 + 15; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Codice univoco linea ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//codice versione servizio cliente
	countinside = 0;
	space = 0;
	for (i = 368; i < 368 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere versione servizio cliente ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//codice prog sede
	countinside = 0;
	space = 0;
	for (i = 370; i < 370 + 8; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere codice prog sede ");
	printf("caratteri totali sono %d\n ", countinside);

	//codice segmento utenza
	countinside = 0;
	space = 0;
	for (i = 378; i < 378 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere codice segmento utenza ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//codice progressivo servizio
	countinside = 0;
	space = 0;
	for (i = 380; i < 380 + 3; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere codice progressivo servizio ");
	printf("caratteri totali sono %d\n ", countinside);

	//Codice Cliente
	countinside = 0;
	space = 0;
	for (i = 383; i < 383 + 16; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere codice cliente ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//codice lotto fatturazione 
	countinside = 0;
	space = 0;
	for (i = 399; i < 399 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere codice lotto fatturazione ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Codice piattaforma  fatturante
	countinside = 0;
	space = 0;
	for (i = 400; i < 400 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Codice piattaforma  fatturante ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Codice procedura fatturante
	countinside = 0;
	space = 0;
	for (i = 401; i < 401 + 3; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Codice procedura fatturante ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Codice servizio attestato
	countinside = 0;
	space = 0;
	for (i = 404; i < 404 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Codice servizio attestato ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Nome file MF
	countinside = 0;
	space = 0;
	for (i = 406; i < 406 + 30; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Nome file MF ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Flag SMS/ MMS gratuito
	countinside = 0;
	space = 0;
	for (i = 436; i < 436 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Flag SMS/ MMS gratuito ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//usage type
	countinside = 0;
	space = 0;
	for (i = 437; i < 437 + 6; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere usage type ");
	printf("caratteri totali sono %d\n ", countinside);

	//Jurisdiction
	countinside = 0;
	space = 0;
	for (i = 443; i < 443 + 6; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere jurisdiction ");
	printf("caratteri totali sono %d\n ", countinside);

	//Data attivazione carta Call-it
	countinside = 0;
	space = 0;
	for (i = 449; i < 449 + 8; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Data attivazione carta Call-it ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Data cessazione carta Call-it

	countinside = 0;
	space = 0;
	for (i = 457; i < 457 + 8; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Data cessazione carta Call-it ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Stato  carta Call-it
	countinside = 0;
	space = 0;
	for (i = 465; i < 465 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Stato  carta Call-it ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Stato  sospensione carta Call-it
	countinside = 0;
	space = 0;
	for (i = 466; i < 466 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Stato  sospensione carta Call-it ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Flag addebito carta Call-it
	countinside = 0;
	space = 0;
	for (i = 468; i < 468 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Flag addebito carta Call-it ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Indicatore origine traffico
	countinside = 0;
	space = 0;
	for (i = 470; i < 470 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Indicatore origine traffico ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Esito lavorazione
	countinside = 0;
	space = 0;
	for (i = 471; i < 471 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Esito lavorazione ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Causale precedente
	countinside = 0;
	space = 0;
	for (i = 472; i < 472 + 3; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Causale precedente ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//DR precedente
	countinside = 0;
	space = 0;
	for (i = 475; i < 475 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere DR precedente ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Segmento utenza precedente
	countinside = 0;
	space = 0;
	for (i = 477; i < 477 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Segmento utenza precedente ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Progressivo Carta
	countinside = 0;
	space = 0;
	for (i = 479; i < 479 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Progressivo Carta ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Tipo Linea Alice Voice
	countinside = 0;
	space = 0;
	for (i = 481; i < 481 + 1; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Tipo Linea Alice Voice ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Distretto linea principale
	countinside = 0;
	space = 0;
	for (i = 482; i < 482 + 4; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Distretto linea principale ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Numero linea principale

	countinside = 0;
	space = 0;
	for (i = 486; i < 486 + 9; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Numero linea principale ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//////////// okkkkk sono qui
	// 	tipo chiamata
	// 	   countinside = 0;
	countinside = 0;
	space = 0;
	for (i = 495; i < 495 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere tipo chimate ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Data contabile flusso contenente il cdr


	countinside = 0;
	space = 0;
	for (i = 497; i < 497 + 8; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Data contabile flusso contenente il cdr ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Data valorizzazione
	countinside = 0;
	space = 0;
	for (i = 505; i < 505 + 8; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Data valorizzazione ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Importo valorizzato std
	countinside = 0;
	space = 0;
	for (i = 513; i < 513 + 12; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere Importo valorizzato std ");
	printf("caratteri totali sono %d\n ", countinside);

	//Flag forzatura valorizzazione
	countinside = 0;
	space = 0;
	for (i = 525; i < 525 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Flag forzatura valorizzazione ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Codice Scaglione
	countinside = 0;
	space = 0;
	for (i = 527; i < 527 + 5; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Codice Scaglione ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Indicatore traffico IP
	countinside = 0;
	space = 0;
	for (i = 532; i < 532 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Indicatore traffico IP ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Zona tariffaria Internazionale
	countinside = 0;
	space = 0;
	for (i = 534; i < 534 + 3; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Zona tariffaria Internazionale ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Codice Univoco Offerta
	countinside = 0;
	space = 0;
	for (i = 537; i < 537 + 10; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Codice Univoco Offerta ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
	//Importo Pricing
	countinside = 0;
	space = 0;
	for (i = 547; i < 547 + 12; i++)
	{
		countinside++;
		std::cout << data[i];

	}
	printf("endhere Importo Pricing ");
	printf("caratteri totali sono %d \n ", countinside);

	//Return Code Prc
	countinside = 0;
	space = 0;
	for (i = 559; i < 559 + 2; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Return Code Prc ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);

	//Importo Call Setup
	countinside = 0;
	space = 0;
	for (i = 561; i < 561 + 9; i++)
	{
		countinside++;
		std::cout << data[i];
		if (data[i] == ' ')
			space++;
	}
	printf("endhere Importo Call Setup ");
	printf("caratteri totali sono %d, possono contenere degli spazi e ci sono %d spazi\n ", countinside, space);
}