
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdlib>
#include<vector>
#include<string>
#include<fstream>


using namespace std;
 
vector<string> split(string str, char pattern);

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Array Temporal
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Data emitida a arrays de Izquierda y Derecha del la lista
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
 

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; 
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


// EMPEANOD UNIONES


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



    mergeSort(arr, 0, n-1);
  
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


//END UNIONS

int main()
{
 
    lectura();
    return 0;
}