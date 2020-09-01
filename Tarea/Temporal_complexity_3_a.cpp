#include <iostream>
#include <vector>


using namespace std;

int main(){
    //O(mlog(n))
    
    int n = 5; //cantidad de elementos en y
    int m = 6; //cantidad de elementos en x
    vector<vector<int>> skyline = {{1,1,1,0,1,1},
                                   {1,1,0,0,1,1},
                                   {0,1,0,0,1,1},
                                   {0,1,0,0,0,1},
                                   {0,0,0,0,0,1}};
    bool tallest_found = false; // Define si se encontro el edificio más alto
    int left = 0; //Esto se refiere a la altura máxima en donde está buscando el algoritmo
    int right = n-1; //Esto se refiere a la altura mínima en donde está buscando el algoritmo
    int value = 0; //Esto es el valor que se está buscando en la matriz
    int current_tallest = 0; //Este es el valor del edificio más alto más reciente que encontró el programa
    int highest = 0; //Esto define la altura máxima que se espera que tenga el edificio más alto
    int middle; // Esto define el centro de los datos que la búsqueda binaria esta considerando

    //Lo siguiente es una versión modificada de búsqueda binaria para encontrar el 0 que está más hacia "Arriba" osea el edificio más alto
    while(tallest_found == false){
        //Revisa que los parámetros sean lógicos de lo contrario genera un error.
        if(right >= left)
            middle = left + (right-left) / 2;
        else
            throw invalid_argument("There are no buildings in the matrix.");
        //Este estilo de busqueda se ejectuta en complejidad O(mlog(n)) ya que la m se busca de forma linear y la n con busqueda binaria
        for(int i = 0; i < m; i++){
            if(value == skyline[middle][i] && middle != highest){
                right = middle - 1;
                current_tallest = i;
                break;
            }
            else if(value == skyline[middle][i] && middle == highest){
                tallest_found = true;
                current_tallest = i;
                break;
            }
            else if(i == m-1 && value != skyline[middle][i]){
                left = middle + 1;
                highest = left;
            } 
        }
        
    }
    cout << "The tallest building is in location = " << current_tallest;
    
}
