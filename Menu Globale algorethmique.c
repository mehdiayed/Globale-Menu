#include<stdio.h>
#include<stdlib.h>
//----------------------------------------------------------------- LISTE---------------------------------------------------------

//-------------------------------------------------------- LISTE SIMPLEMENT CHAINNE --------------------------------------------------
	struct cellule 
	{
		int valeur ;
		struct cellule * next ;
	};
	
	 	
	 	
	struct cellule * l = NULL;

void creat_liste () 
{
	int n=0;
	int i;
	
	
	struct cellule * p = NULL ;
	struct cellule * x = NULL ;
	
	
	printf("donner la taille de la liste : ");
	scanf("%d",&n);
	
	for (i=1;i<=n;i++)
	{
			
		// creation d'une celulle : 
		
		p = (struct cellule *)malloc(sizeof(struct cellule));
		
		printf("donner la valeur de la cellule numero %d :",i);
		scanf("%d",&(p->valeur));
		p->next = NULL ;
		
		
		if (l==NULL)
		{
			l=p;
		}
		else
		{
			//parcours de la liste 
			x=l;
			while(x->next!=NULL)
			{
				x=x->next;
			}
			
			//chainnage 
			x->next=p;
		}
	}
	printf("==================================== \n");
}
void show_liste()
{		
	struct cellule * x = l;
	
	while(x!=NULL)
	{
		printf(" (%d) --> ",(x->valeur));
		x=x->next;
		
	}
	printf(" NILL \n ");
	printf("==================================== \n");
	
}

void  add_element() 	// cest un ajout en queue
{	
	struct cellule * f = NULL ;
	struct cellule * pt = NULL ;
	
	
	if (l==NULL)
	{
		f = (struct cellule *)malloc(sizeof(struct cellule));
		
		printf("donner la valeur de la cellule a ajouté");
		scanf("%d",&(f->valeur));
		f->next = NULL ;
		l=f;
	}
	else
	{	
		pt=l;
		while(pt->next!=NULL)
		{
			pt=pt->next;
		}
		
		f = (struct cellule *)malloc(sizeof(struct cellule));
		printf("donner la valeur de la cellule a ajouté ");
		scanf("%d",&(f->valeur));
		pt->next = f ;
		f->next = NULL ;
		
		
		
	}
	printf("==================================== \n");

}
void insert_element()
{
	int pos;
	int c=0;
	int n=0;
	
	struct cellule * nouv = NULL ;
	struct cellule * prec = l;
	struct cellule * lo = l;
	
	while (lo!=NULL)
	{
		lo=lo->next;
		n++;
	}
	
	do
	{
		printf("donner la position de lelement a ajouté ");
		scanf("%d",&pos);
		
	}while (pos>n);
	
	nouv = (struct cellule *)malloc(sizeof(struct cellule));
	printf("donner la valeur de la nouvelle cellule");
	scanf("%d",&(nouv->valeur));
	
	if (pos==1)
	{
		nouv->next=NULL;
		l=nouv;
	}
	else
	{	
		while (c<pos-1)
		{
			prec=prec->next;
			c++;
		}	
		
		nouv->next=prec->next;
		prec ->next =nouv;	
	}
	
printf("==================================== \n");
}
void delet_element()
{	
	int e;
	struct cellule * a ;
	struct cellule * b ;
	printf("donner l'element a supprimé ");
	scanf("%d",&e);
	
	a=l;
	b=l;
	while(a!=NULL)
	{
		if (a->valeur==e)
		{
			if(a==l)
			{
				l=a->next;
				free(a);
				a=l;
			}
			else
			{
				b->next=a->next;
				free(a);
				a=b->next;
			}
		}
		else
		{
			b=a;
			a=a->next;
		}
	}	
	

		printf("==================================== \n");
}
void sort_liste()
{
	
}

//------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------- LISTE DOUBLEMENT  CHAINNE --------------------------------------------------
struct cellule_double 
{
	int valeur ;
	struct cellule_double  * next ;
	struct cellule_double  * previous ;
};

	struct cellule_double  * l2 = NULL;
void creat_liste_double ()
{
	int n=0;
	int i;
	
	struct cellule_double  * p = NULL ;
	struct cellule_double  * x = NULL ;
	
	
	printf("donner la taille de la liste : ");
	scanf("%d",&n);
	
	for (i=1;i<=n;i++)
	{
			
		// creation d'une celulle : 
		
		p = (struct cellule_double  *)malloc(sizeof(struct cellule_double ));
		printf("donner la valeur de la cellule numero %d :",i);
		scanf("%d",&(p->valeur));
		p->next = NULL ;
		p->previous = NULL ;
		
		if (l2==NULL)
		{
			l2=p;
			p->previous = l2; 
		}
		else
		{
		
			
			//parcours de la liste double
			x=l2;
			while(x->next!=NULL)
			{
				x=x->next;
			}
			
			//chainnage 
			x->next=p;
			p->previous = x;
		}
	}
	printf("==================================== \n");
}				
				
void show_liste_double()
{		
	struct cellule_double  * x = l2;
	
	while(x!=NULL)
	{
		printf(" (%d) --> ",(x->valeur));
		x=x->next;
		
	}
	printf(" NILL \n ");
	printf("==================================== \n");

}				
	


void add_element_double()
{
	struct cellule_double  * f = NULL ;
	struct cellule_double  * pt = NULL ;
	
	
	if (l2==NULL)
	{
		f = (struct cellule_double  *)malloc(sizeof(struct cellule_double ));
		
		printf("donner la valeur de la cellule a ajouté");
		scanf("%d",&(f->valeur));
		f->next = NULL ;
		f->previous=l2;
		l2=f;
	}
	else
	{	
		pt=l2;
		while(pt->next!=NULL)
		{
			pt=pt->next;
		}
		
		f = (struct cellule_double  *)malloc(sizeof(struct cellule_double ));
		printf("donner la valeur de la cellule a ajouté ");
		scanf("%d",&(f->valeur));
		pt->next = f ;
		f->next = NULL ;
		f->previous=pt;
		
		
		
	}
	printf("==================================== \n");
}				
	

void insert_element_double()
{
	int pos;
	int c=0;
	int n=0;
	
	
	struct cellule_double  * nouv = NULL ;
	struct cellule_double  * prec = l2;
	struct cellule_double  * lo = l2;
	
	while (lo!=NULL)
	{
		lo=lo->next;
		n++;
	}
	
	do
	{
		printf("donner la position de lelement a ajouté ");
		scanf("%d",&pos);
		
	}while (pos>n);
	
	nouv = (struct cellule_double  *)malloc(sizeof(struct cellule_double ));
	printf("donner la valeur de la nouvelle cellule");
	scanf("%d",&(nouv->valeur));
	
	if (pos==1)
	{
		nouv->next=NULL;
		l2=nouv;
	}
	else
	{	
		while (c<pos-1)
		{
			prec=prec->next;
			c++;
		}	
		
		nouv->next=prec->next;
		prec ->next =nouv;	
	}
	
printf("==================================== \n");
}				
		
void delet_element_double()
{
	int e;
	struct cellule_double  * a ;
	struct cellule_double  * b ;
	printf("donner l'element a supprimé ");
	scanf("%d",&e);
	
	a=l2;
	b=l2;
	while(a!=NULL)
	{
		if (a->valeur==e)
		{
			if(a==l2)
			{
				l2=a->next;
				free(a);
				a=l2;
			}
			else
			{
				b->next=a->next;
				free(a);
				a=b->next;
			}
		}
		else
		{
			b=a;
			a=a->next;
		}
	}	
	

		printf("==================================== \n");
}				
	
void longueur_double()
{
	int n=0;
	struct cellule_double  * lo = l2;
	
	while (lo!=NULL)
	{
		lo=lo->next;
		n++;
	}
	printf("la longueur de la liste doublement chainnee est : %d \n",n);
}
//------------------------------------------------------------ LISTE CIRCULAIRE --------------------------------------------------
void creat_liste_circulaire(){}
void show_liste_circulaire(){}
void insert_element_circulaire (){}
void delet_element_circulaire (){}
void longueur_circulaire (){}

				
//-------------------------------------------------------------- PILE ----------------------------------------------------------------
struct cellule_pile
	{
		int info ;
		struct cellule_pile * next ;

		
	};
	

struct cellule_pile * pile ;


void creation_pile()
{
	int nb;
	int i=1;
	struct cellule_pile * p ;
	
	printf("donner le nombre de cellule dans la pile: ");
	scanf("%d",&nb);
	
	while(i<=nb)
	{
		p = (struct cellule_pile *)malloc(sizeof(struct cellule_pile ));
		printf("donner la valeur de la cellule numero %d :",i);
		scanf("%d",&(p->info));
		p->next= pile ;
		
		pile=p;
		
		i++;
	}
			
	
	
}
void affichage_pile()
{
	struct cellule_pile * x ;
	x=pile;
	while(x!=NULL)
	{
		printf(" (%d) ",(x->info));
		x=x->next;
		
		
	}
	printf("\n");
	printf("==================================== \n");

}
void empiler_pile()
{	
	struct cellule_pile * c ;
	c = (struct cellule_pile *)malloc(sizeof(struct cellule_pile ));
	printf("donner la valeur de la nouvelle cellule :");
	scanf("%d",&(c->info));
	c->next= NULL ;
	c->next= pile ;
	pile = c ;
	
}
void depiler_pile()
{
	struct cellule_pile * x ;
	struct cellule_pile * x2 ;
	

	if(x==NULL)
	{
		printf("pile vide \n ");
		
			
	}
	else
	{
		x2=pile;
		pile=pile->next;
		free(x2);
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------- FILE ---------------------------------------------------------------
struct cellule_file
	{
		int info ;
		struct cellule_file * next ;

		
	};

struct cellule_file * T ;
struct cellule_file * Q ;



void creat_file()
{
	struct cellule_file * p;
	int nb,i;
	
	printf("donner le nombre de cellule dans le file : ");
	scanf("%d",&nb);
	
	
	for(i=1;i<=nb;i++)
	{
		
		p = (struct cellule_file *)malloc(sizeof(struct cellule_file ));
		printf("donner la valeur de la cellule numero %d :",i);
		scanf("%d",&(p->info));
		p->next= NULL ;
		
		if(T==NULL)
		{	
			T = Q = p;
		}
		else
		{	
			Q->next =p;
			Q=p;
		}
	}
	
	
	
}
void affichage_file()
{
	struct cellule_file * x = T;
	
	while(x!=NULL)
	{
		printf(" (%d) --> ",(x->info));
		x=x->next;
		
	}
	printf(" NILL \n ");
	printf("==================================== \n");
}

void enfiler()
{
	struct cellule_file * p;
	
	
	p = (struct cellule_file *)malloc(sizeof(struct cellule_file ));
	printf("donner la nouvelle valeur ");
	scanf("%d",&(p->info));
	p->next= NULL ;
	
	if(T==NULL)
	{	
		T = Q = p;
	}
	else
	{	
		Q->next =p;
		Q=p;
	}
	
}

void defiler()
{
	struct cellule_file * k ;
	
	if ( T == NULL )
	{
		printf(" vous n'avaiez aucune cellule a supprime , le file est deja vide ");
	}
	else 
	{	
		k = T;
		T = T->next;
		free(k); 	
	}
}
//--------------------------------------------------------------- ARBRE  --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
int main()
{
	int choix,  choix_liste , choix_pile , choix_file , choix_arbre , choix_liste_simple ;
	
	
	do{
		printf("************* MENU PRINCIPALE *************\n");
		
		printf("1 - LISTE 	\n");
		printf("2 - PILE 	\n");
		printf("3 - FILE 	\n");
		printf("4 - ARBRE	\n");
		printf("0 - QUITTER 	\n");
		
		printf("********************************************\n");
		
		
			printf(" taper votre choix ");
			scanf ("%d",&choix);
		printf("\n\n");
		
	}while((choix>4)||(choix<1));
	
	
	if (choix==1)
	{
		do{
			printf("============== MENU LISTE  ============== \n");
			
			printf("1 - SIMPLE	\n");
			printf("2 - DOUBLE 	\n");
			printf("3 - CIRCULAIRE  	\n");
			printf ("  PRESS 0 TO EXIT  \n");
			
			printf("=========================================\n");
			
			printf(" taper votre choix ");
			scanf ("%d",&choix_liste);
						
			printf("\n\n");
			
		}while((choix_liste>3)||(choix_liste<1));
		
							// ************************ LISTE SIMPLE ***************************
		if(choix_liste==1)
		{	
			int choix_liste_simple;	
	
	
	
			do{
		
				printf ("========= MENU PRINCIPALE ========= \n");
				printf (" 1 : CREAT LISTE \n ");
				printf ("2 : SHOW LISTE  \n");
				printf (" 3 : ADD ELEMENT \n");
				printf (" 4 : INSERT ELEMENT \n");
				printf (" 5 : SORT LISTE \n" );
				printf (" 6 : DELET LISTE \n");	
				printf ("  PRESS 0 TO EXIT  \n");
				
				
					printf(" taper votre choix ");
					scanf ("%d",&choix_liste_simple);
			
			
				if ( choix_liste_simple == 1 )
				{
					creat_liste ();
				}
				else if ( choix_liste_simple == 2 )
				{
					show_liste();
				}
				else if ( choix_liste_simple == 3 )
				{
					add_element();	
				}
				else if ( choix_liste_simple == 4 )
				{
					insert_element();	
				}
				else  if ( choix_liste_simple == 5 )
				{
					//sort_list();
					printf("tri");
				}
				else if ( choix_liste_simple == 6 )
				{
					delet_element();
				}
				
			}  while ((( (choix_liste_simple ==1) || (choix_liste_simple ==2) ) || ( (choix_liste_simple ==3) || (choix_liste_simple ==4) )) || ( (choix_liste_simple ==5) || (choix_liste_simple ==6) ));
	
	
			if (choix_liste_simple  == 0 )
			{
				return 0 ;
			}
		}
		
						// ********************** liste double***********************
						
		else if(choix_liste==2)
		{	
					int choix_double;
					
			do{
		
				printf ("========= MENU PRINCIPALE ========= \n");
				printf (" 1 : CREAT LISTE \n ");
				printf ("2 : SHOW LISTE  \n");
				printf (" 3 : ADD ELEMENT \n");
				printf (" 4 : INSERT ELEMENT \n");
				printf (" 5 : DELET LISTE \n" );
				printf (" 6 : LENGHT \n");	
				printf ("  PRESS 0 TO EXIT  \n");
				
				
					printf(" taper votre choix ");
					scanf ("%d",&choix_double );
			
			
				if ( choix_double  == 1 )
				{
					creat_liste_double ();
				}
				else if ( choix_double  == 2 )
				{
					show_liste_double ();
				}
				else if ( choix_double  == 3 )
				{
					add_element_double ();	
				}
				else if ( choix_double  == 4 )
				{
					insert_element_double ();	
				}
				else  if ( choix_double  == 5 )
				{
					delet_element_double ();
				}
				else  if ( choix_double  == 6 )
				{
					longueur_double ();
				}
				if (choix_double  == 0 )
				{
					return 0 ;
				}	
	} while ((( (choix_double ==1) || (choix_double ==2) ) || ( (choix_double ==3) || (choix_double ==4) )) || ( (choix_double ==5) 			|| (choix_double ==6) ));
	
			if (choix_double  == 0 )
			{
				return 0 ;
			}			
				
		}
		
						// ********************** liste circulaire **********************
		
		else if(choix_liste==3)
		{	
			int choix_circulaire;
					
			do{
		
				printf ("========= MENU PRINCIPALE ========= \n");
				printf (" 1 : CREAT LISTE \n ");
				printf ("2 : SHOW LISTE  \n");
				printf (" 3 : ADD ELEMENT \n");
				printf (" 4 : INSERT ELEMENT \n");
				printf (" 5 : DELET LISTE \n" );
				printf (" 6 : LENGHT \n");	
				printf ("  PRESS 0 TO EXIT  \n");
				
				
					printf(" taper votre choix ");
					scanf ("%d",&choix_circulaire );
			
			
				if ( choix_circulaire  == 1 )
				{
					//creat_liste_circulaire();
				}
				else if ( choix_circulaire  == 2 )
				{
					//show_liste_circulaire ();
				}
				else if ( choix_circulaire == 3 )
				{
					//add_element_circulaire ();	
				}
				else if ( choix_circulaire  == 4 )
				{
					//insert_element_circulaire ();	
				}
				else  if ( choix_circulaire  == 5 )
				{
					//delet_element_circulaire ();
				}
				else  if ( choix_circulaire  == 6 )
				{
					//longueur_circulaire ();
				}
				if (choix_circulaire  == 0 )
				{
					return 0 ;
				}	
	} while ((( (choix_circulaire  ==1) || (choix_circulaire  ==2) ) || ( (choix_circulaire  ==3) || (choix_circulaire  ==4) )) || ( (choix_circulaire  ==5) || (choix_circulaire  ==6) ));
		}
				
		
	}
	
							// ************************ PILE ***************************
	
	else if (choix==2)
	{
	
			int choix_pile;
		do{
			printf("======== MENU PRINCIPALE ========  \n");
			printf(" 1-  CREATION \n");
			printf(" 2-  AFFICHAGE \n");
			printf(" 3-  EMPILER  \n");
			printf(" 4-  DEPILER \n");
			printf(" TAPER 0 POUR QUITTER ! \n");
			
			printf(" taper votre choix : ");
			scanf ("%d",&choix_pile);
			
			if(choix_pile==1)
			{	
				creation_pile();
			}
			else if(choix_pile==2)
			{
				affichage_pile();
			}
			else if(choix_pile==3)
			{
				empiler_pile();
			}
			else if(choix_pile==4)
			{
				depiler_pile();
			}
			else if(choix_pile==0)
			{
				return 0;
			}
			
			printf("==================================  \n");
			
			
		}while((choix_pile==1)||(choix_pile==2) ||(choix_pile==3)||(choix_pile==4));
		
			if(choix_pile==0)
			{
				return 0;
			}
	}
	
							// ************************ FILE ***************************			
	
	else if (choix==3)
	{
		do{
			printf("============ MENU FILE ============ \n");
			
			printf("1 - CREATION	\n");
			printf("2 - AFFICHAGE 	\n");
			printf("3 - ENFILER 	\n");
			printf("4 - DEFILER 	\n");
			
			printf("=========================================\n");

			printf(" taper votre choix ");
			scanf ("%d",&choix_file);

		
		
		
		if(choix_file==1)
		{	
			creat_file();
		}
		else if(choix_file==2)
		{
			affichage_file();
		}
		else if(choix_file==3)
		{
			enfiler();
		}
		else if(choix_file==4)
		{
			defiler();
		}
		else if(choix_file==0)
		{
			return 0;
		}
		}while((choix_file==1)||(choix_file==2) ||(choix_file==3)||(choix_file==4));
		if(choix_file==0)
		{
			return 0;
		}
		
		printf("==================================  \n");
		
		printf("\n\n");
	}
	
	
								// ************************ ARBRE ***************************
	else if (choix==4)
	{
		
		do{
			printf("============ MENU ARBRE ============ \n");
			
			printf("1 - CREATION 	\n");
			printf("2 - AFFICHAGE	\n");
			printf ("  PRESS 0 TO EXIT  \n");
			
			
			
			
			printf("=========================================\n");
			
			printf(" taper votre choix ");
			scanf ("%d",&choix_arbre);
						
		}while((choix_arbre>2)||(choix_arbre<1));
		
		if(choix_arbre==0)
		{	
			return 0 ;
		}
		printf("\n\n");
	}
	
	else if(choix==0)
	{
		return 0;
	}
	
	
	
}

