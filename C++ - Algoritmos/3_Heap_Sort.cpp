
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdlib>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
 
void heapSort(int arr[], int n);
void printArray(int arr[], int size);
vector<string> split(string str, char pattern);


//Se da una lectura de datos y calculo de tiempo de ejecucion del algoritmo//
void lectura(){
    ifstream archivo;
    string texto; 
    char pattern=',';
    unsigned t0, t1;
   
    vector<string> results;

    archivo.open("datos1.txt",ios::in);
    if(archivo.fail()){
        cout<<"No se pudo Abrir el Archivo";
        exit(1);
    }

    while (!archivo.eof())
    {
        getline(archivo,texto);  
    }


   results = split(texto, pattern);
    int arr[results.size()];
    for(int i = 0; i < results.size(); i++){
        //cout<<results[i]<<endl;
        arr[i]=atoi(results[i].c_str());
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    
    t0=clock();



    heapSort(arr,n);
    cout<<"Lista Ordenada \n";
    printArray(arr,n);


	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Tiempo de ejecucion: " << time << endl;
	
    archivo.close();
}

vector<string> split(string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}







void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // funcion recursivas que afecta a los sub arboles
        heapify(arr, n, largest);
    }
}
 
// Heapsort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // extaccion una a una los elementos para cabezeras
    for (int i = n - 1; i > 0; i--) {
        // hace el cambio de la raiz al final
        swap(arr[0], arr[i]);
 
        // envia las cabezeras
        heapify(arr, i, 0);
    }
}
 
/* Para la impresion del array */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Main principal
int main()
{
    lectura();
    return 0;
}