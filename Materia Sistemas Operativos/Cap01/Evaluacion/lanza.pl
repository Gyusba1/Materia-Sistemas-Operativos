#**************************************************************
# Pontificia Universidad Javeriana
# Autor: Felipe Garrido
# Fecha: Noviembre 11
# Materia: Sistemas Operativos
# Tema: Taller de Evaluación de Rendimiento
# Fichero: script automatización ejecución por lotes 
#****************************************************************


#Obtener el directorio
$Path = `pwd`;
chomp($Path);

$Nombre_Ejecutable = "transpuesta"; #nombre del .c del cual se va a ejecutar
@Size_Matriz = ("800","1000", "1200", "1400", "1600", "1800", "2000", "2200"); # tamaños de la matriz
@Num_Hilos = (1,2,4,8); #hilos con los que se va a trabajar
$Repeticiones = 30; #repeticiones por cada tamaño e hilos

#bucle para cada matriz existente
foreach $size (@Size_Matriz){ 
	foreach $hilo (@Num_Hilos) { #bucle para cada uno de los hilos
		$file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat"; #ubicacion para poner los resultados
		for ($i=0; $i<$Repeticiones; $i++) { #ejecuta teniendo en cuenta las repeticiones que se hayan puesto
			system("$Path/$Nombre_Ejecutable $size $hilo  >> $file"); #ejecucion del probrama
			#printf("$Path/$Nombre_Ejecutable $size $hilo \n"); 
		}
		close($file); #cierre de archivo
	$p=$p+1; #pruebas ejecutadas (contador)
	}
}
