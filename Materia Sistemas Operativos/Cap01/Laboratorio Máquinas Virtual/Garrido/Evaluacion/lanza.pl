
$Path = `pwd`;
chomp($Path);

$Nombre_Ejecutable = "MM_ejecutable";
@Size_Matriz = ("200","300");
@Num_Hilos = (1,2);
$Repeticiones = 2;

foreach $size (@Size_Matriz){
	foreach $hilo (@Num_Hilos) {
		$file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat";
		for ($i=0; $i<$Repeticiones; $i++) {
#system("$Path/$Nombre_Ejecutable $size $hilo  >> $file");
			printf("$Path/$Nombre_Ejecutable $size $hilo \n");
		}
		close($file);
	$p=$p+1;
	}
}
