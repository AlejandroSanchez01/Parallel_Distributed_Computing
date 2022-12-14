#!/usr/bin/perl


=begin comment

Fecha: 23 Agosto 2022
Autor: Alejandro Sanchez
Tema: Ejecución automatizada de Benchmarks

Perl lenguaje interpretado
Fichero que quiero que interprete pasarlo a ejecutable
$ es para definir una variable 
=end comment
=cut

#Vector para los benchmarks
#@Benchmarks = ("mm_main_int","mm_main_int_rnd","mm_main_double","mm_main_double_rnd");

#Vector para las cargas
#@Cargas = ("280","400","600","750","900","1300","1600","1900","2300","2600","2800","3000");

#doublerandom
@Benchmarks = ("mm_main_int");
@Cargas = ("2600");

#Número de repeticiones 
$n = 30;
#Se almacena la ubicacion
$Path ="/home/alejandro/Documentos/Repositorio_Computacion_Paralela/PrimerCorte/PrimerParcial/Benchmarks_Entregable/";

#Se itera sobre 
#la cantidad de ejecutable 
#sobre la cantidad de cargas
#la cantidad de repeticiones

foreach $exes(@Benchmarks){
	foreach $carga (@Cargas){
	#Se crea un fichero para almacenar los datos
	#Con . se concatena
	$file = "Soluciones/".$exes."-computadorA"."-size-".$carga.".txt";
		#printf("$Path$file\n");
		for ($i=0;$i<$n;$i++){
		system("$Path$exes $carga >>$file");
		#printf("$Path$exes $carga \n");
   	}
   	close($file);
   }
}

