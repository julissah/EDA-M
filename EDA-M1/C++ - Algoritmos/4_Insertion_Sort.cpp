
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdlib>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
 
void lectura();
vector<string> split(string str, char pattern);
// void swap(int *xp, int *yp);
void insertionSort(int arr[], int n);
void printArray(int arr[], int size);

int main(){
    lectura();
    return 0;
}



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


/*INSTRUCCIONES */


    insertionSort(arr,n);
    cout<<"Lista Ordenada \n";
    printArray(arr,n);


/*INSTRUCCIONES FIN*/



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





void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
