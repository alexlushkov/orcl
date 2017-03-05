#include <iostream>
#include <vector>
using namespace std;


void main (void)
{
 FILE *file;
 char *fname = "minmax.in";
 int elem, min, max;
 bool first=true;
  
 

 file = fopen (fname, "r");

 if (file==NULL)
	{ printf ("can't open file '%s'", fname); 
	}

 while(!feof(file)) 
 { 
	 fscanf (file, "%d ", &elem);
	 if (first) {min = elem; max = elem; first= !first;}
	 else 
	 {
		 if ((elem>min)&&(elem<max)) exit;
		 else if (elem<min) min=elem; else max=elem;
			
	 }

	
 }
 fclose (file);

 fname = "minmax.out";
 file = fopen (fname, "w");
 
 if(file!=NULL)
 {
	 fprintf(file, "%d ", min);
	 fprintf(file, "%d", max);
	 fclose (file);
 }

 
}